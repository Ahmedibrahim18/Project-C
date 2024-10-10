/*
 * buzzer.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */
#include"buzzer.h"
#include"gpio.h"

void Buzzer_Init(void){
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID,PIN_OUTPUT); // initialize pin direction

	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_TURN_OFF);//initialize turn off buzzer
}

void Buzzer_on(void){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_TURN_ON);
}
void Buzzer_off(void){
	GPIO_writePin(BUZZER_PORT_ID,BUZZER_PIN_ID,BUZZER_TURN_OFF);
}

