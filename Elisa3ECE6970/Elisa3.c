
#include <avr\io.h>
#include <avr\interrupt.h>
#include <util/delay.h>
#include <stdlib.h>
#include "variables.h"
#include "utility.h"
#include "speed_control.h"
#include "nRF24L01.h"
#include "behaviors.h"
#include "sensors.h"


int main(void) {
	unsigned long int startTime = 0, endTime = 0;
//	unsigned char prevSelector=0;

	initPeripherals();
	GREEN_LED0_ON;
/*	calibrateSensors();

	initBehaviors();

	startTime = getTime100MicroSec();

	disableObstacleAvoidance();
	disableCliffAvoidance();
	GREEN_LED0_OFF;
	GREEN_LED1_OFF;
	GREEN_LED2_OFF;
	GREEN_LED3_OFF;
	GREEN_LED4_OFF;
	GREEN_LED5_OFF;
	GREEN_LED6_OFF;
	GREEN_LED7_OFF; */
	
	
	pwm_green = 255;
//	pwm_green = 255;
//	pwm_blue = 255;
	updateGreenLed(pwm_green);
	GREEN_LED1_OFF;
//	updateGreenLed(pwm_green);
//	updateBlueLed(pwm_blue);

	GREEN_LED4_OFF;

	startTime = getTime100MicroSec();

	while(1) {

		//delay for some time 
		_delay_ms(500);

	
		if (pwm_green == 0) {
			pwm_green=255;
			GREEN_LED0_OFF;
		}
		else {
			pwm_green = 0;
			GREEN_LED0_ON;
			GREEN_LED4_ON;
		}

		updateGreenLed(pwm_green);
	


/*		currentSelector = getSelector();		
		endTime = getTime100MicroSec();
		if((endTime-startTime) >= (PAUSE_2_SEC)) {
			readBatteryLevel();				// the battery level is updated every two seconds
             		
			if(currentSelector==10 || currentSelector==5) {
				pwm_red = rand() % 255;
				pwm_green = rand() % 255;
				pwm_blue = rand() % 255;
			}

			startTime = getTime100MicroSec();
		}

		switch(currentSelector) {
			case 10: //random colors on RGB leds:
/				updateRedLed(pwm_red);
//				updateGreenLed(pwm_green);
//				updateBlueLed(pwm_blue);
//			break;
*/
//		}
//		prevSelector = currentSelector;
	}
	return(0);
}
