/*
 * main.c
 *
 *  Created on: Oct 8, 2024
 *      Author: VICTUS
 */

#include"main.h"


int main(void){
	 LCD_init();

	 Buzzer_Init();
	 LEDS_init();
	 DcMotor_Init();
	 FlameSensor_init();
	 // display fan is ...
	 LCD_displayStringRowColumn(0,4,"FAN is ");
	 LCD_displayStringRowColumn(1,0,"TEMP=");
	 LCD_displayStringRowColumn(1,8,"LDR=");
	 uint16 Intensity=0;
	 uint8 TEMP_LM=0;


	 while(1){
		if (FlameSensor_getValue()) {
			Buzzer_on();
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 4, "Critical");
			LCD_displayStringRowColumn(1, 5, "Alert!");
			while (FlameSensor_getValue())
				;
			Buzzer_off();
			LCD_clearScreen();
			LCD_displayStringRowColumn(0, 4, "FAN is ");
			LCD_displayStringRowColumn(1, 0, "TEMP=");
			LCD_displayStringRowColumn(1, 8, "LDR=");
		}
		Intensity = LDR_GetLightIntensity();
		TEMP_LM = TEMP_SENS_GetTemp();
		if (TEMP_LM > 99) {
			TEMP_LM = 99;
		}
		if (TEMP_LM < 25) {
			LCD_displayStringRowColumn(0, 11, "OFF");
			LCD_moveCursor(1, 5);
			LCD_intgerToString((uint32) TEMP_LM);
			LCD_moveCursor(1, 12);
			if (Intensity > 99) {
				LCD_intgerToString((uint32) Intensity);
				LCD_displayCharacter('%');
			} else {
				LCD_intgerToString((uint32) Intensity);
				LCD_displayCharacter('%');
				LCD_displayCharacter(' ');
			}

		} else {
			LCD_displayStringRowColumn(0, 11, "ON");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 5);
			LCD_intgerToString((uint32) TEMP_LM);
			LCD_moveCursor(1, 12);
			if (Intensity > 99) {
				LCD_intgerToString((uint32) Intensity);
				LCD_displayCharacter('%');
			} else {
				LCD_intgerToString((uint32) Intensity);
				LCD_displayCharacter('%');
				LCD_displayCharacter(' ');
			}
		}

		if (Intensity <= 15) {
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
		} else if ((Intensity > 15) && (Intensity <= 50)) {
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
		} else if ((Intensity > 50) && (Intensity <= 70)) {
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		} else {
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}

		if (TEMP_LM >= 40) {
			DcMotor_Rotate(CW, MAX_DUTY);
		} else if ((TEMP_LM >= 35) && (TEMP_LM < 40)) {
			DcMotor_Rotate(CW, THIRDQUARTER_DUTY);
		} else if ((TEMP_LM >= 30) && (TEMP_LM < 35)) {
			DcMotor_Rotate(CW, HALF_DUTY);
		} else if ((TEMP_LM >= 25) && (TEMP_LM < 30)) {
			DcMotor_Rotate(CW, QUARTER_DUTY);
		} else {
			DcMotor_Rotate(Stop, ZERO_DUTY);
		}

	}

	return 0;
}

