#ifndef CORE_U_TASK_INC_U_APPADC
#define CORE_U_TASK_INC_U_APPADC

#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_adc.h"
#include "u_pwm.h"
#include "queue.h"

extern uint32_t u32_applicationAdc[4];
extern uint32_t u32_applicationAdc_ptr;
extern TaskHandle_t readAdcTaskHandle;
extern QueueHandle_t adcSendToFrontEndHandle;

void u_appAdcCreate();

#endif /* CORE_U_TASK_INC_U_APPADC */
