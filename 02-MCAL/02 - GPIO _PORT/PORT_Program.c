/**************************************************/
/*Author : Rashad                                 */
/*Date   : 16 MAY 2022                            */
/*Version: V01                                    */
/**************************************************/


//libraries 

#include "STD_TYPES.h"
#include "BIT_MATH.h"


//files

#include "PORT_Interface.h"
#include "PORT_Private.h"
#include "PORT_Config.h"


//ports initialization function
//******************************

void GPIO_voidInit(void)
{
	GPIO_RDDRA = PORTA_DIR ;
	GPIO_RDDRB = PORTB_DIR ;
	GPIO_RDDRC = PORTC_DIR ;
	GPIO_RDDRD = PORTD_DIR ;
	
	GPIO_RPORTA = PORTA_VAL ;
	GPIO_RPORTB = PORTB_VAL ;
	GPIO_RPORTC = PORTC_VAL ;
	GPIO_RPORTD = PORTD_VAL ;
}

//******************************