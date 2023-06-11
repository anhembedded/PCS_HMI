#ifndef CORE_U_DRIVER_INC_U_PWM
#define CORE_U_DRIVER_INC_U_PWM
#include <stdint.h>

/*
PA1	TIM5_CH2/PWM	AnalogOut0	TIM5	APB1		AO_0
PA2	TIM5_CH3/PWM	AnalogOut1	TIM5	APB1		AO_1
*/


struct u_pwm_dutyCycle_type
{
    uint32_t u32_Channle0;
    uint32_t u32_Channle1;
};

extern struct u_pwm_dutyCycle_type u_pwm_dutyCycleValue;

void u_pwm_init();

void u_pwm_setPrescaler(uint16_t value);
void u_pwm_setDutyCycleCH2(uint32_t dutyCycle);
void u_pwm_setDutyCycleCH3(uint32_t dutyCycle);
void u_pwm_startCounter();
void u_pwm_stopCounter();

void u_pwm_setDutyCycleISR(struct u_pwm_dutyCycle_type var);

#endif /* CORE_U_DRIVER_INC_U_PWM */
