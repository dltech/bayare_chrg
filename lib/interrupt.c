/*
 * Part of old-school 8-bit transformer battery charger. Interrupt relateg
 * functions of STM8.
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

#include "interrupt.h"

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
