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

#define U_APP_PID_MESSAGE_CONTROL_ON 0b01
#define U_APP_PID_MESSAGE_CONTROL_UPDATE_PID 0b10

#define U_APP_PID_ACTUAL_LEVEL 0b
#define U_APP_PID_ACTUAL_PRESSURE 1u

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
void u_appPid_updateParameters();
void u_appPid_pdiCompute(void *param);
void u_appPid_updateOutput();
void u_appPid_setSetPoint(double setpoint_parm);
void u_appid_updateOutput(void *param);

static void pidInit();
static void u_appPid_updateFeedback();

TaskHandle_t u_task_PidHandle;
TaskHandle_t u_task_UpdateOutputHandle;

QueueHandle_t u_pid_queue_feedbackHandle;
QueueHandle_t u_pid_queue_output;


void u_appPidCreate()
{
    pidParam.sampleTime = 100;
    BaseType_t status;
    pidInit();
    u_pid_queue_feedbackHandle = xQueueCreate(1, sizeof(uint32_t *));
    u_pid_queue_output = xQueueCreate(1, sizeof(uint32_t));
    status = xTaskCreate(u_appPid_pdiCompute, "Pid", 200, NULL, 2, &u_task_PidHandle);
    configASSERT(status == pdPASS);
}


static void pidInit()
{
    PID(&PID_Oject, &pidParam.feedback, &pidParam.pidOutput, &pidParam.setPoint, pidParam.Kp, pidParam.Ki, pidParam.Kd, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetMode(&PID_Oject, _PID_MODE_AUTOMATIC);
    PID_SetSampleTime(&PID_Oject, pidParam.sampleTime);
    PID_SetOutputLimits(&PID_Oject, (double)U_APP_PID_OUTPUT_MIN, (double)U_APP_PID_OUTPUT_MAX);
}

void u_appPid_pdiCompute(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(pidParam.sampleTime));
        u_appPid_updateFeedback();
        PID_Compute(&PID_Oject);
        xQueueSend(u_pid_queue_output,&pidParam.pidOutput, pdMS_TO_TICKS(0)); /*send to pwm output*/
    }
}

static void u_appPid_updateFeedback()
{
    BaseType_t isRecieved = xQueueReceive(u_pid_queue_feedbackHandle, &u32_feedback_ptr, 0);
    if(isRecieved == 1U)
     {
        pidParam.feedback = u32_feedback_ptr[0];
     }
}

void u_appPid_setSetPoint(double setpoint_parm)
{
	pidParam.setPoint = setpoint_parm;
}

