#ifndef H_UART
#define H_UART
/*
 * Part of old-school 8-bit transformer battery charger. Program UART imitation.
 *
 * Copyright 2021 Mikhail Belkin <dltech174@gmail.com>
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


#define BAUDRATE        9600
#define MAX_PSC         7
#define UART_TIM_ARR    FSYSTEM / BAUDRATE / MAX_PSC / 2//119

enum uartState{
    START_RX,
    DATA_RX,
    STOP_RX,
    DATA_TX,
};

typedef struct {
    uint8_t rxCnt;
    uint8_t txCnt;
    uint8_t rxByte;
    uint8_t txByte;
} uartParamTyp;

void progUartInit();


#endif
