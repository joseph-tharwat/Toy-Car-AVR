/*
 * main.c
 *
 *  Created on: Aug 30, 2021
 *      Author: fam
 */


#include "DIO/DIO_int.h"
#include "GIE/GIE_int.h"
#include "USART/USART_int.h"
#include "Keypad/Keypad_int.h"
#include "EXITI/EXITI_int.h"
#include "ADC/ADC_int.h"

void fun_ISR0(void)
{
	USART_vid_SendChar(0x11);		//buzzer

}
void fun_ISR1(void)
{
	USART_vid_SendChar(0x12);		//leds
}

int main(void)
{
	DIO_vid_Init();
	ADC_vid_INIT();
	ADC_vid_ADC_ENABLE();
	USART_vid_INTIAL(9600);
	GIE_vid_INTERENABLE();
	EXITI_vid_INTIAL();
	EXITI_vid_INT1_ENABLE();
	EXITI_vid_INT0_ENABLE();
	EXITI_vid_SetCallBack(fun_ISR0,0);
	EXITI_vid_SetCallBack(fun_ISR1,1);
	DIO_vid_SetPinConf(26,DIO_u8_INPUT);
	DIO_vid_SetPinConf(27,DIO_u8_INPUT);
	DIO_vid_SetPinPullup(26);
	DIO_vid_SetPinPullup(27);
	u8  L_R_con_new,B_F_con_new,L_R_con_old=0,B_F_con_old=0;
	u8 mass=0;
	while(1)
	{
		ADC_u16_ReadChannel(0);
		L_R_con_new=(u8)ADC_f32_GetAnalogValue();
		ADC_u16_ReadChannel(1);
		B_F_con_new=(u8)ADC_f32_GetAnalogValue();
		if(L_R_con_old==0)
		{
			L_R_con_old=L_R_con_new;
			B_F_con_old=B_F_con_new;
		}
		if(L_R_con_old!=L_R_con_new)
		{
			L_R_con_old=L_R_con_new;
			switch(L_R_con_old)
				{
				case 1:
					USART_vid_SendChar(0x01);					//TIMER0_vid_SetCompareReg(2);
					break;
				case 2:
					USART_vid_SendChar(0x02);					//TIMER0_vid_SetCompareReg(22);
					break;
				case 3:
					USART_vid_SendChar(0x03);					//TIMER0_vid_SetCompareReg(41);
					break;
				case 4:
					mass=0x04;
					USART_vid_SendChar(0x04);					//TIMER0_vid_SetCompareReg(59);
					break;
				case 5:
					USART_vid_SendChar(0x05);					//TIMER0_vid_SetCompareReg(120);
					break;
				}
		}
		if(B_F_con_old!=B_F_con_new)
		{
			B_F_con_old=B_F_con_new;
			switch(B_F_con_new)
				{
				case 1:
					USART_vid_SendChar(0x06);						//TIMER2_vid_SetCompareReg(254);
																	//	DIO_vid_SetPinVal(17,0);
					break;
				case 2:
					USART_vid_SendChar(0x07);					//TIMER2_vid_SetCompareReg(100);
																//DIO_vid_SetPinVal(17,0);
					break;
				case 3:
					USART_vid_SendChar(0x08);					//TIMER2_vid_SetCompareReg(0);

					break;
				case 4:
					USART_vid_SendChar(0x09);					//TIMER2_vid_SetCompareReg(100);
																//DIO_vid_SetPinVal(17,1);
					break;
				case 5:
					USART_vid_SendChar(0x10);					//TIMER2_vid_SetCompareReg(254);
																//DIO_vid_SetPinVal(17,1);
					break;
				}
		}

	}

return 0;
}


