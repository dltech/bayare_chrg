#ifndef H_DISPLAY
#define H_DISPLAY
/*
 * Part of old-school 8-bit transformer battery charger.
 * Local 7-segment display output functions. (simplest printf alternative).
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

// schematic depended (not necessarily segment A fits byte 0)
#define SEGA  (1 << 0)
#define SEGB  (1 << 2)
#define SEGC  (1 << 4)
#define SEGD  (1 << 6)
#define SEGE  (1 << 7)
#define SEGF  (1 << 1)
#define SEGG  (1 << 3)
#define SEGDP (1 << 5)

#define DIGITS  3

// show number with one decimal in digit *10 format
void digit1WDot(uint8_t digit);
void digit2WDot(uint8_t digit);
// show text on first or second digit screen
void textLine1(char* str);
void textLine2(char* str);

#endif
