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

	initPeripherals();
	calibrateSensors();
	initBehaviors();
	
	GREEN_LED0_OFF;
	GREEN_LED1_OFF;
	GREEN_LED2_OFF;
	GREEN_LED3_OFF;
	GREEN_LED4_OFF;
	GREEN_LED5_OFF;
	GREEN_LED6_OFF;
	GREEN_LED7_OFF; 


	while(1) {

	gridNavigation();
	
	}
	return(0);
}
