/*
 * Part of old-school 8-bit transformer battery charger.
 * The whole regulator is implemented here.
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
#include "pwm.h"
#include "analogue.h"
#include "tm1637.h"
#include "display.h"
#include "button.h"
#include "autocharge.h"
#include "regs/tim_reg.h"
#include "charger.h"

void chargerInit(void);
void mainMenu(void);
void applyVolt(void);
void applyAmp(void);
void clockTick(void);

volatile setValueTyp setValue;
volatile menuParamTyp param;
extern volatile analogueTyp ana;

void chrgInit()
{
    tmInit();
    analogueInit();
    buttonInit();
    chargerInit();
}

void chargerInit()
{
    setValue.amp = 0;
    setValue.volt = 0;
    param.state = AMP_STABLE;
    enable(TIM1);
    TIM1_IER   = UIE;
    TIM1_PSCRH = 255;
    TIM1_PSCRL = 255;
    TIM1_ARRH  = 0;
    TIM1_ARRL  = (uint8_t)ARRL_MENU;
    TIM1_CR1  |= CEN;
    TIM1_EGR  |= UG;
    setPriority(TIM1_UPD_ITN, 0);
}

void mainMenu()
{
    switch(param.state) {
        case VOLT_STABLE:
            digit1WDot(getVolt());
            if(param.prevRv1 != ana.rv1) {
                param.state = VOLT_CHANGE;
            }
            break;
        case VOLT_CHANGE:
            digit1WDot(((uint16_t)MAX_VOLT*1000)/ana.rv1);
            if(param.prevRv1 != ana.rv1) {
                param.state = VOLT_SET;
            }
            break;
        case VOLT_SET:
            applyVolt();
            param.state = VOLT_STABLE;
            break;
        case AMP_STABLE:
            digit2WDot(getAmp());
            if(param.prevRv1 != ana.rv1) {
                param.state = AMP_CHANGE;
            }
            break;
        case AMP_CHANGE:
            digit2WDot(((uint16_t)MAX_VOLT*1000)/ana.rv1);
            if(param.prevRv1 == ana.rv1) {
                param.state = AMP_SET;
            }
            break;
        case AMP_SET:
            applyAmp();
            param.state = AMP_STABLE;
            break;
        case AUTO_CHARGE:
            autoCharge();
            break;
    }
    param.prevRv1 = ana.rv1;
//    param.prevRv2 = param.rv2;
}


void regulator(uint16_t setAmp, uint16_t setVolt, uint16_t amp, uint16_t volt)
{
    static uint8_t softStartCnt = 0;
    if((setVolt > volt) && (setAmp > amp)) {
        ++softStartCnt;
    } else {
        softStartCnt = 0;
    }
    if(softStartCnt > 254) {
        incDutyCycle();
    }
    if((volt > setVolt) || (amp > setAmp)) {
        decDutyCycle();
    }
    // short circuit protection
    if( (volt > VOLT_THRESH) || (amp > AMP_THRESH) ) {
        pwmOff();
    }
}

void applyVolt()
{
    setValue.volt = voltToAdc(((uint16_t)MAX_VOLT*100)/getRv(RV1_CH));
}

void applyAmp()
{
    setValue.amp = ampToAdc(((uint16_t)MAX_VOLT*100)/getRv(RV1_CH));
}

void menuUpdate(void) __interrupt(TIM1_UPD_ITN)
{
    clockTick();
    mainMenu();
}
