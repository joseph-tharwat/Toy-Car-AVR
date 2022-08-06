//set pin    
//set port
//clear pin
//clear port
//get pin
//get port
///set/clear/get nibble
//active pull up resistor
///config direction

/************************************************/
/*Title		  : DIO peripheral interface filebuf*/
/*Author 	  : fam shokry						*/
/*Release     : 2.0								*/
/*Last Update : Aug 15, 2021					*/
/************************************************/
#include"services/STD_type.h"

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_u8_PIN_0    0
#define DIO_u8_PIN_1    1
#define DIO_u8_PIN_2    2
#define DIO_u8_PIN_3    3
#define DIO_u8_PIN_4    4
#define DIO_u8_PIN_5    5
#define DIO_u8_PIN_6    6
#define DIO_u8_PIN_7    7
#define DIO_u8_PIN_8    8
#define DIO_u8_PIN_9    9
#define DIO_u8_PIN_10   10
#define DIO_u8_PIN_11   11
#define DIO_u8_PIN_12   12
#define DIO_u8_PIN_13   13
#define DIO_u8_PIN_14   14
#define DIO_u8_PIN_15   15
#define DIO_u8_PIN_16   16
#define DIO_u8_PIN_17   17
#define DIO_u8_PIN_18   18
#define DIO_u8_PIN_19   19
#define DIO_u8_PIN_20   20
#define DIO_u8_PIN_21   21
#define DIO_u8_PIN_22   22
#define DIO_u8_PIN_23   23
#define DIO_u8_PIN_24   24
#define DIO_u8_PIN_25   25
#define DIO_u8_PIN_26   26
#define DIO_u8_PIN_27   27
#define DIO_u8_PIN_28   28
#define DIO_u8_PIN_29   29
#define DIO_u8_PIN_30   30
#define DIO_u8_PIN_31   31
/////////////////////////////////
#define DIO_u8_HIGH   1
#define DIO_u8_LOW   0
/////////////////////////////////
#define DIO_u8_OUTPUT  1
#define DIO_u8_INPUT   0
/////////////////////////////////
#define PA  0
#define PB  1
#define PC  2
#define PD  3


void DIO_vid_Init(void);

void DIO_vid_SetPinVal   (u8  copy_u8_PinNo ,u8  copy_u8_PinVal);
void DIO_vid_ClearPinVal (u8 copy_u8_PinNo,u8 copy_u8_PinVal);
void DIO_vid_SetPinConf(u8 copy_u8_PinNo,u8 copy_u8_PinType);
void DIO_vid_SetPinPullup(u8 copy_u8_PinNo);
u8 DIO_u8_GetPinVal (u8 copy_u8_PinNo);

void DIO_vid_SetPortVal(u8 copy_u8_PortNo,u8 copy_u8_PortVal);
void DIO_vid_ClearPortVal(u8 copy_u8_PortNo,u8 copy_u8_PortVal);
u8 DIO_u8_GetPortVal (u8 copy_u8_PortNo);








#endif
