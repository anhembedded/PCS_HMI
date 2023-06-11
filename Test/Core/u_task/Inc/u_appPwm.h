#ifndef CORE_U_TASK_INC_U_APPPWM
#define CORE_U_TASK_INC_U_APPPWM
#include "u_appMain.h"
#include "u_gpio.h"
#include "u_firmwareDefination.h"
#include "u_adc.h"
#include "u_pwm.h"
#include "queue.h"

extern uint32_t u32_PwmCh0_10bit;
extern uint32_t u32_PwmCh1_10bit;

void u_appPwmCreate();

#endif /* CORE_U_TASK_INC_U_APPPWM */
