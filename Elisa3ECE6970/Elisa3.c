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

	//enableObstacleAvoidance();
	//int changeLed = 0;
	while(1) {
		
	//adcSaveDataTo = SAVE_TO_PROX;
		//delay for some time 
		//_delay_ms(2000);
		//if (changeLed==0){
/*		int tempCounter = 0;
		ISR(proxUpdated){
			
			if(changeLed = 1){
			GREEN_LED7_ON;
			changeLed =0;
			}
			else {
			GREEN_LED7_OFF;
			changeLed = 1;
			}
//			proximityResult[9] 
			tempCounter++; 
			proxUpdated = 0;

			if(tempCounter == 160){
			tempCounter = 0;
			}
			//changeLed=1;
			//moveForward(1);
			//mapRoom();
			
			//for (uint16_t stopCounter = 0; stopCounter<27000; stopCounter ++ ){
			while(1){
			stopWait(1);
			
			}
		
		}
		*/
	/*	else {
			GREEN_LED7_OFF;
			changeLed=0;

		}
	
	*/


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
	
	}
	//return(0);
}
