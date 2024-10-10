/*
 * adc.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */
#include"common_macros.h"
#include"adc.h"
#include<avr/io.h>


void ADC_Init(void){

	SET_BIT(ADMUX, REFS0);
		SET_BIT(ADMUX, REFS1);

	SET_BIT(ADCSRA, ADEN);
	switch (PRESCALER) {
	case 128:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		SET_BIT(ADCSRA, ADPS0);
		break;
	case 64:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		CLEAR_BIT(ADCSRA, ADPS0);
		break;
	case 32:
		SET_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS0);
		CLEAR_BIT(ADCSRA, ADPS1);
		break;
	case 16:
		SET_BIT(ADCSRA, ADPS2);
		CLEAR_BIT(ADCSRA, ADPS0);
		CLEAR_BIT(ADCSRA, ADPS1);
		break;
	case 8:
		SET_BIT(ADCSRA, ADPS0);
		CLEAR_BIT(ADCSRA, ADPS2);
		SET_BIT(ADCSRA, ADPS1);
		break;
	case 4:
		SET_BIT(ADCSRA, ADPS1);
		CLEAR_BIT(ADCSRA, ADPS0);
		CLEAR_BIT(ADCSRA, ADPS2);
		break;
	case 2:
		CLEAR_BIT(ADCSRA, ADPS2);
		CLEAR_BIT(ADCSRA, ADPS0);
		CLEAR_BIT(ADCSRA, ADPS1);
		break;
	}
}

uint16 ADC_readChannel(uint8 Ch_num){

	ADMUX=(ADMUX & 0xE0) | (Ch_num & 07);
	SET_BIT(ADCSRA,ADSC);

	while(BIT_IS_CLEAR(ADCSRA,ADIF)); // polling until converting end
	SET_BIT(ADCSRA,ADIF); // clear Flag

	return ADC ;
}


