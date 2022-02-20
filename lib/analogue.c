/*
 * Part of old-school 8-bit transformer battery charger. ADC measurements here.
 *
 * Copyright 2022 Mikhail Belkin <dltech174@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "system.h"
#include "regs/adc_reg.h"
#include "charger.h"
#include "analogue.h"

extern volatile setValueTyp setValue;
volatile analogueTyp ana;

void analogueInit()
{
    portConfig(ADC_PORT, AMP_PIN | VOLT_PIN | RV1_PIN | RV2_PIN, INPUT_FLOAT);
    ADC1_CR1  = SPSEL_DIV4 | CONT;
    ADC1_CR2  = SCAN;
    ADC1_CSR  = EOCIE | CH_AIN6;
    // maximal priority for fast stabilization and short circuit protection
    setPriority(ADC1_ITN, 3);
    ADC1_CR1 |= ADON;
}

uint8_t getVolt(void)
{
    return (ana.volt*10) / ADC_TO_VOLT;
}

uint8_t getAmp(void)
{
    return (ana.amp*10) / ADC_TO_AMP;
}

uint16_t voltToAdc(uint8_t volt)
{
    return ((uint16_t)volt * ADC_TO_VOLT) / 10;
}

uint16_t ampToAdc(uint8_t amp)
{
    return ((uint16_t)amp * ADC_TO_AMP) / 10;
}

uint8_t getRv(uint8_t channel)
{
    uint16_t rv1 = (uint16_t)(ADC1_DBRH(channel) << 8) + ADC1_DBRL(channel);
    return (uint8_t) (rv1 / (uint16_t)ADC_PERCENT);
}

// interrupt on compliting the measurements
void adcComplete(void) __interrupt(ADC1_ITN)
{
    ana.amp += (uint16_t)(ADC1_DBRH(AMP_CH) << 8) + ADC1_DBRL(AMP_CH);
    ana.volt += (uint16_t)(ADC1_DBRH(VOLT_CH) << 8) + ADC1_DBRL(VOLT_CH);
    ana.amp /= 2;
    ana.volt /= 2;
    ana.rv1 = (ana.rv1 + getRv(RV1_CH)) / 2;
//    ana.rv2 = (ana.rv2 + getRv(RV1_CH)) / 2;
    regulator(setValue.amp, setValue.volt, ana.amp, ana.volt);
}
