#include "u_appDigitalOutput.h"
#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_pwm.h"
#include "queue.h"

uint32_t updateDigitalValue;
uint32_t u32_applicationOutputState[8];
uint32_t *u32_applicationAdcState_ptr;

struct u_appDigitalOutputUpdate_type
{
    uint8_t u_appDigitalOutputIsUpdate = 0x00U;
    uint8_t digitalState[8];
};

TaskHandle_t updateDigitalOutputHandle __attribute__((section(".touchgfxccmram")));
TaskHandle_t updateDigitalOutputArrayHandle __attribute__((section(".touchgfxccmram")));

static void updateDigitalOutput(void *param);
static void updateDigitalOutputArray(void *param);

QueueHandle_t queue_updateDigitalOutput __attribute__((section(".touchgfxccmram")));

void u_appDigitalOutputCreate()
{
    BaseType_t status;
    queue_updateDigitalOutput = xQueueCreate(1, sizeof(uint32_t *));
    status = xTaskCreate(updateDigitalOutput, "updateDigitalOutputTask", 200, NULL, 2, &updateDigitalOutputHandle);
    configASSERT(status == pdPASS);
}

static void updateDigitalOutput(void *param)
{
    uint32_t digitalBitmask = 0;
    uint32_t isReciveNotify = 0;
    while (pdTRUE)
    {
        isReciveNotify = xTaskNotifyWait(0, UINT32_MAX, &digitalBitmask, portMAX_DELAY);
        if (isReciveNotify == pdTRUE)
        {
            updateDigitalValue = digitalBitmask;
            u_gpio_writePin(DO_0_PORT, DO_0_PIN, READ_BIT(digitalBitmask, 0));
            u_gpio_writePin(DO_1_PORT, DO_1_PIN, READ_BIT(digitalBitmask, 1));
            u_gpio_writePin(DO_2_PORT, DO_2_PIN, READ_BIT(digitalBitmask, 2));
            u_gpio_writePin(DO_3_PORT, DO_3_PIN, READ_BIT(digitalBitmask, 3));
            u_gpio_writePin(DO_4_PORT, DO_4_PIN, READ_BIT(digitalBitmask, 4));
        }
        else
        {
            /* Time-out*/
        }
    }
}

static void updateDigitalOutputArray(void *param)
{
    while (pdTRUE)
    {
        if (u_appDigitalOutputIsUpdate ==)
    }
}