/*
 * pwm.h
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"
#define F_PRESCALER  1024

#define MAX_DUTY  255
#define THIRDQUARTER_DUTY 192
#define HALF_DUTY 128
#define QUARTER_DUTY 64
#define ZERO_DUTY 0

#define START_COUNT 0
#define COMP_COUNT 0
#define OUTPUT_PORT_ID PORTB_ID
#define OUTPUT_PIN_ID PIN3_ID


void Timer0_init(void);
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
