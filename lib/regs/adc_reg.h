#ifndef H_ADC_REG
#define H_ADC_REG
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

/* ADC data buffer register x high */
#define ADC1_DB0RH  MMIO32(ADC1_BASE + 0x00)
#define ADC1_DB7RH  MMIO32(ADC1_BASE + 0x0e)
#define ADC1_DB8RH  MMIO32(ADC1_BASE + 0x10)
#define ADC1_DB9RH  MMIO32(ADC1_BASE + 0x12)
/* ADC data buffer register x low */
#define ADC1_DB0RL  MMIO32(ADC1_BASE + 0x01)
#define ADC1_DB7RL  MMIO32(ADC1_BASE + 0x0f)
#define ADC1_DB8RL  MMIO32(ADC1_BASE + 0x11)
#define ADC1_DB9RL  MMIO32(ADC1_BASE + 0x13)

/* ADC control/status register */
#define ADC1_CSR    MMIO32(ADC1_BASE + 0x20)
#define ADC2_CSR    MMIO32(ADC2_BASE + 0x20)
// End of conversion
#define EOC      0x80
// Analog Watchdog flag
#define AWD      0x40
// Interrupt enable for EOC
#define EOCIE    0x20
// Analog watchdog interrupt enable
#define AWDIE    0x10
// Channel selection bits
#define CH_AIN0  0x00
#define CH_AIN1  0x01
#define CH_AIN2  0x02
#define CH_AIN3  0x03
#define CH_AIN4  0x04
#define CH_AIN5  0x05
#define CH_AIN6  0x06
#define CH_AIN7  0x07
#define CH_AIN8  0x08
#define CH_AIN9  0x09
#define CH_AIN10 0x0a
#define CH_AIN11 0x0b
#define CH_AIN12 0x0c
#define CH_AIN13 0x0d
#define CH_AIN14 0x0e
#define CH_AIN15 0x0f

/* ADC configuration register 1 */
#define ADC1_CR1    MMIO32(ADC1_BASE + 0x21)
#define ADC2_CR1    MMIO32(ADC2_BASE + 0x21)
// Prescaler selection
#define SPSEL_DIV2  0x00
#define SPSEL_DIV3  0x10
#define SPSEL_DIV4  0x20
#define SPSEL_DIV6  0x30
#define SPSEL_DIV8  0x40
#define SPSEL_DIV10 0x50
#define SPSEL_DIV12 0x60
#define SPSEL_DIV18 0x70
// Continuous conversion
#define CONT        0x02
// A/D Converter on/off
#define ADON        0x01

/* ADC configuration register 2 */
#define ADC1_CR2    MMIO32(ADC1_BASE + 0x22)
#define ADC2_CR2    MMIO32(ADC2_BASE + 0x22)
// External trigger enable
#define EXTTRIG     0x40
// External event selection
#define EXTSEL_INT  0x00
#define EXTSEL_EXT  0x10
// Data alignment
#define ALIGN       0x08
// Scan mode enable
#define SCAN        0x02

/* ADC configuration register 3 */
#define ADC1_CR3    MMIO32(ADC1_BASE + 0x23)
#define ADC2_CR3    MMIO32(ADC2_BASE + 0x23)
// Data buffer enable
#define DBUF    0x80
// Overrun flag
#define OVR     0x40

/* ADC data register high */
#define ADC1_DRH    MMIO32(ADC1_BASE + 0x24)
#define ADC2_DRH    MMIO32(ADC2_BASE + 0x24)
/* ADC data register low */
#define ADC1_DRL    MMIO32(ADC1_BASE + 0x25)
#define ADC2_DRL    MMIO32(ADC2_BASE + 0x25)

/* ADC Schmitt trigger disable register high */
#define ADC1_TDRH   MMIO32(ADC1_BASE + 0x26)
#define ADC2_TDRH   MMIO32(ADC2_BASE + 0x26)
/* ADC Schmitt trigger disable register low */
#define ADC1_TDRL   MMIO32(ADC1_BASE + 0x27)
#define ADC2_TDRL   MMIO32(ADC2_BASE + 0x27)

/* ADC high threshold register high */
#define ADC1_HTRH   MMIO32(ADC1_BASE + 0x28)
/* ADC high threshold register low */
#define ADC1_HTRL   MMIO32(ADC1_BASE + 0x29)
/* ADC low threshold register high */
#define ADC1_LTRH   MMIO32(ADC1_BASE + 0x2a)
/* ADC low threshold register low */
#define ADC1_LTRL   MMIO32(ADC1_BASE + 0x2b)

/* ADC watchdog status register high */
#define ADC1_AWSRH  MMIO32(ADC1_BASE + 0x2c)
/* ADC watchdog status register low */
#define ADC1_AWSRL  MMIO32(ADC1_BASE + 0x2d)

/* ADC watchdog control register high */
#define ADC1_AWCRH  MMIO32(ADC1_BASE + 0x2e)
/* ADC watchdog control register low */
#define ADC1_AWCRL  MMIO32(ADC1_BASE + 0x2f)

#endif
