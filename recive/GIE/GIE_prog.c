/************************************************/
/*Title		  : GIE peripheral programe file    */
/*Author 	  : fam shokry						*/
/*Release     : 2.0								*/
/*Last Update : Aug 22, 2021					*/
/************************************************/
#include"services/STD_type.h"
#include"services/Bit_Math.h"

#include "GIE_int.h"
#include "GIE_config.h"
#include "GIE_priv.h"


void GIE_vid_INTERENABLE   (void)
{
	SET_BIT(SRGE,I_BIT)
}
void GIE_vid_INTERDISABLE (void)
{
	
	CLEAR_BIT(SRGE,I_BIT)
}

