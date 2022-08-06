/************************************************/
/*Title		  : TIMER peripheral private file   */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 22, 2021					*/
/************************************************/




#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

///////////////////////////////////////////////TIMER 
///////////////////////MODE
#define TIMER_u8_NORMAL   	0
#define TIMER_u8_CTC    	1
#define TIMER_u8_PWM		2
#define TIMER_u8_FAST_PWM	3
//////////////////////////////////TIMER_0 CTC EVENT
#define TIMER_u8_NO_ACTION	0
#define TIMER_u8_TOGGLE 	1
#define TIMER_u8_SET 		2
#define TIMER_u8_CLEAR	 	3 
/////////////////////////////////////////////////REGISTERS
////////////////////////////////////timer_0
/////////////////Interrupts
#define TIMSK 						(*(volatile u8 * )0x59)
#define TOIE0						0
#define OCIE0						1
////////////////FLAGS
#define TIFR  						(*(volatile u8 * )0x58)
#define TOV0						0
#define OCF0						1
//////////////CONTROL
#define TCCR0 						(*(volatile u8 * )0x53)
#define CS00						0
#define CS01						1
#define CS02						2
#define WGM01						3
#define COM00						4
#define COM01						5
#define WGM00						6
///////////////
#define TCNT0 						(*(volatile u8 * )0x52)//INTIAL VALUE
#define OCR0  						(*(volatile u8 * )0x5C)//COMPARE VALUE
////////////////////////////////////timer_2
/////////////////Interrupts
#define TOIE2						6
#define OCIE2						7
////////////////FLAGS
#define TOV2						6
#define OCF2						7
//////////////CONTROL
#define TCCR2 						(*(volatile u8 * )0x45)
#define CS20						0
#define CS21						1
#define CS22						2
#define WGM21						3
#define COM20						4
#define COM21						5
#define WGM20						6
///////////////
#define TCNT2 						(*(volatile u8 * )0x44)//INTIAL VALUE
#define OCR2  						(*(volatile u8 * )0x43)//COMPARE VALUE
//////////////////////////////////////CHOOSHE CLOCK SOURCE
#define TIMER_u8_NO_CLOCK_SOURCE 					1
#define TIMER_u8_INTERNAL_CLOCK						0
#define TIMER_u8_INTERNAL_CLOCK_PRE_8				2 
#define TIMER_u8_INTERNAL_CLOCK_PRE_64				3 
#define TIMER_u8_INTERNAL_CLOCK_PRE_256				4 
#define TIMER_u8_INTERNAL_CLOCK_PRE_1024			5 
#define TIMER_u8_EXTERNAL_CLOCK_FALLING_EDGE		6 
#define TIMER_u8_EXTERNAL_CLOCK_RISING_EDGE			7




#endif
