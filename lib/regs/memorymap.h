#ifndef H_MEMORYMAP
#define H_MEMORYMAP
/*
 * Part of old-school 8-bit transformer battery charger. STM8S003F3
 * memory addresses.
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

#define  MMIO32(addr)		(*(volatile uint32_t *)(addr))

#define PORTA_BASE  0x005000
#define PORTB_BASE  0x005005
#define PORTC_BASE  0x00500a
#define PORTD_BASE  0x00500f
#define PORTE_BASE  0x005014
#define PORTF_BASE  0x005019
#define FLASH_BASE  0x00505a
#define EXTI_BASE   0x0050a0
#define CLK_BASE    0x0050c0
#define WWDG_BASE   0x0050d1
#define IWDG_BASE   0x0050e0
#define AWU_BASE    0x0050f0
#define BEEP_BASE   0x0050f3
#define SPI_BASE    0x005200
#define I2C_BASE    0x005210
#define UART1_BASE  0x005230
#define TIM1_BASE   0x005250
#define TIM2_BASE   0x005300
#define TIM4_BASE   0x005340
#define ADC1_BASE   0x0053e0
#define CPU_BASE    0x007f00
#define ITC_BASE    0x007f70
#define SWIM_BASE   0x007f80
#define DM_BASE     0x007f90

#endif
