/*****************************************/
/* Author  :  Gehad Elkoumy              */
/* Version :  V01                        */
/* Date    :  13 Sep 2023                */
/*****************************************/

#ifndef _KEYPAD_INTERFACE_H            //header file guard
#define _KEYPAD_INTERFACE_H

                        /*Functions Prototypes*/
u8 HKEYPAD_u8GetPressedKey(void);
void HKEYPAD_voidInit(void);


#define ALL_NOT_PRESSED       (0xFF)    //number out of possible output range
#define SWITCH_PRESSED        (0x00)
#define SWITCH_NOT_PRESSED    (0x01)

#endif
