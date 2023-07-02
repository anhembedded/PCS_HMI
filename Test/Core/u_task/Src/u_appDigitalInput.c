#include "u_appDigitalInput.h"
#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_pwm.h"
#include "queue.h"
#include "u_appUtilities.h"

uint32_t u32_applicationInputState[8] __attribute__((section(".touchgfxccmram")));
uint32_t u32_applicationInputState_ptr;

TaskHandle_t updateDigitalInputHandle __attribute__((section(".touchgfxccmram")));
TaskHandle_t task_updateDigitalInputHandle;

QueueHandle_t queue_digitalInputHandler;

static void updateDigitalInput(void *param);

void u_appDigitalInputCreate()
{
    BaseType_t status;
    u32_applicationInputState_ptr = (uint32_t)&u32_applicationInputState[0];
    queue_digitalInputHandler = xQueueCreate(1, sizeof(uint32_t *));

    status = xTaskCreate(updateDigitalInput, "DdigitalIn", 200, NULL, 2, &task_updateDigitalInputHandle);
    configASSERT(status == pdPASS);
}

void u_appDdigitalIn_resume()
{
     portBASE_TYPE isSuspend =  isTaskSuspended(task_updateDigitalInputHandle);
    NVIC_EnableIRQ(EXTI3_IRQn);
   NVIC_EnableIRQ(EXTI9_5_IRQn);
   NVIC_EnableIRQ(EXTI15_10_IRQn);
   if(isSuspend == pdTRUE)
   {
    vTaskResume(task_updateDigitalInputHandle);
   }

}

void u_appDdigitalIn_suspend()
{
    portBASE_TYPE isRunOrReady = isTaskRunOrReady(task_updateDigitalInputHandle);
    if(isRunOrReady == pdTRUE)
    {
        vTaskSuspend(task_updateDigitalInputHandle);
    }

  NVIC_DisableIRQ(EXTI3_IRQn);
  NVIC_DisableIRQ(EXTI9_5_IRQn);
  NVIC_DisableIRQ(EXTI15_10_IRQn);
}

void updateDigitalInput(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100));
        xQueueSend(queue_digitalInputHandler, &u32_applicationInputState_ptr, 0);
    }
}
