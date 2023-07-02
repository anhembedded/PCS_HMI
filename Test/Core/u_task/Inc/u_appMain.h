#ifndef CORE_U_TASK_INC_U_APPMAIN
#define CORE_U_TASK_INC_U_APPMAIN
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "u_appAdc.h"
#include "u_appPwm.h"
#include "u_appDigitalInput.h"
#include "u_appDigitalOutput.h"
#include "u_appPid.h"


#define  NumbOfTasks 5
enum task_index
{
    suppened,
    run,
    appADC,
    appDigitalInput,
    appDigitalOutput,
    appPid,
    appPwm
};
enum system_State
{
    
}


extern uint8_t u_appMain_tasksArray[NumbOfTasks];
extern uint32_t u32_applicationAdc[4];
extern uint32_t u32_applicationAdc_ptr;
extern uint32_t u32_applicationInputState[8];
extern uint32_t u32_applicationOutputState[8];
extern uint32_t u32_applicationSampleFrequency;

extern TaskHandle_t updateAdcFrequenceHandle;
extern TaskHandle_t blinkLed_GreenHandle;
extern TaskHandle_t updateDigitalOutputHandle;
extern TaskHandle_t updatePWMHandle;
extern TaskHandle_t updateDigitalInputHandle;

extern QueueHandle_t adcSendToFrontEndHandle;
extern QueueHandle_t queue_updatePwmCh0Handle;
extern QueueHandle_t queue_updatePwmCh1Handle;

void u_appMainCreate();

#endif /* CORE_U_TASK_INC_U_APPMAIN */
