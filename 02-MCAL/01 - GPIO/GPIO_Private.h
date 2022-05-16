/**************************************************/
/*Author : Rashad                                 */
/*Date   : 28 FEB 2022                            */
/*Version: V01                                    */
/**************************************************/
#ifndef GPRIVATE_H
#define GPRIVATE_H

// register defination port A

#define GPIO_RPORTA  *((u8*)0x3B)
#define GPIO_RDDRA   *((u8*)0x3A)
#define GPIO_RPINA   *((u8*)0x39)

// register defination port B

#define GPIO_RPORTB  *((u8*)0x38)
#define GPIO_RDDRB   *((u8*)0x37)
#define GPIO_RPINB   *((u8*)0x36)

// register defination port C

#define GPIO_RPORTC  *((u8*)0x35)
#define GPIO_RDDRC   *((u8*)0x34)
#define GPIO_RPINC   *((u8*)0x33)

// register defination port D

#define GPIO_RPORTD  *((u8*)0x32)
#define GPIO_RDDRD   *((u8*)0x31)
#define GPIO_RPIND   *((u8*)0x30)

#endif