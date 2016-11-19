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
#include "pathing.h"
/*-----header files for ECE6970 Project ------*/ 
//#include "movement.h"

int main(void) {
//	initAdc();
	initPeripherals();
	calibrateSensors();

	initBehaviors();

while(1) {
		getMap(); 
	      }
	return(0);
}

