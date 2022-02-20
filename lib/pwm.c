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
#include "regs/tim_reg.h"
#include "system.h"
#include "pwm.h"

void pwmInit()
{
    portConfig(PWM_PORT, PWM_PIN, OUTPUT_PP_10M);
    // timer for tacts
    enable(TIM2);
    // pwm mode with inversion (0 output means transistor open)
    TIM2_CCMR1 = OC1M_PWM2 | CC1S_OUT;
    TIM2_PSCR  = 0;
    TIM2_ARRH  = 0;
    TIM2_ARRL  = 255;
    TIM2_CCR1H = 0;
    TIM2_CCR1L = 0;
    TIM2_CR1  |= CEN;
    TIM2_EGR  |= UG;
}

void setDutyCycle(uint16_t dut)
{
    TIM2_CCR1H = (uint8_t)(dut>>8) & 0x01;
    TIM2_CCR1L = (uint8_t)dut;
}

uint16_t getDutyCycle()
{
    return (TIM2_CCR1H<<8) + TIM2_CCR1L;
}

void incDutyCycle()
{
    if(TIM2_CCR1L == 255) {
        TIM2_CCR1H = 1;
        TIM2_CCR1L = 0;
    } else {
        TIM2_CCR1L += 1;
    }
}

void decDutyCycle()
{
    if( TIM2_CCR1L > 0 ) {
        TIM2_CCR1L -= 1;
    } else if( TIM2_CCR1H == 1 ) {
        TIM2_CCR1H = 0;
        TIM2_CCR1L = 255;
    }
}

void pwmOff()
{
    TIM2_CCR1H = 0;
    TIM2_CCR1L = 0;
}
