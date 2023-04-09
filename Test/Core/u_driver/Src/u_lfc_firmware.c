#include "u_lfc_firmware.h"

uint32_t left_inputSensor = 0;
uint32_t right_inputSensor = 0;

static uint32_t readLeftSensorPos0();
static uint32_t readLeftSensorPos1();
static uint32_t readLeftSensorPos2();
static uint32_t readLeftSensorPos3();
static uint32_t readLeftSensorPos4();

static uint32_t readRightSensorPos0();
static uint32_t readRightSensorPos1();
static uint32_t readRightSensorPos2();
static uint32_t readRightSensorPos3();
static uint32_t readRightSensorPos4();
void U_LFC_GPIO_Init(void)
{

    LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOG);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOD);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOH);
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);

    /**/
    LL_GPIO_ResetOutputPin(OUT_R_GPIO_Port, OUT_R_Pin);

    /**/
    LL_GPIO_ResetOutputPin(OUT_L_GPIO_Port, OUT_L_Pin);

    /**/
    GPIO_InitStruct.Pin = IN_L_1_Pin | IN_L_2_Pin | IN_R_0_Pin | IN_L_3_Pin | IN_R_1_Pin | IN_L_0_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOG, &GPIO_InitStruct);

    /**/
    GPIO_InitStruct.Pin = OUT_R_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(OUT_R_GPIO_Port, &GPIO_InitStruct);

    /**/
    GPIO_InitStruct.Pin = LL_GPIO_PIN_13;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /**/
    GPIO_InitStruct.Pin = IN_L_4_Pin | IN_R_2_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /**/
    GPIO_InitStruct.Pin = IN_R_3_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(IN_R_3_GPIO_Port, &GPIO_InitStruct);

    /**/
    GPIO_InitStruct.Pin = OUT_L_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
    GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(OUT_L_GPIO_Port, &GPIO_InitStruct);

    /**/
    GPIO_InitStruct.Pin = LL_GPIO_PIN_14 | IN_R_4_Pin;
    GPIO_InitStruct.Mode = LL_GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
    LL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

uint32_t readLeftSensorPos0()
{
    return !u_gpio_readPin(IN_L_0_GPIO_Port, IN_L_0_Pin);
}
uint32_t readLeftSensorPos1()
{
    return u_gpio_readPin(IN_L_1_GPIO_Port, IN_L_1_Pin);
}
uint32_t readLeftSensorPos2()
{
    return u_gpio_readPin(IN_L_2_GPIO_Port, IN_L_2_Pin);
}
uint32_t readLeftSensorPos3()
{
    return u_gpio_readPin(IN_L_3_GPIO_Port, IN_L_3_Pin);
}
uint32_t readLeftSensorPos4()
{
    return u_gpio_readPin(IN_L_4_GPIO_Port, IN_L_4_Pin);
}

uint32_t readRightSensorPos0()
{
    return !u_gpio_readPin(IN_R_0_GPIO_Port, IN_R_0_Pin);
}
uint32_t readRightSensorPos1()
{
    return u_gpio_readPin(IN_R_1_GPIO_Port, IN_R_1_Pin);
}
uint32_t readRightSensorPos2()
{
    return u_gpio_readPin(IN_R_2_GPIO_Port, IN_R_2_Pin);
}
uint32_t readRightSensorPos3()
{
    return u_gpio_readPin(IN_R_3_GPIO_Port, IN_R_3_Pin);
}
uint32_t readRightSensorPos4()
{
    return u_gpio_readPin(IN_R_4_GPIO_Port, IN_R_4_Pin);
}

uint32_t updateLeftSensor()
{
    uint32_t sensorsOutput = 0L;
    sensorsOutput = sensorsOutput | ((readLeftSensorPos0() << 0));
    sensorsOutput = sensorsOutput | ((readLeftSensorPos1() << 1));
    sensorsOutput = sensorsOutput | ((readLeftSensorPos2() << 2));
    sensorsOutput = sensorsOutput | ((readLeftSensorPos3() << 3));
    sensorsOutput = sensorsOutput | ((readLeftSensorPos4() << 4));
    return sensorsOutput;
}

uint32_t updateRightSensor()
{
    uint32_t sensorsOutput = 0L;
    sensorsOutput = sensorsOutput | ((readRightSensorPos0() << 0));
    sensorsOutput = sensorsOutput | ((readRightSensorPos1() << 1));
    sensorsOutput = sensorsOutput | ((readRightSensorPos2() << 2));
    sensorsOutput = sensorsOutput | ((readRightSensorPos3() << 3));
    sensorsOutput = sensorsOutput | ((readRightSensorPos4() << 4));
    return sensorsOutput;
}