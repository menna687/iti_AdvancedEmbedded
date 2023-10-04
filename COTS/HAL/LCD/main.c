/*
 * main.c
 *
 *  Created on: Sep 13, 2023
 *  Author: Gehad
 *
 *  Description: LCD Test
 *
 */

#include "COTS/01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "COTS/01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "COTS/02-MCAL/01-RCC/RCC_interface.h"
#include "COTS/02-MCAL/02-GPIO/GPIO_interface.h"
#include "COTS/02-MCAL/06-STK/STK_interface.h"

#include "COTS/03-HAL/01-LED/LED_interface.h"
#include "COTS/03-HAL/02-SWITCH/SWITCH_interface.h"
#include "COTS/03-HAL/03-LCD/LCD_interface.h"


/* Input: Four doors states: 0 -> open
 * 							 1 -> closed
 *
 * Output: Display states on LCD
 */
void update_LCD(u8 door1_state, u8 door2_state, u8 door3_state, u8 door4_state);

void main()
{
	/*initialize clocks*/
	MRCC_voidInitSysClock();

	/*Enable GPIOA,B clock */
	MRCC_voidEnableClock(RCC_AHB1,GPIOA_EN);
	MRCC_voidEnableClock(RCC_AHB1,GPIOB_EN);

	/* Initialization */
	MSTK_voidInit();
	HLCD_voidInitialize();


	while(1){

		update_LCD(1, 1, 1, 0);
	}
}


void update_LCD(u8 door1_state, u8 door2_state, u8 door3_state, u8 door4_state)
{
	//HLCD_voidClear();
	HLCD_voidGoToXY(0, 1);
	HLCD_voidString("1:");
	if(door1_state)
		HLCD_voidString("CLOSE");
	else
		HLCD_voidString("OPEN");

	HLCD_voidGoToXY(9, 1);
	HLCD_voidString("2:");
		if(door2_state)
			HLCD_voidString("CLOSE");
		else
			HLCD_voidString("OPEN");

	HLCD_voidGoToXY(0, 2);
	HLCD_voidString("3:");
		if(door3_state)
			HLCD_voidString("CLOSE");
		else
			HLCD_voidString("OPEN");

	HLCD_voidGoToXY(9, 2);
	HLCD_voidString("4:");
		if(door4_state)
			HLCD_voidString("CLOSE");
		else
			HLCD_voidString("OPEN");
}
