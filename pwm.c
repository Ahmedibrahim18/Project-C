/*
 * pwm.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */
#include"pwm.h"
#include "common_macros.h"
#include<avr/io.h>
#include"gpio.h"
void Timer0_init(void){
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	SET_BIT(TCCR0,COM01);
	switch (F_PRESCALER) {
	case 1024:
		SET_BIT(TCCR0, CS02);
		SET_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		break;
	case 256:
		SET_BIT(TCCR0, CS02);
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		break;
	case 64:
		SET_BIT(TCCR0, CS01);
		SET_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS02);
		break;
	case 8:
		SET_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS02);

		break;
	case 1:
		SET_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
		break;
	case 0:
		CLEAR_BIT(TCCR0, CS00);
		CLEAR_BIT(TCCR0, CS01);
		CLEAR_BIT(TCCR0, CS02);
		break;
	}
	TCNT0=START_COUNT;
	OCR0=COMP_COUNT;
	GPIO_setupPinDirection(OUTPUT_PORT_ID,OUTPUT_PIN_ID,PIN_OUTPUT);
}

void PWM_Timer0_Start(uint8 duty_cycle){

	OCR0=duty_cycle;
}


