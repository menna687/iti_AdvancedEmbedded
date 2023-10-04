/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  13 Sep 2023                */
/*****************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "../../02-MCAL/02-GPIO/GPIO_interface.h"
#include "../../02-MCAL/06-STK/STK_interface.h"

//#include "../03-LCD/LCD_Interface.h"

#include "Keypad_Config.h"
#include "Keypad_Interface.h"


void HKEYPAD_voidInit(void)
{
	//DIO_voidSetPortDirection(KYP_port,0x0f);    //Column:high , Row:pull up
	MGPIO_VoidSetPinMode(KYP_port,PIN7,OUTPUT);
	MGPIO_VoidSetPinMode(KYP_port,PIN8,OUTPUT);
	MGPIO_VoidSetPinMode(KYP_port,PIN9,OUTPUT);
	MGPIO_VoidSetPinMode(KYP_port,PIN10,OUTPUT);

	MGPIO_VoidSetPinValue(KYP_port,PIN7,HIGH);
	MGPIO_VoidSetPinValue(KYP_port,PIN8,HIGH);
	MGPIO_VoidSetPinValue(KYP_port,PIN9,HIGH);
	MGPIO_VoidSetPinValue(KYP_port,PIN10,HIGH);

	MGPIO_VoidSetPinMode(KYP_port,PIN12,INPUT);
	MGPIO_VoidSetPullType(KYP_port,PIN12,PULL_UP);
	MGPIO_VoidSetPinMode(KYP_port,PIN13,INPUT);
	MGPIO_VoidSetPullType(KYP_port,PIN13,PULL_UP);
	MGPIO_VoidSetPinMode(KYP_port,PIN14,INPUT);
	MGPIO_VoidSetPullType(KYP_port,PIN14,PULL_UP);
	MGPIO_VoidSetPinMode(KYP_port,PIN15,INPUT);
	MGPIO_VoidSetPullType(KYP_port,PIN15,PULL_UP);

	//MGPIO_VoidSetUpperPinsValue(KYP_port,0xff);
}

u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 Local_u8SwValue[4][4] = {{'7','8','9','/'},
		                        {'4','5','6','*'},
								{'1','2','3','-'},
	                            {'c','0','=','+'}};
	u8 Local_u8KeyState = ALL_NOT_PRESSED;
	u8 Local_u8CheckPressed = SWITCH_NOT_PRESSED;    //pull up - 0:pressed

	u8 Copy_u8Col , Copy_u8Row;

	for(Copy_u8Col = Col_Start ; Copy_u8Col <= Col_End ; Copy_u8Col++)
	{
		MGPIO_VoidSetPinValue(KYP_port , Copy_u8Col , LOW);     //activate this column
		for(Copy_u8Row = Row_Start ; Copy_u8Row <= Row_End ; Copy_u8Row++)
		{
			Local_u8CheckPressed = MGPIO_u8GetPinValue(KYP_port , Copy_u8Row);
			if(Local_u8CheckPressed == SWITCH_PRESSED)
			{
				Local_u8KeyState = Local_u8SwValue[Copy_u8Row - Row_Start][Copy_u8Col - Col_Start];

				while(Local_u8CheckPressed == SWITCH_PRESSED)
				{
					Local_u8CheckPressed = MGPIO_u8GetPinValue(KYP_port , Copy_u8Row);
				}
//
//				MSTK_voidSetBusyWait(5000);
				MGPIO_VoidSetPinValue(KYP_port , Copy_u8Col , HIGH);
				return Local_u8KeyState;
			}
		}
		MGPIO_VoidSetPinValue(KYP_port , Copy_u8Col , HIGH);    //deactivate this column
	}
	return Local_u8KeyState;
}
