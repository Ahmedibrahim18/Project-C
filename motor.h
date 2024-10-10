/*
 * motor.h
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include"std_types.h"
#include "pwm.h"
typedef enum
{
	CW,A_CW,Stop
}DcMotor_State;

#define H_Bridge_PORT_ID  PORTB_ID
#define H_Bridge_IN1_ID   PIN0_ID
#define H_Bridge_IN2_ID   PIN1_ID
#define H_Bridge_EN1_ID   PIN3_ID

#endif /* MOTOR_H_ */
