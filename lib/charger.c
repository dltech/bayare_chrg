/*
 * Part of old-school 8-bit transformer battery charger.
 * The whole regulator is implemented here
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
#include "pwm.h"
#include "analogue.h"
#include "tm1637.h"
#include "display.h"
#include "charger.h"

void chargerInit(void);

volatile setValueTyp setValue;

void chrgInit()
{
    tmInit();
    analogueInit();
    chargerInit();
}

void chargerInit()
{
    setValue.amp = 0;
    setValue.volt = 0;
    portConfig(BUTTON_PORT, BUTTON1_PIN | BUTTON2_PIN, INPUT_PULLUP);
}

void mainMenu()
{

}

void regulator(setValueTyp set, uint16_t amp, uint16_t volt)
{
    static uint8_t softStartCnt = 0;
    if((set.volt > volt) && (set.amp > amp)) {
        ++softStartCnt;
    } else {
        softStartCnt = 0;
    }
    if(softStartCnt > 254) {
        incDutyCycle();
    }
    if((volt > set.volt) || (amp > set.amp)) {
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
