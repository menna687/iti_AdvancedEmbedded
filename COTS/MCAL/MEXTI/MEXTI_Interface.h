/*
 * MEXTI_Interface.h
 *
 *  Created on: Aug 14, 2023
 *  Author:     Menna Taha
 *  Version:        1
 */

#ifndef MCAL_MEXTI_MEXTI_INTERFACE_H_
#define MCAL_MEXTI_MEXTI_INTERFACE_H_

typedef enum{

	EXTI_LINE0,
	EXTI_LINE1,
	EXTI_LINE2,
	EXTI_LINE3,
	EXTI_LINE4,
	EXTI_LINE5,
	EXTI_LINE6,
	EXTI_LINE7,
	EXTI_LINE8,
	EXTI_LINE9,
	EXTI_LINE10,
	EXTI_LINE11,
	EXTI_LINE12,
	EXTI_LINE13,
	EXTI_LINE14,
	EXTI_LINE15

} EXTI_Line_t;


#define	EXTI_PORT_A      	0b0000
#define	EXTI_PORT_B      	0b0001
#define	EXTI_PORT_C      	0b0010


// Trigger types
#define EXTI_RISING_EDGE      0
#define EXTI_FALLING_EDGE     1
#define EXTI_ON_CHANGE        2


/* Function: MEXTI_voidEnableEXTI -> Enable external interrupt of given line number
 * Input: LineNum -> Line number to enable
 */
void MEXTI_voidEnableEXTI(EXTI_Line_t copy_u8LineNum);


/* Function: MEXTI_voidDisableEXTI -> Disable external interrupt of given line number
 * Input: LineNum -> Line number to disable
 */
void MEXTI_voidDisableEXTI(EXTI_Line_t copy_u8LineNum);


/*
 *
 */
void MEXTI_voidEnableSoftwareInt(EXTI_Line_t copy_u8LineNum);


/* Function: MEXTI_voidSelectTrigger -> Select interrupt trigger for given line number
 * Input: 	LineNum -> Line number
 * 			TriggerType -> options: EXTI_RISING_EDGE
 * 									EXTI_FALLING_EDGE
 * 									EXTI_ON_CHANGE (Both rising and falling edges)
 */
void MEXTI_voidSelectTrigger(EXTI_Line_t copy_u8LineNum, u8 copy_u8TriggerType);


/* Function: SYSCFG_voidInterruptConfig -> 	Use MUX to set given PortID and PinNum as output of an EXTI Line
 * 											PinNum indicates EXTI LineNum (Pin0 maps to Line0 ...)
 * Input:	PortID
 * 			PinNum
 */
void SYSCFG_voidInterruptConfig(u8 copy_u8PortID, u8 copy_u8PinNum);


/*
 *
 */
void MEXTI_voidSetCallBack(EXTI_Line_t copy_u8LineNum, void(*ptr));
//void MEXTI1_voidSetCallBack(void(*ptr));

#endif /* MCAL_MEXTI_MEXTI_INTERFACE_H_ */
