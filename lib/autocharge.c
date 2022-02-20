/*
 * Part of old-school 8-bit transformer battery charger.
 * Automatic car battery charging algorithm.
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
#include "display.h"
#include "analogue.h"
#include "autocharge.h"

extern volatile setValueTyp setValue;
volatile struct chargeSettings {
    uint8_t state;
    uint8_t stabCnt;
    uint32_t nCycles;
    uint8_t time;
    uint8_t totalTime;
    const uint8_t dispUpdateDiv;
    const uint8_t stabAmount;
    const uint8_t bulkTime;
    const uint8_t absorptionTime;
    const uint8_t equalizationTime;
} chSet = {CHECK, 0, 0, 0, 50, 200, 72*2, 8*2, 1};

void updateLable(void);
void clockTick(void);

void updateLable()
{
    const char lbl[ERROR+1][4] = { {'c', 'h', 'k', '\0'},
                                   {'c', 'h', 'k', '\0'},
                                   {'1', '_', '3', '\0'},
                                   {'2', '_', '3', '\0'},
                                   {'3', '_', '3', '\0'},
                                   {' ', 'o', 'k', '\0'},
                                   {'e', 'r', 'r', '\0'} };
    // щелкает либо сам (каждые n вызовов меняет лейбл), либо сразу, как скажете
    static uint8_t cnt = LABELCNT+1;
    static uint8_t isLabel = 0;
    if((cnt > LABELCNT) && (isLabel == 0)) {
        textLine1(lbl[chSet.state]);
        showTime((chSet.time + chSet.totalTime)/2);
        cnt = 0;
        isLabel = 1;
    }
    if((cnt > NORMALCNT) && (isLabel == 1)) {
        isLabel = 0;
    }
    if(isLabel == 0) {
        digit1WDot(getVolt());
        digit2WDot(getAmp());
    }
    ++cnt;
}

void resetCharger()
{
    chSet.state = START;
}

void autoCharge()
{
    const struct {
        uint8_t minimumAmp;
        uint8_t constantAmp;
        uint8_t equalizationAmp;
        uint8_t maintanceAmp;
        uint8_t constantCurrent;
        uint8_t lowCurrent;
        uint8_t voltageDelta;
        uint8_t currentDelta;
    } table = {40, 145, 15, 135, 50, 10, 5, 5};

    switch( chSet.state )
    {
        case START:
            chSet.totalTime = 0;
            setValue.volt = 0;
            setValue.amp = 2;
            ++chSet.stabCnt;
            if(chSet.stabCnt > chSet.stabAmount) {
                chSet.state = CHECK;
                chSet.stabCnt = 0;
            }
            break;
        case CHECK:
            if( getVolt() >= table.minimumAmp ) {
                ++chSet.stabCnt;
            } else {
                chSet.stabCnt = 0;
            }
            if( chSet.stabCnt > chSet.stabAmount ) {
                setValue.volt = voltToAdc(table.constantAmp);
                setValue.amp = ampToAdc(table.constantCurrent);
                chSet.stabCnt = 0;
                chSet.time = 0;
                chSet.state = BULK;
            }
            break;
        case BULK:
            if( getVolt() >= table.maintanceAmp ) {
                ++chSet.stabCnt;
            } else {
                chSet.stabCnt = 0;
            }
            if( chSet.stabCnt > chSet.stabAmount ) {
                chSet.stabCnt = 0;
                setValue.volt = voltToAdc(table.constantAmp);
                chSet.totalTime = chSet.time;
                chSet.time = 0;
                chSet.state = ABSORPTION;
            }
            if( chSet.time > chSet.bulkTime) {
                chSet.state = ERROR;
            }
            break;
        case ABSORPTION:
            if( getAmp() <= table.lowCurrent ) {
                ++chSet.stabCnt;
            } else {
                chSet.stabCnt = 0;
            }
            if( chSet.stabCnt > chSet.stabAmount ) {
                setValue.volt = voltToAdc(table.maintanceAmp);
                setValue.amp = ampToAdc(table.lowCurrent);
                chSet.stabCnt = 0;
                chSet.state = MAINTANCE;
            }
            if( chSet.time > chSet.absorptionTime ) {
                setValue.volt = voltToAdc(table.equalizationAmp);
                setValue.amp = ampToAdc(table.lowCurrent);
                chSet.stabCnt = 0;
                chSet.totalTime += chSet.time;
                chSet.time = 0;
                chSet.state = EQUALIZATION;
            }
            break;
        case EQUALIZATION:
            if( getVolt() >= table.equalizationAmp ) {
                ++chSet.stabCnt;
            } else {
                chSet.stabCnt = 0;
            }
            if( chSet.stabCnt > chSet.stabAmount ) {
                setValue.volt = voltToAdc(table.maintanceAmp);
                setValue.amp = ampToAdc(table.lowCurrent);
                chSet.stabCnt = 0;
                chSet.state = MAINTANCE;
            }
            if( chSet.time > chSet.equalizationTime ) {
                chSet.stabCnt = 0;
                chSet.time = 0;
                chSet.state = START;
            }
            break;
        case MAINTANCE:
            if( getVolt() < (table.maintanceAmp - table.voltageDelta) ) {
                ++chSet.stabCnt;
            } else {
                chSet.stabCnt = 0;
            }
            if( chSet.stabCnt > chSet.stabAmount ) {
                chSet.stabCnt = 0;
                chSet.time = 0;
                chSet.state = START;
            }
            break;
        case ERROR:
            setValue.volt = 0;
            setValue.amp = 0;
            break;
        default:
            setValue.volt = 0;
            setValue.amp = 0;
            break;
    }
    updateLable();
}

void clockTick()
{
    static uint16_t cnt = 0;
    if(++cnt > HALF_HOUR) {
        cnt = 0;
        ++chSet.time;
    }
}
