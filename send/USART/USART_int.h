/************************************************/
/*Title		  : USART peripheral interface file */
/*Author 	  : fam shokry						*/
/*Release     : 2.0								*/
/*Last Update : Aug 29, 2021					*/
/************************************************/
#include"services/STD_type.h"

#ifndef USART_INT_H_
#define USART_INT_H_


#define USART_COMP_RX 					0
#define USART_COMP_TX					1
#define USART_DATA_EMBTY				2

void USART_vid_INTIAL   (long BaudRate);

void USART_vid_SendChar(u8 Copy_u8_char);
void USART_vid_SendString(u8* Copy_pu8_Str);
void USART_u8_ReadChar(u8* Copy_pu8_char);



void USART_vid_SetCallBack(void (*copy_ptr)(void),u8 Copy_u8_INT_Select);

void USART_vid_Enable_RXInt(void);
void USART_vid_Disable_RXInt(void);
void USART_vid_Enable_TXInt(void);
void USART_vid_Disable_TXInt(void);
void USART_vid_Enable_DataEmptyInt(void);
void USART_vid_Disable_DataEmptyInt(void);






#endif
