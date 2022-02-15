/*
 * Part of old-school 8-bit transformer battery charger. STM8 GPIO relative
 * functions.
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

void setPin(uint8_t port, uint8_t pin)
{
    P_ODR(port) |= pin;
}

void resetPin(uint8_t port, uint8_t pin)
{
    P_ODR(port) &= ~pin;
}

uint8_t readPin(uint8_t port, uint8_t pin)
{
    if( (P_IDR(n) & pin) > 0 )  return 1;
    return 0;
}

void portConfig(uint8_t port, uint8_t pin, uint8_t config)
{
    switch(config) {
        case INPUT_FLOAT:
            P_DDR(port) &= ~pin;
            P_CR1(port) &= ~pin;
            P_CR2(port) &= ~pin;
            break;
        case INPUT_PULLUP:
            P_DDR(port) &= ~pin;
            P_CR1(port) |= pin;
            P_CR2(port) &= ~pin;
            break;
        case INPUT_FLOAT_EXTI:
            P_DDR(port) &= ~pin;
            P_CR1(port) &= ~pin;
            P_CR2(port) |= pin;
            break;
        case INPUT_PULLUP_EXTI:
            P_DDR(port) &= ~pin;
            P_CR1(port) |= pin;
            P_CR2(port) |= pin;
            break;
        case OUTPUT_OD_2M:
            P_DDR(port) |= pin;
            P_CR1(port) &= ~pin;
            P_CR2(port) &= ~pin;
            break;
        case OUTPUT_PP_2M:
            P_DDR(port) |= pin;
            P_CR1(port) |= pin;
            P_CR2(port) &= ~pin;
            break;
        case OUTPUT_OD_10M:
            P_DDR(port) |= pin;
            P_CR1(port) &= ~pin;
            P_CR2(port) |= pin;
            break;
        case OUTPUT_PP_10M:
            P_DDR(port) |= pin;
            P_CR1(port) |= pin;
            P_CR2(port) |= pin;
            break;
    }
}
