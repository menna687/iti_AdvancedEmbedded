/*
 * MEXTI_Private.h
 *
 *  Created on: Aug 14, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#ifndef MCAL_MEXTI_MEXTI_PRIVATE_H_
#define MCAL_MEXTI_MEXTI_PRIVATE_H_

#define EXTI_BASE_ADD    0x40013C00

typedef struct{

	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;

}EXTI_MemMap_t;

#define EXTI   ((volatile EXTI_MemMap_t*)EXTI_BASE_ADD)

/*---------------------------------------------------------------------------*/
#define SYSCFG_BASE_ADD  0x40013800

typedef struct{

	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];

}SYSCFG_MemMap_t;

#define SYSCFG ((volatile SYSCFG_MemMap_t*)SYSCFG_BASE_ADD)

#endif /* MCAL_MEXTI_MEXTI_PRIVATE_H_ */
