/*
 * Part of old-school 8-bit transformer battery charger. Button handling
 * implemented through interrupts.
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
#include "charger.h"
#include "autocharge.h"
#include "button.h"

extern volatile menuParamTyp param;

uint8_t isPressed(uint8_t pin);

void buttonInit()
{
    portConfig(BUTTON_PORT, BUTTON1_PIN | BUTTON2_PIN, INPUT_PULLUP_EXTI);
    EXTI_CR1 = PBIS_FALL;
    setPriority(EXTI1_ITN, 1);
    setPriority(EXTI2_ITN, 1);
}

uint8_t isPressed(uint8_t pin)
{
    uint8_t i;
    for(i=0 ; i<4 ; ++i) {
        delay(7);
        if(readPin(BUTTON_PORT, pin) > 0) {
            break;
        }
    }
    if(i==4) {
        return 1;
    }
    return 0;
}

void button1(void) __interrupt(EXTI1_ITN)
{
    but = isPressed(BUTTON1_PIN);
    if((but>0) && ((param.state == VOLT_STABLE) || \
       (param.state == VOLT_CHANGE) || (param.state == VOLT_SET)) ) {
        param.state = AMP_STABLE;
    }
    if((but>0) && ((param.state == AMP_STABLE) || \
       (param.state == AMP_CHANGE) || (param.state == AMP_SET)) ) {
        param.state = VOLT_STABLE;
    }
}

void button2(void) __interrupt(EXTI2_ITN)
{
    but = isPressed(BUTTON2_PIN);
    if((but>0) && (param.state != AUTO_CHARGE))
        resetCharger();
        param.state == AUTO_CHARGE;
    }
    if((but>0) && (param.state == AUTO_CHARGE))
        param.state == AMP_STABLE;
    }
}
