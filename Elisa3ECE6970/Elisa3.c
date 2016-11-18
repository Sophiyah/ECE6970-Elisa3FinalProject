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

/*-----header files for ECE6970 Project ------*/ 
#include "movement.h"

int main(void) {
//	initAdc();
	initPeripherals();
	calibrateSensors();

	initBehaviors();
	
//	adcSaveDataTo = SAVE_TO_PROX;

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

	//enableObstacleAvoidance();
	int changeLed = 0;
	while(1) {
		
	//adcSaveDataTo = SAVE_TO_PROX;
		//delay for some time 
		_delay_ms(2000);
		if (changeLed==0){
			GREEN_LED7_ON;
			changeLed=1;
			moveForward(1);
			
			//for (uint16_t stopCounter = 0; stopCounter<27000; stopCounter ++ ){
			while(1){
			stopWait(1);
			
			}
		
		}
		else {
			GREEN_LED7_OFF;
			changeLed=0;

		}
	

		if (proximityResult[9] < 10 ) {
			GREEN_LED7_OFF;
			GREEN_LED0_ON;
		}
		else if (proximityResult[9] < 100) {
			GREEN_LED0_OFF;
			GREEN_LED1_ON;
		}
		else if (proximityResult[9] < 150) {
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
