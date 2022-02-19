#ifndef H_ANALOGUE
#define H_ANALOGUE
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

#include "gpio.h"

#define MAX_ADC     1024
#define ADC_PERCENT 102
#define ADC_TO_VOLT 28
#define ADC_TO_AMP  31

#define ADC_PORT    GPIOD
#define AMP_PIN     GPIO2
#define VOLT_PIN    GPIO3
#define RV1_PIN     GPIO5
#define RV2_PIN     GPIO6

#define AMP_CH      3
#define VOLT_CH     4
#define RV1_CH      5
#define RV2_CH      6

// initialization
void analogueInit(void);
// getters of measured values, data formats are:
// voltage in volts multiplied by 10
uint8_t getVolt(void);
// current in amperes *10
uint8_t getAmp(void);
// potemtiometer is in 0-100% boundaries
uint8_t getRv(uint8_t channel);

// measurements translating functions
uint16_t voltToAdc(uint8_t volt);
uint16_t ampToAdc(uint8_t amp);


#endif
