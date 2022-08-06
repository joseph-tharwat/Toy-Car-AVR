/************************************************/
/*Title		  : EXITI peripheral programe file  */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 22, 2021					*/
/************************************************/
#include"services/STD_type.h"
#include"services/Bit_Math.h"

#include "EXITI_int.h"
#include "EXITI_config.h"
#include "EXITI_priv.h"

void (* EXITI_CallBack_INT0)(void);
void (* EXITI_CallBack_INT1)(void);
void (* EXITI_CallBack_INT2)(void);

void __vector_1(void) __attribute__((signal,used));
void __vector_2(void) __attribute__((signal,used));
void __vector_3(void) __attribute__((signal,used));

void __vector_1(void)
{
	EXITI_CallBack_INT0();
}
void __vector_2(void)
{
	EXITI_CallBack_INT1();
}
void __vector_3(void)
{
	EXITI_CallBack_INT2();
}

void EXITI_vid_INTIAL   (void)
{
	//////////MODE_SELECT
	#if EXITI_u8_INT0==EXITI_u8_ENABLE 
		#if EXITI_u8_MODE_INT0==EXITI_u8_Low_LEVEL
		CLEAR_BIT(MCUCR,ISC00)
		CLEAR_BIT(MCUCR,ISC01)
		#elif EXITI_u8_MODE_INT0==EXITI_u8_ALC
		SET_BIT(MCUCR,ISC00)
		CLEAR_BIT(MCUCR,ISC01)
		#elif EXITI_u8_MODE_INT0==EXITI_u8_FALLING_EDGE
		CLEAR_BIT(MCUCR,ISC00)
		SET_BIT(MCUCR,ISC01)
		#elif EXITI_u8_MODE_INT0==EXITI_u8_RISING_EDGE
		SET_BIT(MCUCR,ISC00)
		SET_BIT(MCUCR,ISC01)
		#endif
	#endif
	#if EXITI_u8_INT1==EXITI_u8_ENABLE 
		#if EXITI_u8_MODE_INT1==EXITI_u8_Low_LEVEL
		CLEAR_BIT(MCUCR,ISC10)
		CLEAR_BIT(MCUCR,ISC11)
		#elif EXITI_u8_MODE_INT1==EXITI_u8_ALC
		SET_BIT(MCUCR,ISC10)
		CLEAR_BIT(MCUCR,ISC11)
		#elif EXITI_u8_MODE_INT1==EXITI_u8_FALLING_EDGE
		CLEAR_BIT(MCUCR,ISC10)
		SET_BIT(MCUCR,ISC11)
		#elif EXITI_u8_MODE_INT1==EXITI_u8_RISING_EDGE
		SET_BIT(MCUCR,ISC10)
		SET_BIT(MCUCR,ISC11)
		#endif
	#endif
	#if EXITI_u8_INT2==EXITI_u8_ENABLE 
		#if EXITI_u8_MODE_INT2==EXITI_u8_FALLING_EDGE
		CLEAR_BIT(MCUCSR,ISC2)
		#elif EXITI_u8_MODE_INT2==EXITI_u8_RISING_EDGE
		SET_BIT(MCUCSR,ISC2)
		#endif
	#endif
	///////CLEAR FLAGS
	CLEAR_BIT(GIFR,INTF0)
	CLEAR_BIT(GIFR,INTF1)
	CLEAR_BIT(GIFR,INTF2)
	///////DISABLE INTERRUPT
	EXITI_vid_INT0_DISABLE();
	EXITI_vid_INT1_DISABLE();
	EXITI_vid_INT2_DISABLE();
}


void EXITI_vid_SetCallBack(void (*copy_ptr)(void),u8 Copy_u8_INT_Select)
{
	if(Copy_u8_INT_Select==EXITI_INT0)
		EXITI_CallBack_INT0=copy_ptr;
	else if(Copy_u8_INT_Select==EXITI_INT1)
		EXITI_CallBack_INT1=copy_ptr;
	else if(Copy_u8_INT_Select==EXITI_INT2)
		EXITI_CallBack_INT2=copy_ptr;
}



void EXITI_vid_INT0_ENABLE   (void)
{SET_BIT(GICR,INT0)}
void EXITI_vid_INT1_ENABLE   (void)
{SET_BIT(GICR,INT1)}
void EXITI_vid_INT2_ENABLE   (void)
{SET_BIT(GICR,INT2)}
void EXITI_vid_INT0_DISABLE   (void)
{CLEAR_BIT(GICR,INT0)}
void EXITI_vid_INT1_DISABLE   (void)
{CLEAR_BIT(GICR,INT1)}
void EXITI_vid_INT2_DISABLE   (void)
{CLEAR_BIT(GICR,INT2)}
