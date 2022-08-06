/************************************************/
/*Title		  : USART peripheral CONFIGER file  */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 29, 2021					*/
/************************************************/




#ifndef USART_CONFIG_H_
#define USART_CONFIG_H_



/*CHOOS FRAME_SIZE_SELECT*/
//USART_u8_5_BIT		
//USART_u8_6_BIT			
//USART_u8_7_BIT 	
//USART_u8_8_BIT 	
//USART_u8_9_BIT 	

#define USART_u8_FRAME_SIZE_SELECT		USART_u8_8_BIT

/*CHOOS USART Mode Select*/
//USART_u8_Asyn_Oper	
//USART_u8_Syn_Oper 	
#define USART_u8_MODE_Select		USART_u8_Asyn_Oper


/*CHOOS USART Parity Mode Select*/
//USART_u8_Disabled	
//USART_u8_Enabled_Even_Parity
//USART_u8_Enabled_Odd_Parity
#define USART_u8_Parity_MODE_Select		USART_u8_Disabled

/*CHOOS USART Stop Bit Select*/
//USART_u8_1_BIT	
//USART_u8_2_BIT 	
#define USART_u8_Stop_Bit_Select		USART_u8_1_BIT

/*CHOOS USART  Clock Polarity  Select IN USART_u8_Syn_Oper  MODE*/
//USART_u8_Disabled	
//USART_u8_Enabled	
#define USART_u8_Clock_Polarity		USART_u8_Disabled

#define USART_u8_CPU_CLOCK			1000000UL
#define USART_u8_BAUD_RATE			9600





#endif
