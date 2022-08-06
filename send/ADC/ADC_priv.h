v/************************************************/
/*Title		  : ADC peripheral private file     */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 23, 2021					*/
/************************************************/




#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/////////////////////////////////(ADMUX)
///////////REF SELECT
#define ADC_u8_Active_AREF					0	
#define ADC_u8_Active_Internal_Refernce		1	
#define ADC_u8_Active_VCC					2
#define ADC_u8_REFS0						6	
#define ADC_u8_REFS1						7
///////////MODE SELECT
#define ADC_u8_8Bit_Mode					0	//left adjusted
#define ADC_u8_10Bit_Mode					1	//right adjusted
#define ADC_u8_ADLAR						5	
///////////
#define ADC_u8_MUX_BITS						0xE0	//0b11100000

#define ADMUX 								*((volatile u8*)0x27) //MODE OF INTERRUPT INT0,INT1
/////////////////////////////////(ADCSRA)
///////////Prescaler SELECT
#define ADC_u8_Prescaler_2					0
#define ADC_u8_Prescaler_4					1
#define ADC_u8_Prescaler_8					2
#define ADC_u8_Prescaler_16					3
#define ADC_u8_Prescaler_32					4
#define ADC_u8_Prescaler_64					5
#define ADC_u8_Prescaler_128				6
#define ADC_u8_ADPS0						0	
#define ADC_u8_ADPS1						1
#define ADC_u8_ADPS2						2
////////////bins
#define ADC_u8_ADIE							3
#define ADC_u8_ADIF							4
#define ADC_u8_ADATE						5
#define ADC_u8_ADSC							6
#define ADC_u8_ADEN							7
#define ADCSRA 								*((volatile u8*)0x26) //MODE OF INTERRUPT INT0,INT1
/////////////////////result register
#define ADCH 								*((volatile u8*)0x25) 
#define ADCL 								*((volatile u8*)0x24) 
////////////////////PINS__CHANNELS
#define ADC0 			DIO_u8_PIN_0
#define ADC1           DIO_u8_PIN_1
#define ADC2           DIO_u8_PIN_2
#define ADC3           DIO_u8_PIN_3
#define ADC4           DIO_u8_PIN_4
#define ADC5           DIO_u8_PIN_5
#define ADC6           DIO_u8_PIN_6
#define ADC7           DIO_u8_PIN_7








#endif