/***************************************************************************//**
 * @file
 * @brief Simple Led Driver Configuration
 *******************************************************************************
 * # License
 * <b>Copyright 2019 Silicon Laboratories Inc. www.silabs.com</b>
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

#ifndef SL_SIMPLE_LED_LED0_CONFIG_H
#define SL_SIMPLE_LED_LED0_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Simple LED configuration
// <o SL_SIMPLE_LED_LED0_POLARITY>
// <SL_SIMPLE_LED_POLARITY_ACTIVE_LOW=> Active low
// <SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH=> Active high
// <i> Default: SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
#define SL_SIMPLE_LED_LED0_POLARITY SL_SIMPLE_LED_POLARITY_ACTIVE_HIGH
// </h> end led configuration

// <<< end of configuration section >>>

// <<< sl:start pin_tool >>>

// <gpio> SL_SIMPLE_LED_LED0
// $[GPIO_SL_SIMPLE_LED_LED0]
#ifndef SL_SIMPLE_LED_LED0_PORT                 
#define SL_SIMPLE_LED_LED0_PORT                  SL_GPIO_PORT_A
#endif
#ifndef SL_SIMPLE_LED_LED0_PIN                  
#define SL_SIMPLE_LED_LED0_PIN                   4
#endif
// [GPIO_SL_SIMPLE_LED_LED0]$

// <<< sl:end pin_tool >>>

#endif // SL_SIMPLE_LED_LED0_CONFIG_H
