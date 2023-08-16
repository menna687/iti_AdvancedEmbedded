/*
 * MGPIO_Prog.c
 *
 *  Created on: Aug 10, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"

#include "MGPIO_Config.h"
#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"

void MGPIO_voidSetPinMode(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8Mode){     // Tested (sim) -> INPUT and OUTPUT modes

	switch(copy_u8PortID){
	case GPIO_PORT_A:
		GPIOA -> MODER &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOA -> MODER |= (copy_u8Mode << (copy_u8PinNum * 2));
		break;

	case GPIO_PORT_B:
		GPIOB -> MODER &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOB -> MODER |= (copy_u8Mode << (copy_u8PinNum * 2));
		break;

	case GPIO_PORT_C:
		GPIOC -> MODER &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOC -> MODER |= (copy_u8Mode << (copy_u8PinNum * 2));
		break;
	}
}


void MGPIO_voidSetPinOutputType(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8OutputType){

	if(copy_u8OutputType == GPIO_OPENDRAIN){
		switch(copy_u8PortID){

			case GPIO_PORT_A: SET_BIT(GPIOA -> OTYPER, copy_u8PinNum);		break;
			case GPIO_PORT_B: SET_BIT(GPIOB -> OTYPER, copy_u8PinNum);		break;
			case GPIO_PORT_C: SET_BIT(GPIOC -> OTYPER, copy_u8PinNum);		break;
		}
	}

	else if(copy_u8OutputType == GPIO_PUSHPULL){
		switch(copy_u8PortID){

			case GPIO_PORT_A: CLR_BIT(GPIOA -> OTYPER, copy_u8PinNum);		break;
			case GPIO_PORT_B: CLR_BIT(GPIOB -> OTYPER, copy_u8PinNum);		break;
			case GPIO_PORT_C: CLR_BIT(GPIOC -> OTYPER, copy_u8PinNum);		break;
		}
	}
}


void MGPIO_voidSetPinOutputSpeed(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8OutputSpeed){

	switch(copy_u8PortID){
	case GPIO_PORT_A:
		GPIOA -> OSPEEDER &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOA -> OSPEEDER |= (copy_u8OutputSpeed << (copy_u8PinNum * 2));
		break;

	case GPIO_PORT_B:
		GPIOB -> OSPEEDER &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOB -> OSPEEDER |= (copy_u8OutputSpeed << (copy_u8PinNum * 2));
		break;

	case GPIO_PORT_C:
		GPIOC -> OSPEEDER &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOC -> OSPEEDER |= (copy_u8OutputSpeed << (copy_u8PinNum * 2));
		break;
	}
}


void MGPIO_voidSetPinInputPull(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8InputPullType){      // Tested (sim) -> PULL_DOWN

	switch(copy_u8PortID){
	case GPIO_PORT_A:
		GPIOA -> PUPDR &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOA -> PUPDR |= (copy_u8InputPullType << (copy_u8PinNum * 2));
		break;

	case GPIO_PORT_B:
		GPIOB -> PUPDR &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOB -> PUPDR |= (copy_u8InputPullType << (copy_u8PinNum * 2));
		break;

	case GPIO_PORT_C:
		GPIOC -> PUPDR &= ~(0b11 << (copy_u8PinNum * 2));
		GPIOC -> PUPDR |= (copy_u8InputPullType << (copy_u8PinNum * 2));
		break;
	}
}


u8 MGPIO_u8GetPinVal(u8 copy_u8PortID, u8 copy_u8PinNum){         // Tested (sim)

	u8 LOC_u8PinVal = 0;
	switch(copy_u8PortID){
		case GPIO_PORT_A:    LOC_u8PinVal = GET_BIT(GPIOA -> IDR, copy_u8PinNum);   break;
		case GPIO_PORT_B:    LOC_u8PinVal = GET_BIT(GPIOB -> IDR, copy_u8PinNum);   break;
		case GPIO_PORT_C:    LOC_u8PinVal = GET_BIT(GPIOC -> IDR, copy_u8PinNum);   break;
	}

	return LOC_u8PinVal;
}


void MGPIO_voidSetPinVal(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8PinVal){        // Tested (sim) -> HIGH and LOW

		if(copy_u8PinVal == GPIO_HIGH){
			switch(copy_u8PortID){
				case GPIO_PORT_A:    SET_BIT(GPIOA -> ODR, copy_u8PinNum);   break;
				case GPIO_PORT_B:    SET_BIT(GPIOB -> ODR, copy_u8PinNum);   break;
				case GPIO_PORT_C:    SET_BIT(GPIOC -> ODR, copy_u8PinNum);   break;
			}
		}

		else if(copy_u8PinVal == GPIO_LOW){
			switch(copy_u8PortID){
				case GPIO_PORT_A:    CLR_BIT(GPIOA -> ODR, copy_u8PinNum);   break;
				case GPIO_PORT_B:    CLR_BIT(GPIOB -> ODR, copy_u8PinNum);   break;
				case GPIO_PORT_C:    CLR_BIT(GPIOC -> ODR, copy_u8PinNum);   break;
			}
		}
}


void MGPIO_voidSetPinVal_fast(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8PinVal){   //BSRR

	if(copy_u8PinVal == GPIO_HIGH){
		switch(copy_u8PortID){
			case GPIO_PORT_A:    GPIOA -> BSRR = 1 << copy_u8PinNum;   break;
			case GPIO_PORT_B:    GPIOB -> BSRR = 1 << copy_u8PinNum;   break;
			case GPIO_PORT_C:    GPIOC -> BSRR = 1 << copy_u8PinNum;   break;
		}
	}

	else if(copy_u8PinVal == GPIO_LOW){
		switch(copy_u8PortID){
			case GPIO_PORT_A:    GPIOA -> BSRR = 1 << (copy_u8PinNum + 16);   break;
			case GPIO_PORT_B:    GPIOB -> BSRR = 1 << (copy_u8PinNum + 16);   break;
			case GPIO_PORT_C:    GPIOC -> BSRR = 1 << (copy_u8PinNum + 16);   break;
		}
	}
}


void MGPIO_voidSetAlternatieFunc(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8AltFunc){
	if(copy_u8PinNum < 8){
		switch(copy_u8PortID){
		case GPIO_PORT_A:
			GPIOA -> AFRL &= ~(0b1111 << (copy_u8PinNum * 4));
			GPIOA -> AFRL |= (copy_u8AltFunc << (copy_u8PinNum * 4));
			break;

		case GPIO_PORT_B:
			GPIOB -> AFRL &= ~(0b1111 << (copy_u8PinNum * 4));
			GPIOB -> AFRL |= (copy_u8AltFunc << (copy_u8PinNum * 4));
			break;

		case GPIO_PORT_C:
			GPIOC -> AFRL &= ~(0b1111 << (copy_u8PinNum * 4));
			GPIOC -> AFRL |= (copy_u8AltFunc << (copy_u8PinNum * 4));
			break;
		}
	}

	else if(copy_u8PinNum >= 8 && copy_u8PinNum < 16){
		switch(copy_u8PortID){
		case GPIO_PORT_A:
			GPIOA -> AFRH &= ~(0b1111 << (copy_u8PinNum % 8));
			GPIOA -> AFRH |= (copy_u8AltFunc << (copy_u8PinNum % 8));
			break;

		case GPIO_PORT_B:
			GPIOB -> AFRH &= ~(0b1111 << (copy_u8PinNum % 8));
			GPIOB -> AFRH |= (copy_u8AltFunc << (copy_u8PinNum % 8));
			break;

		case GPIO_PORT_C:
			GPIOC -> AFRH &= ~(0b1111 << (copy_u8PinNum % 8));
			GPIOC -> AFRH |= (copy_u8AltFunc << (copy_u8PinNum % 8));
			break;
		}
	}
}
