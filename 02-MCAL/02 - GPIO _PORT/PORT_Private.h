/**************************************************/
/*Author : Rashad                                 */
/*Date   : 16 MAY 2022                            */
/*Version: V01                                    */
/**************************************************/
#ifndef PORTPRIVATE_H
#define PORTPRIVATE_H

// register defination port A
//****************************************************************
#define GPIO_RPORTA  *((u8*)0x3B)
#define GPIO_RDDRA   *((u8*)0x3A)
#define GPIO_RPINA   *((u8*)0x39)
//****************************************************************

// register defination port B
//****************************************************************
#define GPIO_RPORTB  *((u8*)0x38)
#define GPIO_RDDRB   *((u8*)0x37)
#define GPIO_RPINB   *((u8*)0x36)
//****************************************************************

// register defination port C
//****************************************************************
#define GPIO_RPORTC  *((u8*)0x35)
#define GPIO_RDDRC   *((u8*)0x34)
#define GPIO_RPINC   *((u8*)0x33)
//****************************************************************

// register defination port D
//****************************************************************
#define GPIO_RPORTD  *((u8*)0x32)
#define GPIO_RDDRD   *((u8*)0x31)
#define GPIO_RPIND   *((u8*)0x30)
//****************************************************************

// concatenation functions 
//****************************************************************
#define CONC(B7,B6,B5,B4,B3,B2,B1,B0) LINK(B7,B6,B5,B4,B3,B2,B1,B0)
#define LINK(B7,B6,B5,B4,B3,B2,B1,B0) 0b##B7##B6##B5##B4##B3##B2##B1##B0
//****************************************************************

// registers data concatenation  
//****************************************************************
#define PORTA_DIR CONC(PORTA_PIN7_DIR,PORTA_PIN6_DIR,PORTA_PIN5_DIR,PORTA_PIN4_DIR,PORTA_PIN3_DIR,PORTA_PIN2_DIR,PORTA_PIN1_DIR,PORTA_PIN0_DIR)
#define PORTB_DIR CONC(PORTA_PIN7_DIR,PORTB_PIN6_DIR,PORTB_PIN5_DIR,PORTB_PIN4_DIR,PORTB_PIN3_DIR,PORTB_PIN2_DIR,PORTB_PIN1_DIR,PORTB_PIN0_DIR)
#define PORTC_DIR CONC(PORTC_PIN7_DIR,PORTC_PIN6_DIR,PORTC_PIN5_DIR,PORTC_PIN4_DIR,PORTC_PIN3_DIR,PORTC_PIN2_DIR,PORTC_PIN1_DIR,PORTC_PIN0_DIR)
#define PORTD_DIR CONC(PORTD_PIN7_DIR,PORTD_PIN6_DIR,PORTD_PIN5_DIR,PORTD_PIN4_DIR,PORTD_PIN3_DIR,PORTD_PIN2_DIR,PORTD_PIN1_DIR,PORTD_PIN0_DIR)

#define PORTA_VAL CONC(PORTA_PIN7_VAL,PORTA_PIN6_VAL,PORTA_PIN5_VAL,PORTA_PIN4_VAL,PORTA_PIN3_VAL,PORTA_PIN2_VAL,PORTA_PIN1_VAL,PORTA_PIN0_VAL)
#define PORTB_VAL CONC(PORTA_PIN7_VAL,PORTB_PIN6_VAL,PORTB_PIN5_VAL,PORTB_PIN4_VAL,PORTB_PIN3_VAL,PORTB_PIN2_VAL,PORTB_PIN1_VAL,PORTB_PIN0_VAL)
#define PORTC_VAL CONC(PORTC_PIN7_VAL,PORTC_PIN6_VAL,PORTC_PIN5_VAL,PORTC_PIN4_VAL,PORTC_PIN3_VAL,PORTC_PIN2_VAL,PORTC_PIN1_VAL,PORTC_PIN0_VAL)
#define PORTD_VAL CONC(PORTD_PIN7_VAL,PORTD_PIN6_VAL,PORTD_PIN5_VAL,PORTD_PIN4_VAL,PORTD_PIN3_VAL,PORTD_PIN2_VAL,PORTD_PIN1_VAL,PORTD_PIN0_VAL)
//****************************************************************

#endif