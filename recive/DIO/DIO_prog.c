/************************************************/
/*Title		  : DIO peripheral programe file    */
/*Author 	  : fam shokry						*/
/*Release     : 2.0								*/
/*Last Update : Aug 16, 2021					*/
/************************************************/
#include"services/STD_type.h"
#include"services/Bit_Math.h"

#include "DIO_int.h"
#include "DIO_config.h"
#include "DIO_priv.h"






void DIO_vid_Init(void)
{
	DDRA=DIO_u8_PORTA_DIRECTION;
	DDRB=DIO_u8_PORTB_DIRECTION;
	DDRC=DIO_u8_PORTC_DIRECTION;
	DDRD=DIO_u8_PORTD_DIRECTION;
	
}

void DIO_vid_SetPinVal(u8 copy_u8_PinNo,u8 copy_u8_PinVal)
{
	u8 loc_u8_PinNo=copy_u8_PinNo%Pin_numbers,loc_u8_PortNo=copy_u8_PinNo/Pin_numbers;
	switch(loc_u8_PortNo)
	{
		case Port_A:
		{
			if(copy_u8_PinVal==DIO_u8_HIGH)
				SET_BIT(PORTA,loc_u8_PinNo)
				//PORTA=PORTA | 1<<loc_u8_PinNo;
			else if(copy_u8_PinVal==DIO_u8_LOW)
				CLEAR_BIT(PORTA,loc_u8_PinNo)
			//PORTA=PORTA & ~(1<<loc_u8_PinNo);
			break;}
		case Port_B:
		{
			if(copy_u8_PinVal==DIO_u8_HIGH)
				SET_BIT(PORTB,loc_u8_PinNo)

			//PORTB=PORTB | 1<<loc_u8_PinNo;
			else if(copy_u8_PinVal==DIO_u8_LOW)
				CLEAR_BIT(PORTB,loc_u8_PinNo)
			//PORTB=PORTB & ~(1<<loc_u8_PinNo);
			break;}
		case Port_C:
		{
			if(copy_u8_PinVal==DIO_u8_HIGH)
				SET_BIT(PORTC,loc_u8_PinNo)
			//PORTC=PORTC | 1<<loc_u8_PinNo;
			else if(copy_u8_PinVal==DIO_u8_LOW)
				CLEAR_BIT(PORTC,loc_u8_PinNo)
			//PORTC=PORTC & ~(1<<loc_u8_PinNo);
			break;}
		case Port_D:
		{
			if(copy_u8_PinVal==DIO_u8_HIGH)
				SET_BIT(PORTD,loc_u8_PinNo)
			//PORTD=PORTD | 1<<loc_u8_PinNo;
			else if(copy_u8_PinVal==DIO_u8_LOW)
				CLEAR_BIT(PORTD,loc_u8_PinNo)
			//PORTD=PORTD & ~(1<<loc_u8_PinNo);
			break;}
	}
	
}

void DIO_vid_ClearPinVal(u8 copy_u8_PinNo,u8 copy_u8_PinVal)
{DIO_vid_SetPinVal(copy_u8_PinNo,DIO_u8_LOW);}




void DIO_vid_SetPinConf(u8 copy_u8_PinNo,u8 copy_u8_PinType)
{
	u8 loc_u8_PinNo=copy_u8_PinNo%Pin_numbers,loc_u8_PortNo=copy_u8_PinNo/Pin_numbers;
	switch(loc_u8_PortNo)
	{
		case Port_A:
		{
			if(copy_u8_PinType==DIO_u8_OUTPUT)
				SET_BIT(DDRA,loc_u8_PinNo)
				//PORTA=PORTA | 1<<loc_u8_PinNo;
			else if(copy_u8_PinType==DIO_u8_INPUT)
			{CLEAR_BIT(DDRA,loc_u8_PinNo)
			CLEAR_BIT(PORTA,loc_u8_PinNo)}
			//PORTA=PORTA & ~(1<<loc_u8_PinNo);
			break;}
		case Port_B:
		{
			if(copy_u8_PinType==DIO_u8_OUTPUT)
				SET_BIT(DDRB,loc_u8_PinNo)

			//PORTB=PORTB | 1<<loc_u8_PinNo;
			else if(copy_u8_PinType==DIO_u8_INPUT)
				{CLEAR_BIT(DDRB,loc_u8_PinNo)
			CLEAR_BIT(PORTB,loc_u8_PinNo)}
			//PORTB=PORTB & ~(1<<loc_u8_PinNo);
			break;}
		case Port_C:
		{
			if(copy_u8_PinType==DIO_u8_OUTPUT)
				SET_BIT(DDRC,loc_u8_PinNo)
			//PORTC=PORTC | 1<<loc_u8_PinNo;
			else if(copy_u8_PinType==DIO_u8_INPUT)
				{CLEAR_BIT(DDRB,loc_u8_PinNo)
			CLEAR_BIT(PORTB,loc_u8_PinNo)}
			//PORTC=PORTC & ~(1<<loc_u8_PinNo);
			break;}
		case Port_D:
		{
			if(copy_u8_PinType==DIO_u8_OUTPUT)
				SET_BIT(DDRD,loc_u8_PinNo)
			//PORTD=PORTD | 1<<loc_u8_PinNo;
			else if(copy_u8_PinType==DIO_u8_INPUT)
				{CLEAR_BIT(DDRD,loc_u8_PinNo)
			CLEAR_BIT(PORTD,loc_u8_PinNo)}
			//PORTD=PORTD & ~(1<<loc_u8_PinNo);
			break;}
	}
	
}

void DIO_vid_SetPinPullup(u8 copy_u8_PinNo)
{
	u8 loc_u8_PinNo=copy_u8_PinNo%Pin_numbers,loc_u8_PortNo=copy_u8_PinNo/Pin_numbers;
	switch(loc_u8_PortNo)
	{
		case Port_A:
		{
			CLEAR_BIT(DDRA,loc_u8_PinNo)
			SET_BIT(PORTA,loc_u8_PinNo)
			break;}
		case Port_B:
		{
			SET_BIT(PORTB,loc_u8_PinNo)
			CLEAR_BIT(DDRB,loc_u8_PinNo)
			break;}
		case Port_C:
		{
			SET_BIT(PORTC,loc_u8_PinNo)
			CLEAR_BIT(DDRC,loc_u8_PinNo)	
			break;}
		case Port_D:
		{
			CLEAR_BIT(DDRD,loc_u8_PinNo)
			SET_BIT(PORTD,loc_u8_PinNo)

			break;}
	}
	
}
	

u8 DIO_u8_GetPinVal(u8 copy_u8_PinNo)
{
	u8 loc_u8_PinNo=copy_u8_PinNo%Pin_numbers,loc_u8_PortNo=copy_u8_PinNo/Pin_numbers,loc_u8_PinVal;
	switch(loc_u8_PortNo)
	{
		case Port_A:
		{
				GET_BIT(loc_u8_PinVal,PINA,loc_u8_PinNo)
				//loc_u8_PinVal=PINA & 1<<loc_u8_PinNo;
			
			break;}
		case Port_B:
		{
			GET_BIT(loc_u8_PinVal,PINB,loc_u8_PinNo)
			//loc_u8_PinVal=PINB & 1<<loc_u8_PinNo;
			break;}
		case Port_C:
		{
			GET_BIT(loc_u8_PinVal,PINC,loc_u8_PinNo)
			//loc_u8_PinVal=PINC & 1<<loc_u8_PinNo;
			break;}
		case Port_D:
		{
			GET_BIT(loc_u8_PinVal,PIND,loc_u8_PinNo)
			//loc_u8_PinVal=PIND & 1<<loc_u8_PinNo;
			break;}
	}
	return loc_u8_PinVal;   ///To return 1 or 0
}


void DIO_vid_SetPortVal(u8 copy_u8_PortNo,u8 copy_u8_PortVal)
{
	switch(copy_u8_PortNo)
	{
		case Port_A:
		{

				PORTA=copy_u8_PortVal;

			break;}
		case Port_B:
		{
			PORTB=copy_u8_PortVal;
			break;}
		case Port_C:
		{
			PORTC=copy_u8_PortVal;
			break;}
		case Port_D:
		{
			PORTD=copy_u8_PortVal;;
			break;}
	}
	
}

void DIO_vid_ClearPortVal(u8 copy_u8_PortNo,u8 copy_u8_PortVal)
{DIO_vid_SetPortVal(copy_u8_PortNo,DIO_u8_LOW);}

u8 DIO_u8_GetPortVal(u8 copy_u8_PortNo)
{
	switch(copy_u8_PortNo)
	{
		case Port_A:
		{
			return PORTA;
		}
		case Port_B:
		{
			return PORTB;
		}
		case Port_C:
		{
			return PORTC;
		}
		case Port_D:
		{
			return PORTD;
		}

	}
	return 0;
}



