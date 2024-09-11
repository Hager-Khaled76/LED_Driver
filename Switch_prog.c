
#include "stdTypes.h"
#include "errorStates.h"

#include "Switch_priv.h"
#include "Switch_config.h"

#include "DIO_int.h"

//switch want 3 items       1.port    2.pin   3.state:::  float or pullup:pressed ::0




ES_t Switch_enumInt(SW_t * Copy_ArrayStrSwitchs)
{
	ES_t Local_enumErrorState = ES_NOK;

	if(Copy_ArrayStrSwitchs !=NULL)
	{
	  u8 Local_u8Iterate =0;
	  for(Local_u8Iterate =0 ; Local_u8Iterate<SW_NUM ; Local_u8Iterate++)
	  {
		  Local_enumErrorState = DIO_enumSetPinDirection(Copy_ArrayStrSwitchs[Local_u8Iterate].SW_PortId ,
				  Copy_ArrayStrSwitchs[Local_u8Iterate].SW_PinID ,
				  DIO_u8INPUT);
		  Local_enumErrorState = DIO_enumSetPinValue(Copy_ArrayStrSwitchs[Local_u8Iterate].SW_PortId ,Copy_ArrayStrSwitchs[Local_u8Iterate].SW_PinID , Copy_ArrayStrSwitchs[Local_u8Iterate].SW_Status);

	 }
	}
	else
	{
		Local_enumErrorState = ES_NULL_POINTER;
	}

	return Local_enumErrorState;
}

ES_t Switch_enumGetState(SW_t * Copy_ArrayStrSwitchs,u8 * Copy_pu8SWState)
{
	ES_t Local_enumErrorState = ES_NOK;

	if(Copy_ArrayStrSwitchs != NULL && Copy_pu8SWState != NULL)
	{
		Local_enumErrorState =DIO_enumGetPinValue(Copy_ArrayStrSwitchs->SW_PortId , Copy_ArrayStrSwitchs->SW_PinID , Copy_pu8SWState );

	}
	else
	{
		Local_enumErrorState = ES_NULL_POINTER;
	}


	return Local_enumErrorState;
}
