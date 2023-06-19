#include "u_appDigitalOutput.h"

struct u_appDigitalOutputUpdate_type u_appDigitalVar;


TaskHandle_t updateDigitalOutputArrayHandle __attribute__((section(".touchgfxccmram")));

void u_appDigitalOutput_Statup();
void u_appDigitalOutput_TurnOff();
void u_appDigitalOutput_Main();

static void updateDigitalOutputArray(void *param);

void u_appDigitalOutputCreate()
{
    BaseType_t status;
    status = xTaskCreate(updateDigitalOutputArray, "updateDigitalOutputArrayTask", 200, NULL, 2, &updateDigitalOutputArrayHandle);
    configASSERT(status == pdPASS);
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

void u_appDigitalOutput_Statup()
{

}

void u_appDigitalOutput_TurnOff()
{
	//Note: clear all digital Output
}
