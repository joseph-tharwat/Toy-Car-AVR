/************************************************/
/*Title		  : TIMER peripheral programe file  */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 25, 2021					*/
/************************************************/
#include"services/STD_type.h"
#include"services/Bit_Math.h"

#include "TIMER_int.h"
#include "TIMER_config.h"
#include "TIMER_priv.h"


///////////////////////////////////////////////Interrupts
/////////////////////////////////////timer_0
void (*TIMER0_OV_CallBack) (void) ;
void (*TIMER0_CTC_CallBack) (void) ;
void TIMER0_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER0_OV_CallBack = Copy_ptr ;
}

void TIMER0_void_SetCTCCallBack(void (*Copy_ptr) (void) ) 
{
	TIMER0_CTC_CallBack = Copy_ptr ;
	
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	
	TIMER0_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));

void __vector_10(void)
{
	TIMER0_CTC_CallBack();
}
///////////////////////////////////////timer_2
void (*TIMER2_OV_CallBack) (void) ;
void (*TIMER2_CTC_CallBack) (void) ;
void TIMER2_void_SetOVCallBack(void (*Copy_ptr) (void) )
{
	TIMER2_OV_CallBack = Copy_ptr ;
}

void TIMER2_void_SetCTCCallBack(void (*Copy_ptr) (void) )
{
	TIMER2_CTC_CallBack = Copy_ptr ;

}

void __vector_5(void) __attribute__((signal , used));
void __vector_5(void)
{

	TIMER2_OV_CallBack();
}

void __vector_4(void) __attribute__((signal , used));

void __vector_4(void)
{
	TIMER2_CTC_CallBack();
}
////////////////////////////
void TIMER0_vid_Init(void)
{
	#if(TIMER_u8_TIMER0_MODE == TIMER_u8_NORMAL)
		CLEAR_BIT(TCCR0 , WGM00)
		CLEAR_BIT(TCCR0 , WGM01)
	#elif(TIMER_u8_TIMER0_MODE == TIMER_u8_CTC)
		CLEAR_BIT(TCCR0 , WGM00)
		SET_BIT(TCCR0 , WGM01)
		#if(TIMER_u8_TIMER0_EVENT == TIMER_u8_NO_ACTION)
			CLEAR_BIT(TCCR0 , COM00)
			CLEAR_BIT(TCCR0 , COM01)
		#elif(TIMER_u8_TIMER0_EVENT == TIMER_u8_TOGGLE)
			SET_BIT(TCCR0 , COM00)
			CLEAR_BIT(TCCR0 , COM01)
		#elif(TIMER_u8_TIMER0_EVENT == TIMER_u8_CLEAR )
			CLEAR_BIT(TCCR0 , COM00)
			SET_BIT(TCCR0 , COM01)
		#elif(TIMER_u8_TIMER0_EVENT == TIMER_u8_SET )
			SET_BIT(TCCR0 , COM00)
			SET_BIT(TCCR0 , COM01)
		#endif

	#elif(TIMER_u8_TIMER0_MODE == TIMER_u8_FAST_PWM )
		SET_BIT(TCCR0 , WGM00)
		SET_BIT(TCCR0 , WGM01)
		#if(TIMER_u8_TIMER0_EVENT == TIMER_u8_NO_ACTION)
			CLEAR_BIT(TCCR0 , COM00)
			CLEAR_BIT(TCCR0 , COM01)
		#elif(TIMER_u8_TIMER0_EVENT == TIMER_u8_CLEAR )
			CLEAR_BIT(TCCR0 , COM00)
			SET_BIT(TCCR0 , COM01)
		#elif(TIMER_u8_TIMER0_EVENT == TIMER_u8_SET )
			SET_BIT(TCCR0 , COM00)
			SET_BIT(TCCR0 , COM01)
		#endif
	#elif(TIMER_u8_TIMER0_MODE == TIMER_u8_PWM )
		SET_BIT(TCCR0 , WGM00)
		CLEAR_BIT(TCCR0 , WGM01)
		#if(TIMER_u8_TIMER0_EVENT == TIMER_u8_NO_ACTION)
			CLEAR_BIT(TCCR0 , COM00)
			CLEAR_BIT(TCCR0 , COM01)
		#elif(TIMER_u8_TIMER0_EVENT == TIMER_u8_CLEAR )
			CLEAR_BIT(TCCR0 , COM00)
			SET_BIT(TCCR0 , COM01)
		#elif(TIMER_u8_TIMER0_EVENT == TIMER_u8_SET )
			SET_BIT(TCCR0 , COM00)
			SET_BIT(TCCR0 , COM01)
		#endif

	#endif
	#if(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_NO_CLOCK_SOURCE)
		CLEAR_BIT(TCCR0 , CS00)
		CLEAR_BIT(TCCR0 , CS01)
		CLEAR_BIT(TCCR0 , CS02)
	#elif(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK)
		SET_BIT(TCCR0 , CS00)
		CLEAR_BIT(TCCR0 , CS01)
		CLEAR_BIT(TCCR0 , CS02)
	#elif(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_8)
		CLEAR_BIT(TCCR0 , CS00)
		SET_BIT(TCCR0 , CS01)
		CLEAR_BIT(TCCR0 , CS02)
	#elif(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_64 )
		SET_BIT(TCCR0 , CS00)
		SET_BIT(TCCR0 , CS01)
		CLEAR_BIT(TCCR0 , CS02)
	#elif(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_256 )
		CLEAR_BIT(TCCR0 , CS00)
		CLEAR_BIT(TCCR0 , CS01)
		SET_BIT(TCCR0 , CS02)
	#elif(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_81024 )
		SET_BIT(TCCR0 , CS00)
		CLEAR_BIT(TCCR0 , CS01)
		SET_BIT(TCCR0 , CS02)
	#elif(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_EXTERNAL_CLOCK_FALLING_EDGE )
		SET_BIT(TCCR0 , CS01)
		CLEAR_BIT(TCCR0 , CS00)
		SET_BIT(TCCR0 , CS02)
	#elif(TIMER_u8_TIMER0_CLOCK_MODE == TIMER_u8_EXTERNAL_CLOCK_RISING_EDGE )
		SET_BIT(TCCR0 , CS01)
		SET_BIT(TCCR0 , CS00)
		SET_BIT(TCCR0 , CS02)

	#endif
	//////////////////////////Disable Interrupts
	CLEAR_BIT(TIMSK , TOIE0)
	CLEAR_BIT(TIMSK , OCIE0)
	//////////////////////////CLEAR FLAGS
	SET_BIT(TIFR , TOV0)
	SET_BIT(TIFR , OCF0)
	///////////////////////////Clear register
	TCNT0 = 0x00 ;
	OCR0 = 0x00 ;
}
void TIMER0_void_SetTimerReg(u8 Copy_u8Val)
{
	TCNT0 = Copy_u8Val ;
}

void TIMER0_vid_SetCompareReg(u8 Copy_u8Val)
{
	OCR0 = Copy_u8Val ;
}

void TIMER0_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , TOIE0)
}

void TIMER0_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , TOIE0)
}
void TIMER0_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , OCIE0)
}

void TIMER0_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , OCIE0)
}
////////////////////////////////////////////////////////////TIMER_2
void TIMER2_vid_Init(void)
{
	#if(TIMER_u8_TIMER2_MODE == TIMER_u8_NORMAL)
		CLEAR_BIT(TCCR2 , WGM20)
		CLEAR_BIT(TCCR2 , WGM21)
	#elif(TIMER_u8_TIMER2_MODE == TIMER_u8_CTC)
		CLEAR_BIT(TCCR2 , WGM20)
		SET_BIT(TCCR2 , WGM21)
		#if(TIMER_u8_TIMER2_EVENT == TIMER_u8_NO_ACTION)
			CLEAR_BIT(TCCR2 , COM20)
			CLEAR_BIT(TCCR2 , COM21)
		#elif(TIMER_u8_TIMER2_EVENT == TIMER_u8_TOGGLE)
			SET_BIT(TCCR2 , COM20)
			CLEAR_BIT(TCCR2 , COM21)
		#elif(TIMER_u8_TIMER2_EVENT == TIMER_u8_CLEAR )
			CLEAR_BIT(TCCR2 , COM20)
			SET_BIT(TCCR2 , COM21)
		#elif(TIMER_u8_TIMER2_EVENT == TIMER_u8_SET )
			SET_BIT(TCCR2 , COM20)
			SET_BIT(TCCR2 , COM21)
		#endif
		
	#elif(TIMER_u8_TIMER2_MODE == TIMER_u8_FAST_PWM )
		SET_BIT(TCCR2 , WGM20)
		SET_BIT(TCCR2 , WGM21)
		#if(TIMER_u8_TIMER2_EVENT == TIMER_u8_NO_ACTION)
			CLEAR_BIT(TCCR2 , COM20)
			CLEAR_BIT(TCCR2 , COM21)
		#elif(TIMER_u8_TIMER2_EVENT == TIMER_u8_CLEAR )
			CLEAR_BIT(TCCR2 , COM20)
			SET_BIT(TCCR2 , COM21)
		#elif(TIMER_u8_TIMER2_EVENT == TIMER_u8_SET )
			SET_BIT(TCCR2 , COM20)
			SET_BIT(TCCR2 , COM21)
		#endif		
	#elif(TIMER_u8_TIMER2_MODE == TIMER0_u8_PWM )
		SET_BIT(TCCR2 , WGM20)
		CLEAR_BIT(TCCR2 , WGM21)
		#if(TIMER_u8_TIMER2_EVENT == TIMER_u8_NO_ACTION)
			CLEAR_BIT(TCCR2 , COM20)
			CLEAR_BIT(TCCR2 , COM21)
		#elif(TIMER_u8_TIMER2_EVENT == TIMER_u8_CLEAR )
			CLEAR_BIT(TCCR2 , COM20)
			SET_BIT(TCCR2 , COM21)
		#elif(TIMER_u8_TIMER2_EVENT == TIMER_u8_SET )
			SET_BIT(TCCR2 , COM20)
			SET_BIT(TCCR2 , COM21)
		#endif		
		
	#endif
	#if(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_NO_CLOCK_SOURCE)
		CLEAR_BIT(TCCR2 , CS20)
		CLEAR_BIT(TCCR2 , CS21)
		CLEAR_BIT(TCCR2 , CS22)
	#elif(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK)
		SET_BIT(TCCR2 , CS20)
		CLEAR_BIT(TCCR2 , CS21)
		CLEAR_BIT(TCCR2 , CS22)
	#elif(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_8)
		CLEAR_BIT(TCCR2 , CS20)
		SET_BIT(TCCR2 , CS21)
		CLEAR_BIT(TCCR2 , CS22)
	#elif(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_64 )
		SET_BIT(TCCR2 , CS20)
		SET_BIT(TCCR2 , CS21)
		CLEAR_BIT(TCCR2 , CS22)
	#elif(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_256 )
		CLEAR_BIT(TCCR2 , CS20)
		CLEAR_BIT(TCCR2 , CS21)
		SET_BIT(TCCR2 , CS22)
	#elif(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_INTERNAL_CLOCK_PRE_81024 )
		SET_BIT(TCCR2 , CS20)
		CLEAR_BIT(TCCR2 , CS21)
		SET_BIT(TCCR2 , CS22)
	#elif(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_EXTERNAL_CLOCK_FALLING_EDGE )
		SET_BIT(TCCR2 , CS21)
		CLEAR_BIT(TCCR2 , CS20)
		SET_BIT(TCCR2 , CS22)
	#elif(TIMER_u8_TIMER2_CLOCK_MODE == TIMER_u8_EXTERNAL_CLOCK_RISING_EDGE )
		SET_BIT(TCCR2 , CS21)
		SET_BIT(TCCR2 , CS20)
		SET_BIT(TCCR2 , CS22)
		
	#endif
	//////////////////////////Disable Interrupts
	CLEAR_BIT(TIMSK , TOIE2)
	CLEAR_BIT(TIMSK , OCIE2)
	//////////////////////////CLEAR FLAGS
	SET_BIT(TIFR , TOV2)
	SET_BIT(TIFR , OCF2)
	///////////////////////////Clear register
	TCNT2 = 0x00 ;
	OCR2 = 0x00 ;
}
void TIMER2_void_SetTimerReg(u8 Copy_u8Val)
{
	TCNT2 = Copy_u8Val ;
}

void TIMER2_vid_SetCompareReg(u8 Copy_u8Val)
{
	OCR2 = Copy_u8Val ;
}

void TIMER2_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , TOIE2)
}

void TIMER2_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , TOIE2)
}
void TIMER2_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , OCIE2)
}

void TIMER2_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , OCIE2)
}
