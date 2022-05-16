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
#include "LEDANIMATION_Private.h"
#include "LEDANIMATION_Config.h"


//animation functions 
//**********************************************************************
//**********************************************************************

//blink all the leds at the same time 
//*****************************************

void LEDANIMATION_voidBlinkAll ()
{
	GPIO_voidWritePort   (LEDANIMATION_PORT , 1);           // * * * * * * * * 
	_delay_ms(LEDANIMATION_DELAY);
	GPIO_voidWritePort   (LEDANIMATION_PORT , 0);           // - - - - - - - -
	_delay_ms(LEDANIMATION_DELAY);
}

//*****************************************


//turn on leds sequentially from 0 to 7 
//*****************************************

void LEDANIMATION_voidSequance ()
{
	u8 local_u8Counter = 0 ;                                                 //for loop counter
	for (local_u8Counter=0 ; local_u8Counter<8 ; local_u8Counter++)          //animation loop
	{
		switch(local_u8Counter)                                              //to handle the three possible cases : start (0) , end (7) , default(1-6)
		{
			case 0  :                                                       
				
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8Counter   , 1 );  // * - - - - - - -
				_delay_ms(LEDANIMATION_DELAY);
				break;
			
			case 7  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8Counter-1 , 0 );  // - - - - - - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8Counter   , 1 );  // - - - - - - - *
				_delay_ms(LEDANIMATION_DELAY);
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8Counter   , 0 );  // - - - - - - - -
				break; 
			
			default :
				
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8Counter-1 , 0 );  // - - - - - - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8Counter   , 1 );  
				_delay_ms(LEDANIMATION_DELAY);
				break;
		}
	}
} 


//*****************************************

//turn on leds sequentially from 7 to 0 
//*****************************************

void LEDANIMATION_voidSequanceReversed ()
{
	s8 local_s8Counter = 7 ;                                                  //for loop counter
	for (local_s8Counter = 7 ; local_s8Counter>=0 ; local_s8Counter--)        //animation loop
	{
		switch(local_s8Counter)                                               //to handle the three possible cases : start (7) , end (0) , default(1-6)
		{
			case 0  :
		
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8Counter+1 , 0 );   // - - - - - - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8Counter   , 1 );   // * - - - - - - -
				_delay_ms(LEDANIMATION_DELAY);
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8Counter   , 0 );   // - - - - - - - -
				break;
				
			case 7  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8Counter   , 1 );   // - - - - - - - *
				_delay_ms(LEDANIMATION_DELAY);
				break;
			
			default :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8Counter+1 , 0 );   // - - - - - - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8Counter   , 1 );
				_delay_ms(LEDANIMATION_DELAY);
				break;
		}
	}
}

//*****************************************

//turn on leds sequentially from 0 and 7 simultaneously to the center  
//**************************************************************************
void LEDANIMATION_voidToCenter ()
{
	u8 local_u8upCounter  =0;                                                   //counter from 0 to 3
	s8 local_s8downCounter=7;                                                   //counter from 7 to 4
	for (local_u8upCounter=0 ; local_u8upCounter<4 ; local_u8upCounter++)       //animation loop
	{                                                                           
		switch(local_u8upCounter)                                               //to handle the three possible cases : start (0) , end (3) , default(1-2)
		{
		
			case 0  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 ); // * - - - - - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 ); // * - - - - - - *
				_delay_ms(LEDANIMATION_DELAY);
				local_s8downCounter--;                                          //update the down counter
				break;
			
			case 3  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 ); // - - - * - - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 ); // - - - * * - - -
				_delay_ms(LEDANIMATION_DELAY);
				GPIO_voidWritePort   (LEDANIMATION_PORT , 0);                          // - - - - - - - - 
				break;
			
			default :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 );
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 );
				_delay_ms(LEDANIMATION_DELAY);
				local_s8downCounter--;
				break;
		}
	}
}

//**************************************************************************

//turn on leds sequentially from 3 and 4 simultaneously to out  
//**************************************************************************

void LEDANIMATION_voidToOut ()
{
	u8 local_u8upCounter  =4;                                                    //counter from 4 to 7
	s8 local_s8downCounter=3;                                                    //counter from 3 to 0
	for (local_u8upCounter=4 ; local_u8upCounter<8 ; local_u8upCounter++)        //animation loop
	{
		switch(local_u8upCounter)                                                //to handle the three possible cases : start (4) , end (7) , default(5-6)
		{
			case 4  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 );  // - - - - * - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 );  // - - - * * - - -
				_delay_ms(LEDANIMATION_DELAY);
				local_s8downCounter--;                                           //update the down counter
				break; 
				
			case 7  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 );  // - - - - - - - *
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 );  // * - - - - - - *
				_delay_ms(LEDANIMATION_DELAY);
				GPIO_voidWritePort   (LEDANIMATION_PORT , 0);                           // - - - - - - - - 
				break;
			
			default :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 );
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 );
				_delay_ms(LEDANIMATION_DELAY);
				local_s8downCounter--;
				break;
		}
	}
}

//**************************************************************************

//turn on leds sequentially from 0 to 7 then from 7 to 0  
//**************************************************************************

void LEDANIMATION_voidPingPong ()
{
	LEDANIMATION_voidSequance();           // - - - - - - - - >
	LEDANIMATION_voidSequanceReversed();   // < - - - - - - - -
}

//**************************************************************************

//turn on leds sequentially from 0 and 7 simultaneously to center then turn them off from 3 and 4 to out 
//**************************************************************************

void LEDANIMATION_voidInOut ()
{
	u8 local_u8upCounter  =0;                                                     //counter from 0 to 3 for the first animation 
	s8 local_s8downCounter=7;                                                     //counter from 7 to 4 for the first animation 
	for (local_u8upCounter=0 ; local_u8upCounter<4 ; local_u8upCounter++)         //first animation loop
	{
		switch(local_u8upCounter)                                                 //to handle the three possible cases : start (0) , end (3) , default(1-2)
		{
			case 0  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 );   // * - - - - - - - 
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 );   // * - - - - - - *
				_delay_ms(LEDANIMATION_DELAY);
				local_s8downCounter--;                                            //update the down counter
				break;
			
			case 3  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 );   // * * * * - * * *
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 );   // * * * * * * * *
				_delay_ms(LEDANIMATION_DELAY);
				break;
			
			default :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter   , 1 );
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter     , 1 );
				_delay_ms(LEDANIMATION_DELAY);                           
				local_s8downCounter--;
				break;
		}
	}
	u8 local_u8upCounter2  =4;                                                     //counter from 4 to 7 for the second animation 
	s8 local_s8downCounter2=3;                                                     //counter from 3 to 0 for the second animation 
	for (local_u8upCounter2=4 ; local_u8upCounter2<8 ; local_u8upCounter2++)       //second animation loop
	{                                                                              
		switch(local_u8upCounter2)                                                 //to handle the three possible cases : start (4) , end (7) , default(5-6)
		{
			case 4  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter2     , 0 );   // * * * * - * * *
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter2   , 0 );   // * * * - - * * *
				_delay_ms(LEDANIMATION_DELAY);
				local_s8downCounter2--;                                            //update the down counter
				break;
			
			case 7  :
			
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter2     , 0 );   // * - - - - - - -
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter2   , 0 );   // - - - - - - - -
				_delay_ms(LEDANIMATION_DELAY);
				GPIO_voidWritePort   (LEDANIMATION_PORT , 0);
				break;
			
			default :
				
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8downCounter2   , 0 );
				GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8upCounter2     , 0 );
				_delay_ms(LEDANIMATION_DELAY);
				local_s8downCounter2--;
				break;
		}
	}
	
}

//**************************************************************************

//turn on leds sequentially from 0 to 7 then from 7 to 0 
//**************************************************************************

void LEDANIMATION_voidUpDown()
{
	u8 local_u8Counter = 0 ;                                              //counter from 0 to 7
	for (local_u8Counter=0 ; local_u8Counter<8 ; local_u8Counter++)       //turning on from 0 to 7 loop
	{
		GPIO_voidWritePin    (LEDANIMATION_PORT , local_u8Counter   , 1 );       
		_delay_ms(LEDANIMATION_DELAY);
	}
	
	
	GPIO_voidWritePort   (LEDANIMATION_PORT , 0);                                // - - - - - - - -
	
	s8 local_s8Counter = 7 ;                                              //counter from 7 to 0
	for (local_s8Counter = 7 ; local_s8Counter>=0 ; local_s8Counter--)    //turning on from 7 to 0 loop
	{
		GPIO_voidWritePin    (LEDANIMATION_PORT , local_s8Counter   , 1 );       
		_delay_ms(LEDANIMATION_DELAY);
	}
	
	GPIO_voidWritePort   (LEDANIMATION_PORT , 0);                                // - - - - - - - -
}

//**************************************************************************


//**********************************************************************
//**********************************************************************
