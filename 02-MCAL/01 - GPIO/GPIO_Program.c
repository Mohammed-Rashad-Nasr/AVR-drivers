/**************************************************/
/*Author : Rashad                                 */
/*Date   : 14 MAY 2022                            */
/*Version: V03                                    */
/**************************************************/


//libraries 

#include "STD_TYPES.h"
#include "BIT_MATH.h"


//files

#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"




//function to set pin type

GPIO_TypedefErrorType GPIO_voidSetPinType (u8 COPY_u8PortId , u8 COPY_u8PinId , u8 COPY_u8PinType , u8 COPY_u8PullUp)
{
	if (COPY_u8PortId == GPIO_PORTA)
	{
		if      (COPY_u8PinId < 0 || COPY_u8PinId > 7)            return GPIO_INVALID_PIN_ID ;
		else if (COPY_u8PinType != 0b0 && COPY_u8PinType != 0b1 ) return GPIO_INVALID_TYPE   ;
		else 
		{
			GPIO_RDDRA  &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset type
			GPIO_RDDRA  |=   (((COPY_u8PinType))<<(COPY_u8PinId)) ;     //Write the pin type 
			GPIO_RPORTA &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset 
			GPIO_RPORTA |=   (((COPY_u8PullUp)) <<(COPY_u8PinId)) ;     //pull up option 
		}
	}
	else if (COPY_u8PortId == GPIO_PORTB)
	{
		if      (COPY_u8PinId < 0 || COPY_u8PinId > 7)            return GPIO_INVALID_PIN_ID ;
		else if (COPY_u8PinType != 0b0 && COPY_u8PinType != 0b1 ) return GPIO_INVALID_TYPE   ;
		else 
		{
			GPIO_RDDRB  &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset type
			GPIO_RDDRB  |=   (((COPY_u8PinType))<<(COPY_u8PinId)) ;     //Write the pin type 
			GPIO_RPORTB &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset 
			GPIO_RPORTB |=   (((COPY_u8PullUp)) <<(COPY_u8PinId)) ;     //pull up option
		}		
	}
	else if (COPY_u8PortId == GPIO_PORTC)
	{
		if      (COPY_u8PinId < 0 || COPY_u8PinId > 7)            return GPIO_INVALID_PIN_ID ;
		else if (COPY_u8PinType != 0b0 && COPY_u8PinType != 0b1 ) return GPIO_INVALID_TYPE   ;
		else 
		{
			GPIO_RDDRC  &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset type
			GPIO_RDDRC  |=   (((COPY_u8PinType))<<(COPY_u8PinId)) ;     //Write the pin type 
			GPIO_RPORTC &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset 
			GPIO_RPORTC |=   (((COPY_u8PullUp)) <<(COPY_u8PinId)) ;     //pull up option 
		}
	}
	else if (COPY_u8PortId == GPIO_PORTD)
	{
		if      (COPY_u8PinId < 0 || COPY_u8PinId > 7)            return GPIO_INVALID_PIN_ID ;
		else if (COPY_u8PinType != 0b0 && COPY_u8PinType != 0b1 ) return GPIO_INVALID_TYPE   ;
		else 
		{
			GPIO_RDDRD  &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset type
			GPIO_RDDRD  |=   (((COPY_u8PinType))<<(COPY_u8PinId)) ;     //Write the pin type 
			GPIO_RPORTD &= ~ ((0b1)             <<(COPY_u8PinId)) ;     //reset 
			GPIO_RPORTD |=   (((COPY_u8PullUp)) <<(COPY_u8PinId)) ;     //pull up option 
		}
	}
	
	else return GPIO_INVALID_PORT_ID ;
	return      GPIO_OK ;
}

//function to write on pin 

GPIO_TypedefErrorType GPIO_voidWritePin (u8 COPY_u8PortId , u8 COPY_u8PinId , u8 COPY_u8Value)
{
	if      (COPY_u8PinId < 0 || COPY_u8PinId > 7)            return GPIO_INVALID_PIN_ID ;
	else if (COPY_u8Value   != 0   && COPY_u8Value   != 1   ) return GPIO_INVALID_VALUE  ;
	else 
	{
		if (COPY_u8PortId == GPIO_PORTA)
		{
				GPIO_RPORTA &= ~ ((0b1)           <<(COPY_u8PinId)) ;     //reset output
				GPIO_RPORTA |=   (((COPY_u8Value))<<(COPY_u8PinId)) ;     //Write the Output value
		}
		else if (COPY_u8PortId == GPIO_PORTB)
		{
				GPIO_RPORTB &= ~ ((0b1)           <<(COPY_u8PinId)) ;     //reset output
				GPIO_RPORTB |=   (((COPY_u8Value))<<(COPY_u8PinId)) ;     //Write the Output value
		}
		else if (COPY_u8PortId == GPIO_PORTC)
		{
				GPIO_RPORTC &= ~ ((0b1)           <<(COPY_u8PinId)) ;     //reset output
				GPIO_RPORTC |=   (((COPY_u8Value))<<(COPY_u8PinId)) ;     //Write the Output value
		}
		else if (COPY_u8PortId == GPIO_PORTD)
		{
				GPIO_RPORTD &= ~ ((0b1)           <<(COPY_u8PinId)) ;     //reset output
				GPIO_RPORTD |=   (((COPY_u8Value))<<(COPY_u8PinId)) ;     //Write the Output value
		}
		else return GPIO_INVALID_PORT_ID ;
	}
	return GPIO_OK ;
}	

//function to read pin value

u8 GPIO_u8ReadPin (u8 COPY_u8PortId , u8 COPY_u8PinId )
{
	if      (COPY_u8PortId == GPIO_PORTA)
	{
	    return GET_BIT(GPIO_RPINA,COPY_u8PinId) ;	
	}
	else if (COPY_u8PortId == GPIO_PORTB)
	{
	    return GET_BIT(GPIO_RPINB,COPY_u8PinId) ;	
	}
	else if (COPY_u8PortId == GPIO_PORTC)
	{
	    return GET_BIT(GPIO_RPINC,COPY_u8PinId) ;	
	}
	else if (COPY_u8PortId == GPIO_PORTD)
	{
	    return GET_BIT(GPIO_RPIND,COPY_u8PinId) ;	
	}
	return 0 ;
}	

//function to set port type

GPIO_TypedefErrorType GPIO_voidSetPortType (u8 COPY_u8PortId , u8 COPY_u8PinType , u8 COPY_u8PullUp)
{
	if      (COPY_u8PortId < 0 || COPY_u8PortId > 3)          return GPIO_INVALID_PORT_ID ;
	else if (COPY_u8PinType != 0b0 && COPY_u8PinType != 0b1 ) return GPIO_INVALID_TYPE    ;
	else 
	{
		u8 LOCAL_u8Count = 0 ;                                                                         //for loop counter
		for (LOCAL_u8Count=0;LOCAL_u8Count<8;LOCAL_u8Count++)                                          //for loop to set the type of all the pins of the port
		{
			GPIO_voidSetPinType (COPY_u8PortId , LOCAL_u8Count ,  COPY_u8PinType ,  COPY_u8PullUp) ;   
		}
	}
	return GPIO_OK ;
}

//function to write on port

GPIO_TypedefErrorType GPIO_voidWritePort (u8 COPY_u8PortId , u8 COPY_u8Value)
{
	if      (COPY_u8PortId < 0 || COPY_u8PortId > 3)          return GPIO_INVALID_PORT_ID ;
	else if (COPY_u8Value   != 0   && COPY_u8Value   != 1   ) return GPIO_INVALID_VALUE   ;
	else 
	{
		u8 LOCAL_u8Count = 0 ;                                                                        //for loop counter
		for (LOCAL_u8Count=0;LOCAL_u8Count<8;LOCAL_u8Count++)                                         //for loop to set or clear all the pins of the port
		{
			GPIO_voidWritePin (COPY_u8PortId , LOCAL_u8Count , COPY_u8Value) ;
		}
	}
	return GPIO_OK ;
}

//function to read port value

u8 GPIO_u8ReadPort (u8 COPY_u8PortId )
{
	if      (COPY_u8PortId == GPIO_PORTA)
	{
	    return GPIO_RPINA ;	
	}
	else if (COPY_u8PortId == GPIO_PORTB)
	{
	    return GPIO_RPINB ;	
	}
	else if (COPY_u8PortId == GPIO_PORTC)
	{
	    return GPIO_RPINC ;	
	}
	else if (COPY_u8PortId == GPIO_PORTD)
	{
	    return GPIO_RPIND ;	
	}
	return 0 ;
}
