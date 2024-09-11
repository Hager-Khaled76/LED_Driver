/*
 * LED_int.h
 *
 *  Created on: Sep 10, 2024
 *      Author: c
 */

#ifndef LED_INT_H
#define LED_INT_H

#include "LED_priv.h"

ES_t LED_enumInit(LED_t * Copy_PStrcLedConfig);

ES_t LED_enumTurnON(LED_t * Copy_PStrcLedID);

ES_t LED_enumTurnOFF(LED_t * Copy_PStrcLedID);



#endif /* LED_INT_H_ */
