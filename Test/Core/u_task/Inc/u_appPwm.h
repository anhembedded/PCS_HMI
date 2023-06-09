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
void u_appPWM_updatePwmCh_resume();
void u_appPWM_updatePwmCh_suspend();
void u_appPwm_updatePwmFromPid_resume();
void u_appPwm_updatePwmFromPid_suspend();
void u_appPWM_Main();

#endif /* CORE_U_TASK_INC_U_APPPWM */
