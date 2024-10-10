/*
 * lm35.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */


#include"lm35.h"
#include"adc.h"
uint8 TEMP_SENS_GetTemp(void){
	ADC_Init();
	uint16 Digital_Value=0;
	uint8 Temp=0;

	Digital_Value=ADC_readChannel(TEMP_SENSOR_CHANNEL_ID);

	Temp=(uint8) (((uint32)Digital_Value*SENSOR_MAX_VALUE*ADC_VREF_VALUE)/(SENSOR_VMAX_VALUE*ADC_MAX_VALUE ));

	return Temp;

}


