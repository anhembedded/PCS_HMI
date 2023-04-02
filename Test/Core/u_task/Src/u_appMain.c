#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_pwm.h"
#include "queue.h"

uint32_t u32_applicationSampleFrequency __attribute__((section(".touchgfxccmram")));

TaskHandle_t blinkLed_GreenHandle __attribute__((section(".touchgfxccmram")));
TaskHandle_t mainApplicationHandle __attribute__((section(".touchgfxccmram")));

static void mainApplication(void *param);
static void blinkLed_Green(void *param);

void u_appMainCreate()
{
    BaseType_t status;
    status = xTaskCreate(mainApplication, "mainApplicationTask", 200, NULL, 2, &mainApplicationHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(blinkLed_Green, "blinkLed_GreenTask", 200, NULL, 2, &blinkLed_GreenHandle);
    configASSERT(status == pdPASS);
    u_appDigitalInputCreate();
    u_appDigitalOutputCreate();
    u_appPwmCreate();
    u_appAdcCreate();
    // u_pidSImCreate();
}

static void mainApplication(void *param)
{
    uint32_t updateDigitalValue = 0;

    while (1)
    {
        xTaskNotify(updateDigitalOutputHandle, updateDigitalValue, eSetValueWithOverwrite);
        updateDigitalValue++;

        vTaskDelay(pdMS_TO_TICKS(500));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

static void blinkLed_Green(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();
    while (1)
    {
        u_gpio_togglePin(LED_GREEN_PORT, LED_GREEN_PIN);
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(200));
    }
}
