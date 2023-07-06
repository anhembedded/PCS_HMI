#include "u_appDigitalOutput.h"
#include "u_appUtilities.h"

uint32_t u_appDigitalOut_array[4];

struct u_appDigitalOutputUpdate_type u_appDigitalVar;

TaskHandle_t updateDigitalOutputArrayHandle __attribute__((section(".touchgfxccmram")));
TaskHandle_t u_appDigitalOutput_mainHandle __attribute__((section(".touchgfxccmram")));

QueueHandle_t u_app_queue_digitalOutput __attribute__((section(".touchgfxccmram")));


static void updateDigitalOutputArray(void *param);

void u_appDigitalOutputCreate()
{
    BaseType_t status;
    u_app_queue_digitalOutput = xQueueCreate(1, sizeof(uint32_t *));
    status = xTaskCreate(updateDigitalOutputArray, "DdigitalOut", 200, NULL, 2, &updateDigitalOutputArrayHandle);
    configASSERT(status == pdPASS);
    status = xTaskCreate(u_appDigitalOutput_main, "DdigitalOutMain", 200, NULL, 2, &u_appDigitalOutput_mainHandle);
    configASSERT(status == pdPASS);

}

void u_appDigitalOut_resume()
{
    portBASE_TYPE isSuspend = isTaskSuspended(updateDigitalOutputArrayHandle);
    if (isSuspend == pdTRUE)
    {
        vTaskResume(updateDigitalOutputArrayHandle);
    }
}

void u_appDigitalOut_suspend()
{
    portBASE_TYPE isRunOrReady = isTaskRunOrReady(updateDigitalOutputArrayHandle);
    if (isRunOrReady == pdTRUE)
    {
        vTaskSuspend(updateDigitalOutputArrayHandle);
    }
    
}

static void updateDigitalOutputArray(void *param)
{
    u_appDigitalVar.digitalState[0] = 0;
    u_appDigitalVar.digitalState[1] = 0;
    u_appDigitalVar.digitalState[2] = 0;
    u_appDigitalVar.digitalState[3] = 0;
    u_appDigitalVar.digitalState[4] = 0;

    while (pdTRUE)
    {
        if (u_appDigitalVar.isUpdate == 1)
        {
            u_gpio_writePin(DO_0_PORT, DO_0_PIN, u_appDigitalVar.digitalState[0]);
            u_gpio_writePin(DO_1_PORT, DO_1_PIN, u_appDigitalVar.digitalState[1]);
            u_gpio_writePin(DO_2_PORT, DO_2_PIN, u_appDigitalVar.digitalState[2]);
            u_gpio_writePin(DO_3_PORT, DO_3_PIN, u_appDigitalVar.digitalState[3]);
            u_gpio_writePin(DO_4_PORT, DO_4_PIN, u_appDigitalVar.digitalState[4]);
            u_appDigitalVar.isUpdate = 0;
        }
        else
        {
            vTaskDelay(pdMS_TO_TICKS(100));
        }
    }
}

void u_appDigitalOutput_main()
{
    uint32_t isReciv = 0;
    while(1)
    {
    	isReciv = xQueueReceive(u_app_queue_digitalOutput, u_appDigitalOut_array, portMAX_DELAY);
        if(isReciv == pdTRUE)
        {
            u_gpio_writePin(DO_0_PORT, DO_0_PIN, u_appDigitalOut_array[0]);
            u_gpio_writePin(DO_1_PORT, DO_1_PIN, u_appDigitalOut_array[1]);
            u_gpio_writePin(DO_2_PORT, DO_2_PIN, u_appDigitalOut_array[2]);
            u_gpio_writePin(DO_3_PORT, DO_3_PIN, u_appDigitalOut_array[3]);
        }
    }
}

void u_appDigitalOutput_Statup()
{
}

void u_appDigitalOutput_TurnOff()
{
    // Note: clear all digital Output
}
