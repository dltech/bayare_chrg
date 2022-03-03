/*
 * TM1637 low level driver.
 *
 * Copyright 2021 Mikhail Belkin <dltech174@gmail.com>
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
#include "regs/tim_reg.h"
#include "system.h"
#include "tm1637.h"

// little init functions as parts of main init function
void tmPortInit(void);
void tmDelayInit(void);
void tmDelayUpdate(void);
// timer based accurate delays
void quaterTact(void);
void halfTact(void);
// data transmission
uint8_t pushByte(uint8_t byte);
uint8_t tipoI2cBlockingTx1(uint8_t data);
uint8_t tipoI2cBlockingTx(uint8_t *data, uint8_t size);

/* display only, no keys reads */
void tmInit()
{
    tmPortInit();
    tmDelayInit();
    uint8_t data[DISPLAY_SIZE] = {0};
    tmUpd(data);
    setBrightness(100);
}

void tmPortInit()
{
    portConfig(TM_PORT, TM_SCL | TM_SDA, OUTPUT_OD_10M);
}

void tmDelayInit()
{
    // timer for tacts
    enable(TIM4);
    TIM4_CR1  |= CEN;
    tmDelayUpdate();
}

void tmDelayUpdate()
{
    TIM4_PSCR  = TIM4_MAX_PSCR;
    TIM4_ARR   = 4;
    TIM4_EGR  |= UG;
}

void quaterTact()
{
    uint8_t timeout = 255;
    tmDelayUpdate();
    TIM4_SR = 0;
    while( (TIM4_SR == 0) && (--timeout > 0) );
}

void halfTact()
{
    quaterTact();
    quaterTact();
}

uint8_t pushByte(uint8_t byte)
{
    int ret;
    for(int i=0 ; i<8 ; ++i)
    {
        resetPin(TM_PORT, TM_SCL);
        quaterTact();
        if((byte & (1<<i)) > 0) {
            setPin(TM_PORT, TM_SDA);
        } else {
            resetPin(TM_PORT, TM_SDA);
        }
        quaterTact();
        setPin(TM_PORT, TM_SCL);
        halfTact();
    }
    // ack tact
    resetPin(TM_PORT, TM_SCL);
    quaterTact();
    setPin(TM_PORT, TM_SDA);
    quaterTact();
    setPin(TM_PORT, TM_SCL);
    quaterTact();
    if(readPin(TM_PORT,TM_SDA) > 0) {
        ret = 255;
    } else {
        ret = 0;
    }
    quaterTact();
    return ret;
}

// transmit to tm only one byte
uint8_t tipoI2cBlockingTx1(uint8_t data)
{
    int err = 0;
    setPin(TM_PORT, TM_SDA | TM_SCL);
    halfTact();
    halfTact();
    // start condition
    resetPin(TM_PORT, TM_SDA);
    halfTact();
    // clock data
    err = pushByte(data);
    // stop bit
    resetPin(TM_PORT, TM_SDA | TM_SCL);
    halfTact();
    setPin(TM_PORT, TM_SCL);
    halfTact();
    setPin(TM_PORT, TM_SDA | TM_SCL);
    return err;
}

// transmit to tm array of bytes
uint8_t tipoI2cBlockingTx(uint8_t *data, uint8_t size)
{
    int err = 0;
    setPin(TM_PORT, TM_SDA | TM_SCL);
    halfTact();
    halfTact();
    // start condition
    resetPin(TM_PORT, TM_SDA);
    halfTact();
    // clock data
    for(int i=0 ; i<size ; ++i) {
        err += pushByte(data[i]);
    }
    // stop bit
    resetPin(TM_PORT, TM_SDA | TM_SCL);
    halfTact();
    setPin(TM_PORT, TM_SCL);
    halfTact();
    setPin(TM_PORT, TM_SDA | TM_SCL);
    return err;
}

void tmUpd(uint8_t *data)
{
    tmDelayUpdate();
    tipoI2cBlockingTx1(WRITE_DATA_CMD_AVT);
    uint8_t cnt = 0;
    uint8_t tx[DISPLAY_SIZE+1];
    tx[cnt++] = SET_0H;
    for(int i=0 ; i<DISPLAY_SIZE ; ++i) {
        tx[cnt++] = data[i];
    }
    tipoI2cBlockingTx(tx, cnt);
}

void setBrightness(uint8_t percent)
{
    tmDelayUpdate();
    uint8_t reg = BRIGHT6P;
    if(percent == 0) {
        reg = DISP_OFF;
    } else if(percent <= 6) {
        reg = BRIGHT6P;
    } else if(percent <= 13) {
        reg = BRIGHT13P;
    } else if(percent <= 25) {
        reg = BRIGHT25P;
    } else if(percent <= 63) {
        reg = BRIGHT63P;
    } else if(percent <= 69) {
        reg = BRIGHT69P;
    } else if(percent <= 75) {
        reg = BRIGHT75P;
    } else if(percent <= 81) {
        reg = BRIGHT81P;
    } else if(percent <= 100) {
        reg = BRIGHT88P;
    }
    tipoI2cBlockingTx1(reg);
}
