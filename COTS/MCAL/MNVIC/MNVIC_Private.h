/*
 * MNVIC_Private.h
 *
 *  Created on: Aug 13, 2023
 *  Author: 	Menna Taha
 * 	Version:    1			
 */

#ifndef MCAL_MNVIC_MNVIC_PRIVATE_H_
#define MCAL_MNVIC_MNVIC_PRIVATE_H_

#define NVIC_BASE_ADD   0xE000E100
#define SCB_AIRCR_ADD   0xE000ED0C

typedef struct{

	u32 ISER[8];
	u32 res0[24];
	u32 ICER[8];
	u32 res1[24];
	u32 ISPR[8];
	u32 res2[24];
	u32 ICPR[8];
	u32 res3[24];
	u32 IABR[8];
	u32 res4[56];
	u32 IPR[60];
	u32 res5[580];
	u32 STIR;

}NVIC_MemMap_t;

#define NVIC ((volatile NVIC_MemMap_t*)NVIC_BASE_ADD)
#define SCB_AIRCR  *((volatile u32*)SCB_AIRCR_ADD)

#define VECTKEY     0x05FA0000

#endif /* MCAL_MNVIC_MNVIC_PRIVATE_H_ */
