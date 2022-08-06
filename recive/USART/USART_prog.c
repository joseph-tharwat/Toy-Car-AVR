/************************************************/
/*Title		  : USART peripheral programe file  */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 29, 2021					*/
/************************************************/
#include"services/STD_type.h"
#include"services/Bit_Math.h"

#include "USART_int.h"
#include "USART_config.h"
#include "USART_priv.h"


void (* USART_CallBack_ISR_COMP_RX)(void);
void (* USART_CallBack_DATA_EMBTY)(void);
void (* USART_CallBack_COMP_TX)(void);

void __vector_13(void) __attribute__((signal,used));
void __vector_14(void) __attribute__((signal,used));
void __vector_15(void) __attribute__((signal,used));

void __vector_13(void)
{
	USART_CallBack_ISR_COMP_RX();
}
void __vector_14(void)
{
	USART_CallBack_DATA_EMBTY();
}
void __vector_15(void)
{
	USART_CallBack_COMP_TX();
}

void USART_vid_INTIAL   (long BaudRate)
{

	UCSRB=0x00;
	UCSRC=0x00;
	/////////////////ENABLE RX&&TX
	SET_BIT(UCSRB,RXEN)
	SET_BIT(UCSRB,TXEN)
	SET_BIT(UCSRC,URSEL)
	//DIO_vid_SetPinConf(24,0);
	//DIO_vid_SetPinConf(25,1);
	//////////FRAME_SIZE_SELECT
	#if USART_u8_FRAME_SIZE_SELECT==USART_u8_5_BIT
	CLEAR_BIT(UCSRC,UCSZ0)
	CLEAR_BIT(UCSRC,UCSZ1)
	CLEAR_BIT(UCSRB,UCSZ2)
	#elif USART_u8_FRAME_SIZE_SELECT==USART_u8_6_BIT
	SET_BIT(UCSRC,UCSZ0)
	CLEAR_BIT(UCSRC,UCSZ1)
	CLEAR_BIT(UCSRB,UCSZ2)
	#elif USART_u8_FRAME_SIZE_SELECT==USART_u8_7_BIT
	CLEAR_BIT(UCSRC,UCSZ0)
	SET_BIT(UCSRC,UCSZ1)
	CLEAR_BIT(UCSRB,UCSZ2)
	#elif USART_u8_FRAME_SIZE_SELECT==USART_u8_8_BIT
	SET_BIT(UCSRC,UCSZ0)
	SET_BIT(UCSRC,UCSZ1)
	CLEAR_BIT(UCSRB,UCSZ2)
	#elif USART_u8_FRAME_SIZE_SELECT==USART_u8_9_BIT
	SET_BIT(UCSRC,UCSZ0)
	SET_BIT(UCSRC,UCSZ1)
	SET_BIT(UCSRB,UCSZ2)
	#endif
	////////////////////////USART Mode Select	
	#if USART_u8_MODE_Select==USART_u8_Asyn_Oper
	CLEAR_BIT(UCSRC,UMSEL)
	CLEAR_BIT(UCSRC,UCPOL)
	#elif USART_u8_MODE_Select==USART_u8_Syn_Oper
	SET_BIT(UCSRC,UMSEL)
	//////////USART  Clock Polarity
	#if USART_u8_Clock_Polarity==USART_u8_Disabled
	CLEAR_BIT(UCSRC,UCPOL)
	#elif USART_u8_Clock_Polarity==USART_u8_Enabled
	SET_BIT(UCSRC,UCPOL)
	#endif
	#endif
	////////////////////////USART Parity Mode Select	
	#if USART_u8_Parity_MODE_Select==USART_u8_Disabled
	CLEAR_BIT(UCSRC,UPM0)
	CLEAR_BIT(UCSRC,UPM1)
	#elif USART_u8_Parity_MODE_Select==USART_u8_Enabled_Even_Parity
	CLEAR_BIT(UCSRC,UPM0)
	SET_BIT(UCSRC,UPM1)
	#elif USART_u8_Parity_MODE_Select==USART_u8_Enabled_Odd_Parity
	SET_BIT(UCSRC,UPM0)
	SET_BIT(UCSRC,UPM1)
	#endif	
	////////////////////////USART  Stop Bit Select
	#if USART_u8_Stop_Bit_Select==USART_u8_1_BIT
	CLEAR_BIT(UCSRC,USBS)
	#elif USART_u8_Stop_Bit_Select==USART_u8_2_BIT
	SET_BIT(UCSRC,USBS)
	#endif	
	
	u16 Local_16_BaudRate = (((1000000UL)/(16*BaudRate))-1);
		UBRRH = (unsigned char)(Local_16_BaudRate>>8)&0x0F ;
		UBRRL =(unsigned char) Local_16_BaudRate&0xFF ;

}





void USART_vid_SendChar(u8 Copy_u8_char)
{
	while(!(GET_BIT(UCSRA,UDRE))) ;

	UDR = Copy_u8_char ;

}

void USART_vid_SendString(u8* Copy_pu8_Str)
{
	while(*Copy_pu8_Str != '\0')
	{
		USART_vid_SendChar(*Copy_pu8_Str) ;
		Copy_pu8_Str++ ;
	}
}

void USART_u8_ReadChar(u8* Copy_pu8_char)
{
	while((GET_BIT(UCSRA,RXC))==0) ;

	*Copy_pu8_char = UDR ;

}







void USART_vid_SetCallBack(void (*copy_ptr)(void),u8 Copy_u8_INT_Select)
{
	if(Copy_u8_INT_Select==USART_COMP_RX)
		USART_CallBack_ISR_COMP_RX=copy_ptr;
	else if(Copy_u8_INT_Select==USART_COMP_TX)
		USART_CallBack_COMP_TX=copy_ptr;
	else if(Copy_u8_INT_Select==USART_DATA_EMBTY)
		USART_CallBack_DATA_EMBTY=copy_ptr;
}

void USART_vid_Enable_RXInt(void)
{
	
	SET_BIT(UCSRB,RXCIE) 
}

void USART_vid_Disable_RXInt(void)
{
	CLEAR_BIT(UCSRB,RXCIE)
}

void USART_vid_Enable_TXInt(void)
{
	
	SET_BIT(UCSRB,TXCIE) 
}
void USART_vid_Disable_TXInt(void)
{
	CLEAR_BIT(UCSRB,TXCIE);
}

void USART_vid_Enable_DataEmptyInt(void)
{
	
	SET_BIT(UCSRB,UDRIE)
}

void USART_vid_Disable_DataEmptyInt(void)
{
	CLEAR_BIT(UCSRB,UDRIE)
}

