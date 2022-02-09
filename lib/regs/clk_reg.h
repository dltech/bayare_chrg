#ifndef H_CLK_REG
#define H_CLK_REG
/*
 * Part of old-school 8-bit transformer battery charger. STM8 ADC register
 * definitions.
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
#include "memorymap.h"

/* Internal clock register */
#define CLK_ICKR        MMIO32(CLK_BASE + 0x00)
// Regulator power off in Active-halt mode
#define REGAH   0x20
// Low speed internal oscillator ready
#define LSIRDY  0x10
// Low speed internal RC oscillator enable
#define LSIEN   0x08
// Fast wakeup from Halt/Active-halt modes
#define FHWU    0x04
// High speed internal oscillator ready
#define HSIRDY  0x02
// High speed internal RC oscillator enable
#define HSIEN   0x01

/* External clock register */
#define CLK_ECKR        MMIO32(CLK_BASE + 0x01)
// High speed external crystal oscillator ready
#define HSERDY  0x02
// High speed external crystal oscillator enable
#define HSEEN   0x01

/* Clock master status register */
#define CLK_CMSR        MMIO32(CLK_BASE + 0x03)
// Clock master status bits
#define CKM_HSI 0xe1
#define CKM_LSI 0xd2
#define CKM_HSE 0xb4

/* Clock master switch register */
#define CLK_SWR         MMIO32(CLK_BASE + 0x04)
// Clock master selection bits
#define SWI_HSI 0xe1
#define SWI_LSI 0xd2
#define SWI_HSE 0xb4

/* Switch control registers */
#define CLK_SWCR        MMIO32(CLK_BASE + 0x05)
// Clock switch interrupt flag
#define SWIF    0x08
// Clock switch interrupt enable
#define SWIEN   0x04
// Switch start/stop
#define SWEN    0x02
// Switch busy
#define SWBSY   0x01

/* Clock divider register */
#define CLK_CKDIVR      MMIO32(CLK_BASE + 0x06)
// High speed internal clock prescaler
#define HSIDIV_NODIV    0x00
#define HSIDIV_NDIV2    0x08
#define HSIDIV_NDIV4    0x10
#define HSIDIV_NDIV8    0x18
// CPU clock prescaler
#define CPUDIV_NODIV    0x00
#define CPUDIV_DIV2     0x01
#define CPUDIV_DIV4     0x02
#define CPUDIV_DIV8     0x03
#define CPUDIV_DIV16    0x04
#define CPUDIV_DIV32    0x05
#define CPUDIV_DIV64    0x06
#define CPUDIV_DIV128   0x07

/* Peripheral clock gating register 1 */
#define CLK_PCKENR1     MMIO32(CLK_BASE + 0x07)
// Peripheral clock enable
#define PCKEN1_TIM1     0x80
#define PCKEN1_TIM3     0x40
#define PCKEN1_TIM2     0x20
#define PCKEN1_TIM4     0x10
#define PCKEN1_UART1    0x08
#define PCKEN1_SPI      0x02
#define PCKEN1_I2C      0x01

/* Peripheral clock gating register 2 */
#define CLK_PCKENR2     MMIO32(CLK_BASE + 0x0a)
// Peripheral clock enable
#define PCKEN2_ADC      0x08
#define PCKEN2_AWU      0x04

/* Clock security system register */
#define CLK_CSSR        MMIO32(CLK_BASE + 0x08)
// Clock security system detection
#define CSSD    0x08
// Clock security system detection interrupt enable
#define CSSDIE  0x04
// Auxiliary oscillator connected to master clock
#define AUX     0x02
// Clock security system enable
#define CSSEN   0x01

/* Configurable clock output register */
#define CLK_CCOR        MMIO32(CLK_BASE + 0x09)
// Configurable clock output busy
#define CCOBSY          0x40
// Configurable clock output ready
#define CCORDY          0x20
// Configurable clock output selection.
#define CCOSEL_HSIDIV   0x00
#define CCOSEL_LSI      0x02
#define CCOSEL_HSE      0x04
#define CCOSEL_CPU      0x08
#define CCOSEL_CPU_D2   0x0a
#define CCOSEL_CPU_D4   0x0c
#define CCOSEL_CPU_D8   0x0e
#define CCOSEL_CPU_D16  0x10
#define CCOSEL_CPU_D32  0x12
#define CCOSEL_CPU_D64  0x14
#define CCOSEL_HSI      0x16
#define CCOSEL_MASTER   0x18
#define CCOSEL_CPU      0x1a
#define CCOSEL_CPU      0x1c
#define CCOSEL_CPU      0x1e
// Configurable clock output enable
#define CCOEN           0x01

/* HSI clock calibration trimming register */
#define CLK_HSITRIMR    MMIO32(CLK_BASE + 0x0c)
// HSI trimming value
#define HSITRIM_MSK     0x0f

/* SWIM clock control register */
#define CLK_SWIMCCR     MMIO32(CLK_BASE + 0x0d)
// SWIM clock divider
#define SWIMCLK    0x01

#endif
