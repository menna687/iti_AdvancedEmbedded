/*
 * LED_Prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Menna
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MGPIO/MGPIO_Interface.h"

void LED_voidInit(u8 copy_u8PortID, u8 copy_u8PinNum){

	MGPIO_voidSetPinMode(copy_u8PortID, copy_u8PinNum, GPIO_MODE_OUTPUT);
}


void LED_voidOnOff(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8OnOff){

	MGPIO_voidSetPinVal(copy_u8PortID, copy_u8PinNum, copy_u8OnOff);
}


void LED_voidToggle(u8 copy_u8PortID, u8 copy_u8PinNum){
	MGPIO_voidTogglePinVal(copy_u8PortID, copy_u8PinNum);
}
