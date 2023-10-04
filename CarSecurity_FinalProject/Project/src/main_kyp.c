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



void main1()
{
	/* initialize clocks */
	MRCC_voidInitSysClock();

	/* Enable GPIOA,B clock */
	MRCC_voidEnableClock(RCC_AHB1,GPIOA_EN);
	MRCC_voidEnableClock(RCC_AHB1,GPIOB_EN);

	/* Car Motor and LED (indicators) */
	MGPIO_VoidSetPinMode(GPIO_B,PIN5,OUTPUT);
	HLED_VoidInit(GPIO_B, PIN4);

	/* Keypad */
	MSTK_voidInit();
	HKEYPAD_voidInit();

	u8 input, i=0, wrong = 0;
	u8 currentPass[] = "1567";


	while(1)
	{
		input = HKEYPAD_u8GetPressedKey();
		if(input != ALL_NOT_PRESSED)
		{
			/* Reset key is pressed
			 * Reset password characters counter and reset flag
			 */
			if (input == 'c')
			{
				i = 0;
				wrong = 0;
				HLED_VoidLedState(GPIO_B, PIN4, LED_OFF);
				continue;
			}

			/* Check the pressed input with the relative character in the reserved password
			 * Set the flag to 1 in case of wrong input
			 */
			if(input != currentPass[i])
			{
				wrong = 1;
			}

			i++;

			// Check the flag
			if (i == 4)
			{
				if (wrong == 0)
				{
					MGPIO_VoidSetPinValue(GPIO_B, PIN5, HIGH);
					// password flag is correct
				}

				else
				{
					HLED_VoidLedState(GPIO_B, PIN4, LED_ON);
					// Reset variables to start a new loop (Ask for password again)
					i = 0;
					wrong = 0;
				}
			}
		}
	}
}
