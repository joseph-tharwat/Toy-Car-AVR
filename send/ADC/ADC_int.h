/************************************************/
/*Title		  : ADC peripheral interface filebuf*/
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 23, 2021					*/
/************************************************/
#include"services/STD_type.h"

#ifndef ADC_INT_H_
#define ADC_INT_H_

;
void ADC_vid_INIT (void);
void ADC_vid_ADC_ENABLE   (void);
void ADC_vid_ADC_DISABLE   (void);

/////////////////////////////////////////////////////////////////////////////INTERRUPT
void ADC_vid_SetCallBack(void (*copy_ptr)(void));
void ADC_vid_INT_ENABLE   (void);
void ADC_vid_INT_DISABLE   (void);

//////////////////////////////////////////////////////////////////////////////8bit mode
#if ADC_u8_Mode==ADC_u8_8Bit_Mode        //left adjusted
u16 ADC_u16_ReadChannel(u8 Copy_u8_Channel);
u8 ADC_u8_GetLastValue(void);	             
f32 ADC_f32_GetAnalogValue(void);
	
//////////////////////////////////////////////////////////////////////////////10bit mode
#elif ADC_u8_Mode==ADC_u8_10Bit_Mode		 //right adjusted
u16 ADC_u16_ReadChannel(u8 Copy_u8_Channel);
u16 ADC_u8_GetLastValue(void);	             
f32 ADC_f32_GetAnalogValue(void);

#endif



#endif
