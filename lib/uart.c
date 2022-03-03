/*
 * Part of old-school 8-bit transformer battery charger. Program UART.
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
#include "regs/tim_reg.h"
#include "uart.h"

uartParamTyp uartProp;

void uartIrqInit();
void uartDelayUpdate();

void uartIrqInit()
{
    // timer for tacts
    enable(TIM4);
    TIM4_CR1  |= CEN;
    TIM4_PSCR  = MAX_PSC;
    TIM4_ARR   = UART_TIM_ARR;
    TIM4_IER   = UIE;
    setPriority(TIM4_UPD_ITN, 1);
}

void uartDelayUpdate()
{
    TIM4_PSCR  = MAX_PSC;
    TIM4_ARR   = UART_TIM_ARR;
    TIM4_EGR  |= UG;
}

void RxTx(void) __interrupt(TIM1_UPD_ITN)
{
    if(uartProp.rxCnt == STOP_RX)
}
