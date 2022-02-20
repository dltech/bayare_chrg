#ifndef H_CHARGER
#define H_CHARGER
/*
 * Part of old-school 8-bit transformer battery charger.
 * The whole regulator is implemented here, in main run chrgInit
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

#define AMP_THRESH  512
#define VOLT_THRESH 900
#define MAX_VOLT    17
#define MAX_AMP     10
#define UPDATE_FPS  15

#define ARRL_MENU   244/UPDATE_FPS
#define HALF_HOUR   1800*UPDATE_FPS

typedef struct {
    uint16_t volt;
    uint16_t amp;
} setValueTyp;

typedef struct {
    uint8_t prevRv1;
    uint8_t prevRv2;
    uint8_t state;
    uint8_t time;
} menuParamTyp;

enum states {
    VOLT_CHANGE,
    VOLT_SET,
    VOLT_STABLE,
    AMP_CHANGE,
    AMP_SET,
    AMP_STABLE,
    AUTO_CHARGE
};

void chrgInit(void);

void regulator(setValueTyp set, uint16_t amp, uint16_t volt);
void applyAmp(void);
void applyVolt(void);


#endif
