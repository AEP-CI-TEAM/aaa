/***************************************************************************//**
 * @file
 * @brief Clock Manager - Clock Tree configuration file.
 *******************************************************************************
 * # License
 * <b>Copyright 2025 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * SPDX-License-Identifier: Zlib
 *
 * The licensor of this software is Silicon Laboratories Inc.
 *
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 ******************************************************************************/

#ifndef SL_CLOCK_MANAGER_TREE_CONFIG_H
#define SL_CLOCK_MANAGER_TREE_CONFIG_H

#if defined(SL_COMPONENT_CATALOG_PRESENT)
#include "sl_component_catalog.h"

#endif

// Internal Defines: DO NOT MODIFY
// Those defines are used internally to help converting the DEFAULT_HF_CLOCK_SOURCE and DEFAULT_LF_CLOCK_SOURCE
// selection of each clock branch to the right HW register value.
#define SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_HFRCODPLL    0xFF
#define SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_HFXO         0xFE
#define SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_FSRCO        0xFD
#define SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_LFRCO        0xFC
#define SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_LFXO         0xFB
#define SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_ULFRCO       0xFA

#if defined(SL_CATALOG_RAIL_LIB_PRESENT)
#define SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_AUTO         SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_HFXO
#else
#define SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_AUTO         SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_HFRCODPLL
#endif

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Clock Tree Settings

// <o SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE> Default Clock Source Selection for HF clock branches
//   <SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_AUTO=> AUTO
//   <SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_HFRCODPLL=> HFRCODPLL
//   <SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_HFXO=> HFXO
//   <SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_FSRCO=> FSRCO
// <i> Selection of the high frequency clock source. HF clock branches can select this value by chosing the DEFAULT_HF value.
// <i> AUTO uses HFXO if a radio is used and HFRCODPLL otherwise
// <d> SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_AUTO
#ifndef SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE
#define SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE_HFXO
#endif

// <o SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE> Default Clock Source Selection for LF clock branches
//   <SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_LFRCO=> LFRCO
//   <SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_LFXO=> LFXO
//   <SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_ULFRCO=> ULFRCO
// <i> Selection of the low frequency clock source. LF clock branches can select this value by chosing the DEFAULT_HF value.
// <d> SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_LFRCO
#ifndef SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#define SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE_LFXO
#endif

// <h> System Clock Branch Settings

// <o SL_CLOCK_MANAGER_SYSCLK_SOURCE> Clock Source Selection for SYSCLK branch
//   <SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE=> DEFAULT_HF
//   <CMU_SYSCLKCTRL_CLKSEL_FSRCO=> FSRCO
//   <CMU_SYSCLKCTRL_CLKSEL_HFRCODPLL=> HFRCODPLL
//   <CMU_SYSCLKCTRL_CLKSEL_HFXO=> HFXO
//   <CMU_SYSCLKCTRL_CLKSEL_CLKIN0=> CLKIN0
// <i> Selection of the Clock source for SYSCLK
// <d> SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE
#ifndef SL_CLOCK_MANAGER_SYSCLK_SOURCE
#define SL_CLOCK_MANAGER_SYSCLK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE
#endif

// <o SL_CLOCK_MANAGER_HCLK_DIVIDER> HCLK branch divider
//   <CMU_SYSCLKCTRL_HCLKPRESC_DIV1=> DIV1
//   <CMU_SYSCLKCTRL_HCLKPRESC_DIV2=> DIV2
//   <CMU_SYSCLKCTRL_HCLKPRESC_DIV4=> DIV4
//   <CMU_SYSCLKCTRL_HCLKPRESC_DIV8=> DIV8
//   <CMU_SYSCLKCTRL_HCLKPRESC_DIV16=> DIV16
// <i> HCLK branch is derived from SYSCLK. This clock drives the AHB bus interface.
// <d> CMU_SYSCLKCTRL_HCLKPRESC_DIV1
#ifndef SL_CLOCK_MANAGER_HCLK_DIVIDER
#define SL_CLOCK_MANAGER_HCLK_DIVIDER    CMU_SYSCLKCTRL_HCLKPRESC_DIV1
#endif

// <o SL_CLOCK_MANAGER_PCLK_DIVIDER> PCLK branch divider
//   <CMU_SYSCLKCTRL_PCLKPRESC_DIV1=> DIV1
//   <CMU_SYSCLKCTRL_PCLKPRESC_DIV2=> DIV2
// <i> PCLK branch is derived from HCLK. This clock drives the APB bus interface.
// <d> CMU_SYSCLKCTRL_PCLKPRESC_DIV1
#ifndef SL_CLOCK_MANAGER_PCLK_DIVIDER
#define SL_CLOCK_MANAGER_PCLK_DIVIDER    CMU_SYSCLKCTRL_PCLKPRESC_DIV1
#endif

// </h>

// <h> Trace Clock Branches Settings
// <o SL_CLOCK_MANAGER_TRACECLK_DIVIDER> TRACECLK branch Divider
//   <CMU_TRACECLKCTRL_PRESC_DIV1=> DIV1
//   <CMU_TRACECLKCTRL_PRESC_DIV2=> DIV2
//   <CMU_TRACECLKCTRL_PRESC_DIV4=> DIV4
// <i> Selection of the divider value for TRACECLK branch
// <d> CMU_TRACECLKCTRL_PRESC_DIV1
#ifndef SL_CLOCK_MANAGER_TRACECLK_DIVIDER
#define SL_CLOCK_MANAGER_TRACECLK_DIVIDER    CMU_TRACECLKCTRL_PRESC_DIV1
#endif

// </h>

// <h> High Frequency Clock Branches Settings
// <i> Each HF Clock Tree branch can be customized, else the same clock source as for SYSCLK will be used when possible
// <i> EM01GRPACLK clock the Timer peripherals
// <o SL_CLOCK_MANAGER_EM01GRPACLK_SOURCE> Clock Source Selection for EM01GRPACLK branch
//   <SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE=> DEFAULT_HF
//   <CMU_EM01GRPACLKCTRL_CLKSEL_HFRCODPLL=> HFRCODPLL
//   <CMU_EM01GRPACLKCTRL_CLKSEL_HFXO=> HFXO
//   <CMU_EM01GRPACLKCTRL_CLKSEL_FSRCO=> FSRCO
// <i> Selection of the Clock source for EM01GRPACLK
// <d> SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE
#ifndef SL_CLOCK_MANAGER_EM01GRPACLK_SOURCE
#define SL_CLOCK_MANAGER_EM01GRPACLK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE
#endif

// <o SL_CLOCK_MANAGER_EM01GRPBCLK_SOURCE> Clock Source Selection for EM01GRPBCLK branch
//   <SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE=> DEFAULT_HF
//   <CMU_EM01GRPBCLKCTRL_CLKSEL_HFRCODPLL=> HFRCODPLL
//   <CMU_EM01GRPBCLKCTRL_CLKSEL_HFXO=> HFXO
//   <CMU_EM01GRPBCLKCTRL_CLKSEL_FSRCO=> FSRCO
//   <CMU_EM01GRPBCLKCTRL_CLKSEL_CLKIN0=> CLKIN0
//   <CMU_EM01GRPBCLKCTRL_CLKSEL_HFRCODPLLRT=> HFRCODPLLRT
//   <CMU_EM01GRPBCLKCTRL_CLKSEL_HFXORT=> HFXORT
// <i> Selection of the Clock source for EM01GRPBCLK
// <d> SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE
#ifndef SL_CLOCK_MANAGER_EM01GRPBCLK_SOURCE
#define SL_CLOCK_MANAGER_EM01GRPBCLK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_HF_CLOCK_SOURCE
#endif

// <o SL_CLOCK_MANAGER_IADCCLK_SOURCE> Clock Source Selection for IADCCLK branch
//   <CMU_IADCCLKCTRL_CLKSEL_EM01GRPACLK=> EM01GRPACLK
//   <CMU_IADCCLKCTRL_CLKSEL_FSRCO=> FSRCO
// <i> Selection of the Clock source for IADCCLK
// <d> CMU_IADCCLKCTRL_CLKSEL_EM01GRPACLK
#ifndef SL_CLOCK_MANAGER_IADCCLK_SOURCE
#define SL_CLOCK_MANAGER_IADCCLK_SOURCE    CMU_IADCCLKCTRL_CLKSEL_EM01GRPACLK
#endif

// </h>

// <h> Low Frequency Clock Branches Settings

// <o SL_CLOCK_MANAGER_EM23GRPACLK_SOURCE> Clock Source Selection for EM23GRPACLK branch
//   <SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE=> DEFAULT_LF
//   <CMU_EM23GRPACLKCTRL_CLKSEL_LFRCO=> LFRCO
//   <CMU_EM23GRPACLKCTRL_CLKSEL_LFXO=> LFXO
//   <CMU_EM23GRPACLKCTRL_CLKSEL_ULFRCO=> ULFRCO
// <i> Selection of the Clock source for EM23GRPACLK
// <d> SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#ifndef SL_CLOCK_MANAGER_EM23GRPACLK_SOURCE
#define SL_CLOCK_MANAGER_EM23GRPACLK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#endif

// <o SL_CLOCK_MANAGER_EM4GRPACLK_SOURCE> Clock Source Selection for EM4GRPACLK branch
//   <SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE=> DEFAULT_LF
//   <CMU_EM4GRPACLKCTRL_CLKSEL_LFRCO=> LFRCO
//   <CMU_EM4GRPACLKCTRL_CLKSEL_LFXO=> LFXO
//   <CMU_EM4GRPACLKCTRL_CLKSEL_ULFRCO=> ULFRCO
// <i> Selection of the Clock source for EM4GRPACLK
// <d> SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#ifndef SL_CLOCK_MANAGER_EM4GRPACLK_SOURCE
#define SL_CLOCK_MANAGER_EM4GRPACLK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#endif

// <o SL_CLOCK_MANAGER_RTCCCLK_SOURCE> Clock Source Selection for EM23GRPACLK branch
//   <SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE=> DEFAULT_LF
//   <CMU_RTCCCLKCTRL_CLKSEL_LFRCO=> LFRCO
//   <CMU_RTCCCLKCTRL_CLKSEL_LFXO=> LFXO
//   <CMU_RTCCCLKCTRL_CLKSEL_ULFRCO=> ULFRCO
// <i> Selection of the Clock source for RTCCCLK
// <d> SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#ifndef SL_CLOCK_MANAGER_RTCCCLK_SOURCE
#define SL_CLOCK_MANAGER_RTCCCLK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#endif

// <o SL_CLOCK_MANAGER_WDOG0CLK_SOURCE> Clock Source Selection for WDOG0CLK branch
//   <SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE=> DEFAULT_LF
//   <CMU_WDOG0CLKCTRL_CLKSEL_LFRCO=> LFRCO
//   <CMU_WDOG0CLKCTRL_CLKSEL_LFXO=> LFXO
//   <CMU_WDOG0CLKCTRL_CLKSEL_ULFRCO=> ULFRCO
//   <CMU_WDOG0CLKCTRL_CLKSEL_HCLKDIV1024=> HCLKDIV1024
// <i> Selection of the Clock source for WDOG0CLK
// <d> SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#ifndef SL_CLOCK_MANAGER_WDOG0CLK_SOURCE
#define SL_CLOCK_MANAGER_WDOG0CLK_SOURCE    SL_CLOCK_MANAGER_DEFAULT_LF_CLOCK_SOURCE
#endif

// </h>

// <h> Mixed Frequency Clock Branch Settings
// <o SL_CLOCK_MANAGER_EUART0CLK_SOURCE> Clock Source Selection for EUARTCLK branch
//   <CMU_EUART0CLKCTRL_CLKSEL_DISABLED=> DISABLED
//   <CMU_EUART0CLKCTRL_CLKSEL_EM01GRPACLK=> EM01GRPACLK
//   <CMU_EUART0CLKCTRL_CLKSEL_EM23GRPACLK=> EM23GRPACLK
// <i> Selection of the Clock source for EUARTCLK
// <d> CMU_EUART0CLKCTRL_CLKSEL_EM01GRPACLK
#ifndef SL_CLOCK_MANAGER_EUART0CLK_SOURCE
#define SL_CLOCK_MANAGER_EUART0CLK_SOURCE    CMU_EUART0CLKCTRL_CLKSEL_EM01GRPACLK
#endif

// <o SL_CLOCK_MANAGER_SYSTICKCLK_SOURCE> Clock Source Selection for SYSTICKCLK branch
//   <0=> HCLK
//   <1=> EM23GRPACLK
// <i> Selection of the Clock source for SYSTICKCLK
// <d> 0
#ifndef SL_CLOCK_MANAGER_SYSTICKCLK_SOURCE
#define SL_CLOCK_MANAGER_SYSTICKCLK_SOURCE    0
#endif
// </h>
// </h>

#endif /* SL_CLOCK_MANAGER_TREE_CONFIG_H */

// <<< end of configuration section >>>
