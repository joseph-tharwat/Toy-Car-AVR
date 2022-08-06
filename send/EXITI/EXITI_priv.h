/************************************************/
/*Title		  : EXITI peripheral private file   */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 22, 2021					*/
/************************************************/




#ifndef EXITI_PRIV_H_
#define EXITI_PRIV_H_
///////////////////////////////////////////////
#define EXITI_u8_ENABLE     	1
#define EXITI_u8_DISABLE     	0
/////////////////////////////////////////////////
#define EXITI_u8_Low_LEVEL 		0
#define EXITI_u8_ALC 			1
#define EXITI_u8_RISING_EDGE 	2
#define EXITI_u8_FALLING_EDGE 	3 
/////////////////////////////////////////////////
#define MCUCR 					*((volatile u8*)0x55) //MODE OF INTERRUPT INT0,INT1
#define MCUCSR 					*((volatile u8*)0x54) //MODE OF INTERRUPT INT2
#define GICR 					*((volatile u8*)0x5B) //PIE (peripheral INTERRUPT ENABLE)
#define GIFR 					*((volatile u8*)0x5A) //PIF (peripheral INTERRUPT FLAG) 
/////////////////////////////////////////////////
#define ISC00 					0 
#define ISC01 					1 
#define ISC10 					2 
#define ISC11 					3 
#define ISC2 					6 
#define INT0 					6//PIE(GICR) 
#define INT1					7//PIE(GICR) 
#define INT2					5//PIE(GICR) 
#define INTF0 					6//PIF(GIFR)
#define INTF1					7//PIF(GIFR)
#define INTF2					5//PIF(GIFR)



#endif