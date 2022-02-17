
#include "system.h"
#include "regs/adc_reg.h"

void analogueInit()
{
    portConfig(ADC_PORT, AMP_PIN | VOLT_PIN | RV1_PIN | RV2_PIN, INPUT_FLOAT);
    ADC1_CR1  = SPSEL_DIV2 | CONT;
    ADC1_CR2  = SCAN;
    ADC1_CSR  = EOCIE | CH_AIN6;
    ADC1_CR1 |= ADON;
}

void adcComplete(void) __interrupt(ADC1_ITN)
{
    uint16_t rv1 = (uint16_t)(ADC1_DB5RH << 8) + ADC1_DB5RL;
    uint16_t rv2 = (uint16_t)(ADC1_DB6RH << 8) + ADC1_DB6RL;
    uint16_t volt = (uint16_t)(ADC1_DBRH(VOLT_CH) << 8) + ADC1_DB4RL;
    uint16_t amp  = (uint16_t)(ADC1_DB3RH << 8) + ADC1_DB3RL;
}
