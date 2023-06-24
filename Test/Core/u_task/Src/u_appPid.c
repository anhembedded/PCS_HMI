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
#define U_APP_PID_OUTPUT_MAX 0U
#define U_APP_PID_OUTPUT_MIN 1023U
struct u_appPid_updateParam_type
{
    uint32_t messControl;
    double Kp;
    double Ki;
    double Kd;
    double feedback;
    double setPoint;
    double pidOutput;
    uint32_t sampleTime;
};
struct u_appPid_updateParam_type pidParam;
uint32_t *u32_feedback_ptr = NULL;
 
double u_appPid_getPidOutput();


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
void u_appPid_setSetPoint(double setpoint_parm);
static void pidInit();

uint32_t u_appPid_GetFeedBack();

TaskHandle_t u_task_PidHandle;
TaskHandle_t u_task_PidSimSetupHandle;
TaskHandle_t u_task_PidSimControlHandle;
TaskHandle_t u_task_UpdateOutputHandle;

QueueHandle_t u_pid_queue_feedbackHandle;
QueueHandle_t u_pidSim_queue_messageControl;

void u_appPidCreate()
{
    pidParam.sampleTime = 100;
    BaseType_t status;
    pidInit();
    u_pid_queue_feedbackHandle = xQueueCreate(1, sizeof(uint32_t *));
    status = xTaskCreate(u_appPid_pdiCompute, "PidSimTask", 200, NULL, 2, &u_task_PidHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(u_appPid_updateOutput, "UpdateOutputTask", 200, NULL, 2, &u_task_UpdateOutputHandle);
    configASSERT(status == pdPASS);
}
void u_pidSimUpdateOutput(void *param);

static void pidInit()
{
    PID(&PID_Oject, &pidParam.feedback, &pidParam.pidOutput, &pidParam.setPoint, pidParam.Kp, pidParam.Ki, pidParam.Kd, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetMode(&PID_Oject, _PID_MODE_AUTOMATIC);
    PID_SetSampleTime(&PID_Oject, pidParam.sampleTime);
    PID_SetOutputLimits(&PID_Oject, (double)U_APP_PID_OUTPUT_MIN, (double)U_APP_PID_OUTPUT_MAX);
}

void u_pidSim_Init(void)
{
    PID(&PID_Oject, &u_appPid_feedback, &u_appPid_pidOutput, &u_appPid_setPoint, u_appPid_Kp, u_appPid_Ki, u_appPid_Kd, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetMode(&PID_Oject, _PID_MODE_AUTOMATIC);
    PID_SetSampleTime(&PID_Oject, pidParam.sampleTime);
    PID_SetOutputLimits(&PID_Oject, 0, 1023);
}

void u_appPid_pdiCompute(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    u_pidSim_Init();

    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(pidParam.sampleTime));
        u_appPid_feedback = u_appPid_GetFeedBack();
        PID_Compute(&PID_Oject);
        xTaskNotifyGive(u_task_UpdateOutputHandle); // Unblock for Task::u_appPid_updateOutput
    }
}

void u_appPid_updateOutput(void *param)
{

    while (1)
    {
       // ulTaskNotifyTake(pdTRUE, portMAX_DELAY);// Notify pid::output had beed computed here
     BaseType_t isRecieved = xQueueReceive(u_pid_queue_feedbackHandle, &u32_feedback_ptr, 0);
     if(isRecieved == 1U)
     {
        pidParam.feedback = u32_feedback_ptr[0];
     }
     
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
    while (1)
    {


    }
}
void u_appPid_setSetPoint(double setpoint_parm)
{
	pidParam.setPoint = setpoint_parm;
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
