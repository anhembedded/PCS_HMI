#include "u_appAdc.h"
#include "stm32f4xx_ll_adc.h"

uint32_t u32_enableAdc;



uint32_t u32_applicationAdc[4] __attribute__((section(".touchgfxccmram")));
uint32_t u32_applicationAdc_ptr __attribute__((section(".touchgfxccmram")));

TaskHandle_t updateAdcFrequenceHandle __attribute__((section(".touchgfxccmram")));
QueueHandle_t adcSendToFrontEndHandle __attribute__((section(".touchgfxccmram")));

extern uint32_t adcVar;
static void updateAdcFrequence(void *param);


static void updateAdcFrequence(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(10));
        /*Start*/
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_9);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[0] = adcVar;
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_12);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[1] = adcVar;
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_13);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[2] = adcVar;
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_14);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[3] = adcVar;
        xQueueSend(adcSendToFrontEndHandle, &u32_applicationAdc_ptr, 0);
    }
}
void u_appAdcCreate()
{
    BaseType_t status;
    u32_applicationAdc_ptr = (uint32_t)&u32_applicationAdc[0];
    adcSendToFrontEndHandle = xQueueCreate(1, sizeof(uint32_t *));
    status = xTaskCreate(updateAdcFrequence, "readAdcTask", 200, NULL, 2, &updateAdcFrequenceHandle);
    configASSERT(status == pdPASS);
}

void u_appAdc_TurnOff()
{
    NVIC_DisableIRQ(ADC_IRQn);
    u32_applicationAdc[0] = 0;
    u32_applicationAdc[1] = 0;
    u32_applicationAdc[2] = 0;
    u32_applicationAdc[3] = 0;
    xQueueSend(adcSendToFrontEndHandle, &u32_applicationAdc_ptr, 0);
}

void u_appAdc_Statup()
{
    NVIC_EnableIRQ(ADC_IRQn);
}
