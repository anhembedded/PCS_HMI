#include "u_appDigitalInput.h"
#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_pwm.h"
#include "queue.h"

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

    status = xTaskCreate(updateDigitalInput, "uDdigitalIn", 200, NULL, 2, &task_updateDigitalInputHandle);
    configASSERT(status == pdPASS);
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
