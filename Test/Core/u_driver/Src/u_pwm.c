#include <u_firmwareDefination.h>
#include <u_gpio.h>
#include <u_pwm.h>
#include <u_rcc.h>
#include "SEGGER_SYSVIEW.h"

#define CH2_PIN AO_0_PIN
#define CH2_PORT AO_0_PORT

#define CH3_PIN AO_1_PIN
#define CH3_PORT AO_1_PORT

/*
PA1	TIM5_CH2/PWM	AnalogOut0	TIM5	APB1		AO_0
PA2	TIM5_CH3/PWM	AnalogOut1	TIM5	APB1		AO_1

TIM5:
    APB1::TIM::Clock = 90 MHz
    32 Bit resolution
    16 Bit prescaler
    Frequency determined by the value of the TIMx_ARR.
    Duty cycle determined by the value of theTIMx_CCRx.
    One PWM per OCxoutput.
    Enable the corresponding preload register.
    Enable the auto-reload preload register.
    The counter counts from 0 to the auto-reload value.

*/

#define CHOSING_PWM_MODE_MODE_1 0b110U
#define CHOSING_PWM_MODE_MODE_2 0b111U

struct u_pwm_dutyCycle_type u_pwm_dutyCycleValue;

static void u_pwm_enableAutoReloadPerload(void);
static void u_pwm_setUpdateSourceOnlyInterrupt();
static void u_pwm_timerUpdateInterruptEnable();
static void u_pwm_enableInterruptHandler(void);
static void u_pwm_chosingPwmModeCH2(uint32_t mode);
static void u_pwm_chosingPwmModeCH3(uint32_t mode);
static void u_pwm_enablePreloadOC2(void);
static void u_pwm_enablePreloadOC3(void);
static void u_pwm_initGPIO();
static void u_pwm_setAutoReload(uint32_t value);
static void u_pwm_enableOutputCH2();
static void u_pwm_enableOutputCH3();
static void u_pwm_updateGenerate();
static void u_pwm_clearUpdateFlag();

void u_pwm_setDutyCycleCH2(uint32_t dutyCycle)
{
    TIM5->CCR2 = dutyCycle;
}
void u_pwm_setDutyCycleCH3(uint32_t dutyCycle)
{
    TIM5->CCR3 = dutyCycle;
}

void u_pwm_startCounter()
{
    SET_BIT(TIM5->CR1, TIM_CR1_CEN);
}
void u_pwm_stopCounter()
{
    CLEAR_BIT(TIM5->CR1, TIM_CR1_CEN);
}
void u_pwm_setDutyCycleISR(struct u_pwm_dutyCycle_type var)
{
    u_pwm_setDutyCycleCH2(var.u32_Channle0);
    u_pwm_setDutyCycleCH3(var.u32_Channle1);
    u_pwm_clearUpdateFlag();
}
void u_pwm_setPrescaler(uint16_t value)
{
    WRITE_REG(TIM5->PSC, value);
}

void u_pwm_init()
{
    u_rcc_enableClk_TIM5();
    u_pwm_enableAutoReloadPerload();
    /* Direction: Counter used as upcounter */
    /* One-pulse mode: Counter is not stopped at update event */
    /* Update request source:
        - Counter overflow/underflow
        – Setting the UG bit
        – Update generation through the slave mode controller
    */
    /*
    CC2, CC3  channel is configured as output
    */
    u_pwm_setUpdateSourceOnlyInterrupt();
    u_pwm_timerUpdateInterruptEnable();
    u_pwm_chosingPwmModeCH2(CHOSING_PWM_MODE_MODE_1);
    u_pwm_chosingPwmModeCH3(CHOSING_PWM_MODE_MODE_1);
    u_pwm_enablePreloadOC2();
    u_pwm_enablePreloadOC3();
    u_pwm_enableOutputCH3();
    u_pwm_enableOutputCH2();
    u_pwm_enableInterruptHandler();
    u_pwm_setPrescaler(0);
    u_pwm_setAutoReload(0xffff);
    u_pwm_setDutyCycleCH2(0x6fff);
    u_pwm_setDutyCycleCH3(0x7fff);
    u_pwm_updateGenerate();
    u_pwm_initGPIO();

    u_pwm_startCounter();
}

static void u_pwm_enableAutoReloadPerload(void)
{
    SET_BIT(TIM5->CR1, TIM_CR1_ARPE);
}
static void u_pwm_setUpdateSourceOnlyInterrupt()
{
    SET_BIT(TIM5->CR1, TIM_CR1_URS);
}
static void u_pwm_timerUpdateInterruptEnable()
{
    SET_BIT(TIM5->DIER, TIM_DIER_UIE);
}
static void u_pwm_enableInterruptHandler(void)
{
    NVIC_SetPriority(TIM5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 5, 0));
    __NVIC_EnableIRQ(TIM5_IRQn);
}
static void u_pwm_chosingPwmModeCH2(uint32_t mode)
{
    uint32_t modeBitMask;
    modeBitMask = mode << TIM_CCMR1_OC2M_Pos;
    SET_BIT(TIM5->CCMR1, modeBitMask);
}
static void u_pwm_chosingPwmModeCH3(uint32_t mode)
{
    uint32_t modeBitMask;
    modeBitMask = mode << TIM_CCMR2_OC3M_Pos;
    SET_BIT(TIM5->CCMR2, modeBitMask);
}
static void u_pwm_enablePreloadOC2(void)
{
    SET_BIT(TIM5->CCMR1, TIM_CCMR1_OC2PE);
}
static void u_pwm_enablePreloadOC3(void)
{
    SET_BIT(TIM5->CCMR2, TIM_CCMR2_OC3PE);
}

static void u_pwm_initGPIO()
{
    u_rcc_enableClk_GPIOA();

    u_gpio_setPinMode(CH2_PORT, CH2_PIN, SET_PIN_MODE_ALTERNATE_FUNCTION_MODE);
    u_gpio_setPinMode(CH3_PORT, CH3_PIN, SET_PIN_MODE_ALTERNATE_FUNCTION_MODE);

    u_gpio_setAlternateFunction(CH2_PORT, CH2_PIN, SET_ALTERNATE_FUNCTION_PORTA_PIN_1_TIM5_CH2);
    u_gpio_setAlternateFunction(CH3_PORT, CH3_PIN, SET_ALTERNATE_FUNCTION_PORTA_PIN_2_TIM5_CH3);
}
static void u_pwm_setAutoReload(uint32_t value)
{
    TIM5->ARR = value;
}
static void u_pwm_enableOutputCH2()
{
    SET_BIT(TIM5->CCER, TIM_CCER_CC2E);
}
static void u_pwm_enableOutputCH3()
{
    SET_BIT(TIM5->CCER, TIM_CCER_CC3E);
}

static void u_pwm_updateGenerate()
{
    SET_BIT(TIM5->EGR, TIM_EGR_UG);
}
static void u_pwm_clearUpdateFlag()
{
    CLEAR_BIT(TIM5->SR, TIM_SR_UIF);
}

void TIM5_IRQHandler()
{
	 SEGGER_SYSVIEW_RecordEnterISR();
    u_pwm_setDutyCycleISR(u_pwm_dutyCycleValue);
    __NVIC_ClearPendingIRQ(TIM5_IRQn);
    SEGGER_SYSVIEW_RecordExitISR();
}
