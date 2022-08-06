/************************************************/
/*Title		  : ADC peripheral programe file    */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 23, 2021					*/
/************************************************/
#include"services/STD_type.h"
#include"services/Bit_Math.h"

#include "ADC_config.h"
#include "ADC_priv.h"
#include "ADC_int.h"
#include "avr/delay.h"

///////////////////////////////////////////////////////////////////////////INTERRUPT

void (* ADC_CallBack)(void);
void __vector_16 (void) __attribute__((signal,used));

void __vector_16 (void)
{
	ADC_CallBack();
}
/////////////////////////////////////////////////////////////////////////////////////INITAIL
void ADC_vid_INIT  (void)
{
	///////////REF SELECT
	#if ADC_u8_Volt_Ref_Selec==ADC_u8_Active_AREF
	CLEAR_BIT(ADMUX,ADC_u8_REFS0)
	CLEAR_BIT(ADMUX,ADC_u8_REFS1)
	#elif ADC_u8_Volt_Ref_Selec==ADC_u8_Active_VCC
	SET_BIT(ADMUX,ADC_u8_REFS0)
	CLEAR_BIT(ADMUX,ADC_u8_REFS1)
	#elif ADC_u8_Volt_Ref_Selec==ADC_u8_Active_Internal_Refernce
	SET_BIT(ADMUX,ADC_u8_REFS0)
	SET_BIT(ADMUX,ADC_u8_REFS1)
	#endif
	///////////MODE SELECT
	#if ADC_u8_Mode==ADC_u8_8Bit_Mode        //left adjusted
	CLEAR_BIT(ADMUX,ADC_u8_ADLAR)
	#elif ADC_u8_Mode==ADC_u8_10Bit_Mode		 //right adjusted
	CLEAR_BIT(ADMUX,ADC_u8_ADLAR)
	#endif
	///////////Prescaler SELECT
	#if ADC_u8_Prescaler_selec==ADC_u8_Prescaler_2
	CLEAR_BIT(ADMUX,ADC_u8_ADPS0)
	CLEAR_BIT(ADMUX,ADC_u8_ADPS1)
	CLEAR_BIT(ADMUX,ADC_u8_ADPS2)
	#elif ADC_u8_Prescaler_selec==ADC_u8_Prescaler_4
	CLEAR_BIT(ADMUX,ADC_u8_ADPS0)
	SET_BIT(ADMUX,ADC_u8_ADPS1)
	CLEAR_BIT(ADMUX,ADC_u8_ADPS2)
	#elif ADC_u8_Prescaler_selec==ADC_u8_Prescaler_8
	SET_BIT(ADMUX,ADC_u8_ADPS0)
	SET_BIT(ADMUX,ADC_u8_ADPS1)
	CLEAR_BIT(ADMUX,ADC_u8_ADPS2)
	#elif ADC_u8_Prescaler_selec==ADC_u8_Prescaler_16
	CLEAR_BIT(ADMUX,ADC_u8_ADPS0)
	CLEAR_BIT(ADMUX,ADC_u8_ADPS1)
	SET_BIT(ADMUX,ADC_u8_ADPS2)
	#elif ADC_u8_Prescaler_selec==ADC_u8_Prescaler_32
	SET_BIT(ADMUX,ADC_u8_ADPS0)
	CLEAR_BIT(ADMUX,ADC_u8_ADPS1)
	SET_BIT(ADMUX,ADC_u8_ADPS2)
	#elif ADC_u8_Prescaler_selec==ADC_u8_Prescaler_64
	CLEAR_BIT(ADMUX,ADC_u8_ADPS0)
	SET_BIT(ADMUX,ADC_u8_ADPS1)
	SET_BIT(ADMUX,ADC_u8_ADPS2)
	#elif ADC_u8_Prescaler_selec==ADC_u8_Prescaler_128
	SET_BIT(ADMUX,ADC_u8_ADPS0)
	SET_BIT(ADMUX,ADC_u8_ADPS1)
	SET_BIT(ADMUX,ADC_u8_ADPS2)
	#endif
	//////////////ENABLE ADC
	SET_BIT(ADCSRA,ADC_u8_ADEN)
	//////////////DISABL INTERRUPT
	CLEAR_BIT(ADCSRA,ADC_u8_ADIE)
	//////////////CLEAR INTERRUPT FLAG
	CLEAR_BIT(ADCSRA,ADC_u8_ADIF)

}
void ADC_vid_ADC_ENABLE   (void)
{SET_BIT(ADCSRA,ADC_u8_ADEN)}
void ADC_vid_ADC_DISABLE   (void)
{CLEAR_BIT(ADCSRA,ADC_u8_ADEN)}
//////////////////////////////////////////////////////////////////////////////INTERRUPT
void ADC_vid_SetCallBack(void (*copy_ptr)(void))
{
	ADC_CallBack =copy_ptr ;
}
void ADC_vid_INT_ENABLE   (void)
{	SET_BIT(ADCSRA,ADC_u8_ADIE)}
void ADC_vid_INT_DISABLE   (void)
{
	CLEAR_BIT(ADCSRA,ADC_u8_ADIE)
}

//////////////////////////////////////////////////////////////////////////////8bit mode
#if ADC_u8_Mode==ADC_u8_8Bit_Mode        //left adjusted
u16 ADC_u16_ReadChannel(u8 Copy_u8_Channel)
{
	u16 Loc_u16_low,Loc_u16_high;
		CLEAR_BITS(ADMUX,ADC_u8_MUX_BITS)			//clear MUX BITS
		SET_BITS(ADMUX,Copy_u8_Channel)				// select channel
		SET_BIT(ADCSRA,ADC_u8_ADSC)					//start conversion
		//_delay_ms(20);

		while(GET_BIT(ADCSRA,ADC_u8_ADIF)==1 )
		{}
		SET_BIT(ADCSRA,ADC_u8_ADIF)

		_delay_ms(20);

		Loc_u16_low=ADCL;
		Loc_u16_high=ADCH;


		 return Loc_u16_low ;
}	             
u8 ADC_u8_GetLastValue(void)
{return ADCH;  }
f32 ADC_f32_GetAnalogValue(void)
{return (f32)(((f32)ADCH*(f32)ADC_u8_Voltage_Refrence)/(f32)254);}
	
//////////////////////////////////////////////////////////////////////////////10bit mode
#elif ADC_u8_Mode==ADC_u8_10Bit_Mode		 //right adjusted
u16 ADC_u16_ReadChannel(u8 Copy_u8_Channel)
{
	u16 Loc_u16_low,Loc_u16_high;
	CLEAR_BITS(ADMUX,ADC_u8_MUX_BITS)			//clear MUX BITS
	SET_BITS(ADMUX,Copy_u8_Channel)				// select channel
	SET_BIT(ADCSRA,ADC_u8_ADSC)					//start conversion
	//_delay_ms(20);

	while(GET_BIT(ADCSRA,ADC_u8_ADIF)==0 );
	SET_BIT(ADCSRA,ADC_u8_ADIF)

	//_delay_ms(20);

	Loc_u16_low=ADCL;
	Loc_u16_high=ADCH;

	
	 return Loc_u16_low|(Loc_u16_high<<8);
 

}  
u16 ADC_u16_GetLastValue(void)
{
	u16 Loc_u16_low,Loc_u16_high;

	Loc_u16_low=ADCL;
	Loc_u16_high=ADCH;

	return Loc_u16_low|(Loc_u16_high<<8);}
f32 ADC_f32_GetAnalogValue(void)
{return (f32)(((f32)(ADC_u16_GetLastValue())*(f32)ADC_u8_Voltage_Refrence)/(f32)1023);
}
#endif







    
