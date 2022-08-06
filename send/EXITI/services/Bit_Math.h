/************************************************/
/*Title		  : Bit_Math                        */
/*Author 	  : fam shokry						*/
/*Release     : 2.0								*/
/*Last Update : Aug 15, 2021					*/
/************************************************/



#ifndef Bit_Math_H_
#define Bit_Math_H_



#define SET_BIT(Var,BitNo)   Var = (Var | (1 << BitNo));
#define CLEAR_BIT(Var,BitNo)   Var = (Var & ~(1 << BitNo));
#define GET_BIT(Return,Var,BitNo)   Return=(Var & (1<<BitNo));


#define CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0)     CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)
#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)    0b##A7##A6##A5##A4##A3##A2##A1##A0





#endif
