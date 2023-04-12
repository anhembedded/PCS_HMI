//
// Created by hoang on 3/24/2023.
//

#ifndef CORE_U_DRIVER_INC_U_GPIO
#define CORE_U_DRIVER_INC_U_GPIO

#include "stm32f4xx.h"
#include <stdint.h>

/*
LED1 PG6 Non GPIOG Green
LED2 PD4 Non GPIOD Orange
LED3 PD5 Non GPIOD Red
LED4 PK3 Non GPIOK Blue
*/

#define SET_PIN_MODE_OUTPUT_MODE 0b01U
#define SET_PIN_MODE_ALTERNATE_FUNCTION_MODE 0b10U

#define U_GPIO_SET_PIN_MODE_INPUT_MODE 0b00U
#define SET_ALTERNATE_FUNCTION_PORTA_PIN_1_TIM5_CH2 2U
#define SET_ALTERNATE_FUNCTION_PORTA_PIN_2_TIM5_CH3 2U

#define SET_PIN_PULL_NO_PULL 0b00U
#define SET_PIN_PULL_PULLUP 0b01U
#define SET_PIN_PULL_PULLDOWN 0b10U

#define LED_GREEN_PORT GPIOG
#define LED_ORANGE_PORT GPIOD
#define LED_RED_PORT GPIOD
#define LED_BLUE_PORT GPIOK

#define LED_GREEN_PIN 6U
#define LED_ORANGE_PIN 4U
#define LED_RED_PIN 5U
#define LED_BLUE_PIN 3U

void u_gpio_setPinMode(GPIO_TypeDef *gpioParam, uint8_t gpioPin, uint32_t mode);
void u_gpio_setPinOutputType(GPIO_TypeDef *gpioParam, uint8_t gpioPin, uint32_t outputType);
void u_gpio_setPinOutputSpeed(GPIO_TypeDef *gpioParam, uint8_t gpioPin, uint32_t speed);
void u_gpio_setPinPull(GPIO_TypeDef *gpioParam, uint8_t gpioPin, uint32_t pullType);
void u_gpio_setAlternateFunction(GPIO_TypeDef *gpioParam, uint8_t gpioPin, uint32_t al);

void u_gpio_outputSet(GPIO_TypeDef *gpioParam, uint8_t gpioPin);
void u_gpio_outputClear(GPIO_TypeDef *gpioParam, uint8_t gpioPin);
void u_gpio_writePin(GPIO_TypeDef *gpioParam, uint8_t gpioPin, uint32_t PinState);
uint32_t u_gpio_readPin(GPIO_TypeDef *gpioParam, uint8_t gpioPin);
void u_gpio_togglePin(GPIO_TypeDef *gpioParam, uint8_t gpioPin);

void u_gpio_OnboardInit_LED();
void u_gpio_Init_DigitalOutput();
void u_gpio_Init_DigitalInput();
void u_gpio_Init_externalInterrupt();

void digitalInputChangedHandler_0();
void digitalInputChangedHandler_1();
void digitalInputChangedHandler_2();
void digitalInputChangedHandler_3();
void digitalInputChangedHandler_4();
void digitalInputChangedHandler_5();
void digitalInputChangedHandler_6();

#endif /* CORE_U_DRIVER_INC_U_GPIO */
