/*
 * LED_prog.c
 *
 *  Created on: Sep 10, 2024
 *      Author: c
 */



#include "stdTypes.h"
#include "errorStates.h"

#include "LED_priv.h"
#include "LED_config.h"

#include "DIO_int.h"



ES_t LED_enumInit(LED_t * Copy_PStrcLedConfig)
{
	ES_t Local_enumErrorState = ES_NOK;
	if( Copy_PStrcLedConfig != NULL)
	{
		u8 Local_enumIterator =0;
		for(Local_enumIterator =0; Local_enumIterator <LED_NUM ; Local_enumIterator ++)
		{
			Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedConfig[Local_enumIterator].LED_u8PortID ,Copy_PStrcLedConfig[Local_enumIterator].LED_u8PinID , DIO_u8OUTPUT);   // at first is output
			if((Copy_PStrcLedConfig[Local_enumIterator].LED_u8Connection == LED_SINK))   // sink => on=> low[0]    ----sink => off=> high[1]
			{
				if(Copy_PStrcLedConfig[Local_enumIterator].LED_u8InitState == LED_ON)
				{
					Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedConfig[Local_enumIterator].LED_u8PortID ,Copy_PStrcLedConfig[Local_enumIterator].LED_u8PinID , DIO_u8LOW);
				}
				else if(Copy_PStrcLedConfig[Local_enumIterator].LED_u8InitState == LED_OFF)
				{
					Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedConfig[Local_enumIterator].LED_u8PortID ,Copy_PStrcLedConfig[Local_enumIterator].LED_u8PinID , DIO_u8HIGH);

				}
				else
				{
					Local_enumErrorState= ES_OUT_OF_RANGE;
				}
			}
            else if((Copy_PStrcLedConfig[Local_enumIterator].LED_u8Connection == LED_SOURCE))   // source => on=> high[1]    ----source => off=> low[0]
			{
				if(Copy_PStrcLedConfig[Local_enumIterator].LED_u8InitState == LED_ON)
				{
					Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedConfig[Local_enumIterator].LED_u8PortID ,Copy_PStrcLedConfig[Local_enumIterator].LED_u8PinID , DIO_u8HIGH);
				}
				else if(Copy_PStrcLedConfig[Local_enumIterator].LED_u8InitState == LED_OFF)
				{
					Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedConfig[Local_enumIterator].LED_u8PortID ,Copy_PStrcLedConfig[Local_enumIterator].LED_u8PinID , DIO_u8LOW);

				}
				else
				{
					Local_enumErrorState = ES_OUT_OF_RANGE;
				}
			}
			else
			{
				Local_enumErrorState = ES_OUT_OF_RANGE;

			}
		}

	}
	else
	{
		 Local_enumErrorState = ES_NULL_POINTER;
	}
	return Local_enumErrorState;

}



ES_t LED_enumTurnON(LED_t * Copy_PStrcLedID)
{
	ES_t Local_enumErrorState = ES_NOK;
	if( Copy_PStrcLedID != NULL)
	{
		if(Copy_PStrcLedID->LED_u8Connection == LED_SINK)
		{
			Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedID->LED_u8PortID ,Copy_PStrcLedID->LED_u8PinID , DIO_u8LOW);

		}
		else if(Copy_PStrcLedID->LED_u8Connection == LED_SOURCE)
		{
			Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedID->LED_u8PortID ,Copy_PStrcLedID->LED_u8PinID , DIO_u8HIGH);

		}
		else
		{
			Local_enumErrorState = ES_OUT_OF_RANGE;

		}

	}
	else
	{
		 Local_enumErrorState = ES_NULL_POINTER;
	}
	return Local_enumErrorState;

}

ES_t LED_enumTurnOFF(LED_t * Copy_PStrcLedID)
{
	ES_t Local_enumErrorState = ES_NOK;
	if( Copy_PStrcLedID != NULL)
	{
		if(Copy_PStrcLedID->LED_u8Connection == LED_SINK)
		{
			Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedID->LED_u8PortID ,Copy_PStrcLedID->LED_u8PinID , DIO_u8HIGH);

		}
		else if(Copy_PStrcLedID->LED_u8Connection == LED_SOURCE)
		{
			Local_enumErrorState = DIO_enumSetPinValue(Copy_PStrcLedID->LED_u8PortID ,Copy_PStrcLedID->LED_u8PinID , DIO_u8LOW);

		}
		else
		{
			Local_enumErrorState = ES_OUT_OF_RANGE;

		}

	}
	else
	{
		 Local_enumErrorState = ES_NULL_POINTER;
	}
	return Local_enumErrorState;

}
