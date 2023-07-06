#ifndef CORE_U_DRIVER_INC_U_FIRMWAREDEFINATION
#define CORE_U_DRIVER_INC_U_FIRMWAREDEFINATION

#include "stm32f4xx.h"

#define AI_0_PIN 1
#define AI_1_PIN 2
#define AI_2_PIN 3
#define AI_3_PIN 4
#define DO_0_PIN 5
#define DO_1_PIN 4
#define DO_2_PIN 9
#define DO_3_PIN 14
#define DO_4_PIN 13
#define AO_0_PIN 1

#define AO_1_PIN 2
#define DI_0_PIN 6
#define DI_1_PIN 11
#define DI_2_PIN 10
#define DI_3_PIN 7
#define DI_4_PIN 6
#define DI_5_PIN 15

#define AI_0_PORT GPIOB
#define AI_1_PORT GPIOC
#define AI_2_PORT GPIOC
#define AI_3_PORT GPIOC
#define DO_0_PORT GPIOC
#define DO_1_PORT GPIOA
#define DO_2_PORT GPIOG
#define DO_3_PORT GPIOG
#define DO_4_PORT GPIOG
#define AO_0_PORT GPIOA

#define AO_1_PORT GPIOA
#define DI_0_PORT GPIOA
#define DI_1_PORT GPIOG
#define DI_2_PORT GPIOG
#define DI_3_PORT GPIOA
#define DI_4_PORT GPIOH
#define DI_5_PORT GPIOB

#define DigitalInput0_Pin LL_GPIO_PIN_11
#define DigitalInput0_GPIO_Port GPIOG
#define DigitalInput0_EXTI_IRQn EXTI15_10_IRQn

#define DigitalInput1_Pin LL_GPIO_PIN_10
#define DigitalInput1_GPIO_Port GPIOG
#define DigitalInput1_EXTI_IRQn EXTI15_10_IRQn

#define DigitalInput2_Pin LL_GPIO_PIN_7
#define DigitalInput2_GPIO_Port GPIOA
#define DigitalInput2_EXTI_IRQn EXTI9_5_IRQn

#define DigitalInput3_Pin LL_GPIO_PIN_6
#define DigitalInput3_GPIO_Port GPIOH
#define DigitalInput3_EXTI_IRQn EXTI9_5_IRQn

#define DigitalInput4_Pin LL_GPIO_PIN_15
#define DigitalInput4_GPIO_Port GPIOB
#define DigitalInput4_EXTI_IRQn EXTI15_10_IRQn

#define DigitalInput5_Pin LL_GPIO_PIN_14
#define DigitalInput5_GPIO_Port GPIOB
#define DigitalInput5_EXTI_IRQn EXTI15_10_IRQn

#define DigitalInput6_Pin LL_GPIO_PIN_3
#define DigitalInput6_GPIO_Port GPIOD
#define DigitalInput6_EXTI_IRQn EXTI3_IRQn

#endif /* CORE_U_DRIVER_INC_U_FIRMWAREDEFINATION */
