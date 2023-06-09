#include "u_appPid.h"
#include "pid.h"
#include <stdint.h>
#include <math.h>
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "u_appUtilities.h"
#include "gui/model/u_type.h"
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
#define U_APP_PID_OUTPUT_MAX 1023U
#define U_APP_PID_OUTPUT_MIN 0U

struct u_appPid_updateParam_type pidParam;
struct u_appPid_updateParam_type pidFormForntEnd;
uint32_t actuatorVar = 0;
uint32_t *u32_feedback_ptr = NULL;
 
double u_appPid_getPidOutput();
void u_appPid_updateParameters();
void u_appPid_pdiCompute(void *param);
void u_appPid_updateOutput();
void u_appPid_setSetPoint(double setpoint_parm);
void u_appid_updateOutput(void *param);
void u_appPid_updatePid(void *param);

static void pidInit();
static void u_appPid_updateFeedback(uint32_t actIndex);

TaskHandle_t u_task_PidHandle;
TaskHandle_t u_task_PidUpdateHandle;
TaskHandle_t u_task_UpdateOutputHandle;

QueueHandle_t u_pid_queue_feedbackHandle;
QueueHandle_t u_pid_queue_output;
QueueHandle_t u_pid_queue_actuator;
QueueHandle_t u_pid_queue_pidParam;
QueueHandle_t u_pid_queue_sendOutPutToFrontEnd;


void u_appPidCreate()
{
    pidParam.sampleTime = 100;
    BaseType_t status;
    pidInit();
    u_pid_queue_feedbackHandle = xQueueCreate(1, sizeof(uint32_t *));
    u_pid_queue_output = xQueueCreate(1, sizeof(uint32_t));
    u_pid_queue_sendOutPutToFrontEnd = xQueueCreate(1, sizeof(uint32_t));
    u_pid_queue_actuator = xQueueCreate(1, sizeof(uint32_t));
    u_pid_queue_pidParam = xQueueCreate(1, sizeof(struct u_appPid_updateParam_type));

    status = xTaskCreate(u_appPid_pdiCompute, "pidComputing", 200, NULL, 2, &u_task_PidHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(u_appPid_updatePid, "pidUpdate", 200, NULL, 2, &u_task_PidUpdateHandle);
    configASSERT(status == pdPASS);
    
}

void u_appPidComputing_resume()
{
    portBASE_TYPE isSuspend = isTaskSuspended(u_task_PidHandle);
    if (isSuspend == pdTRUE)
    {
        vTaskResume(u_task_PidHandle);
    }
}

void u_appPidComputing_suspend()
{
    portBASE_TYPE isRunOrReady = isTaskRunOrReady(u_task_PidHandle);
    if (isRunOrReady == pdTRUE)
    {
        vTaskSuspend(u_task_PidHandle);
    }
    pidParam.pidOutput = 0;
   xQueueSend(u_pid_queue_output,&pidParam.pidOutput, pdMS_TO_TICKS(0)); /*send to pwm output*/

}

static void pidInit()
{
	PID_Oject.Kp =1;
    PID(&PID_Oject, &pidParam.feedback, &pidParam.pidOutput, &pidParam.setPoint, pidParam.Kp, pidParam.Ki, pidParam.Kd, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetMode(&PID_Oject, _PID_MODE_AUTOMATIC);
    PID_SetSampleTime(&PID_Oject, pidParam.sampleTime);
    PID_SetOutputLimits(&PID_Oject, (double)U_APP_PID_OUTPUT_MIN, (double)U_APP_PID_OUTPUT_MAX);
}

void u_appPid_pdiCompute(void *param)
{
    TickType_t xLastWakeTime;
    portBASE_TYPE isRec = 0;
    xLastWakeTime = xTaskGetTickCount();
    const uint32_t NO_WAITTING = 0;
    uint32_t u32_pidOut;
    while (1)
    {
        isRec = xQueueReceive(u_pid_queue_pidParam, (void*)&pidFormForntEnd, NO_WAITTING);
        if(isRec == pdTRUE)
        {
           pidParam.setPoint =  pidFormForntEnd.setPoint;
           PID_Oject.Kp = pidFormForntEnd.Kp;
           PID_Oject.Ki = pidFormForntEnd.Ki;
           PID_Oject.Kd = pidFormForntEnd.Kd;
        }
        xQueueReceive(u_pid_queue_actuator,(void *) &actuatorVar, NO_WAITTING);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(pidParam.sampleTime));
        u_appPid_updateFeedback(actuatorVar);
        PID_Compute(&PID_Oject);
        u32_pidOut = (uint32_t)pidParam.pidOutput;
        xQueueSend(u_pid_queue_output,(void*)&u32_pidOut, pdMS_TO_TICKS(0)); /*send to pwm output*/
        xQueueSend(u_pid_queue_sendOutPutToFrontEnd,(void*)&u32_pidOut,pdMS_TO_TICKS(0));/*send to backEnd*/
    }
}

void u_appPid_updatePid(void *param)
{
    portBASE_TYPE isRec = 0;
    while(1)
    {
    isRec = xQueueReceive(u_pid_queue_pidParam, (void*)&pidFormForntEnd, portMAX_DELAY);
      
        if(isRec == pdTRUE)
        {
           pidParam.setPoint =  pidFormForntEnd.setPoint;
           PID_Oject.Kp = pidFormForntEnd.Kp;
           PID_Oject.Ki = pidFormForntEnd.Ki;
           PID_Oject.Kd = pidFormForntEnd.Kd;
        }
    }
}
static void u_appPid_updateFeedback(uint32_t actIndex)
{
    BaseType_t isRecieved = xQueueReceive(u_pid_queue_feedbackHandle, &u32_feedback_ptr, 0);
    if(isRecieved == 1U)
     {

        pidParam.feedback = u32_feedback_ptr[actIndex];
     }
}

void u_appPid_setSetPoint(double setpoint_parm)
{
	pidParam.setPoint = setpoint_parm;
}

