/*
 * motor.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */


#include"gpio.h"
#include"motor.h"
#include "pwm.h"

void DcMotor_Init(void){
	Timer0_init();

	GPIO_setupPinDirection( H_Bridge_PORT_ID,H_Bridge_IN1_ID,PIN_OUTPUT);
	GPIO_setupPinDirection( H_Bridge_PORT_ID,H_Bridge_IN2_ID,PIN_OUTPUT);
	// make motor off

	GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN1_ID,LOGIC_LOW);
	GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN2_ID,LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed){
	switch(state){

	case CW:
		GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN2_ID,LOGIC_HIGH);
		GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN1_ID,LOGIC_LOW);
		PWM_Timer0_Start(speed);
	break;

	case A_CW:
		GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN2_ID,LOGIC_LOW);
		GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN1_ID,LOGIC_HIGH);
		PWM_Timer0_Start(speed);
	break;
	case Stop:
		GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN1_ID,LOGIC_LOW);
			GPIO_writePin(H_Bridge_PORT_ID,H_Bridge_IN2_ID,LOGIC_LOW);
			PWM_Timer0_Start(speed);
	break;
	}
}
