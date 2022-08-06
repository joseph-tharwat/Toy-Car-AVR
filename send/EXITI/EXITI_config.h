/************************************************/
/*Title		  : EXITI peripheral CONFIGER file    */
/*Author 	  : fam shokry						*/
/*Release     : 1.0								*/
/*Last Update : Aug 22, 2021					*/
/************************************************/




#ifndef EXITI_CONFIG_H_
#define EXITI_CONFIG_H_


/*ENABLE  INT0,INT1,INT2*/
//EXITI_u8_ENABLE 
//EXITI_u8_DISABLE
#define EXITI_u8_INT0			EXITI_u8_ENABLE
#define EXITI_u8_INT1			EXITI_u8_ENABLE
#define EXITI_u8_INT2			EXITI_u8_ENABLE


/*CHOOS MODE FOR INT0,INT1*/
//EXITI_u8_Low_LEVEL 		
//EXITI_u8_ALC 			
//EXITI_u8_RISING_EDGE 	
//EXITI_u8_FALLING_EDGE 	

#define EXITI_u8_MODE_INT0		EXITI_u8_ALC
#define EXITI_u8_MODE_INT1		EXITI_u8_ALC

/*CHOOS MODE FOR INT2*/
//EXITI_u8_RISING_EDGE 	
//EXITI_u8_FALLING_EDGE 	
#define EXITI_u8_MODE_INT2		EXITI_u8_FALLING_EDGE



#endif
