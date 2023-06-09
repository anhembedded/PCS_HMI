#include "u_appAdc.h"
#include "u_appPid.h"
#include "stm32f4xx_ll_adc.h"
#include "u_appUtilities.h"

uint32_t u32_enableAdc;



uint32_t u32_applicationAdc[4] __attribute__((section(".touchgfxccmram")));
uint32_t u32_applicationAdc_ptr __attribute__((section(".touchgfxccmram")));

TaskHandle_t updateAdcFrequenceHandle __attribute__((section(".touchgfxccmram")));
QueueHandle_t adcSendToFrontEndHandle __attribute__((section(".touchgfxccmram")));

static void u_appAdc_TurnOff();
extern uint32_t adcVar;
static void updateAdcFrequence(void *param);


static void updateAdcFrequence(void *param)
{
    TickType_t xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    while (1)
    {
        vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(100));
        /*Start*/
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_9);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion, Interrupt give Notify when compleet*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[0] = adcVar;
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_12);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion, Interrupt give Notify when compleet*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[1] = adcVar;
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_13);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion, Interrupt give Notify when compleet*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[2] = adcVar;
        LL_ADC_REG_SetSequencerRanks(ADC1, LL_ADC_REG_RANK_1, LL_ADC_CHANNEL_14);
        LL_ADC_REG_StartConversionSWStart(ADC1);
        /*Wait for end of conversion, Interrupt give Notify when compleet*/
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        /*TransferData*/
        u32_applicationAdc[3] = adcVar;
        xQueueSend(adcSendToFrontEndHandle, &u32_applicationAdc_ptr, 0);
        xQueueSend(u_pid_queue_feedbackHandle,&u32_applicationAdc_ptr, 0);
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

void u_appAdc_resume()
{
   portBASE_TYPE isSuspend = isTaskSuspended(updateAdcFrequenceHandle);
   u_appAdc_Statup();
   if(isSuspend == pdTRUE)
   {
       vTaskResume(updateAdcFrequenceHandle);
   }
   u_appAdc_Statup();
}

void u_appAdc_suspend()
{
    portBASE_TYPE taskStatus = isTaskRunOrReady(updateAdcFrequenceHandle);
    if(taskStatus == pdTRUE)
    {
        vTaskSuspend(updateAdcFrequenceHandle);
    }
    u_appAdc_TurnOff();
}

static void u_appAdc_TurnOff()
{
   // NVIC_DisableIRQ(ADC_IRQn);
    u32_applicationAdc[0] = 0;
    u32_applicationAdc[1] = 0;
    u32_applicationAdc[2] = 0;
    u32_applicationAdc[3] = 0;
   // xQueueSend(adcSendToFrontEndHandle, &u32_applicationAdc_ptr, 0);
}

void u_appAdc_Statup()
{
    //xQueueReset(adcSendToFrontEndHandle);
    //NVIC_EnableIRQ(ADC_IRQn);
}
