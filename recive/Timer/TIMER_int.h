/************************************************/
/*Title		  : TIMER peripheral interface file */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 25, 2021					*/
/************************************************/
#include"services/STD_type.h"

#ifndef TIMER_INT_H_
#define TIMER_INT_H_




void TIMER0_vid_Init(void);
void TIMER0_vid_SetTimerReg(u8 Copy_u8_Val);
void TIMER0_vid_SetCompareReg(u8 Copy_u8_Val);

void TIMER0_vid_EnableOVInt(void);
void TIMER0_vid_DisableOVInt(void);

void TIMER0_vid_EnableCTCInt(void);
void TIMER0_vid_DisableCTCInt(void);

void TIMER0_vid_SetOVIntCallBack(void (*Copy_ptr)(void));
void TIMER0_vid_SetCTCIntCallBack(void (*Copy_ptr)(void));


void TIMER2_vid_Init(void);
void TIMER2_vid_SetTimerReg(u8 Copy_u8_Val);
void TIMER2_vid_SetCompareReg(u8 Copy_u8_Val);
void TIMER2_vid_EnableOVInt(void);
void TIMER2_vid_DisableOVInt(void);

void TIMER2_vid_EnableCTCInt(void);
void TIMER2_vid_DisableCTCInt(void);

void TIMER2_vid_SetOVIntCallBack(void (*Copy_ptr)(void));
void TIMER2_vid_SetCTCIntCallBack(void (*Copy_ptr)(void));





#endif
