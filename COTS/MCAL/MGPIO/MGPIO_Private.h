/*
 * MGPIO_Private.h
 *
 *  Created on: Aug 10, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#ifndef MCAL_MGPIO_MGPIO_PRIVATE_H_
#define MCAL_MGPIO_MGPIO_PRIVATE_H_

#define GPIOA_BASE_ADD 0x40020000
#define GPIOB_BASE_ADD 0x40020400
#define GPIOC_BASE_ADD 0x40020800

typedef struct{

	u32 MODER;
	u32 OTYPER;
	u32 OSPEEDER;
	u32 PUPDR;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 LCKR;
	u32 AFRL;
	u32 AFRH;

}GPIO_MemMap_t;

#define GPIOA ((volatile GPIO_MemMap_t*)GPIOA_BASE_ADD)
#define GPIOB ((volatile GPIO_MemMap_t*)GPIOB_BASE_ADD)
#define GPIOC ((volatile GPIO_MemMap_t*)GPIOC_BASE_ADD)


#endif /* MCAL_MGPIO_MGPIO_PRIVATE_H_ */
