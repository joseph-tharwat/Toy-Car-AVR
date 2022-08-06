/************************************************/
/*Title		  : USART peripheral private file   */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 29, 2021					*/
/************************************************/




#ifndef USART_PRIV_H_
#define USART_PRIV_H_
///////////////////////////////////USART Mode Select
#define USART_u8_Asyn_Oper  	0
#define USART_u8_Syn_Oper    	1
///////////////////////////////////FRAME_SIZE_SELECT	
#define USART_u8_5_BIT		0
#define USART_u8_6_BIT		1
#define USART_u8_7_BIT		2
#define USART_u8_8_BIT 	3 
#define USART_u8_9_BIT 	4 
/////////////////////////////////////Parity Mode Select
#define USART_u8_Disabled				0
#define USART_u8_Enabled_Even_Parity	1
#define USART_u8_Enabled_Odd_Parity		2
///////////////////////////////////USART Mode Select
#define USART_u8_1_BIT  	0
#define USART_u8_2_BIT   	1
///////////////////////////////////USART Clock Polarity
#define USART_u8_Disabled 	0
#define USART_u8_Enabled  	1
/////////////////////////////////////////////////
#define UCSRB 					*((volatile u8*)0x2A) 
#define RXEN 					4 //ENABLE RX PIN
#define TXEN 					3 //ENABLE TX PIN
#define UCSZ2 					2 //FRAME_SIZE_SELECT
#define RXCIE 					7 // Complete Interrupt Enable
#define TXCIE 					6 // Complete Interrupt Enable
#define UDRIE 					5// Data Register Empty Interrupt Enable	
		
//////////
#define UCSRA 					*((volatile u8*)0x2B) 
#define RXC 					7 // Complete Interrupt Enable
#define UDRE 					5
/////////
#define UCSRC					*((volatile u8*)0x40) 
#define USBS 					3 //Stop Bit Select	
#define UCSZ1 					2 //FRAME_SIZE_SELECT	
#define UCSZ0					1 //FRAME_SIZE_SELECT	
#define UCPOL					0 //Clock Polarity	
#define	UPM0					4 //Parity Mode Select
#define	UPM1					5 //Parity Mode Select
#define	UMSEL					6  //USART Mode Select
#define URSEL					7
//////////
#define		UDR									*((volatile u8*)0x2C)
#define		UBRRH								*((volatile u8*)0x40)
#define		UBRRL								*((volatile u8*)0x29)
/////////////////////////////////////////////////





#endif
