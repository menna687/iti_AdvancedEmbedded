/*
 * SWITCH_Prog.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Menna
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include "../../MCAL/MGPIO/MGPIO_Interface.h"

void SWITCH_voidInit(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8PullType){

	MGPIO_voidSetPinMode(copy_u8PortID, copy_u8PinNum, GPIO_MODE_INPUT);
	MGPIO_voidSetPinInputPull(copy_u8PortID, copy_u8PinNum, copy_u8PullType);
}


u8 SWITCH_u8GetState(u8 copy_u8PortID, u8 copy_u8PinNum){

	return MGPIO_u8GetPinVal(copy_u8PortID, copy_u8PinNum);
}
