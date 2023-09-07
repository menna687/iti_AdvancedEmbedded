/*
 * MNVIC_Prog.c
 *
 *  Created on: Aug 13, 2023
 *  Author: 	Menna Taha
 * 	Version:    1			
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "MNVIC_Config.h"
#include "MNVIC_Interface.h"
#include "MNVIC_Private.h"


void MNVIC_voidEnableIRQ(u8 copy_u8IRQn){

	SET_BIT(NVIC -> ISER[copy_u8IRQn / REG_WIDTH], copy_u8IRQn % REG_WIDTH);
}


void MNVIC_voidDisableIRQ(u8 copy_u8IRQn){

	SET_BIT(NVIC -> ICER[copy_u8IRQn / REG_WIDTH], copy_u8IRQn % REG_WIDTH);
}


void MNVIC_voidSetPendingIRQ(u8 copy_u8IRQn){

	SET_BIT(NVIC -> ISPR[copy_u8IRQn / REG_WIDTH], copy_u8IRQn % REG_WIDTH);
}


void MNVIC_voidClearPendingIRQ(u8 copy_u8IRQn){

	SET_BIT(NVIC -> ICPR[copy_u8IRQn / REG_WIDTH], copy_u8IRQn % REG_WIDTH);
}


u8 MNVIC_u8GetActiveIRQ(u8 copy_u8IRQn){

	u8 local_u8ActiveState;
	local_u8ActiveState = GET_BIT(NVIC -> IABR[copy_u8IRQn / REG_WIDTH], copy_u8IRQn % REG_WIDTH);
	return local_u8ActiveState;
}


void NVIC_voidSetPriorityIRQ(u8 copy_u8IRQn, u8 copy_u8Priority){

	NVIC -> IPR[copy_u8IRQn / PRIORITY_WIDTH] |= (copy_u8Priority << PRIORITY_WIDTH * (copy_u8IRQn % PRIORITY_WIDTH));
}


void MNVIC_voidSetGroupNum(u8 copy_u8PrioritySplit){

	SCB_AIRCR |= VECTKEY;
	SCB_AIRCR |= (copy_u8PrioritySplit << 8);
}


void MNVIC_voidSetSoftwareIRQ(u8 copy_u8IRQn){

	NVIC -> STIR |= copy_u8IRQn;
}
