/*
 * flame.h
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#ifndef FLAME_H_
#define FLAME_H_

#include "std_types.h"

#define FLAME_SENSOR_PORT_ID  PORTD_ID
#define FLAME_SENSOR_PIN_ID   PIN2_ID








uint8 FlameSensor_getValue(void);
void FlameSensor_init(void);



#endif /* FLAME_H_ */
