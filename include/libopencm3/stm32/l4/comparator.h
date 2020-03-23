/** @defgroup comp_defines COMP Defines
 *
 * @brief <b>libopencm3 Defined Constants and Types for the STM32L4xx
 * Comparator module</b>
 *
 * @ingroup STM32F3xx_defines
 *
 * @version 1.0.0
 *
 * @date 24 Mar 2020
 *
 *LGPL License Terms @ref lgpl_license
 */
/*
 * This file is part of the libopencm3 project.
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBOPENCM3_COMP_H
#define LIBOPENCM3_COMP_H
/**@{*/

#define COMP1				(COMP_BASE + 0x00)
#define COMP2				(COMP_BASE + 0x04)

/* Comparator registers */

/* Control and status register (COMPx_CSR) */
#define COMP_CSR(comp_base)		MMIO32((comp_base) + 0x00)
#define COMP1_CSR			COMP_CSR(COMP1)
#define COMP2_CSR			COMP_CSR(COMP2)

/* COMPx_CSR values */

#define COMP_CSR_LOCK			(0x1 << 31)
#define COMP_CSR_OUT			(0x1 << 30)

/* individual blanking sources depends on COMP used */
#define COMP_CSR_BLANKING_MASK		(0x7)
#define COMP_CSR_BLANKING_SHIFT		(18)
#define COMP_CSR_BLANKING_NONE		(0x0)
#define COMP_CSR_BLANKING(blanking)	(((blanking) & COMP_CSR_BLANKING_MASK) << COMP_CSR_BLANKING_SHIFT)

#define COMP_CSR_HYST_NONE		(0x0)
#define COMP_CSR_HYST_LOW		(0x1)
#define COMP_CSR_HYST_MEDIUM		(0x2)
#define COMP_CSR_HYST_HIGH		(0x3)
#define COMP_CSR_HYST_MASK		(0x3)
#define COMP_CSR_HYST_SHIFT		(16)

#define COMP_CSR_POL			(0x1 << 15)

/* only on COMP2 */
#define COMP_CSR_WINMODE		(0x1 << 9)

#define COMP_CSR_INPSEL(inpsel)		(((inpsel) & 0x3) << 7)
#define COMP_CSR_INPSEL_MASK		(0x3 << 7)
#define COMP_CSR_INPSEL_PC5		(0x0 << 7)
#define COMP_CSR_INPSEL_PB2		(0x1 << 7)
#define COMP_CSR_INPSEL_PA1		(0x2 << 7)

#define COMP_CSR_INMSEL(inmsel)		((((inmsel) & 0x7) << 4) | \
					 ((((inmsel) & 0x8) >> 3) << 25))
#define COMP_CSR_INMSEL_MASK		((0x3 << 25) | (0x7 << 4))

#define COMP_CSR_INMSEL_GPIO		(0x7)
#define COMP_CSR_INMSEL_GPIO_PC4	((0x0 << 3) | COMP_CSR_INMSEL_GPIO)
#define COMP_CSR_INMSEL_GPIO_PA0	((0x1 << 3) | COMP_CSR_INMSEL_GPIO)
#define COMP_CSR_INMSEL_GPIO_PA4	((0x2 << 3) | COMP_CSR_INMSEL_GPIO)
#define COMP_CSR_INMSEL_GPIO_PA5	((0x3 << 3) | COMP_CSR_INMSEL_GPIO)

#define COMP_CSR_MODE_HIGHSPEED		(0x0)
#define COMP_CSR_MODE_MEDIUMSPEED	(0x1)
#define COMP_CSR_MODE_LOWSPEED		(0x2)
#define COMP_CSR_MODE_ULTRALOWPOWER	(0x3)
#define COMP_CSR_MODE_MASK		(0x3)
#define COMP_CSR_MODE_SHIFT		(2)

#define COMP_CSR_EN			(0x1 << 0)

void comp_enable(uint8_t id);
void comp_disable(uint8_t id);
void comp_select_inm(uint8_t id, uint32_t input);
void comp_select_inp(uint8_t id, uint32_t input);
void comp_select_hyst(uint8_t id, uint32_t hyst);
void comp_select_speed(uint8_t id, uint32_t speed);

/**@}*/
#endif
