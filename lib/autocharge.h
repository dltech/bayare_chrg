#ifndef H_AUTOCHARGE
#define H_AUTOCHARGE
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
#include "charger.h"

#define LABELTIME   2
#define NORMALTIME  8
#define LABELCNT    LABELTIME*UPDATE_FPS
#define NORMALCNT   NORMALTIME*UPDATE_FPS
#define HALF_HOUR   1800*UPDATE_FPS

enum chargeState {
    START = 0,
    CHECK,
    BULK,
    ABSORPTION,
    EQUALIZATION,
    MAINTANCE,
    ERROR
};

void resetCharger(void);
void autoCharge(void);

#endif
