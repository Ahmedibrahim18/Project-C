/*
 * buzzer.h
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"

/*  ***************Configuration********************/
#define BUZZER_TURN_ON  LOGIC_HIGH
#define BUZZER_TURN_OFF LOGIC_LOW
#define BUZZER_PORT_ID  PORTD_ID
#define BUZZER_PIN_ID   PIN3_ID



/***********************DECLERATION FUNCTION******************/
void Buzzer_Init(void);
void Buzzer_on(void);
void Buzzer_off(void);

#endif /* BUZZER_H_ */
