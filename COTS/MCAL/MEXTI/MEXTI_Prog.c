/*
 * MEXTI_Prog.c
 *
 *  Created on: Aug 14, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "MEXTI_Private.h"
#include "MEXTI_Config.h"
#include "MEXTI_Interface.h"


void MEXTI_voidEnableEXTI(EXTI_Line_t copy_u8LineNum){

	SET_BIT(EXTI -> IMR, copy_u8LineNum);
}


void MEXTI_voidDisableEXTI(EXTI_Line_t copy_u8LineNum){

	CLR_BIT(EXTI -> IMR, copy_u8LineNum);
}


void MEXTI_voidEnableSoftwareInt(EXTI_Line_t copy_u8LineNum){

	SET_BIT(EXTI -> SWIER, copy_u8LineNum);
}


void MEXTI_voidSelectTrigger(EXTI_Line_t copy_u8LineNum, u8 copy_u8TriggerType){

	switch(copy_u8TriggerType){

		case(EXTI_RISING_EDGE):     SET_BIT(EXTI -> RTSR, copy_u8LineNum);	break;
		case(EXTI_FALLING_EDGE):	SET_BIT(EXTI -> FTSR, copy_u8LineNum);	break;
		case(EXTI_ON_CHANGE):		SET_BIT(EXTI -> RTSR, copy_u8LineNum);
									SET_BIT(EXTI -> FTSR, copy_u8LineNum);  break;
	}
}


void SYSCFG_voidInterruptConfig(u8 copy_u8PortID, u8 copy_u8PinNum){

	 (SYSCFG -> EXTICR[copy_u8PinNum / 4]) |= (copy_u8PortID << (copy_u8PinNum * 4));
}


/* Set Callback */
static void(*EXTI_GPFun_arr[16])(void) = {0};

void MEXTI_voidSetCallBack(EXTI_Line_t copy_u8LineNum, void(*ptr))
{
	EXTI_GPFun_arr[copy_u8LineNum] = ptr;
}


/******************      IRQ Handlers      ******************/
void EXTI0_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE0]){
		EXTI_GPFun_arr[EXTI_LINE0]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE0);
}

void EXTI1_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE1]){
		EXTI_GPFun_arr[EXTI_LINE1]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE1);
}

void EXTI2_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE2]){
		EXTI_GPFun_arr[EXTI_LINE2]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE2);
}

void EXTI3_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE3]){
		EXTI_GPFun_arr[EXTI_LINE3]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE3);
}

void EXTI4_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE4]){
		EXTI_GPFun_arr[EXTI_LINE4]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE4);
}

void EXTI5_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE5]){
		EXTI_GPFun_arr[EXTI_LINE5]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE5);
}

void EXTI6_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE6]){
		EXTI_GPFun_arr[EXTI_LINE6]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE6);
}

void EXTI7_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE7]){
		EXTI_GPFun_arr[EXTI_LINE7]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE7);
}

void EXTI8_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE8]){
		EXTI_GPFun_arr[EXTI_LINE8]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE8);
}

void EXTI9_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE9]){
		EXTI_GPFun_arr[EXTI_LINE9]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE9);
}

void EXTI10_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE10]){
		EXTI_GPFun_arr[EXTI_LINE10]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE10);
}

void EXTI11_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE11]){
		EXTI_GPFun_arr[EXTI_LINE11]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE11);
}

void EXTI12_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE12]){
		EXTI_GPFun_arr[EXTI_LINE12]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE12);
}

void EXTI13_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE13]){
		EXTI_GPFun_arr[EXTI_LINE13]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE13);
}

void EXTI14_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE14]){
		EXTI_GPFun_arr[EXTI_LINE14]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE14);
}

void EXTI15_IRQHandler(void){
	if(EXTI_GPFun_arr[EXTI_LINE15]){
		EXTI_GPFun_arr[EXTI_LINE15]();
	}
	SET_BIT(EXTI -> PR, EXTI_LINE15);
}
