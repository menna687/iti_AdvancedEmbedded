/*
 * LED_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Menna
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_


#define LED_OFF    0
#define LED_ON     1

void LED_voidInit(u8 copy_u8PortID, u8 copy_u8PinNum);
void LED_voidOnOff(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8OnOff);
void LED_voidToggle(u8 copy_u8PortID, u8 copy_u8PinNum);

#endif /* HAL_LED_LED_INTERFACE_H_ */
