/************************************************/
/*Title		  : EXITI peripheral interface file */
/*Author 	  : fam shokry						*/
/*Release     : 2.0								*/
/*Last Update : Aug 15, 2021					*/
/************************************************/
#include"services/STD_type.h"

#ifndef EXITI_INT_H_
#define EXITI_INT_H_


#define EXITI_INT0 					0
#define EXITI_INT1					1
#define EXITI_INT2					2

void EXITI_vid_INTIAL   (void);

void EXITI_vid_SetCallBack(void (*copy_ptr)(void),u8 Copy_u8_INT_Select);




void EXITI_vid_INT0_ENABLE   (void);
void EXITI_vid_INT1_ENABLE   (void);
void EXITI_vid_INT2_ENABLE   (void);
void EXITI_vid_INT0_DISABLE   (void);
void EXITI_vid_INT1_DISABLE   (void);
void EXITI_vid_INT2_DISABLE   (void);





#endif
