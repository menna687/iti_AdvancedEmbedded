/*
 * MRCC_Private.h       (Registers and addresses)
 *
 *  Created on: Aug 10, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */


#ifndef MCAL_MRCC_MRCC_PRIVATE_H_
#define MCAL_MRCC_MRCC_PRIVATE_H_


#define RCC_BASE_ADD 0x40023800

typedef struct{

	u32 CR;
	u32 PLLCFGR;
	u32 CFGR;
	u32 CIR;
	u32 AHB1RSTR;
	u32 AHB2RSTR;
	u32 res1;
	u32 res2;
	u32 APB1RSTR;
	u32 APB2RSTR;
	u32 res3;
	u32 res4;
	u32 AHB1ENR;
	u32 AHB2ENR;
	u32 res5;
	u32 res6;
	u32 APB1ENR;
	u32 APB2ENR;
	u32 res7;
	u32 res8;
	u32 AHB1LPENR;
	u32 AHB2LPENR;
	u32 res9;
	u32 res10;
	u32 APB1LPENR;
	u32 APB2LPENR;
	u32 res11;
	u32 res12;
	u32 BDCR;
	u32 CSR;
	u32 res13;
	u32 res14;
	u32 SSCGR;
	u32 PLLI2SCFGR;
	u32 res15;
	u32 DCKCFGR;

}RCC_MemMap_t;

#define RCC ((volatile RCC_MemMap_t*)RCC_BASE_ADD)

// RCC_CR register bits
#define CR_PLLON        24
#define CR_CSSON        19
#define CR_HSEBYP       18
#define CR_HSEON        16
#define CR_HSIRDY       1
#define CR_HSION        0

// RCC_CFGR register bits
#define CFGR_SW0        0
#define CFGR_SW1        1
#define CFGR_SWS0       2
#define CFGR_SWS1       3

// RCC_PLLCFGR register bits
#define PLLCFGR_PLLSRC      22
#define PLLCFGR_PLLP0       16
#define PLLCFGR_PLLP1       17


#endif /* MCAL_MRCC_MRCC_PRIVATE_H_ */
