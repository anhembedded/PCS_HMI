#include <u_rcc.h>








void u_rcc_enableClk_ADC1() {
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_ADC1EN);
}

void u_rcc_enableClk_GPIOA() {
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOAEN);
}

void u_rcc_enableClk_GPIOB() {
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOBEN);
}

void u_rcc_enableClk_GPIOC() {
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN);
}

void u_rcc_enableClk_GPIOD() {
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIODEN);
}

void u_rcc_enableClk_GPIOG()
{
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOGEN);
}

void u_rcc_enableClk_GPIOH()
{
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOHEN);
}

void u_rcc_enableClk_GPIOK()
{
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOKEN);
}

void u_rcc_enableClk_TIM5()
{
    SET_BIT(RCC->APB1ENR, RCC_APB1ENR_TIM5EN);
}

