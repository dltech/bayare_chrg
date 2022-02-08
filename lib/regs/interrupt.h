/*
 * Part of old-school 8-bit transformer battery charger. Interrupt vectors of
 * STM8.
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

/* Interrupt vectors */
#define TLI_ITN         0
#define AWU_ITN         1
#define CLK_ITN         2
#define EXTI0_ITN       3
#define EXTI1_ITN       4
#define EXTI2_ITN       5
#define EXTI3_ITN       6
#define EXTI4_ITN       7
#define SPI_ITN         10
#define TIM1_UPD_ITN    11
#define TIM1_CC_ITN     12
#define TIM2_UPD_ITN    13
#define TIM2_CC_ITN     14
#define UART1_TX_ITN    17
#define UART1_RX_ITN    18
#define I2C_ITN         19
#define ADC1_ITN        22
#define TIM4_ITN        23
#define FLASH_ITN       24

/* Interrupt registers */
/* Software priority register n */
#define ITC_SPR1    MMIO8(ITC_BASE + 0x00)
#define ITC_SPR2    MMIO8(ITC_BASE + 0x01)
#define ITC_SPR3    MMIO8(ITC_BASE + 0x02)
#define ITC_SPR4    MMIO8(ITC_BASE + 0x03)
#define ITC_SPR5    MMIO8(ITC_BASE + 0x04)
#define ITC_SPR6    MMIO8(ITC_BASE + 0x05)
#define ITC_SPR7    MMIO8(ITC_BASE + 0x06)
#define ITC_SPR8    MMIO8(ITC_BASE + 0x07)

/* External interrupt control register 1 */
#define EXTI_CR1    MMIO8(EXTI_BASE + 0x00)
// Port D external interrupt sensitivity bits
#define PDIS_FALL_LOW   0x00
#define PDIS_RISE       0x40
#define PDIS_FALL       0x80
#define PDIS_RISE_FALL  0xc0
// Port C external interrupt sensitivity bits
#define PCIS_FALL_LOW   0x00
#define PCIS_RISE       0x10
#define PCIS_FALL       0x20
#define PCIS_RISE_FALL  0x30
// Port B external interrupt sensitivity bits
#define PBIS_FALL_LOW   0x00
#define PBIS_RISE       0x04
#define PBIS_FALL       0x08
#define PBIS_RISE_FALL  0x0c
// Port A external interrupt sensitivity bits
#define PAIS_FALL_LOW   0x00
#define PAIS_RISE       0x01
#define PAIS_FALL       0x02
#define PAIS_RISE_FALL  0x03

/* External interrupt control register 2 */
#define EXTI_CR2    MMIO8(EXTI_BASE + 0x01)
// Top level interrupt sensitivity
#define TLIS            0x4
// Port E external interrupt sensitivity bits
#define PEIS_FALL_LOW   0x0
#define PEIS_RISE       0x1
#define PEIS_FALL       0x2
#define PEIS_RISE_FALL  0x3

//void ext_port_d(void) __interrupt(6)
