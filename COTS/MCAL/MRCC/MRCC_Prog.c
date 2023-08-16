/*
 * MRCC_Prog.c
 *
 *  Created on: Aug 10, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "MRCC_Config.h"
#include "MRCC_Interface.h"
#include "MRCC_Private.h"

void MRCC_voidInitSysClk(void){

#if RCC_SYS_CLK == RCC_HSI                    // Tested (sim)
	// Enable HSI
	SET_BIT(RCC -> CR, CR_HSION);

	// Set HSI as system clock
	CLR_BIT(RCC -> CFGR, CFGR_SW0);
	CLR_BIT(RCC -> CFGR, CFGR_SW1);


#elif RCC_SYS_CLK == RCC_HSE

	/* CSS (ON/OFF) */
	#if RCC_CSS_ENABLE == ENABLE
		SET_BIT(RCC -> CR, CR_CSSON)
	#else
		CLR_BIT(RCC -> CR, CR_CSSON)
	#endif

	/* HSEBYP (CLR -> Osc enable not bypassed, SET -> Osc disable bypassed */
	#if RCC_HSE_SRC == EXT        // external clock source -> bypass
		SET_BIT(RCC -> CR, CR_HSEBYP);
	#elif RCC_HSE_SRC == RC       // external crystal/ceramic resonator
		CLR_BIT(RCC -> CR, CR_HSEBYP);
	#endif

	// Enable HSE
	SET_BIT(RCC -> CR, CR_HSEON);

	// Set HSE as system clock
	SET_BIT(RCC -> CFGR, CFGR_SW0);
	CLR_BIT(RCC -> CFGR, CFGR_SW1);


#elif RCC_SYS_CLK == RCC_PLL
	// PLL source
	#if RCC_PLL_SRC == RCC_HSI
		CLR_BIT(RCC -> PLLCFGR, PLLCFGR_PLLSRC);

	#elif RCC_PLL_SRC == RCC_HSE
		SET_BIT(RCC -> PLLCFGR, PLLCFGR_PLLSRC);
	#endif

	// Enable PLL
	SET_BIT(RCC -> CR, CR_PLLON);

	// Set PLL as system clock
	CLR_BIT(RCC -> CFGR, CFGR_SW0);
	SET_BIT(RCC -> CFGR, CFGR_SW1);

#endif

}


void MRCC_voidEnablePeripheralClock(u8 copy_u8BusName, peripherals_t copy_u8PerName){      // Tested (sim) -> GPIOA, GPIOB, GPIOC

	switch(copy_u8BusName){
		case (RCC_AHB1_BUS):  SET_BIT(RCC -> AHB1ENR, copy_u8PerName);    break;
		case (RCC_AHB2_BUS):  SET_BIT(RCC -> AHB2ENR, copy_u8PerName);    break;
		case (RCC_APB1_BUS):  SET_BIT(RCC -> APB1ENR, copy_u8PerName);    break;
		case (RCC_APB2_BUS):  SET_BIT(RCC -> APB2ENR, copy_u8PerName);    break;
	}
}


void MRCC_voidDisablePeripheralClock(u8 copy_u8BusName, peripherals_t copy_u8PerName){

	switch(copy_u8BusName){
		case (RCC_AHB1_BUS):  CLR_BIT(RCC -> AHB1ENR, copy_u8PerName);    break;
		case (RCC_AHB2_BUS):  CLR_BIT(RCC -> AHB2ENR, copy_u8PerName);    break;
		case (RCC_APB1_BUS):  CLR_BIT(RCC -> APB1ENR, copy_u8PerName);    break;
		case (RCC_APB2_BUS):  CLR_BIT(RCC -> APB2ENR, copy_u8PerName);    break;
	}
}
