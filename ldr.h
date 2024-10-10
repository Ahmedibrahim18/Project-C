/*
 * ldr.h
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#ifndef LDR_H_
#define LDR_H_

#include"std_types.h"
/*  ***************Configuration********************/
#define SENSOR_LDR_VMAX_VALUE  2.56
#define SENSOR__LDR_MAX_VALUE  100
#define SENSOR_LDR_MIN_VALUE  0
#define LDR_SENSOR_CHANNEL_ID  0

/***********************DECLERATION FUNCTION******************/
uint16 LDR_SENS_GetIntensity(void);

#endif /* LDR_H_ */
