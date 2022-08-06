/************************************************/
/*Title		  : ADC peripheral CONFIGER file    */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 23, 2021					*/
/************************************************/




#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

////////////////// Voltage Reference Selection
/*
ADC_u8_Active_AREF				
ADC_u8_Active_Internal_Refernce  ///2.56V
ADC_u8_Active_VCC	
*/
#define ADC_u8_Volt_Ref_Selec 	ADC_u8_Active_VCC

////////////////// Mode Selection
/*
ADC_u8_8Bit_Mode	
ADC_u8_10Bit_Mode
*/
#define ADC_u8_Mode 	ADC_u8_10Bit_Mode
////////////////// Prescaler Selection
/*
Prescaler_2	
Prescaler_4	
Prescaler_8	
Prescaler_16	
Prescaler_32	
Prescaler_64	
Prescaler_128
*/
#define ADC_u8_Prescaler_selec 	Prescaler_128
/////////////////////////Voltage Refrence
#define ADC_u8_Voltage_Refrence     6



#endif
