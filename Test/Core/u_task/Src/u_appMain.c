#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_pwm.h"
#include "queue.h"


uint8_t u_appMain_tasksArray[NumbOfTasks];
QueueHandle_t u_appMain_queue_taskState __attribute__((section(".touchgfxccmram")));


uint32_t u32_applicationSampleFrequency __attribute__((section(".touchgfxccmram")));

TaskHandle_t blinkLed_GreenHandle __attribute__((section(".touchgfxccmram")));
TaskHandle_t blinkOrange_OrangeHandle __attribute__((section(".touchgfxccmram")));

TaskHandle_t mainApplicationHandle __attribute__((section(".touchgfxccmram")));

static void mainApplication(void *param);
static void blinkLed_Green(void *param);
static void blinkLed_Orange(void *param);

void u_appMainCreate()
{
    BaseType_t status;
    status = xTaskCreate(mainApplication, "mainApplicationTask", 200, NULL, 1, &mainApplicationHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(blinkLed_Green, "blinkLed_GreenTask", 200, NULL, 2, &blinkLed_GreenHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(blinkLed_Orange, "blinkLed_OrangeTask", 200, NULL, 2, &blinkOrange_OrangeHandle);
    configASSERT(status == pdPASS);
    u_appMain_queue_taskState = xQueueCreate(sizeof(u_appMain_tasksArray)/sizeof(uint8_t), sizeof(uint8_t));

    u_appDigitalInputCreate();
    u_appDigitalOutputCreate();
    u_appPwmCreate();
    u_appAdcCreate();
    u_appPidCreate();
}

static void mainApplication(void *param)
{
    while (1)
    {
       /*  xQueueReceive(u_appMain_queue_taskState,u_appMain_tasksArray, portMAX_DELAY);
        if(u_appMain_tasksArray[appADC] == 1)
        {

        }else
        {
            
        } */ 
    }
}

static void blinkLed_Green(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    while (1)
    {
        u_gpio_togglePin(LED_GREEN_PORT, LED_GREEN_PIN);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1050 - u32_PwmCh0_10bit));
    }
}
static void blinkLed_Orange(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    while (1)
    {
        u_gpio_togglePin(LED_ORANGE_PORT, LED_ORANGE_PIN);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1050 - u32_PwmCh1_10bit));
    }
}
