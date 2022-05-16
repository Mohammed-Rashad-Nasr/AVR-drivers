/**************************************************/
/*Author : Rashad                                 */
/*Date   : 15 MAY 2022                            */
/*Version: V01                                    */
/**************************************************/

//libraries

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>


//files

#include "GPIO_Interface.h"
#include "LEDANIMATION_Interface.h"


int main(void)
{
	GPIO_voidSetPortType (GPIO_PORTA , GPIO_INPUT_PULLUP);
    GPIO_voidSetPortType (GPIO_PORTC , GPIO_OUTPUT      );
   
    while (1) 
    {
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN0)) LEDANIMATION_voidBlinkAll();
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN1)) LEDANIMATION_voidSequance();
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN2)) LEDANIMATION_voidSequanceReversed();
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN3)) LEDANIMATION_voidToCenter();
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN4)) LEDANIMATION_voidToOut();
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN5)) LEDANIMATION_voidPingPong();
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN6)) LEDANIMATION_voidInOut();
		if(!GPIO_u8ReadPin(GPIO_PORTA , GPIO_PIN7)) LEDANIMATION_voidUpDown();
		else GPIO_voidWritePort   (GPIO_PORTC , 0);
    }
}

