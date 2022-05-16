/**************************************************/
/*Author : Rashad                                 */
/*Date   : 14 MAY 2022                            */
/*Version: V03                                    */
/**************************************************/
#ifndef GINTERFACE_H
#define GINTERFACE_H

//PORT ID 
 
#define GPIO_PORTA               0
#define GPIO_PORTB               1
#define GPIO_PORTC               2
#define GPIO_PORTD               3

//Pin ID
#define GPIO_PIN0                0
#define GPIO_PIN1                1
#define GPIO_PIN2                2
#define GPIO_PIN3                3
#define GPIO_PIN4                4
#define GPIO_PIN5                5
#define GPIO_PIN6                6
#define GPIO_PIN7                7


//Pin types

#define GPIO_INPUT_FLOATING      0b0,0
#define GPIO_INPUT_PULLUP        0b0,1
#define GPIO_OUTPUT              0b1,0

//error types enum

typedef enum 
{
	  GPIO_OK              =  0
	, GPIO_INVALID_PIN_ID  = -1 
	, GPIO_INVALID_PORT_ID = -2
	, GPIO_INVALID_TYPE    = -3
	, GPIO_INVALID_VALUE   = -4
}     GPIO_TypedefErrorType;


//functions prototype

GPIO_TypedefErrorType GPIO_voidSetPinType  (u8 COPY_u8PortId , u8 COPY_u8PinId , u8 COPY_u8PinType , u8 COPY_u8PullUp);
GPIO_TypedefErrorType GPIO_voidWritePin    (u8 COPY_u8PortId , u8 COPY_u8PinId , u8 COPY_u8Value);
u8                    GPIO_u8ReadPin       (u8 COPY_u8PortId , u8 COPY_u8PinId );
GPIO_TypedefErrorType GPIO_voidSetPortType (u8 COPY_u8PortId , u8 COPY_u8PinType , u8 COPY_u8PullUp);
GPIO_TypedefErrorType GPIO_voidWritePort   (u8 COPY_u8PortId , u8 COPY_u8Value);
u8                    GPIO_u8ReadPort      (u8 COPY_u8PortId );

#endif
