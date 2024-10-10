/*
 * ldr.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */


#include"ldr.h"
#include"adc.h"

uint16 LDR_GetLightIntensity(void)
{
	ADC_Init();
	uint16 Digital_Value=0;
    uint16 Intensity=0;
	 Digital_Value=ADC_readChannel(LDR_SENSOR_CHANNEL_ID);

	 Intensity=(uint16) (((uint32)Digital_Value*SENSOR__LDR_MAX_VALUE*ADC_VREF_VALUE)/(SENSOR_LDR_VMAX_VALUE*ADC_MAX_VALUE ));

	return Intensity;

}

