/*
 * main.c
 *
 *  Created on: Sep 13, 2023
 *  Author: Gehad
 *
 *  Description: Keypad Test
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
#include "COTS/03-HAL/04-Keypad/Keypad_interface.h"



void main()
{
	/*initialize clocks*/
	MRCC_voidInitSysClock();

	/*Enable GPIOA,B clock */
	MRCC_voidEnableClock(RCC_AHB1,GPIOA_EN);
	MRCC_voidEnableClock(RCC_AHB1,GPIOB_EN);

	/* Car Motor */
	MGPIO_VoidSetPinMode(GPIO_A,PIN10,OUTPUT);

	/* Initialization */
	MSTK_voidInit();
	//HLCD_voidInitialize();
	HKEYPAD_voidInit();

	u8 keypadpressed = 0;
	u8 Password = '5';

	while(1)
	{
		keypadpressed = HKEYPAD_voidGetPressedKey();

		if (keypadpressed != 0xff)
		{
			if(keypadpressed == Password)
			{
				MGPIO_VoidSetPinValue(GPIO_A,PIN10,HIGH);
			}

		}

	}
}
