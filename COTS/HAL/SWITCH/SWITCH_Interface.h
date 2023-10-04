/*
 * SWITCH_Interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Menna
 */

#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_


/*
 * Function: SWITCH_voidInit
 * Input: PortID: GPIO_PORT_A / GPIO_PORT_B / GPIO_PORT_C
 *        PinNum: Integer from 0 to 15
 *        InputPullType: GPIO_NO_PULL / GPIO_PULL_UP / GPIO_PULL_DOWN
 */
void SWITCH_voidInit(u8 copy_u8PortID, u8 copy_u8PinNum, u8 copy_u8PullType);


u8 SWITCH_u8GetState(u8 copy_u8PortID, u8 copy_u8PinNum);

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
