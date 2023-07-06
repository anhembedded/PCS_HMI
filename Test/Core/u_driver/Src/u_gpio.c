//
// Created by hoang on 3/24/2023.
//

#include "stm32f4xx.h"
#include "stm32f4xx_ll_bus.h"
#include "stm32f4xx_ll_exti.h"
#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_system.h"
#include "u_appMain.h"
#include <u_firmwareDefination.h>
#include <u_gpio.h>
#include <u_pwm.h>
#include <u_rcc.h>
#include "SEGGER_SYSVIEW.h"

/*
LED1 PG6 Non GPIOG Green
LED2 PD4 Non GPIOD Orange
LED3 PD5 Non GPIOD Red
LED4 PK3 Non GPIOK Blue
*/

void u_gpio_setPinMode(GPIO_TypeDef *gpioParam, uint8_t gpioPin,
                       uint32_t mode) {
  const uint8_t l_moderRegFactor = 2;
  uint32_t modeBitMask;
  uint32_t clearMask;
  clearMask = 0b11 << (gpioPin * l_moderRegFactor);
  modeBitMask = mode << (gpioPin * l_moderRegFactor);
  MODIFY_REG(gpioParam->MODER, clearMask, modeBitMask);
}

void u_gpio_setPinOutputType(GPIO_TypeDef *gpioParam, uint8_t gpioPin,
                             uint32_t outputType) {
  const uint8_t l_moderRegoutputType = 1;
  SET_BIT(gpioParam->OTYPER, (outputType << (gpioPin * l_moderRegoutputType)));
}

void u_gpio_setPinOutputSpeed(GPIO_TypeDef *gpioParam, uint8_t gpioPin,
                              uint32_t speed) {
  const uint8_t l_moderRegSpeed = 2;
  SET_BIT(gpioParam->OSPEEDR, (speed << (gpioPin * l_moderRegSpeed)));
}
void u_gpio_setPinPull(GPIO_TypeDef *gpioParam, uint8_t gpioPin,
                       uint32_t pullType) {
  const uint8_t l_moderRegPullType = 2;
  SET_BIT(gpioParam->PUPDR, (pullType << (gpioPin * l_moderRegPullType)));
}

void u_gpio_setAlternateFunction(GPIO_TypeDef *gpioParam, uint8_t gpioPin,
                                 uint32_t al) {
  __IO uint32_t *afRegister = NULL;
  uint32_t alBitMask;

  if (gpioPin <= 7) {
    afRegister = &gpioParam->AFR[0];
    alBitMask = al << (gpioPin * 4U);
    SET_BIT(*afRegister, alBitMask);
  } else {
    uint8_t gpioPinOffset = gpioPin - 8;
    afRegister = &gpioParam->AFR[1];
    alBitMask = al << (gpioPinOffset * 4U);
    SET_BIT(*afRegister, alBitMask);
  }
}

void u_gpio_outputSet(GPIO_TypeDef *gpioParam, uint8_t gpioPin) {
  uint32_t pinMask;
  pinMask = 0x01 << gpioPin;
  gpioParam->BSRR = pinMask;
}
void u_gpio_outputClear(GPIO_TypeDef *gpioParam, uint8_t gpioPin) {
  uint32_t pinMask;
  pinMask = 0x01 << gpioPin;
  gpioParam->BSRR = (uint32_t)pinMask << 16U;
}
void u_gpio_writePin(GPIO_TypeDef *gpioParam, uint8_t gpioPin,
                     uint32_t PinState) {
  uint32_t pinMask;
  pinMask = 0x01UL << gpioPin;
  if (PinState != GPIO_PIN_RESET) {
    gpioParam->BSRR = pinMask;
  } else {
    gpioParam->BSRR = (uint32_t)pinMask << 16U;
  }
}

uint32_t u_gpio_readPin(GPIO_TypeDef *gpioParam, uint8_t gpioPin) {
  uint32_t pinMask = 0x01UL << gpioPin;
  return (READ_BIT(gpioParam->IDR, pinMask) == (pinMask));
}

void u_gpio_togglePin(GPIO_TypeDef *gpioParam, uint8_t gpioPin) {
  uint32_t PinMask = 1 << gpioPin;
  uint32_t odr = READ_REG(gpioParam->ODR);
  WRITE_REG(gpioParam->BSRR, ((odr & PinMask) << 16u) | (~odr & PinMask));
}

void u_gpio_OnboardInit_LED() {
  /*
  LED1 PG6 Non GPIOG Green
  LED2 PD4 Non GPIOD Orange
  LED3 PD5 Non GPIOD Red
  LED4 PK3 Non GPIOK Blue
  */
  u_rcc_enableClk_GPIOG();
  u_rcc_enableClk_GPIOD();
  u_rcc_enableClk_GPIOK();

  u_gpio_setPinMode(LED_GREEN_PORT, LED_GREEN_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(LED_RED_PORT, LED_RED_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(LED_ORANGE_PORT, LED_ORANGE_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(LED_BLUE_PORT, LED_BLUE_PIN, SET_PIN_MODE_OUTPUT_MODE);

  /* Output push-pull (reset state) */
  /* Output speed low(reset state) */
  /* Output No pull-up, pull-down(reset state) */

  /*
  u_rcc_enableClk_GPIOA();
  u_gpio_setPinMode(AO_0_PORT, 	AO_0_PIN, 	SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(AO_1_PORT, 	AO_1_PIN, 	SET_PIN_MODE_OUTPUT_MODE);
  */
}

void u_gpio_Init_DigitalOutput() {
  /*
  GPIOC AHB1 DO_0
  GPIOA AHB1 DO_1
  GPIOG AHB1 DO_2
  */
  u_rcc_enableClk_GPIOC();
  u_rcc_enableClk_GPIOA();
  u_rcc_enableClk_GPIOG();

  u_gpio_setPinMode(DO_0_PORT, DO_0_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(DO_1_PORT, DO_1_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(DO_2_PORT, DO_2_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(DO_3_PORT, DO_3_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(DO_4_PORT, DO_4_PIN, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(GPIOA, 6, SET_PIN_MODE_OUTPUT_MODE);
  u_gpio_setPinMode(GPIOG, 12, SET_PIN_MODE_OUTPUT_MODE);
  /* Output push-pull (reset state) */
  /* Output speed low(reset state) */
  /* Output No pull-up, pull-down(reset state) */
   u_gpio_writePin(GPIOA, 6, 1);
   u_gpio_writePin(GPIOG, 12, 0);
}

/*
ARD_D6 	PA6 	DigitalInput0 GPIOA AHB1 DI_0
ARD_D7 	PG11 	DigitalInput1 GPIOG AHB1 DI_1
ARD_D8 	PG10 	DigitalInput2 GPIOG AHB1 DI_2
ARD_D9 	PA7 	DigitalInput3 GPIOA AHB1 DI_3
ARD_D10 PH6 	DigitalInput4 GPIOH AHB1 DI_4
ARD_D11 PB15 	DigitalInput5 GPIOB AHB1 DI_5
*/

void u_gpio_Init_DigitalInput() {
  u_rcc_enableClk_GPIOA();
  u_rcc_enableClk_GPIOG();
  u_rcc_enableClk_GPIOH();
  u_rcc_enableClk_GPIOB();

  u_gpio_setPinMode(DI_0_PORT, DI_0_PIN, U_GPIO_SET_PIN_MODE_INPUT_MODE);
  u_gpio_setPinMode(DI_1_PORT, DI_1_PIN, U_GPIO_SET_PIN_MODE_INPUT_MODE);
  u_gpio_setPinMode(DI_2_PORT, DI_2_PIN, U_GPIO_SET_PIN_MODE_INPUT_MODE);
  u_gpio_setPinMode(DI_3_PORT, DI_3_PIN, U_GPIO_SET_PIN_MODE_INPUT_MODE);
  u_gpio_setPinMode(DI_4_PORT, DI_4_PIN, U_GPIO_SET_PIN_MODE_INPUT_MODE);
  u_gpio_setPinMode(DI_5_PORT, DI_5_PIN, U_GPIO_SET_PIN_MODE_INPUT_MODE);

  u_gpio_setPinPull(DI_0_PORT, DI_0_PIN, SET_PIN_PULL_NO_PULL);
  u_gpio_setPinPull(DI_1_PORT, DI_1_PIN, SET_PIN_PULL_NO_PULL);
  u_gpio_setPinPull(DI_2_PORT, DI_2_PIN, SET_PIN_PULL_NO_PULL);
  u_gpio_setPinPull(DI_3_PORT, DI_3_PIN, SET_PIN_PULL_NO_PULL);
  u_gpio_setPinPull(DI_4_PORT, DI_4_PIN, SET_PIN_PULL_NO_PULL);
  u_gpio_setPinPull(DI_5_PORT, DI_5_PIN, SET_PIN_PULL_NO_PULL);
}
void u_gpio_Init_externalInterrupt() {

  LL_EXTI_InitTypeDef EXTI_InitStruct = {0};

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOI);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOF);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOK);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOJ);
  /**/
  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTG, LL_SYSCFG_EXTI_LINE11);

  /**/
  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTG, LL_SYSCFG_EXTI_LINE10);

  /**/
  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTD, LL_SYSCFG_EXTI_LINE3);

  /**/
  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTH, LL_SYSCFG_EXTI_LINE6);

  /**/
  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTA, LL_SYSCFG_EXTI_LINE7);

  /**/
  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTB, LL_SYSCFG_EXTI_LINE14);

  /**/
  LL_SYSCFG_SetEXTISource(LL_SYSCFG_EXTI_PORTB, LL_SYSCFG_EXTI_LINE15);

  /**/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_11;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /**/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_10;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /**/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_3;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /**/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_6;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /**/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_7;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /**/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_14;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /**/
  EXTI_InitStruct.Line_0_31 = LL_EXTI_LINE_15;
  EXTI_InitStruct.LineCommand = ENABLE;
  EXTI_InitStruct.Mode = LL_EXTI_MODE_IT;
  EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_RISING_FALLING;
  LL_EXTI_Init(&EXTI_InitStruct);

  /**/
  LL_GPIO_SetPinPull(DigitalInput0_GPIO_Port, DigitalInput0_Pin,
                     LL_GPIO_PULL_DOWN);

  /**/
  LL_GPIO_SetPinPull(DigitalInput1_GPIO_Port, DigitalInput1_Pin,
                     LL_GPIO_PULL_DOWN);

  /**/
  LL_GPIO_SetPinPull(DigitalInput6_GPIO_Port, DigitalInput6_Pin,
                     LL_GPIO_PULL_DOWN);

  /**/
  LL_GPIO_SetPinPull(DigitalInput3_GPIO_Port, DigitalInput3_Pin,
                     LL_GPIO_PULL_DOWN);

  /**/
  LL_GPIO_SetPinPull(DigitalInput2_GPIO_Port, DigitalInput2_Pin,
                     LL_GPIO_PULL_DOWN);

  /**/
  LL_GPIO_SetPinPull(DigitalInput5_GPIO_Port, DigitalInput5_Pin,
                     LL_GPIO_PULL_DOWN);

  /**/
  LL_GPIO_SetPinPull(DigitalInput4_GPIO_Port, DigitalInput4_Pin,
                     LL_GPIO_PULL_DOWN);

  /**/
  LL_GPIO_SetPinMode(DigitalInput0_GPIO_Port, DigitalInput0_Pin,
                     LL_GPIO_MODE_INPUT);

  /**/
  LL_GPIO_SetPinMode(DigitalInput1_GPIO_Port, DigitalInput1_Pin,
                     LL_GPIO_MODE_INPUT);

  /**/
  LL_GPIO_SetPinMode(DigitalInput6_GPIO_Port, DigitalInput6_Pin,
                     LL_GPIO_MODE_INPUT);

  /**/
  LL_GPIO_SetPinMode(DigitalInput3_GPIO_Port, DigitalInput3_Pin,
                     LL_GPIO_MODE_INPUT);

  /**/
  LL_GPIO_SetPinMode(DigitalInput2_GPIO_Port, DigitalInput2_Pin,
                     LL_GPIO_MODE_INPUT);

  /**/
  LL_GPIO_SetPinMode(DigitalInput5_GPIO_Port, DigitalInput5_Pin,
                     LL_GPIO_MODE_INPUT);

  /**/
  LL_GPIO_SetPinMode(DigitalInput4_GPIO_Port, DigitalInput4_Pin,
                     LL_GPIO_MODE_INPUT);

  /* EXTI interrupt init*/
  NVIC_SetPriority(EXTI3_IRQn,
                   NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 5, 0));
  NVIC_EnableIRQ(EXTI3_IRQn);
  NVIC_SetPriority(EXTI9_5_IRQn,
                   NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 5, 0));
  NVIC_EnableIRQ(EXTI9_5_IRQn);
  NVIC_SetPriority(EXTI15_10_IRQn,
                   NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 5, 0));
  NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void digitalInputChangedHandler_0() {
  uint32_t inputPort = LL_GPIO_ReadInputPort(DigitalInput0_GPIO_Port);
  u32_applicationInputState[0] = READ_BIT(inputPort, (DigitalInput0_Pin));
}
void digitalInputChangedHandler_1() {
  uint32_t inputPort = LL_GPIO_ReadInputPort(DigitalInput1_GPIO_Port);
  u32_applicationInputState[1] = READ_BIT(inputPort, (DigitalInput1_Pin));
}
void digitalInputChangedHandler_2() {
  uint32_t inputPort = LL_GPIO_ReadInputPort(DigitalInput2_GPIO_Port);
  u32_applicationInputState[2] = READ_BIT(inputPort, (DigitalInput2_Pin));
}
void digitalInputChangedHandler_3() {
  uint32_t inputPort = LL_GPIO_ReadInputPort(DigitalInput3_GPIO_Port);
  u32_applicationInputState[3] = READ_BIT(inputPort, (DigitalInput3_Pin));
}
void digitalInputChangedHandler_4() {
  uint32_t inputPort = LL_GPIO_ReadInputPort(DigitalInput4_GPIO_Port);
  u32_applicationInputState[4] = READ_BIT(inputPort, (DigitalInput4_Pin));
}
void digitalInputChangedHandler_5() {
  uint32_t inputPort = LL_GPIO_ReadInputPort(DigitalInput5_GPIO_Port);
  u32_applicationInputState[5] = READ_BIT(inputPort, (DigitalInput5_Pin));
}
void digitalInputChangedHandler_6() {
  uint32_t inputPort = LL_GPIO_ReadInputPort(DigitalInput6_GPIO_Port);
  u32_applicationInputState[6] = READ_BIT(inputPort, (DigitalInput6_Pin));
}

/**
 * @brief This function handles EXTI line[9:5] interrupts.
 */
void EXTI9_5_IRQHandler(void) {
  /* USER CODE BEGIN EXTI9_5_IRQn 0 */
   SEGGER_SYSVIEW_RecordEnterISR();
  /* USER CODE END EXTI9_5_IRQn 0 */

  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_6) != RESET) {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_6);
    /* USER CODE BEGIN LL_EXTI_LINE_6 */

    digitalInputChangedHandler_3();
    /* USER CODE END LL_EXTI_LINE_6 */
  }
  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_7) != RESET) {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_7);
    /* USER CODE BEGIN LL_EXTI_LINE_7 */
    digitalInputChangedHandler_2();

    /* USER CODE END LL_EXTI_LINE_7 */
  }
  /* USER CODE BEGIN EXTI9_5_IRQn 1 */
SEGGER_SYSVIEW_RecordExitISR();
  /* USER CODE END EXTI9_5_IRQn 1 */
}

/**
 * @brief This function handles EXTI line[15:10] interrupts.
 */
void EXTI15_10_IRQHandler(void) {
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */
   SEGGER_SYSVIEW_RecordEnterISR();
  /* USER CODE END EXTI15_10_IRQn 0 */
  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_10) != RESET) {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_10);
    /* USER CODE BEGIN LL_EXTI_LINE_10 */

    digitalInputChangedHandler_1();
    /* USER CODE END LL_EXTI_LINE_10 */
  }
  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_11) != RESET) {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_11);
    /* USER CODE BEGIN LL_EXTI_LINE_11 */
    digitalInputChangedHandler_0();

    /* USER CODE END LL_EXTI_LINE_11 */
  }
  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_14) != RESET) {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_14);
    /* USER CODE BEGIN LL_EXTI_LINE_14 */

    digitalInputChangedHandler_5();
    /* USER CODE END LL_EXTI_LINE_14 */
  }
  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_15) != RESET) {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_15);
    /* USER CODE BEGIN LL_EXTI_LINE_15 */
    digitalInputChangedHandler_4();

    /* USER CODE END LL_EXTI_LINE_15 */
  }
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */
SEGGER_SYSVIEW_RecordExitISR();
  /* USER CODE END EXTI15_10_IRQn 1 */
}

void EXTI3_IRQHandler(void) {
  /* USER CODE BEGIN EXTI3_IRQn 0 */
   SEGGER_SYSVIEW_RecordEnterISR();
  /* USER CODE END EXTI3_IRQn 0 */
  if (LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_3) != RESET) {
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_3);
    /* USER CODE BEGIN LL_EXTI_LINE_3 */
    digitalInputChangedHandler_6();

    /* USER CODE END LL_EXTI_LINE_3 */
  }
  /* USER CODE BEGIN EXTI3_IRQn 1 */
SEGGER_SYSVIEW_RecordExitISR();
  /* USER CODE END EXTI3_IRQn 1 */
}
