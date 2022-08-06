/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: fam
 */


#include "DIO/DIO_int.h"
#include "GIE/GIE_int.h"
#include "USART/USART_int.h"
#include "Timer/TIMER_int.h"




int main(void)
{
	DIO_vid_Init();

	TIMER0_vid_Init();
	TIMER2_vid_Init();
	USART_vid_INTIAL(9600);
	GIE_vid_INTERENABLE();
	///////////MOTOR && SERVO INTIAL &&led && buzzer
	TIMER2_vid_SetCompareReg(0);
	TIMER0_vid_SetCompareReg(41);
	DIO_vid_SetPinVal(18,0);
	DIO_vid_SetPinVal(16,0);
	u8 mass=0;
	while(1)
	{

		USART_u8_ReadChar(&mass);

		switch(mass)
				{
				case 0x81:
					TIMER0_vid_SetCompareReg(2);
					break;

				case  0x82:
					TIMER0_vid_SetCompareReg(22);
					break;

				case  0x83:
					TIMER0_vid_SetCompareReg(41);
					break;

				case  0x84:
					TIMER0_vid_SetCompareReg(59);
					break;

				case  0x85:
					TIMER0_vid_SetCompareReg(120);
					break;

				case 0x86:
					TIMER2_vid_SetCompareReg(254);
					DIO_vid_SetPinVal(17,0);
					break;

				case 0x87:
					TIMER2_vid_SetCompareReg(100);
					DIO_vid_SetPinVal(17,0);
					break;

				case 0x88:
					TIMER2_vid_SetCompareReg(0);
					break;

				case 0x89:
					TIMER2_vid_SetCompareReg(100);
					DIO_vid_SetPinVal(17,1);
					break;

				case 0x90:
					TIMER2_vid_SetCompareReg(254);
					DIO_vid_SetPinVal(17,1);
					break;

				case 0x91:
					if(DIO_u8_GetPinVal(16)==0)
						DIO_vid_SetPinVal(16,1);
					else
						DIO_vid_SetPinVal(16,0);
					break;

				case 0x92:
					if(DIO_u8_GetPinVal(18)==0)
						DIO_vid_SetPinVal(18,1);
					else
						DIO_vid_SetPinVal(18,0);
					break;
				}
		mass=0;
	}

return 0;
}


