/*
 * MRCC_Config.h
 *
 *  Created on: Aug 10, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#ifndef MCAL_MRCC_MRCC_CONFIG_H_
#define MCAL_MRCC_MRCC_CONFIG_H_

// System clock (RCC_HSE / RCC_HSI / RCC_PLL)
#define RCC_SYS_CLK         RCC_HSI

// HSE options
#define RCC_CSS_ENABLE      DISABLE
#define RCC_HSE_SRC         RC         // RC / EXT

// PLL options
#define RCC_PLL_SRC         RCC_HSI       // RCC_HSE / RCC_HSI


#endif /* MCAL_MRCC_MRCC_CONFIG_H_ */
