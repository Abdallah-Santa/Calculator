/*
 * Calculator.c
 *
 *  Created on: Oct 4, 2021
 *      Author: Abdallah Taha
 */
#include"STD_TYPES.h"
#include"HKPD_Interface.h"
#include"HLCD_Interface.h"
#define TRUE 1
#define FALSE 0
#define Reset_Calc do{\
	sym=num=0;\
	button=50;\
	opd[0]=opd[1]=opd[2]=opd[3]=opd[4]=opd[5]=opd[6]=opd[7]=opd[8]=opd[9]=0;\
	opr[0]=opr[1]=opr[2]=opr[3]=opr[4]=opr[5]=opr[6]=opr[7]=opr[8]=opr[9]=0;\
	OPD_Last=Result_Exist=Result_Disp=Divide_By_Zero=FALSE;\
	cursor=1;\
	HLCD_VoidSendCommand(0x01);\
}while(0) // One Time Execute


void main(void)
{
#if 1
	/*Initialize HardWare*/
	HLCD_VoidInit();
	HKPD_VoidInit();

	/*Define Variables*/

	/*Operations Array*/
u8 opr[10]={0};

/*Operands Array*/
u32 opd[10]={0};

/*Index Of Operands Array*/
u8 num=0;
/*Index Operations Array*/
u8 sym=0;

u32 Result=0;
u8 Divide_By_Zero=FALSE;
u8 OPD_Last=FALSE;
u8 Result_Exist=FALSE;
u8 Result_Disp=FALSE;
u8 cursor=1;
	u8 button;
#endif


#if 1

	while(1) //Super Loop
	{
    /*Get Key From KeyPad*/
	button=HKPD_U8GetPressedKey();

	/*If There A Key Pressed*/
if(button!=50)
{
	/*If There Is a Result Stored*/
	if(Result_Exist)
	{
	if(button=='+'|| button=='*'|| button=='-'|| button=='/')
	{
		/*Clear Calculator*/
    Reset_Calc;
    /*Put A Result In Array*/
    opd[num]=Result;
    /*Last Key Is An Operand*/
    OPD_Last=TRUE;
    /*Show Result On Display*/
    HLCD_VoidSendNumber(Result);

	}
	}

	/*Check Which Key Is Pressed*/
 switch(button)
 {

  case 0:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
HLCD_VoidSendNumber(button);
      break;

  case 1:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;

  case 2:
	  opd[num]*=10;
	  opd[num]+=button;
	  HLCD_VoidSendNumber(button);
      break;

  case 3:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;

  case 4:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;

  case 5:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;

  case 6:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;

  case 7:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;

  case 8:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;

  case 9:
	  opd[num]*=10;
	  opd[num]+=button;
      OPD_Last=TRUE;
      HLCD_VoidSendNumber(button);
      break;


  case '+' :
	  /*If Last Key Is A Number*/
	  if(OPD_Last)
	  {
		  /*Put The Symbol In Operations Array*/
		  opr[sym++]='+';
		  num++;
		  OPD_Last=FALSE;
HLCD_VoidSendChar('+');
	  }
	  else
	  {
		  OPD_Last=TRUE;
	  }
	  break;

  case '-' :
	  /*If Last Key Is A Number*/
	  if(OPD_Last)
	  {
		  /*Put The Symbol In Operations Array*/
		  opr[sym++]='-';
		  num++;
		  OPD_Last=FALSE;
		  HLCD_VoidSendChar('-');
	  }
	  else
	  {
		  OPD_Last=TRUE;
	  }
	  break;

  case '*' :
	  /*If Last Key Is A Number*/
	  if(OPD_Last)
	  {
		  /*Put The Symbol In Operations Array*/
		  opr[sym++]='*';
		  num++;
		  OPD_Last=FALSE;
		  HLCD_VoidSendChar('*');
	  }
	  else
	  {
		  OPD_Last=TRUE;
	  }
	  break;

  case '/' :
	  /*If Last Key Is A Number*/
	  if(OPD_Last)
	  {

		  /*Put The Symbol In Operations Array*/
		  opr[sym++]='/';
		  num++;
		  OPD_Last=FALSE;
		  HLCD_VoidSendChar('/');

	  }
	  else
	  {
		  OPD_Last=TRUE;
	  }
	  break;

  case '=' :
	  /*Calculate The Result*/
	  HLCD_VoidSendChar('=');
	 Result=opd[0];
	 u8 calc;
	 for(calc=0;calc<=sym;calc++)
	 {
		 switch(opr[calc])
		 {
		 case '+':
			 Result+=opd[calc+1];
			 break;

		 case '-':
				 Result-=opd[calc+1];
				 break;

		 case '*':
				 Result*=opd[calc+1];
				 break;

		 case '/':
			 /*If Divide By ZERO*/
			 if(opd[num]==0)
			 {
				 /*Clear Calculator*/
				 HLCD_VoidSendCommand(0x01);
				 HLCD_VoidSendString("ERROR Divide By0");
				 Result_Disp=FALSE;
				 Divide_By_Zero=TRUE;

			 }
			 else if(opd[num]!=0)
			 {
				 Result/=opd[calc+1];
				 Divide_By_Zero==FALSE;
			 }
				 break;

		 default:
			 break;
		 }
	 }
	 if(Divide_By_Zero==FALSE)
	 {
	 Result_Exist=TRUE;
     Result_Disp=TRUE;
	 }
          break;
  case 'C':
	  /*Clear Calculator*/
	  Reset_Calc;
	  break;

  default:
	  break;

            }

	cursor++;
	if(Result_Disp)
	{
		/*Send The Calculated Result To LCD*/
		HLCD_VoidSendNumber(Result);
		HLCD_VoidSetPostion(2,1);
		Result_Disp=FALSE;
	}
	/*Ensure The Key Is Un Pressed*/
	while( HKPD_U8GetPressedKey() == 0 ) { }
}//end if of pressed key
      }//end while
#endif
	}//main



