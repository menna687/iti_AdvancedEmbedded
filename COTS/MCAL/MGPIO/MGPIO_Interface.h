/*
 * MGPIO_Interface.h
 *
 *  Created on: Aug 10, 2023
 *  Author: Menna Taha
 *  Version:    1
 */

#ifndef MCAL_MGPIO_MGPIO_INTERFACE_H_
#define MCAL_MGPIO_MGPIO_INTERFACE_H_

// Port IDs
#define GPIO_PORT_A      		0
#define GPIO_PORT_B      		1
#define GPIO_PORT_C      		2

// Pin Modes
#define GPIO_MODE_INPUT     	0b00
#define GPIO_MODE_OUTPUT    	0b01
#define GPIO_MODE_ALTFUN    	0b10
#define GPIO_MODE_ANALOG    	0b11

// Output Modes
#define GPIO_PUSHPULL       	0
#define GPIO_OPENDRAIN      	1

// Speeds
#define GPIO_LOW_SPEED         	0b00
#define GPIO_MEDIUM_SPEED      	0b01
#define GPIO_HIGH_SPEED        	0b10
#define GPIO_VERY_HIGH_SPEED   	0b11

// Input Pull
#define GPIO_NO_PULL           	0b00
#define GPIO_PULL_UP           	0b01
#define GPIO_PULL_DOWN         	0b10

// Pin value
#define GPIO_LOW    			0
#define GPIO_HIGH   			1

// Alternative functions
#define GPIO_AF0            	0b0000
#define GPIO_AF1            	0b0001
#define GPIO_AF2      			0b0010
#define GPIO_AF3      			0b0011
#define GPIO_AF4      			0b0100
#define GPIO_AF5      			0b0101
#define GPIO_AF6      			0b0110
#define GPIO_AF7      			0b0111
#define GPIO_AF8      			0b1000
#define GPIO_AF9      			0b1001
#define GPIO_AF10     			0b1010
#define GPIO_AF11     			0b1011
#define GPIO_AF12     			0b1100
#define GPIO_AF13     			0b1101
#define GPIO_AF14     			0b1110
#define GPIO_AF15     			0b1111


/**************************         Functions Prototypes         **************************/

/*
 * Function: MGPIO_voidSetPinMode
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        Mode: GPIO_MODE_INPUT / GPIO_MODE_OUTPUT / GPIO_MODE_ALTFUN / GPIO_MODE_ANALOG
 */
void MGPIO_voidSetPinMode(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8Mode);


/*
 * Function: MGPIO_voidSetOutputType
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        OutputType: GPIO_PUSHPULL / GPIO_OPENDRAIN
 */
void MGPIO_voidSetPinOutputType(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8OutputType);


/*
 * Function: MGPIO_vSetPinOutputSpeed
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        OutputSpeed: GPIO_LOW_SPEED / GPIO_MEDIUM_SPEED / GPIO_HIGH_SPEED / GPIO_VERY_HIGH_SPEED
 */
void MGPIO_voidSetPinOutputSpeed(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8OutputSpeed);


/*
 * Function: MGPIO_voidSetPinVal
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        PinVal: GPIO_LOW / GPIO_HIGH
 */
void MGPIO_voidSetPinVal(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8PinVal);


/*
 * Function: MGPIO_voidSetPinVal_fast (Uses BSRR for faster bit assignment)
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        PinVal: GPIO_LOW / GPIO_HIGH
 */
void MGPIO_voidSetPinVal_fast(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8PinVal);   //BSRR


/*
 * Function: MGPIO_voidSetPinInputPull
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        InputPullType: GPIO_NO_PULL / GPIO_PULL_UP / GPIO_PULL_DOWN
 */
void MGPIO_voidSetPinInputPull(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8InputPullType);


/*
 * Function: MGPIO_u8GetPinVal
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *
 * Return: PinVal: 0 -> GPIO_LOW
 *                 1 -> GPIO_HIGH
 */
u8 MGPIO_u8GetPinVal(u8 copy_u8PortID, u8 copy_u8PinNum);


/*
 * Function: MGPIO_voidSetAlternatieFunc
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        AltFun: GPIO_AF0 ..... GPIO_AF16
 */
void MGPIO_voidSetAlternatieFunc(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8AltFunc);


#endif /* MCAL_MGPIO_MGPIO_INTERFACE_H_ */
