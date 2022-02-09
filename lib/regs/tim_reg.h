#ifndef H_TIM_REG
#define H_TIM_REG
/*
 * Part of old-school 8-bit transformer battery charger. STM8 timer register
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

/*****************TIM1************************/

/* Control register 1 */
#define TIM1_CR1    MMIO32(TIM1_BASE + 0x00)
// Auto-reload preload enable
#define ARPE    0x80
// Center-aligned mode selection
#define CMS_EDGE                0x00
#define CMS_CENTER_ACTIVE_DN    0x20
#define CMS_CENTER_ACTIVE_UP    0x40
#define CMS_CENTER_ACTIVE_BOTH  0x60
// Direction
#define DIR     0x10
// One-pulse mode
#define OPM     0x08
// Update request source
#define URS     0x04
// Update disable
#define UDIS    0x02
// Counter enable
#define CEN     0x01

/* Control register 2 */
#define TIM1_CR2    MMIO32(TIM1_BASE + 0x01)
// Master mode selection
#define MMS_RESET   0x00
#define MMS_ENABLE  0x10
#define MMS_UPDATE  0x20
#define MMS_COMPARE 0x30
#define MMS_OC1REF  0x40
#define MMS_OC2REF  0x50
#define MMS_OC3REF  0x60
#define MMS_OC4REF  0x70
// Capture/compare control update selection
#define COMS        0x04
// Capture/compare preloaded control
#define CCPC        0x01

/* Slave mode control register */
#define TIM1_SMCR   MMIO32(TIM1_BASE + 0x02)
// Master/slave mode
#define MSM     0x80
// Trigger selection
#define TS_TIM6     0x00
#define TS_TIM5     0x30
#define TS_TI1F_ED  0x40
#define TS_TI1FP1   0x50
#define TS_TI2FP2   0x60
#define ETRF        0x70
// Clock/trigger/slave mode selection
#define SMS_DISABLE          0x00
#define SMS_ENCODER1         0x01
#define SMS_ENCODER2         0x02
#define SMS_ENCODER3         0x03
#define SMS_RESET            0x04
#define SMS_TRIGGER_GATED    0x05
#define SMS_TRIGGER_STANDARD 0x06
#define SMS_EXTERNAL         0x07

/* External trigger register */
#define TIM1_ETR    MMIO32(TIM1_BASE + 0x03)
// External trigger polarity
#define ETP     0x80
// External clock enable
#define ECE     0x40
// External trigger prescaler
#define ETPS_OFF    0x00
#define ETPS_DIV2   0x10
#define ETPS_DIV4   0x20
#define ETPS_DIV8   0x30
// External trigger filter
#define ETF_DIS         0x00
#define ETF_FM_N2       0x01
#define ETF_FM_N4       0x02
#define ETF_FM_N8       0x03
#define ETF_FMD2_N6     0x04
#define ETF_FMD2_N8     0x05
#define ETF_FMD4_N6     0x06
#define ETF_FMD4_N8     0x07
#define ETF_FMD8_N6     0x08
#define ETF_FMD8_N8     0x09
#define ETF_FMD16_N5    0x0a
#define ETF_FMD16_N6    0x0b
#define ETF_FMD16_N8    0x0c
#define ETF_FMD32_N5    0x0d
#define ETF_FMD32_N6    0x0e
#define ETF_FMD32_N8    0x0f

/* Interrupt enable register */
#define TIM1_IER    MMIO32(TIM1_BASE + 0x04)
// Break interrupt enable
#define BIE     0x80
// Trigger interrupt enable
#define TIE     0x40
// Commutation interrupt enable
#define COMIE   0x20
// Capture/compare 4 interrupt enable
#define CC4IE   0x10
// Capture/compare 3 interrupt enable
#define CC3IE   0x08
// Capture/compare 2 interrupt enable
#define CC2IE   0x04
// Capture/compare 1 interrupt enable
#define CC1IE   0x02
// Update interrupt enable
#define UIE     0x01

/* Status register 1 */
#define TIM1_SR1    MMIO32(TIM1_BASE + 0x05)
// Break interrupt enable
#define BIF     0x80
// Trigger interrupt enable
#define TIF     0x40
// Commutation interrupt enable
#define COMIF   0x20
// Capture/compare 4 interrupt enable
#define CC4IF   0x10
// Capture/compare 3 interrupt enable
#define CC3IF   0x08
// Capture/compare 2 interrupt enable
#define CC2IF   0x04
// Capture/compare 1 interrupt enable
#define CC1IF   0x02
// Update interrupt enable
#define UIF     0x01

/* Status register 2 */
#define TIM1_SR2    MMIO32(TIM1_BASE + 0x06)
// Capture/compare 4 interrupt enable
#define CC4OF   0x10
// Capture/compare 3 interrupt enable
#define CC3OF   0x08
// Capture/compare 2 interrupt enable
#define CC2OF   0x04
// Capture/compare 1 interrupt enable
#define CC1OF   0x02

/* Event generation register */
#define TIM1_EGR    MMIO32(TIM1_BASE + 0x07)
// Break generation
#define BG      0x80
// Trigger generation
#define TG      0x40
// Capture/compare control update generation
#define COMG    0x20
// Capture/compare 4 generation
#define CC4G    0x10
// Capture/compare 3 generation
#define CC3G    0x08
// Capture/compare 2 generation
#define CC2G    0x04
// Capture/compare 1 generation
#define CC1G    0x02
// Update generation
#define UG      0x01

/* Capture/compare mode register 1 */
#define TIM1_CCMR1  MMIO32(TIM1_BASE + 0x08)
// Output compare 1 clear enable
#define OC1CE   0x80
// Output compare 1 mode
#define OC1M_FROZEN         0x00
#define OC1M_ACTIVE         0x10
#define OC1M_INACTIVE       0x20
#define OC1M_TOGGLE         0x30
#define OC1M_FORCE_INACTIVE 0x40
#define OC1M_FORCE_ACTIVE   0x50
#define OC1M_PWM1           0x60
#define OC1M_PWM2           0x70
// Output compare 1 preload enable
#define OC1PE   0x08
// Output compare 1 fast enable
#define OC1FE   0x04
// Capture/compare 1 selection
#define CC1S_OUT        0x00
#define CC1S_TI1FP1     0x01
#define CC1S_TI2FP1     0x02
#define CC1S_TRC        0x03
// Input capture 1 filter
#define IC1F_DIS        0x00
#define IC1F_FM_N2      0x10
#define IC1F_FM_N4      0x20
#define IC1F_FM_N8      0x30
#define IC1F_FMD2_N6    0x40
#define IC1F_FMD2_N8    0x50
#define IC1F_FMD4_N6    0x60
#define IC1F_FMD4_N8    0x70
#define IC1F_FMD8_N6    0x80
#define IC1F_FMD8_N8    0x90
#define IC1F_FMD16_N5   0xa0
#define IC1F_FMD16_N6   0xb0
#define IC1F_FMD16_N8   0xc0
#define IC1F_FMD32_N5   0xd0
#define IC1F_FMD32_N6   0xe0
#define IC1F_FMD32_N8   0xf0
#define IC1F_SHIFT      4
// Input capture 1 prescaler
#define IC1PSC_NO       0x00
#define IC1PSC_DIV2     0x04
#define IC1PSC_DIV4     0x08
#define IC1PSC_DIV8     0x0c

/* Capture/compare mode register 2 */
#define TIM1_CCMR2  MMIO32(TIM1_BASE + 0x09)
// Output compare 2 clear enable
#define OC2CE   0x80
// Output compare 2 mode
#define OC2M_FROZEN         0x00
#define OC2M_ACTIVE         0x10
#define OC2M_INACTIVE       0x20
#define OC2M_TOGGLE         0x30
#define OC2M_FORCE_INACTIVE 0x40
#define OC2M_FORCE_ACTIVE   0x50
#define OC2M_PWM1           0x60
#define OC2M_PWM2           0x70
// Output compare 2 preload enable
#define OC2PE   0x08
// Output compare 2 fast enable
#define OC2FE   0x04
// Capture/compare 2 selection
#define CC2S_OUT        0x00
#define CC2S_TI1FP1     0x01
#define CC2S_TI2FP1     0x02
#define CC2S_TRC        0x03
// Input capture 2 filter
#define IC2F_DIS        0x00
#define IC2F_FM_N2      0x10
#define IC2F_FM_N4      0x20
#define IC2F_FM_N8      0x30
#define IC2F_FMD2_N6    0x40
#define IC2F_FMD2_N8    0x50
#define IC2F_FMD4_N6    0x60
#define IC2F_FMD4_N8    0x70
#define IC2F_FMD8_N6    0x80
#define IC2F_FMD8_N8    0x90
#define IC2F_FMD16_N5   0xa0
#define IC2F_FMD16_N6   0xb0
#define IC2F_FMD16_N8   0xc0
#define IC2F_FMD32_N5   0xd0
#define IC2F_FMD32_N6   0xe0
#define IC2F_FMD32_N8   0xf0
#define IC2F_SHIFT      4
// Input capture 2 prescaler
#define IC2PSC_NO       0x00
#define IC2PSC_DIV2     0x04
#define IC2PSC_DIV4     0x08
#define IC2PSC_DIV8     0x0c

/* Capture/compare mode register 3 */
#define TIM1_CCMR3  MMIO32(TIM1_BASE + 0x0a)
// Output compare 3 clear enable
#define OC3CE   0x80
// Output compare 3 mode
#define OC3M_FROZEN         0x00
#define OC3M_ACTIVE         0x10
#define OC3M_INACTIVE       0x20
#define OC3M_TOGGLE         0x30
#define OC3M_FORCE_INACTIVE 0x40
#define OC3M_FORCE_ACTIVE   0x50
#define OC3M_PWM1           0x60
#define OC3M_PWM2           0x70
// Output compare 3 preload enable
#define OC3PE   0x08
// Output compare 3 fast enable
#define OC3FE   0x04
// Capture/compare 3 selection
#define CC3S_OUT        0x00
#define CC3S_TI1FP1     0x01
#define CC3S_TI2FP1     0x02
#define CC3S_TRC        0x03
// Input capture 3 filter
#define IC3F_DIS        0x00
#define IC3F_FM_N2      0x10
#define IC3F_FM_N4      0x20
#define IC3F_FM_N8      0x30
#define IC3F_FMD2_N6    0x40
#define IC3F_FMD2_N8    0x50
#define IC3F_FMD4_N6    0x60
#define IC3F_FMD4_N8    0x70
#define IC3F_FMD8_N6    0x80
#define IC3F_FMD8_N8    0x90
#define IC3F_FMD16_N5   0xa0
#define IC3F_FMD16_N6   0xb0
#define IC3F_FMD16_N8   0xc0
#define IC3F_FMD32_N5   0xd0
#define IC3F_FMD32_N6   0xe0
#define IC3F_FMD32_N8   0xf0
#define IC3F_SHIFT      4
// Input capture 3 prescaler
#define IC3PSC_NO       0x00
#define IC3PSC_DIV2     0x04
#define IC3PSC_DIV4     0x08
#define IC3PSC_DIV8     0x0c

/* Capture/compare mode register 4 */
#define TIM1_CCMR4  MMIO32(TIM1_BASE + 0x0b)
// Output compare 4 clear enable
#define OC4CE   0x80
// Output compare 4 mode
#define OC4M_FROZEN         0x00
#define OC4M_ACTIVE         0x10
#define OC4M_INACTIVE       0x20
#define OC4M_TOGGLE         0x30
#define OC4M_FORCE_INACTIVE 0x40
#define OC4M_FORCE_ACTIVE   0x50
#define OC4M_PWM1           0x60
#define OC4M_PWM2           0x70
// Output compare 4 preload enable
#define OC4PE   0x08
// Output compare 4 fast enable
#define OC4FE   0x04
// Capture/compare 4 selection
#define CC4S_OUT        0x00
#define CC4S_TI1FP1     0x01
#define CC4S_TI2FP1     0x02
#define CC4S_TRC        0x03
// Input capture 4 filter
#define IC4F_DIS        0x00
#define IC4F_FM_N2      0x10
#define IC4F_FM_N4      0x20
#define IC4F_FM_N8      0x30
#define IC4F_FMD2_N6    0x40
#define IC4F_FMD2_N8    0x50
#define IC4F_FMD4_N6    0x60
#define IC4F_FMD4_N8    0x70
#define IC4F_FMD8_N6    0x80
#define IC4F_FMD8_N8    0x90
#define IC4F_FMD16_N5   0xa0
#define IC4F_FMD16_N6   0xb0
#define IC4F_FMD16_N8   0xc0
#define IC4F_FMD32_N5   0xd0
#define IC4F_FMD32_N6   0xe0
#define IC4F_FMD32_N8   0xf0
#define IC4F_SHIFT      4
// Input capture 4 prescaler
#define IC4PSC_NO       0x00
#define IC4PSC_DIV2     0x04
#define IC4PSC_DIV4     0x08
#define IC4PSC_DIV8     0x0c

/* Capture/compare enable register 1 */
#define TIM1_CCER1  MMIO32(TIM1_BASE + 0x0c)
// Capture/compare 2 complementary output polarity
#define CC2NP   0x80
// Capture/compare 2 complementary output enable
#define CC2NE   0x40
// Capture/compare 2 output polarity
#define CC2P    0x20
// Capture/compare 2 output enable
#define CC2E    0x10
// Capture/compare 1 complementary output polarity
#define CC1NP   0x08
// Capture/compare 1 complementary output enable
#define CC1NE   0x04
// Capture/compare 1 output polarity
#define CC1P    0x02
// Capture/compare 1 output enable
#define CC1E    0x01

/* Capture/compare enable register 2 */
#define TIM1_CCER2  MMIO32(TIM1_BASE + 0x0d)
// Capture/compare 4 output polarity
#define CC4P    0x20
// Capture/compare 4 output enable
#define CC4E    0x10
// Capture/compare 3 complementary output polarity
#define CC3NP   0x08
// Capture/compare 3 complementary output enable
#define CC3NE   0x04
// Capture/compare 3 output polarity
#define CC3P    0x02
// Capture/compare 3 output enable
#define CC3E    0x01

/* Counter high */
#define TIM1_CNTRH  MMIO32(TIM1_BASE + 0x0e)
/* Counter low */
#define TIM1_CNTRL  MMIO32(TIM1_BASE + 0x0f)

/* Prescaler high */
#define TIM1_PSCRH  MMIO32(TIM1_BASE + 0x10)
/* Prescaler low */
#define TIM1_PSCRL  MMIO32(TIM1_BASE + 0x11)

/* Auto-reload register high */
#define TIM1_ARRH   MMIO32(TIM1_BASE + 0x12)
/* Auto-reload register low */
#define TIM1_ARRL   MMIO32(TIM1_BASE + 0x13)

/* Repetition counter register */
#define TIM1_RCR    MMIO32(TIM1_BASE + 0x14)

/* Capture/compare register 1 high */
#define TIM1_CCR1H  MMIO32(TIM1_BASE + 0x15)
/* Capture/compare register 1 low */
#define TIM1_CCR1L  MMIO32(TIM1_BASE + 0x16)
/* Capture/compare register 2 high */
#define TIM1_CCR2H  MMIO32(TIM1_BASE + 0x17)
/* Capture/compare register 2 low */
#define TIM1_CCR2L  MMIO32(TIM1_BASE + 0x18)
/* Capture/compare register 3 high */
#define TIM1_CCR3H  MMIO32(TIM1_BASE + 0x19)
/* Capture/compare register 3 low */
#define TIM1_CCR3L  MMIO32(TIM1_BASE + 0x1a)
/* Capture/compare register 4 high */
#define TIM1_CCR4H  MMIO32(TIM1_BASE + 0x1b)
/* Capture/compare register 4 low */
#define TIM1_CCR4L  MMIO32(TIM1_BASE + 0x1c)

/* Break register */
#define TIM1_BKR    MMIO32(TIM1_BASE + 0x1d)
// Main output enable
#define MOE         0x80
// Automatic output enable
#define AOE         0x40
// Break polarity
#define BKP         0x20
// Break enable
#define BKE         0x10
// Off state selection for Run mode
#define OSSR        0x08
// Off state selection for idle mode
#define OSSI        0x04
// Lock configuration
#define LOCK_OFF    0x00
#define LOCK_LVL1   0x01
#define LOCK_LVL2   0x02
#define LOCK_LVL3   0x03

/* Deadtime register */
#define TIM1_DTR    MMIO32(TIM1_BASE + 0x1e)

/* Output idle state register */
#define TIM1_OISR   MMIO32(TIM1_BASE + 0x1f)
// Output idle state 4 (OC4 output)
#define OIS4    0x40
// Output idle state 3 (OC3N output)
#define OIS3N   0x20
// Output idle state 3 (OC3 output)
#define OIS3    0x10
// Output idle state 2 (OC2N output)
#define OIS2N   0x08
// Output idle state 2 (OC2 output)
#define OIS2    0x04
// Output idle state 1 (OC1N output)
#define OIS1N   0x02
// Output idle state 1 (OC1 output)
#define OIS1    0x01

/***************************TIM2/3/5***************************/

/* Control register 1 */
#define TIM2_CR1    MMIO32(TIM2_BASE + 0x00)
#define TIM3_CR1    MMIO32(TIM3_BASE + 0x00)
#define TIM5_CR1    MMIO32(TIM5_BASE + 0x00)
// Auto-reload preload enable
#define T2_ARPE    0x80
// One-pulse mode
#define T2_OPM     0x08
// Update request source
#define T2_URS     0x04
// Update disable
#define T2_UDIS    0x02
// Counter enable
#define T2_CEN     0x01

/* Control register 2 */
#define TIM5_CR2    MMIO32(TIM5_BASE + 0x01)
// Master mode selection
#define T5_MMS_ENABLE  0x10
#define T5_MMS_RESET   0x00
#define T5_MMS_UPDATE  0x20

/* Slave mode control register */
#define TIM5_SMCR   MMIO32(TIM5_BASE + 0x02)
// Master/slave mode
#define T5_MSM     0x80
// Trigger selection
#define TS_ITR0_TIM6 0x00
#define TS_ITR1_TIM6 0x30
// Clock/trigger/slave mode selection
#define T5_SMS_DISABLE          0x00
#define T5_SMS_RESET            0x04
#define T5_SMS_TRIGGER_GATED    0x05
#define T5_SMS_TRIGGER_STANDARD 0x06
#define T5_SMS_EXTERNAL         0x07

/* Interrupt enable register */
#define TIM2_IER    MMIO32(TIM2_BASE + 0x03)
#define TIM3_IER    MMIO32(TIM3_BASE + 0x03)
#define TIM5_IER    MMIO32(TIM5_BASE + 0x03)
// Trigger interrupt enable
#define T2_TIE     0x40
// Capture/compare 3 interrupt enable
#define T2_CC3IE   0x08
// Capture/compare 2 interrupt enable
#define T2_CC2IE   0x04
// Capture/compare 1 interrupt enable
#define T2_CC1IE   0x02
// Update interrupt enable
#define T2_UIE     0x01

/* Status register 1 */
#define TIM2_SR1    MMIO32(TIM2_BASE + 0x04)
#define TIM3_SR1    MMIO32(TIM3_BASE + 0x04)
#define TIM5_SR1    MMIO32(TIM5_BASE + 0x04)
// Trigger interrupt enable
#define T2_TIF     0x40
// Capture/compare 3 interrupt enable
#define T2_CC3IF   0x08
// Capture/compare 2 interrupt enable
#define T2_CC2IF   0x04
// Capture/compare 1 interrupt enable
#define T2_CC1IF   0x02
// Update interrupt enable
#define T2_UIF     0x01

/* Status register 2 */
#define TIM2_SR2    MMIO32(TIM2_BASE + 0x05)
#define TIM3_SR2    MMIO32(TIM3_BASE + 0x05)
#define TIM5_SR2    MMIO32(TIM5_BASE + 0x05)
// Capture/compare 3 interrupt enable
#define T2_CC3OF   0x08
// Capture/compare 2 interrupt enable
#define T2_CC2OF   0x04
// Capture/compare 1 interrupt enable
#define T2_CC1OF   0x02

/* Event generation register */
#define TIM2_EGR    MMIO32(TIM2_BASE + 0x06)
#define TIM3_EGR    MMIO32(TIM3_BASE + 0x06)
#define TIM5_EGR    MMIO32(TIM5_BASE + 0x06)
// Trigger generation
#define T2_TG      0x40
// Capture/compare 3 generation
#define T2_CC3G    0x08
// Capture/compare 2 generation
#define T2_CC2G    0x04
// Capture/compare 1 generation
#define T2_CC1G    0x02
// Update generation
#define T2_UG      0x01

/* Capture/compare mode register 1 */
#define TIM2_CCMR1  MMIO32(TIM2_BASE + 0x07)
#define TIM3_CCMR1  MMIO32(TIM3_BASE + 0x07)
#define TIM5_CCMR1  MMIO32(TIM5_BASE + 0x07)
// Output compare 1 mode
#define T2_OC1M_FROZEN         0x00
#define T2_OC1M_ACTIVE         0x10
#define T2_OC1M_INACTIVE       0x20
#define T2_OC1M_TOGGLE         0x30
#define T2_OC1M_FORCE_INACTIVE 0x40
#define T2_OC1M_FORCE_ACTIVE   0x50
#define T2_OC1M_PWM1           0x60
#define T2_OC1M_PWM2           0x70
// Output compare 1 preload enable
#define T2_OC1PE   0x08
// Capture/compare 1 selection
#define T2_CC1S_OUT        0x00
#define T2_CC1S_TI1FP1     0x01
#define T2_CC1S_TI2FP1     0x02
#define T2_CC1S_TRC        0x03
// Input capture 1 filter
#define T2_IC1F_DIS        0x00
#define T2_IC1F_FM_N2      0x10
#define T2_IC1F_FM_N4      0x20
#define T2_IC1F_FM_N8      0x30
#define T2_IC1F_FMD2_N6    0x40
#define T2_IC1F_FMD2_N8    0x50
#define T2_IC1F_FMD4_N6    0x60
#define T2_IC1F_FMD4_N8    0x70
#define T2_IC1F_FMD8_N6    0x80
#define T2_IC1F_FMD8_N8    0x90
#define T2_IC1F_FMD16_N5   0xa0
#define T2_IC1F_FMD16_N6   0xb0
#define T2_IC1F_FMD16_N8   0xc0
#define T2_IC1F_FMD32_N5   0xd0
#define T2_IC1F_FMD32_N6   0xe0
#define T2_IC1F_FMD32_N8   0xf0
#define T2_IC1F_SHIFT      4
// Input capture 1 prescaler
#define T2_IC1PSC_NO       0x00
#define T2_IC1PSC_DIV2     0x04
#define T2_IC1PSC_DIV4     0x08
#define T2_IC1PSC_DIV8     0x0c

/* Capture/compare mode register 2 */
#define TIM2_CCMR2  MMIO32(TIM2_BASE + 0x08)
#define TIM3_CCMR2  MMIO32(TIM3_BASE + 0x08)
#define TIM5_CCMR2  MMIO32(TIM5_BASE + 0x08)
// Output compare 2 mode
#define T2_OC2M_FROZEN         0x00
#define T2_OC2M_ACTIVE         0x10
#define T2_OC2M_INACTIVE       0x20
#define T2_OC2M_TOGGLE         0x30
#define T2_OC2M_FORCE_INACTIVE 0x40
#define T2_OC2M_FORCE_ACTIVE   0x50
#define T2_OC2M_PWM1           0x60
#define T2_OC2M_PWM2           0x70
// Output compare 2 preload enable
#define T2_OC2PE   0x08
// Capture/compare 2 selection
#define T2_CC2S_OUT        0x00
#define T2_CC2S_TI1FP1     0x01
#define T2_CC2S_TI2FP1     0x02
#define T2_CC2S_TRC        0x03
// Input capture 2 filter
#define T2_IC2F_DIS        0x00
#define T2_IC2F_FM_N2      0x10
#define T2_IC2F_FM_N4      0x20
#define T2_IC2F_FM_N8      0x30
#define T2_IC2F_FMD2_N6    0x40
#define T2_IC2F_FMD2_N8    0x50
#define T2_IC2F_FMD4_N6    0x60
#define T2_IC2F_FMD4_N8    0x70
#define T2_IC2F_FMD8_N6    0x80
#define T2_IC2F_FMD8_N8    0x90
#define T2_IC2F_FMD16_N5   0xa0
#define T2_IC2F_FMD16_N6   0xb0
#define T2_IC2F_FMD16_N8   0xc0
#define T2_IC2F_FMD32_N5   0xd0
#define T2_IC2F_FMD32_N6   0xe0
#define T2_IC2F_FMD32_N8   0xf0
#define T2_IC2F_SHIFT      4
// Input capture 2 prescaler
#define T2_IC2PSC_NO       0x00
#define T2_IC2PSC_DIV2     0x04
#define T2_IC2PSC_DIV4     0x08
#define T2_IC2PSC_DIV8     0x0c

/* Capture/compare mode register 3 */
#define TIM2_CCMR3  MMIO32(TIM2_BASE + 0x09)
#define TIM3_CCMR3  MMIO32(TIM3_BASE + 0x09)
#define TIM5_CCMR3  MMIO32(TIM5_BASE + 0x09)
// Output compare 3 mode
#define T2_OC3M_FROZEN         0x00
#define T2_OC3M_ACTIVE         0x10
#define T2_OC3M_INACTIVE       0x20
#define T2_OC3M_TOGGLE         0x30
#define T2_OC3M_FORCE_INACTIVE 0x40
#define T2_OC3M_FORCE_ACTIVE   0x50
#define T2_OC3M_PWM1           0x60
#define T2_OC3M_PWM2           0x70
// Output compare 3 preload enable
#define T2_OC3PE   0x08
// Capture/compare 3 selection
#define T2_CC3S_OUT        0x00
#define T2_CC3S_TI1FP1     0x01
#define T2_CC3S_TI2FP1     0x02
#define T2_CC3S_TRC        0x03
// Input capture 3 filter
#define T2_IC3F_DIS        0x00
#define T2_IC3F_FM_N2      0x10
#define T2_IC3F_FM_N4      0x20
#define T2_IC3F_FM_N8      0x30
#define T2_IC3F_FMD2_N6    0x40
#define T2_IC3F_FMD2_N8    0x50
#define T2_IC3F_FMD4_N6    0x60
#define T2_IC3F_FMD4_N8    0x70
#define T2_IC3F_FMD8_N6    0x80
#define T2_IC3F_FMD8_N8    0x90
#define T2_IC3F_FMD16_N5   0xa0
#define T2_IC3F_FMD16_N6   0xb0
#define T2_IC3F_FMD16_N8   0xc0
#define T2_IC3F_FMD32_N5   0xd0
#define T2_IC3F_FMD32_N6   0xe0
#define T2_IC3F_FMD32_N8   0xf0
#define T2_IC3F_SHIFT      4
// Input capture 3 prescaler
#define T2_IC3PSC_NO       0x00
#define T2_IC3PSC_DIV2     0x04
#define T2_IC3PSC_DIV4     0x08
#define T2_IC3PSC_DIV8     0x0c

/* Capture/compare enable register 1 */
#define TIM2_CCER1  MMIO32(TIM2_BASE + 0x0a)
#define TIM3_CCER1  MMIO32(TIM3_BASE + 0x0a)
#define TIM5_CCER1  MMIO32(TIM5_BASE + 0x0a)
// Capture/compare 2 output polarity
#define T2_CC2P    0x20
// Capture/compare 2 output enable
#define T2_CC2E    0x10
// Capture/compare 1 output polarity
#define T2_CC1P    0x02
// Capture/compare 1 output enable
#define T2_CC1E    0x01

/* Capture/compare enable register 2 */
#define TIM2_CCER2  MMIO32(TIM2_BASE + 0x0b)
#define TIM3_CCER2  MMIO32(TIM3_BASE + 0x0b)
#define TIM5_CCER2  MMIO32(TIM5_BASE + 0x0b)
// Capture/compare 3 output polarity
#define T2_CC3P    0x02
// Capture/compare 3 output enable
#define T2_CC3E    0x01

/* Counter high */
#define TIM2_CNTRH  MMIO32(TIM2_BASE + 0x0c)
#define TIM3_CNTRH  MMIO32(TIM3_BASE + 0x0c)
#define TIM5_CNTRH  MMIO32(TIM5_BASE + 0x0c)
/* Counter low */
#define TIM2_CNTRL  MMIO32(TIM2_BASE + 0x0d)
#define TIM3_CNTRL  MMIO32(TIM3_BASE + 0x0d)
#define TIM5_CNTRL  MMIO32(TIM5_BASE + 0x0d)

/* Prescaler register */
#define TIM2_PSCR   MMIO32(TIM2_BASE + 0x0e)
#define TIM3_PSCR   MMIO32(TIM3_BASE + 0x0e)
#define TIM5_PSCR   MMIO32(TIM5_BASE + 0x0e)

/* Auto-reload register high */
#define TIM2_ARRH   MMIO32(TIM2_BASE + 0x0f)
#define TIM3_ARRH   MMIO32(TIM3_BASE + 0x0f)
#define TIM5_ARRH   MMIO32(TIM5_BASE + 0x0f)
/* Auto-reload register low */
#define TIM2_ARRL   MMIO32(TIM2_BASE + 0x10)
#define TIM3_ARRL   MMIO32(TIM3_BASE + 0x10)
#define TIM5_ARRL   MMIO32(TIM5_BASE + 0x10)

/* Capture/compare register 1 high */
#define TIM2_CCR1H  MMIO32(TIM2_BASE + 0x11)
#define TIM3_CCR1H  MMIO32(TIM3_BASE + 0x11)
#define TIM5_CCR1H  MMIO32(TIM5_BASE + 0x11)
/* Capture/compare register 1 low */
#define TIM2_CCR1L  MMIO32(TIM2_BASE + 0x12)
#define TIM3_CCR1L  MMIO32(TIM3_BASE + 0x12)
#define TIM5_CCR1L  MMIO32(TIM5_BASE + 0x12)

/* Capture/compare register 2 high */
#define TIM2_CCR2H  MMIO32(TIM2_BASE + 0x13)
#define TIM3_CCR2H  MMIO32(TIM3_BASE + 0x13)
#define TIM5_CCR2H  MMIO32(TIM5_BASE + 0x13)
/* Capture/compare register 2 low */
#define TIM2_CCR2L  MMIO32(TIM2_BASE + 0x14)
#define TIM3_CCR2L  MMIO32(TIM3_BASE + 0x14)
#define TIM5_CCR2L  MMIO32(TIM5_BASE + 0x14)

/* Capture/compare register 3 high */
#define TIM2_CCR3H  MMIO32(TIM2_BASE + 0x15)
#define TIM3_CCR3H  MMIO32(TIM3_BASE + 0x15)
#define TIM5_CCR3H  MMIO32(TIM5_BASE + 0x15)
/* Capture/compare register 3 low */
#define TIM2_CCR3L  MMIO32(TIM2_BASE + 0x16)
#define TIM3_CCR3L  MMIO32(TIM3_BASE + 0x16)
#define TIM5_CCR3L  MMIO32(TIM5_BASE + 0x16)

/***************************TIM4***************************/
/* Control register 1 */
#define TIM4_CR1    MMIO32(TIM4_BASE + 0x00)
#define TIM6_CR1    MMIO32(TIM6_BASE + 0x00)
// Auto-reload preload enable
#define T4_ARPE    0x80
// One-pulse mode
#define T4_OPM     0x08
// Update request source
#define T4_URS     0x04
// Update disable
#define T4_UDIS    0x02
// Counter enable
#define T4_CEN     0x01

/* Control register 2 */
#define TIM6_CR2    MMIO32(TIM6_BASE + 0x01)
// Master mode selection
#define T6_MMS_ENABLE  0x10
#define T6_MMS_RESET   0x00
#define T6_MMS_UPDATE  0x20

/* Slave mode control register */
#define TIM6_SMCR   MMIO32(TIM6_BASE + 0x02)
// Master/slave mode
#define T6_MSM     0x80
// Trigger selection
#define TS_ITR1_TIM1 0x10
#define TS_ITR3_TIM5 0x30
// Clock/trigger/slave mode selection
#define T6_SMS_DISABLE          0x00
#define T6_SMS_RESET            0x04
#define T6_SMS_TRIGGER_GATED    0x05
#define T6_SMS_TRIGGER_STANDARD 0x06
#define T6_SMS_EXTERNAL         0x07

/* Interrupt enable register */
#define TIM4_IER    MMIO32(TIM4_BASE + 0x03)
#define TIM6_IER    MMIO32(TIM6_BASE + 0x03)
// Trigger interrupt enable
#define T4_TIE     0x40
// Update interrupt enable
#define T4_UIE     0x01

/* Status register 1 */
#define TIM4_SR     MMIO32(TIM4_BASE + 0x04)
#define TIM6_SR     MMIO32(TIM6_BASE + 0x04)
// Trigger interrupt enable
#define T4_TIF     0x40
// Update interrupt enable
#define T4_UIF     0x01

/* Event generation register */
#define TIM4_EGR    MMIO32(TIM4_BASE + 0x05)
#define TIM6_EGR    MMIO32(TIM6_BASE + 0x05)
// Trigger generation
#define T4_TG      0x40
// Update generation
#define T4_UG      0x01

/* Counter */
#define TIM4_CNTR   MMIO32(TIM4_BASE + 0x06)
#define TIM6_CNTR   MMIO32(TIM6_BASE + 0x06)

/* Prescaler register */
#define TIM4_PSCR   MMIO32(TIM4_BASE + 0x07)
#define TIM6_PSCR   MMIO32(TIM6_BASE + 0x07)

/* Auto-reload register */
#define TIM4_ARR    MMIO32(TIM4_BASE + 0x08)
#define TIM6_ARR    MMIO32(TIM6_BASE + 0x08)


#endif
