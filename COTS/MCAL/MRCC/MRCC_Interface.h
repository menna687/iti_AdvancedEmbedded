/*
 * MRCC_Interface.h
 *
 *  Created on: Aug 10, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */


#ifndef MCAL_MRCC_MRCC_INTERFACE_H_
#define MCAL_MRCC_MRCC_INTERFACE_H_


/**********************     Peripheral Clock Enable Registers     **********************/
typedef enum {

	RCC_GPIOA = 0,
	RCC_GPIOB,
	RCC_GPIOC,

	RCC_USART2 = 17,
	RCC_TIM1 = 0,
	RCC_TIM2,
	RCC_TIM3,
	RCC_TIM4,
	RCC_TIM5,

	RCC_ADC1 = 8,
	RCC_SYSCFG = 14

}peripherals_t;


/**********************      Peripherals buses      **********************/
#define RCC_AHB1_BUS    0
#define RCC_AHB2_BUS    1
#define RCC_APB1_BUS    2
#define RCC_APB2_BUS    3


// System clock
#define RCC_HSI         0
#define RCC_HSE         1
#define RCC_PLL     	2


// RCC_HSE_SRC
#define RC       		0
#define EXT        		1


#define ENABLE          0
#define DISABLE         1



/************************          Functions prototypes          ************************/
void MRCC_voidInitSysClk(void);
void MRCC_voidEnablePeripheralClock(u8 copy_u8BusName, peripherals_t copy_u8PerName);
void MRCC_voidDisablePeripheralClock(u8 copy_u8BusName, peripherals_t copy_u8PerName);


#endif /* MCAL_MRCC_MRCC_INTERFACE_H_ */
