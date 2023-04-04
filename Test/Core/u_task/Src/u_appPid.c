#include "u_appPid.h"
#include "pid.h"
#include <stdint.h>
#include <math.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
/*
 *  each transfer function we have 2 PID function:
 *  The first one is: open loop transfer function, which is the PID control theory without feedback
 *  The second one is: closed loop transfer function, which is the PID control theory with feedback
 *	Only use closed loop
 *  3 transfer function (S domain):
 *    1. Control System engineering page 165/ graph C. system0Sdomain = (a/s) *(9/(1*s^2+9*s+9))
 *    2.
 *    3.
 *    the system function G(s) (NOTE: G(s) is not a transfer function)
 */

// Structure to strore PID data and pointer to PID structure
PID_TypeDef PID_Oject;
double u_appPid_Kp = 0.0F;
double u_appPid_Ki = 0.0F;
double u_appPid_Kd = 0.0F;
double u_appPid_setPoint;
double u_appPid_feedback;
double u_appPid_pidOutput;

#define U_APP_PID_MESSAGE_CONTROL_ON 0b01
#define U_APP_PID_MESSAGE_CONTROL_UPDATE_PID 0b10

/*
 * MessControl:
 *
 *
 */
struct u_appPid_updateParam_type
{
    uint32_t messControl;
    double u_appPid_Kp;
    double u_appPid_Ki;
    double u_appPid_Kd;
    double u_appPid_setPoint;
};

uint32_t *u32_feedback_ptr = NULL;

double u_appPid_getPidOutput();

static void u_appPid_start();
static void u_appPid_stop();
static uint32_t messageControl_isOn(struct u_appPid_updateParam_type *pidMess);
static uint32_t messageControl_isUpdatePidParameter(struct u_appPid_updateParam_type *pidMess);
void messageControl_setOn(struct u_appPid_updateParam_type *pidMess);
void messageControl_clearOn(struct u_appPid_updateParam_type *pidMess);
void messageControl_setUpdatePidParameter(struct u_appPid_updateParam_type *pidMess);
void messageControl_clearUpdatePidParameter(struct u_appPid_updateParam_type *pidMess);
void u_appPid_updateParameters();

void u_appPid_pdiCompute(void *param);
void u_appPid_updateOutput(void *param);
void u_appPid_controlTask(void *param);

uint32_t u_appPid_GetFeedBack();

TaskHandle_t u_pidSim_task_PidSimHandle;
TaskHandle_t u_pidSim_task_PidSimSetupHandle;
TaskHandle_t u_pidSim_task_PidSimControlHandle;
TaskHandle_t u_pidSim_task_UpdateOutputHandle;

QueueHandle_t u_pidSim_queue_messageControl;

void u_appPidCreate()
{
    BaseType_t status;
    status = xTaskCreate(u_appPid_pdiCompute, "PidSimTask", 200, NULL, 5, &u_pidSim_task_PidSimHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(u_appPid_updateOutput, "UpdateOutputTask", 200, NULL, 5, &u_pidSim_task_UpdateOutputHandle);
    configASSERT(status == pdPASS);
}
void u_pidSimUpdateOutput(void *param);

void u_pidSim_Init(void)
{
    PID(&PID_Oject, &u_appPid_feedback, &u_appPid_pidOutput, &u_appPid_setPoint, u_appPid_Kp, u_appPid_Ki, u_appPid_Kd, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetMode(&PID_Oject, _PID_MODE_AUTOMATIC);
    PID_SetSampleTime(&PID_Oject, 100);
    PID_SetOutputLimits(&PID_Oject, 0, 1023);
}

void u_appPid_pdiCompute(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    u_pidSim_Init();

    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100));
        u_appPid_feedback = u_appPid_GetFeedBack();
        PID_Compute(&PID_Oject);
        xTaskNotifyGive(u_pidSim_task_UpdateOutputHandle);
    }
}

void u_appPid_updateOutput(void *param)
{
    double timeT = 0.1;
    while (1)
    {
        timeT = timeT + 0.1;
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }
}

uint32_t u_appPid_GetFeedBack()
{
    return *u32_feedback_ptr;
}
double u_appPid_getPidOutput()
{
    return u_appPid_pidOutput;
}

void u_appPid_updateParameters()
{
    PID(&PID_Oject, &u_appPid_feedback, &u_appPid_pidOutput, &u_appPid_setPoint, u_appPid_Kp, u_appPid_Ki, u_appPid_Kd, _PID_P_ON_E, _PID_CD_DIRECT);
}

void u_appPid_controlTask(void *param)
{
    struct u_appPid_updateParam_type *queueControlPtr;
    while (1)
    {
    }
}
uint32_t messageControl_isOn(struct u_appPid_updateParam_type *pidMess)
{
    return READ_BIT(pidMess->messControl, U_APP_PID_MESSAGE_CONTROL_ON);
}
uint32_t messageControl_isUpdatePidParameter(struct u_appPid_updateParam_type *pidMess)
{
    return READ_BIT(pidMess->messControl, U_APP_PID_MESSAGE_CONTROL_UPDATE_PID);
}
void messageControl_setOn(struct u_appPid_updateParam_type *pidMess)
{
    SET_BIT(pidMess->messControl, U_APP_PID_MESSAGE_CONTROL_ON);
}
void messageControl_clearOn(struct u_appPid_updateParam_type *pidMess)
{
    CLEAR_BIT(pidMess->messControl, U_APP_PID_MESSAGE_CONTROL_ON);
}
void messageControl_clearUpdatePidParameter(struct u_appPid_updateParam_type *pidMess)
{
    CLEAR_BIT(pidMess->messControl, U_APP_PID_MESSAGE_CONTROL_UPDATE_PID);
}