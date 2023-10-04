/*
 * MSYSTICK_Interface.h
 *
 *  Created on: Aug 15, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#ifndef MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_
#define MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_


void MSYSTICK_vInit(void);
void MSYSTICK_vDelayTicks(u32 copy_u32Ticks);

u32 MSYSTICK_u32GetElapsedTime();
u32 MSYSTICK_u32GetRemainingTime();

void MSYSTICK_vSetInterruptSingle(u32 copy_u32Ticks, void(*ptr));
void MSYSTICK_vSetInterruptPeriodic(u32 copy_u32Ticks, void(*ptr)(void));


#define CTRL_COUNTFLAG     16

#define CTRL_CLKSOURCE     2
#define CTRL_TICKINT       1
#define CTRL_ENABLE        0

#define AHB_8    0
#define AHB      1

#endif /* MCAL_MSYSTICK_MSYSTICK_INTERFACE_H_ */
