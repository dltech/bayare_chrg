#ifndef H_ADC_REG
#define H_ADC_REG
/*
 * Part of old-school 8-bit transformer battery charger. STM8 ADC register
 * definitions.
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

#include "memorymap.h"

#define ADC1_DB0RH  MMIO32(ADC1_BASE + 0x00)
#define ADC1_DB0RL  MMIO32(ADC1_BASE + 0x00)
#define ADC1_DB7RH  MMIO32(ADC1_BASE + 0x0e)
#define ADC1_DB7RL  MMIO32(ADC1_BASE + 0x0f)




//
#define
//
#define
