/*
 * flame.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */
#include"gpio.h"
#include"flame.h"
#include"common_macros.h"

void FlameSensor_init(void){
	GPIO_setupPinDirection(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID,PIN_INPUT);

}

uint8 FlameSensor_getValue(void){

	uint8 FLAME_VALUE =0;
	 FLAME_VALUE= GPIO_readPin(FLAME_SENSOR_PORT_ID,FLAME_SENSOR_PIN_ID);

	return FLAME_VALUE;
}
