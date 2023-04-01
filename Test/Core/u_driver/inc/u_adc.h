#ifndef CORE_U_DRIVER_INC_U_ADC
#define CORE_U_DRIVER_INC_U_ADC
#include <stm32f4xx_ll_adc.h>
#include <u_firmwareDefination.h>

/*
ARD_A0	PB1	ADC12_IN9	AnalogIn0	ADC1	APB2		AI_0
ARD_A1	PC2	ADC12_IN12	AnalogIn1	ADC1	APB2		AI_1
ARD_A2	PC3	ADC12_IN13	AnalogIn2	ADC1	APB2		AI_2
ARD_A3	PC4	ADC12_IN14	AnalogIn3	ADC1	APB2		AI_3
    ADC1:
        Single conversion mode
        The ADC needs a stabilization time of tSTAB before it starts
converting accurately.

*/

void u_adc_Init(void);
void u_adc_initSingleConversion(void);


void u_adc_startConvention();
void u_adc_stopConvention();
void u_adc_isRunningConvention();



#endif /* CORE_U_DRIVER_INC_U_ADC */
