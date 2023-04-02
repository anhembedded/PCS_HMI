#include "u_pidSim.h"
#include "pid.h"
#include <stdint.h>
#include <math.h>
#include "FreeRTOS.h"
#include "task.h"
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
struct pid_controller ctrldata;

pid_t pid;

// Control loop input,output and setpoint variables
float input = 0, output = 0;
float setpoint = 1000;

// Control loop gains
float kp = 1, ki = 0.0, kd = 0.0;

void u_pidSim_task_PidSim(void *param);
void u_pidSimUpdateOutput(void *param);
float u_pidSim_system0TimeDomain(float timeVar, float inputVar);
TaskHandle_t u_pidSim_task_PidSimHandle;
TaskHandle_t u_pidSim_task_PidSimSetupHandle;
TaskHandle_t u_pidSim_task_PidSimControlHandle;
TaskHandle_t u_pidSim_task_UpdateOutputHandle;

void u_pidSImCreate()
{
    BaseType_t status;
    status = xTaskCreate(u_pidSim_task_PidSim, "PidSimTask", 200, NULL, 5, &u_pidSim_task_PidSimHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(u_pidSimUpdateOutput, "UpdateOutputTask", 200, NULL, 5, &u_pidSim_task_UpdateOutputHandle);
    configASSERT(status == pdPASS);
}
void u_pidSimUpdateOutput(void *param);

void u_pidSim_Init(void)
{
    // Prepare PID controller for operation
    pid = pid_create(&ctrldata, &input, &output, &setpoint, kp, ki, kd);
    // Set controler output limits from 0 to 200
    pid_limits(pid, 1, 1023);
    // Allow PID to compute and change output
    pid_auto(pid);
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
        // vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(10));
        vTaskDelay(pdMS_TO_TICKS(100));

        pid_compute(pid);

        xTaskNotifyGive(u_pidSim_task_UpdateOutputHandle);
    }
}

void u_pidSimUpdateOutput(void *param)
{
    double timeT = 0.1;
    while (1)
    {
        timeT = timeT + 0.1;
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        input = u_pidSim_system0TimeDomain(timeT, output);
    }
}

float u_pidSim_system0TimeDomain(float timeVar, float inputVar)
{

    return inputVar * timeVar - (inputVar / 9) + ((inputVar * exp(-9 * timeVar)) / 9);
}
