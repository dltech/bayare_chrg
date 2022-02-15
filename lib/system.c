/*
 * Part of old-school 8-bit transformer battery charger. System init functions
 *  of STM8.
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
#include "regs/clk_reg.h"

void setPriority(uint8_t nInt, uint8_t level)
{
    const uint8_t nIntMax = 29;
    const uint8_t intPerReg = 4;
    if(nInt > nIntMax) return;
    uint8_t reg = nInt / intPerReg;
    uint8_t shift = (nInt % intPerReg)*2;
    ITC_SPR(reg) &= ~(PRIORITY_MSK << shift);
    ITC_SPR(reg) |= (level & PRIORITY_MSK) << shift;
}

void clockTo16Hsi(void)
{
    CLK_CKDIVR = HSIDIV_NODIV | CPUDIV_NODIV;
    CLK_SWR = SWI_HSI;
    uint16_t timeout = 65535;
    while( ( CLK_SWCR & SWIF ) || (--timeout > 1) );
    if( timeout < 2 ) {
        CLK_SWCR &= ~SWBSY;
    }
    CLK_SWCR |= SWEN;
}

void enable(uint8_t periph)
{
    switch( periph ) {
        case TIM1:
            CLK_PCKENR1 |= PCKEN1_TIM1;
            break;
        case TIM2:
            CLK_PCKENR1 |= PCKEN1_TIM2;
            break;
        case TIM3:
            CLK_PCKENR1 |= PCKEN1_TIM3;
            break;
        case TIM4:
            CLK_PCKENR1 |= PCKEN1_TIM4;
            break;
        case UART1:
            CLK_PCKENR1 |= PCKEN1_UART1;
            break;
        case SPI:
            CLK_PCKENR1 |= PCKEN1_SPI;
            break;
        case I2C:
            CLK_PCKENR1 |= PCKEN1_I2C;
            break;
        case ADC:
            CLK_PCKENR2 |= PCKEN2_ADC;
            break;
        case AWU:
            CLK_PCKENR2 |= PCKEN2_AWU;
            break;
    }
}
