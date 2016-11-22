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

	while(1) {

		moveForward(3);
		int temp1 = gridEdgeDetected(); 
		int temp = temp1 + 0x30;	;
		 usart0Transmit(temp,1);	
//		moveForwardOne();
		while(1){
		stopWait(1);
		}

		
	// while(temp1 == 1) {
	//		temp1 = blackToWhiteEdgeDetect();
	//			while(temp1 ==0) {}
	 //}

	//	while(temp1 ==0) {}


/*		if (proximityResult[9] > 540 || proximityResult[10] > 540){
			GREEN_LED6_ON;
	
		}
		else{
			GREEN_LED6_OFF;
		}
		*/
/*		
		//delay for some time 
		//_delay_ms(2000);
		if (changeLed==0){
			GREEN_LED7_ON;
			changeLed=1;
			turnLeft(1);
			
			//for (uint16_t stopCounter = 0; stopCounter<27000; stopCounter ++ ){
			//}
		
		}
		else {
			GREEN_LED7_OFF;
			changeLed=0;
			stopWait(1);

		}
*/
	
	
	}
	return(0);
}
