#ifndef H_GPIO
#define H_GPIO
/*
 * Part of old-school 8-bit transformer battery charger.
 * All neccesary for GPIO using.
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
#include "regs/gpio_reg.h"

enum gpios{
    GPIOA = 0,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOF
};
// get configuration here
enum configs{
    INPUT_FLOAT = 0,
    INPUT_PULLUP,
    INPUT_FLOAT_EXTI,
    INPUT_PULLUP_EXTI,
    OUTPUT_OD_2M,
    OUTPUT_PP_2M,
    OUTPUT_OD_10M,
    OUTPUT_PP_10M
};

void setPin(uint8_t port, uint8_t pin);
void resetPin(uint8_t port, uint8_t pin);
uint8_t readPin(uint8_t port, uint8_t pin);
void portConfig(uint8_t port, uint8_t pin, uint8_t config);

#endif
