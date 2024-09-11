/*
 * main.c
 *
 *  Created on: Sep 10, 2024
 *      Author: c
 */



#include "stdTypes.h"
#include "errorStates.h"

#include "DIO_int.h"
#include "LED_config.h"
#include "LED_int.h"
#include "Switch_config.h"
#include "Switch_int.h"
#include<util/delay.h>

extern LED_t LED_ArrStrcLedConfig [LED_NUM];
extern SW_t Switch_ArrayStrSwitchStates[SW_NUM];
int main()
{
	DIO_enumInt();
	LED_enumInit(LED_ArrStrcLedConfig);
	Switch_enumInt(Switch_ArrayStrSwitchStates);
	u8 PinnState =0;


	while(1)
	{
		Switch_enumGetState(&Switch_ArrayStrSwitchStates[1] ,&PinnState );   // element 1 :: switch will be on portD , pin 3
		if(PinnState ==0)
		{
		   LED_enumTurnON(&LED_ArrStrcLedConfig[1]);    // element 1 :: led will be on  portB , pin 2
		  _delay_ms(500);
		}
		else
		   LED_enumTurnOFF(&LED_ArrStrcLedConfig[1]);



	}
}
