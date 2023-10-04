/**********************************************************/
/* Author    : Gehad Ekoumy                               */
/* Version   : V01                           		     */
/* Date      : 16 AUG 2023                                */
/**********************************************************/

#include "../../01-LIB/01-STD_TYPES/STD_TYPES.h"
#include "../../01-LIB/02-BIT_MATH/BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* Define Variable for interval mode */
static u8 MSTK_u8ModeOfInterval;


void MSTK_voidInit(void)
{
#if MSTK_CLK_SRC == MSTK_SRC_AHB
    /* Disable STK - Disable STK Interrupt - Set clock source AHB */
	MSTK -> CTRL = 0x00000004;
#else
    /* Disable STK - Disable STK Interrupt - Set clock source AHB/8 */
	MSTK -> CTRL = 0x00000000;
#endif
}

		/*synchronous function*/
void MSTK_voidSetBusyWait( u32 Copy_u32Ticks )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks ;
	/* Start Timer */
	SET_BIT(MSTK -> CTRL, 0);
	/* Wait till flag is raised */
	while( (GET_BIT(MSTK -> CTRL,COUNTFLAG)) == 0);
	/* Stop Timer */
	SET_BIT(MSTK -> CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

			/*Asynchronous function count time once*/
void MSTK_voidSetIntervalSingle  ( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks ;
	/* Start Timer */
	SET_BIT(MSTK -> CTRL, 0);
	/* Save CallBack */
	MSTK_GlobalPtr = Copy_ptr;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_SINGLE_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK -> CTRL, 1);
}

			/*Asynchronous function count periodic*/
void MSTK_voidSetIntervalPeriodic( u32 Copy_u32Ticks, void (*Copy_ptr)(void) )
{
	/* Load ticks to load register */
	MSTK -> LOAD = Copy_u32Ticks ;
	/* Start Timer */
	SET_BIT(MSTK -> CTRL, 0);
	/* Save CallBack */
	MSTK_GlobalPtr = Copy_ptr;
	/* Set Mode to Single */
	MSTK_u8ModeOfInterval = MSTK_PERIOD_INTERVAL;
	/* Enable STK Interrupt */
	SET_BIT(MSTK -> CTRL, 1);
}

/*stop timer for asyncronous functions*/
void MSTK_voidStopInterval(void)
{
	/* Disable STK Interrupt */
	CLR_BIT(MSTK -> CTRL, 1);
	/* Stop Timer */
	SET_BIT(MSTK -> CTRL, 0);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

/*load - value (counted time)*/
u32  MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = (MSTK -> LOAD) - (MSTK -> VAL) ;
	return Local_u32ElapsedTime;
}

/*value register (remaining time)*/
u32  MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32RemainTime;
	Local_u32RemainTime = MSTK -> VAL ;
	return Local_u32RemainTime;
}


void SysTick_Handler(void)
{
	u8 Local_u8Temporary = 0;

	if (MSTK_u8ModeOfInterval == MSTK_SINGLE_INTERVAL)
	{
		/* Disable STK Interrupt */
		CLR_BIT(MSTK -> CTRL, 1);
		/* Stop Timer */
		SET_BIT(MSTK -> CTRL, 0);
		MSTK -> LOAD = 0;
		MSTK -> VAL  = 0;
	}

	/* Callback notification */
	if(MSTK_GlobalPtr != NULL)
	{
		MSTK_GlobalPtr();
	}

	/* Clear interrupt flag */
	Local_u8Temporary = GET_BIT(MSTK -> CTRL,COUNTFLAG);
}

