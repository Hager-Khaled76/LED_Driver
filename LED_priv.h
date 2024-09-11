/*
 * LED_priv.h
 *
 *  Created on: Sep 10, 2024
 *      Author: c
 */

#ifndef LED_PRIV_H_
#define LED_PRIV_H_



#define LED_SINK       0    //8
#define LED_SOURCE     1    //9

#define LED_ON         0   //9
#define LED_OFF        1   //123



typedef struct
{
	u8 LED_u8PortID;
	u8 LED_u8PinID;
	u8 LED_u8Connection;         //connct: sink  ON(0) or source  ON(1)
	u8 LED_u8InitState;         //on or off


}LED_t;


#endif /* LED_PRIV_H_ */
