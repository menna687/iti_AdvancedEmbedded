/*
 * MSYSTICK_Prog.c
 *
 *  Created on: Aug 15, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "MSYSTICK_Config.h"
#include "MSYSTICK_Interface.h"
#include "MSYSTICK_Private.h"



void MSYSTICK_vInit(void){

#if SYSTICK_CLK_SRC == AHB/8
	CLR_BIT(SYSTICK -> CTRL, CTRL_CLKSOURCE);

#elif SYSTICK_CLK_SRC == AHB
	SET_BIT(SYSTICK -> CTRL, CTRL_CLKSOURCE);
#endif

	//interrupt en/dis
}


void MSYSTICK_vDelayTicks(u32 copy_u32Ticks){

	SYSTICK -> VAL = 0;
	SYSTICK -> LOAD |= copy_u32Ticks * 1000000;           // Reload value
	//GET_BIT(SYSTICK -> CTRL, CTRL_COUNTFLAG);           // Read counter flag (to clear it)
	SET_BIT(SYSTICK -> CTRL, CTRL_ENABLE);                // Counter enable
	while(!GET_BIT(SYSTICK -> CTRL, CTRL_COUNTFLAG));     // Wait
	CLR_BIT(SYSTICK -> CTRL, CTRL_ENABLE);                // Counter disable
}


/* Set Callback */
static void(*STK_CallBack)(void) = '\0';

void MSYSTICK_vSetInterruptSingle(u32 copy_u32Ticks, void(*ptr))
{
	STK_CallBack = ptr;

	SYSTICK -> VAL = 0;
	SYSTICK -> LOAD |= copy_u32Ticks;
	SET_BIT(SYSTICK -> CTRL, CTRL_TICKINT);

	SET_BIT(SYSTICK -> CTRL, CTRL_ENABLE);

	// Counter disable
	CLR_BIT(SYSTICK -> CTRL, CTRL_ENABLE);
}


void MSYSTICK_vSetInterruptPeriodic(u32 copy_u32Ticks, void (*ptr)(void))
{
	STK_CallBack = ptr;

	SYSTICK -> VAL = 0;
	SYSTICK -> LOAD |= (copy_u32Ticks * 2000000);

	SET_BIT(SYSTICK -> CTRL, CTRL_TICKINT);
	SET_BIT(SYSTICK -> CTRL, CTRL_ENABLE);
}


void SysTick_Handler(void){

	if(STK_CallBack){
		STK_CallBack();
	}
}


u32 MSYSTICK_u32GetElapsedTime(){

	return ((SYSTICK -> LOAD) - (SYSTICK -> VAL));
}


u32 MSYSTICK_u32GetRemainingTime(){

	return SYSTICK -> VAL;
}

