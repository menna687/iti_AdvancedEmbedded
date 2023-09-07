/*
 * MNVIC_Interface.h
 *
 *  Created on: Aug 13, 2023
 *  Author: 	Menna Taha
 * 	Version:    1			
 */

#ifndef MCAL_MNVIC_MNVIC_INTERFACE_H_
#define MCAL_MNVIC_MNVIC_INTERFACE_H_


#define REG_WIDTH         32
#define PRIORITY_WIDTH    4

// Group/subgroup division
#define GP16_SUB0      0b000
#define GP8_SUB2       0b100
#define GP4_SUB4       0b101
#define GP2_SUB8       0b110
#define GP0_SUB16      0b111


/***************************      Functions Prototypes     ***************************/

/* Function: MNVIC_voidEnableIRQ
 * Input: IRQ number
 */
void MNVIC_voidEnableIRQ(u8 copy_u8IRQn);


/* Function: MNVIC_voidDisableIRQ
 * Input: IRQ number
 */
void MNVIC_voidDisableIRQ(u8 copy_u8IRQn);


/* Function: MNVIC_voidSetPendingIRQ -> Set pending flag by software (for testing)
 * Input: IRQ number
 */
void MNVIC_voidSetPendingIRQ(u8 copy_u8IRQn);


/* Function: MNVIC_voidClearPendingIRQ
 * Input: IRQ number
 */
void MNVIC_voidClearPendingIRQ(u8 copy_u8IRQn);


/* Function: MNVIC_u8GetActiveIRQ
 * Input: IRQ number
 * Return: Active flag of IRQn -> 0: Inactive
 *                                1: Active
 */
u8 MNVIC_u8GetActiveIRQ(u8 copy_u8IRQn);


/* Function: NVIC_voidSetPriorityIRQ
 * Input: IRQ number
 *        Priority -> group|subgroup
 */
void NVIC_voidSetPriorityIRQ(u8 copy_u8IRQn, u8 copy_u8Priority);


u8 MNVIC_u8GetPriorityIRQ(u8 copy_u8IRQn);


/* Function: MNVIC_voidSetGroupNum
 * Input: PrioritySplit -> number of bit separating priority group from subgroup
 */
void MNVIC_voidSetGroupNum(u8 copy_u8PrioritySplit);


/* Function: MNVIC_voidSetSoftwareIRQ -> generate a Software Generated Interrupt (SGI) with ID IRQn
 * Input: IRQ number
 */
void MNVIC_voidSetSoftwareIRQ(u8 copy_u8IRQn);



#endif /* MCAL_MNVIC_MNVIC_INTERFACE_H_ */
