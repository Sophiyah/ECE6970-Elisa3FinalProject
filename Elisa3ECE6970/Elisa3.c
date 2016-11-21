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
#include "mapping.h"

int main(void) {
//	initAdc();
	initPeripherals();
	calibrateSensors();

	initBehaviors();
	initUsart0();	

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

	//int changeLed = 0;
	while(1) {
		
		//delay for some time 
		//_delay_ms(2000);
		//if (changeLed==0){
/*		int tempCounter = 0;
		
		}
		*/
	/*	else {
			GREEN_LED7_OFF;
			changeLed=0;

		}
	
	*/
		mapRoom();

/*
		//for(int i=0; i<12; i++) {
		int tempProxResult = proximityResult[9] + 0x30;
									usart0Transmit(tempProxResult&0xFF,1);
									usart0Transmit(tempProxResult>>8,1);
									//usart0Transmit(proximityValue[i*2]&0xFF,1);
									//usart0Transmit(proximityValue[i*2]>>8,1);
		//						}
		int temp = proxUpdated + 0x30;	;
		 usart0Transmit(1,1);

		if(proximityResult[6] < 312){
			GREEN_LED6_ON; 
		}
		else {
			GREEN_LED6_OFF;
		}

		if (proximityResult[9] < 600 ) {
			GREEN_LED4_OFF;
		}
		else {
			GREEN_LED4_ON;
		}
*/	
	}
	//return(0);
}
