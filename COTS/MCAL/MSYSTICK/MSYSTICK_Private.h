/*
 * MSYSTICK_Private.h
 *
 *  Created on: Aug 15, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#ifndef MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_
#define MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_

#define SYSTICK_BASE_ADD   0xE000E010

typedef struct{

	u32 CTRL;
	u32 LOAD;
	u32 VAL;
	u32 CALIB;

}SYSTICK_MemMap_t;

#define SYSTICK ((volatile SYSTICK_MemMap_t*)SYSTICK_BASE_ADD)

#endif /* MCAL_MSYSTICK_MSYSTICK_PRIVATE_H_ */
