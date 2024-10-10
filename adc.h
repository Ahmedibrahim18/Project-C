/*
 * adc.h
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#ifndef ADC_H_
#define ADC_H_

#include"std_types.h"

/*  ***************Configuration********************/
#define ADC_VREF_VALUE  2.56
#define ADC_MAX_VALUE  1023
#define PRESCALER 128
#define REF_SEL 'INTERNAL'



/*************************DECLERATION OF FUNCTION*******************************
 */
void adc_Init(void);
uint16 ADC_readChannel(uint8 Ch_num);


#endif /* ADC_H_ */
