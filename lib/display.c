/*
 * Part of old-school 8-bit transformer battery charger.
 * Interlayer between TM driver and text with digits.
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
#include "tm1637.h"
#include "display.h"

uint8_t alphabet(char s);

// we need the second digit to be buffered to change first
volatile uint8_t displayBuffer[DISPLAY_SIZE] = {0};

void digit1WDot(uint8_t digit)
{
    uint8_t strDigit[4];
    utoa(digit, strDigit, 10);
    displayBuffer[3] = alphabet(strDigit[1]);
    displayBuffer[4] = alphabet(strDigit[2]) | SEGDP;
    displayBuffer[5] = alphabet(strDigit[0]);
    tmUpd(displayBuffer);
}

void digit2WDot(uint8_t digit)
{
    uint8_t strDigit[4];
    utoa(digit, strDigit, 10);
    for(uint8_t i=0 ; i<DIGITS ; ++i) {
        displayBuffer[i] = alphabet(strDigit[i]);
    }
    displayBuffer[1] |= SEGDP;
    tmUpd(displayBuffer);
}

void showTime(uint8_t time)
{
    uint8_t strTime[3];
    if(time > 99) time = 99;
    utoa(time, strTime, 10);
    for(uint8_t i=0 ; i<2 ; ++i) {
        displayBuffer[i] = alphabet(strDigit[i]);
    }
    displayBuffer[2] |= alphabet('h');
    tmUpd(displayBuffer);
}

void textLine1(char* str)
{
    // разворачивательница строки в то как у меня дорожки легли
    displayBuffer[3] = alphabet(str[1]);
    displayBuffer[4] = alphabet(str[2]);
    displayBuffer[5] = alphabet(str[0]);
    tmUpd(displayBuffer);
}

void textLine2(char* str)
{
    for(uint8_t i=0 ; i<DIGITS ; ++i) {
        displayBuffer[i] = alphabet(str[i]);
    }
    tmUpd(displayBuffer);
}

uint8_t alphabet(char s)
{
    switch (s)
    {
        case '.':
        case ',':
            return SEGDP;
            break;
        case '=':
            return SEGD + SEGD;
            break;
        case '-':
            return SEGG;
            break;
        case '_':
            return SEGD;
            break;
        case '"':
            return SEGB + SEGF;
            break;
        case '\'':
            return SEGF;
            break;
        case ']':
            return SEGA + SEGB + SEGC + SEGD;
            break;
        case '2':
            return SEGA + SEGB + SEGD + SEGE + SEGG;
            break;
        case '3':
            return SEGA + SEGB + SEGC + SEGD + SEGG;
            break;
        case '4':
            return SEGB + SEGC + SEGG + SEGF;
            break;
        case '5':
            return SEGA + SEGC + SEGD + SEGF + SEGG;
            break;
        case '6':
            return SEGA + SEGC + SEGD + SEGE + SEGF + SEGG;
            break;
        case '7':
            return SEGA + SEGB + SEGC;
            break;
        case '8':
            return SEGA + SEGB + SEGC + SEGD + SEGE + SEGF + SEGG;
            break;
        case '9':
            return SEGA + SEGB + SEGC + SEGD + SEGF + SEGG;
            break;
        case 'A':
        case 'a':
            return SEGA + SEGB + SEGC + SEGE + SEGF + SEGG;
            break;
        case 'B':
        case 'b':
            return SEGC + SEGD + SEGE + SEGF + SEGG;
            break;
        case '[' :
        case 'C' :
        case 'c' :
            return SEGA + SEGD + SEGE + SEGF;
            break;
        case 'D' :
        case 'd' :
            return SEGB + SEGC + SEGD + SEGE + SEGG;
            break;
        case 'E' :
        case 'e' :
            return SEGA + SEGD + SEGE + SEGF + SEGG;
            break;
        case 'F' :
        case 'f' :
            return SEGA + SEGE + SEGF + SEGG;
            break;
        case 'G' :
        case 'g' :
            return SEGA + SEGC + SEGD + SEGE + SEGF;
            break;
        case 'H' :
        case 'h' :
        case 'x' :
        case 'X' :
            return SEGB + SEGC + SEGE + SEGF + SEGG;
            break;
        case 'I' :
        case 'i' :
        case '1' :
            return SEGB + SEGC;
            break;
        case 'J' :
        case 'j' :
            return SEGB + SEGC + SEGD;
            break;
        case 'K' :
        case 'k' :
            return SEGA + SEGC + SEGE + SEGF + SEGG;
            break;
        case 'L':
        case 'l':
            return SEGD + SEGE + SEGF;
            break;
        case 'M':
        case 'm':
            return SEGA + SEGC + SEGE;
            break;
        case 'N':
        case 'n':
            return SEGC + SEGE + SEGG;
            break;
        case 'O':
        case 'o':
        case '0':
            return SEGA + SEGB + SEGC + SEGD + SEGE + SEGF;
            break;
        case 'P':
        case 'p':
            return SEGA + SEGB + SEGE + SEGF + SEGG;
            break;
        case 'Q':
        case 'q':
            return SEGA + SEGB + SEGC + SEGF + SEGG;
            break;
        case 'R':
        case 'r':
            return SEGE + SEGG;
            break;
        case 'S':
        case 's':
            return SEGA + SEGC + SEGD + SEGF;
            break;
        case 'T':
        case 't':
            return SEGD + SEGE + SEGF + SEGG;
            break;
        case 'U':
        case 'u':
            return SEGB + SEGC + SEGD + SEGE + SEGF;
            break;
        case 'V':
        case 'v':
            return SEGC + SEGD + SEGE;
            break;
        case 'W':
        case 'w':
            return SEGB + SEGD + SEGF;
            break;
        case 'Y':
        case 'y':
            return SEGB + SEGC + SEGD + SEGF + SEGG;
            break;
        case 'Z':
        case 'z':
            return SEGA + SEGB + SEGD + SEGE;
            break;
        default :
            return 0;
    }
}
