//#include <stdint.h>


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

#include "movement.h"

int main(void) {
	unsigned long int startTime = 0, endTime = 0;
//	unsigned char prevSelector=0;

	initPeripherals();
	calibrateSensors();

	initBehaviors();
	GREEN_LED0_ON;
/*	calibrateSensors();

	initBehaviors();

	startTime = getTime100MicroSec();

	disableObstacleAvoidance();
	disableCliffAvoidance();
*/	GREEN_LED0_OFF;
	GREEN_LED1_OFF;
	GREEN_LED2_OFF;
	GREEN_LED3_OFF;
	GREEN_LED4_OFF;
	GREEN_LED5_OFF;
	GREEN_LED6_OFF;
	GREEN_LED7_OFF; 
	
	


	while(1) {
		

		//delay for some time 
		//_delay_ms(2000);



		if (proximityResult[9] < 50 ) {
			GREEN_LED1_ON;
		}
		else if (proximityResult[9] < 100) {
			GREEN_LED1_OFF;
			GREEN_LED2_ON;
		}
		else if (proximityResult[9] < 200) {
			GREEN_LED2_OFF;
			GREEN_LED3_ON;
		}
		else if (proximityResult[9] < 250) {
			GREEN_LED3_OFF;
			GREEN_LED4_ON;
		}
		else if (proximityResult[9] < 300) {
			GREEN_LED4_OFF;
			GREEN_LED5_ON;
		}
		else if (proximityResult[9] < 400) {
			GREEN_LED5_OFF;
			GREEN_LED6_ON;
		}
		else if (proximityResult[9] <500) {
			GREEN_LED6_OFF;
			GREEN_LED7_ON;
		}
	
	
	}
	return(0);
}
