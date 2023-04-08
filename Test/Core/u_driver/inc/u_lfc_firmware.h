#ifndef CORE_U_DRIVER_INC_U_LFC_FIRMWARE
#define CORE_U_DRIVER_INC_U_LFC_FIRMWARE
#include "stm32f4xx.h"
#include <stdint.h>
#include "stm32f4xx_ll_system.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"
#include "u_gpio.h"

#define IN_L_1_Pin LL_GPIO_PIN_14
#define IN_L_1_GPIO_Port GPIOG
#define IN_L_2_Pin LL_GPIO_PIN_13
#define IN_L_2_GPIO_Port GPIOG
#define IN_R_0_Pin LL_GPIO_PIN_11
#define IN_R_0_GPIO_Port GPIOG
#define IN_L_3_Pin LL_GPIO_PIN_12
#define IN_L_3_GPIO_Port GPIOG
#define IN_R_1_Pin LL_GPIO_PIN_10
#define IN_R_1_GPIO_Port GPIOG
#define IN_L_0_Pin LL_GPIO_PIN_9
#define IN_L_0_GPIO_Port GPIOG
#define OUT_R_Pin LL_GPIO_PIN_2
#define OUT_R_GPIO_Port GPIOC
#define IN_L_4_Pin LL_GPIO_PIN_6
#define IN_L_4_GPIO_Port GPIOA
#define IN_R_3_Pin LL_GPIO_PIN_6
#define IN_R_3_GPIO_Port GPIOH
#define IN_R_2_Pin LL_GPIO_PIN_7
#define IN_R_2_GPIO_Port GPIOA
#define OUT_L_Pin LL_GPIO_PIN_1
#define OUT_L_GPIO_Port GPIOB
#define IN_R_4_Pin LL_GPIO_PIN_15
#define IN_R_4_GPIO_Port GPIOB

extern uint32_t left_inputSensor;
extern uint32_t right_inputSensor;

uint32_t updateLeftSensor();
uint32_t updateRightSensor();
void U_LFC_GPIO_Init(void);

#endif /* CORE_U_DRIVER_INC_U_LFC_FIRMWARE */
