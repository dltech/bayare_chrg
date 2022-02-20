#ifndef H_PWM
#define H_PWM
/*
 * Part of old-school 8-bit transformer battery charger. STM8 PWM output to
 * the swithing transistor.
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

#define PWM_PORT    GPIOD
#define PWM_PIN     GPIO4

void pwmInit(void);
void setDutyCycle(uint16_t dut);
uint16_t getDutyCycle(void);
void incDutyCycle(void);
void decDutyCycle(void);
void pwmOff(void);

#endif
