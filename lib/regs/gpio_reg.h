#ifndef H_GPIO_REG
#define H_GPIO_REG
/*
 * Part of old-school 8-bit transformer battery charger. STM8 GPIO register
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

/* registers of porta */
/* Port A output data register */
#define PA_ODR  MMIO32(PORTA_BASE + 0x00)
/* Port A pin input register */
#define PA_IDR  MMIO32(PORTA_BASE + 0x01)
/* Port A data direction register */
#define PA_DDR  MMIO32(PORTA_BASE + 0x02)
/* Port A control register 1 */
#define PA_CR1  MMIO32(PORTA_BASE + 0x03)
/* Port A control register 2 */
#define PA_CR2  MMIO32(PORTA_BASE + 0x04)
#define GPIO0   0x01
#define GPIO1   0x02
#define GPIO2   0x04
#define GPIO3   0x08
#define GPIO4   0x10
#define GPIO5   0x20
#define GPIO6   0x40
#define GPIO7   0x80
#define GPIOALL 0xff

/* registers of portb */
#define PB_ODR  MMIO32(PORTB_BASE + 0x00)
#define PB_IDR  MMIO32(PORTB_BASE + 0x01)
#define PB_DDR  MMIO32(PORTB_BASE + 0x02)
#define PB_CR1  MMIO32(PORTB_BASE + 0x03)
#define PB_CR2  MMIO32(PORTB_BASE + 0x04)
/* registers of portc */
#define PC_ODR  MMIO32(PORTC_BASE + 0x00)
#define PC_IDR  MMIO32(PORTC_BASE + 0x01)
#define PC_DDR  MMIO32(PORTC_BASE + 0x02)
#define PC_CR1  MMIO32(PORTC_BASE + 0x03)
#define PC_CR2  MMIO32(PORTC_BASE + 0x04)
/* registers of portd */
#define PD_ODR  MMIO32(PORTD_BASE + 0x00)
#define PD_IDR  MMIO32(PORTD_BASE + 0x01)
#define PD_DDR  MMIO32(PORTD_BASE + 0x02)
#define PD_CR1  MMIO32(PORTD_BASE + 0x03)
#define PD_CR2  MMIO32(PORTD_BASE + 0x04)
/* registers of porte */
#define PE_ODR  MMIO32(PORTE_BASE + 0x00)
#define PE_IDR  MMIO32(PORTE_BASE + 0x01)
#define PE_DDR  MMIO32(PORTE_BASE + 0x02)
#define PE_CR1  MMIO32(PORTE_BASE + 0x03)
#define PE_CR2  MMIO32(PORTE_BASE + 0x04)
/* registers of portf */
#define PF_ODR  MMIO32(PORTF_BASE + 0x00)
#define PF_IDR  MMIO32(PORTF_BASE + 0x01)
#define PF_DDR  MMIO32(PORTF_BASE + 0x02)
#define PF_CR1  MMIO32(PORTF_BASE + 0x03)
#define PF_CR2  MMIO32(PORTF_BASE + 0x04)
/* registers of portn */
#define P_ODR(n)  MMIO32(PORTA_BASE + 5*n + 0x00)
#define P_IDR(n)  MMIO32(PORTA_BASE + 5*n + 0x01)
#define P_DDR(n)  MMIO32(PORTA_BASE + 5*n + 0x02)
#define P_CR2(n)  MMIO32(PORTA_BASE + 5*n + 0x04)
#define P_CR1(n)  MMIO32(PORTA_BASE + 5*n + 0x03)


#endif
