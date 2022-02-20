#ifndef H_SYSTEM
#define H_SYSTEM
/*
 * Part of old-school 8-bit transformer battery charger.
 * System init functions of STM8
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
#include <stdint.h>
#include "regs/interrupt_reg.h"

// list of peripherial for enable function
enum enablePeriph {
    TIM1,
    TIM2,
    TIM3,
    TIM4,
    UART1,
    SPI,
    I2C,
    ADC,
    AWU
};

// set priority level of choosen interrupt
void setPriority(uint8_t nInt, uint8_t level);
// set maximal built in clock
void clockTo16Hsi(void);
// enable peripherial clocking
void enable(uint8_t periph);
void delay(uint8_t ms);

#endif
