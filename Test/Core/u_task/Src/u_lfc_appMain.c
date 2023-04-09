#include "u_lfc_appMain.h"
#include "u_appPwm.h"

PID_TypeDef u_lfc_PID_Oject;
double u_lfc_appPid_Kp = 0.0F;
double u_lfc_appPid_Ki = 0.0F;
double u_lfc_appPid_Kd = 0.0F;
double u_lfc_appPid_setPoint;
double u_lfc_appPid_feedback;
double u_lfc_appPid_pidOutput;

TaskHandle_t u_lfc_task_PidSimControlHandle;
TaskHandle_t u_flc_task_UpdateOutputHandle;

void u_lfc_appPid_pdiCompute(void *param);
void u_lfc_appPid_updateOutput(void *param);
float u_lfc_appPid_GetFeedBack();

void u_lfc_appMainCreate()
{
    BaseType_t status;
    u_appPwmCreate();
    status = xTaskCreate(u_lfc_appPid_pdiCompute, "PidSimTask", 200, NULL, 5, &u_lfc_task_PidSimControlHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(u_lfc_appPid_updateOutput, "UpdateOutputTask", 200, NULL, 5, &u_flc_task_UpdateOutputHandle);
    configASSERT(status == pdPASS);
}

static void pidMainTask();
void u_lfc_Init(void)
{
    PID(&u_lfc_PID_Oject, &u_lfc_appPid_feedback, &u_lfc_appPid_pidOutput, &u_lfc_appPid_setPoint, u_lfc_appPid_Kp, u_lfc_appPid_Ki, u_lfc_appPid_Kd, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetMode(&u_lfc_PID_Oject, _PID_MODE_AUTOMATIC);
    PID_SetSampleTime(&u_lfc_PID_Oject, 100);
    PID_SetOutputLimits(&u_lfc_PID_Oject, 0, 1023);
}
void u_lfc_appPid_pdiCompute(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    u_lfc_Init();

    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100));
        u_lfc_appPid_feedback = u_lfc_appPid_GetFeedBack();
        PID_Compute(&u_lfc_PID_Oject);
        xTaskNotifyGive(u_flc_task_UpdateOutputHandle);
    }
}

void u_lfc_appPid_updateOutput(void *param)
{
    double timeT = 0.1;
    while (1)
    {
        timeT = timeT + 0.1;
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
    }
}