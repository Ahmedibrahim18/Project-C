/*
 * lm35.h
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#ifndef LM35_H_
#define LM35_H_

#include"std_types.h"
/*  ***************Configuration********************/
#define SENSOR_VMAX_VALUE  1.5
#define SENSOR_MAX_VALUE  150
#define SENSOR_MIN_VALUE  0
#define TEMP_SENSOR_CHANNEL_ID  1


/***********************DECLERATION FUNCTION******************/
uint8 TEMP_SENS_GetTemp(void);

#endif /* LM35_H_ */
