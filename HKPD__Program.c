/*                      ************************************************************************
 						**               Created on: Sep 25, 2021                             **
                        **                Author: Abdallah Taha                               **           
						**                File Name : HKPD_Program                            **
						**                 V 1.0                                              **
						**           Description: KeyPad  Driver                              **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						**                                                                    **
						************************************************************************/



#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MDIO_Interface.h"
#include "HKPD_Config.h"
#include "avr/delay.h"


void HKPD_VoidInit(void)
{
	
	/*Set Inputs & OutPuts Pins*/
	MDIO_VoidSetPortDirection(HKPD_Port,0b11110000);
	
	/*Set Default State*/
	MDIO_VoidSetPortValue(HKPD_Port,0b11111111);
	
}




u8 HKPD_U8GetPressedKey(void)
{
	/*Define Variables*/
	u8 LOC_Check;
	u8 LOC_PressedKey =50;
	u8 ROW =0 , COL =0 ;
	
	/*Check On Pressed Key*/
	for(COL=0;COL<4;COL++)
	{
		
		/*Set The Sepicific COL LOW & Others HIGH*/
		MDIO_VoidSetPinValue(HKPD_Port,4+COL,0);
		
		/*Check On Pressed Key*/
		for(ROW=0;ROW<4;ROW++)
		{
			
			/*Get Location Of Pressed Key*/
			LOC_Check =MDIO_u8GetPinValue(HKPD_Port,ROW);
			
			
			/*If Pressed*/
			if(0==LOC_Check)
			{
				/*Get Value Of Presse Key*/
				LOC_PressedKey=(4*ROW)+COL+1;
				
			}
			else
			{
				//Do Nothing
			}
			
			/*Check If User Un Pressed Key*/
			while(MDIO_u8GetPinValue(HKPD_Port,ROW)==0)
			{
				//Do Nothing
				
			}
			/*To Prevent Bounce*/
			_delay_ms(5);
		}
			
		/*Reverse Col To Its Orginial State*/
			MDIO_VoidSetPinValue(HKPD_Port,4+COL,1);
			
			/*Return Value Of Pressed Key*/


		
	}
	
	switch(LOC_PressedKey)
{



	        case 1: return 1; break;
			case 2: return 2; break;
			case 3: return 3; break;
			case 4: return '+'; break;
			case 5: return 4; break;
			case 6: return 5; break;
			case 7: return 6; break;
			case 8: return '-'; break;
			case 9: return 7; break;
			case 10: return 8; break;
			case 11: return 9; break;
			case 12: return '*'; break;
			case 13: return 'C'; break;
			case 14: return 0; break;
			case 15: return '='; break;
			case 16: return '/'; break;
			default: return 50;break;
}
	
	
	
}
