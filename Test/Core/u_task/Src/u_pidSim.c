#include "u_pidSim.h"
#include "pid.h"
#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
/*
 *  each transfer function we have 2 PID function:
 *  The first one is: open loop transfer function, which is the PID control theory without feedback
 *  The second one is: closed loop transfer function, which is the PID control theory with feedback
 *	Only use closed loop
 *  3 transfer function (S domain):
 *    1. Control System engineering page 165/ graph C.
 *    2.
 *    3.
 *    the system function G(s) (NOTE: G(s) is not a transfer function)
 */

PID_TypeDef TPID;
double pidInput, pidOut, pidSetpoint;

uint32_t u_pidSimOutput;
uint32_t u_pidSimInput;
uint32_t u_pidSimSetpoint;

void u_pidSim_task_PidSim(void *param);
TaskHandle_t u_pidSim_task_PidSimHandle;
TaskHandle_t u_pidSim_task_PidSimSetupHandle;
TaskHandle_t u_pidSim_task_PidSimControlHandle;
TaskHandle_t u_pidSim_task_UpdateOutputHandle;

void u_pidSImCreate()
{
    BaseType_t status;
    status = xTaskCreate(u_pidSim_task_PidSim, "u_pidSim_task_PidSimTask", 200, NULL, 2, &u_pidSim_task_PidSimHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(u_pidSim_task_UpdateOutputHandle, "u_pidSim_task_UpdateOutputTask", 200, NULL, 2, &u_pidSim_task_UpdateOutputHandle);
    configASSERT(status == pdPASS);
}
void u_pidSimUpdateOutput(void *param);

void u_pidSim_Init(void)
{
    PID(&TPID, &pidInput, &pidOut, &pidSetpoint, 2, 0, 0, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetSampleTime(&TPID, 100);
}
uint32_t systemFuctionTimeDomain(uint32_t u32_inputVar)
{
    uint32_t feedBack = 0u;
}

void u_pidSim_task_PidSim(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    u_pidSim_Init();

    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100));
        PID_Compute(&TPID);
        xTaskNotifyGive(u_pidSim_task_UpdateOutputHandle);
    }
}

void u_pidSimUpdateOutput(void *param)
{
    while (1)
    {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        u_pidSimOutput = (uint32_t)pidOut;
        u_pidSimInput = (uint32_t)pidInput;
        u_pidSimSetpoint = (uint32_t)u_pidSimSetpoint;
    }
}
