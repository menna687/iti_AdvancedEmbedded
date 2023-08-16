#include "LIB/STD_Types.h"
#include "MCAL/MRCC/MRCC_Interface.h"
#include "MCAL/MGPIO/MGPIO_Interface.h"


/* ****************** RCC and GPIO test code *******************
 * Use a switch to turn LED ON or OFF
 * Pins: switch -> PB0
 *       LED -> PC13
 */

int main(){

	// Clock Setup
	MRCC_voidInitSysClk();
	MRCC_voidEnablePeripheralClock(RCC_AHB1_BUS, RCC_GPIOC);
	MRCC_voidEnablePeripheralClock(RCC_AHB1_BUS, RCC_GPIOB);

	// GPIO Setup
	MGPIO_voidSetPinMode(GPIO_PORT_C, 13, GPIO_MODE_OUTPUT);

	MGPIO_voidSetPinMode(GPIO_PORT_B, 0, GPIO_MODE_INPUT);
	MGPIO_voidSetPinInputPull(GPIO_PORT_B, 0, GPIO_PULL_DOWN);


	while(1){
		MGPIO_voidSetPinVal(GPIO_PORT_C, 13, MGPIO_u8GetPinVal(GPIO_PORT_B, 0));
	}
	return 0;
}
