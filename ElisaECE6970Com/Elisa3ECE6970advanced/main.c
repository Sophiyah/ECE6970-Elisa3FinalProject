
#include <avr\io.h>
#include <avr\interrupt.h>

#include <stdlib.h>
#include "variables.h"
#include "utility.h"
#include "speed_control.h"
#include "nRF24L01.h"
#include "behaviors.h"
#include "sensors.h"
#include "irCommunication.h"
#include "motors.h"
#include "movement.h"

int main(void) {
//	initAdc();
	initPeripherals();
	calibrateSensors();

	initBehaviors();

	while(1) {
		//getMap();
		turnLeft();
		moveForward(1); 
	      

	}
}
