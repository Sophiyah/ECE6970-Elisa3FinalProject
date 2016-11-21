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
//#include "movement.h"


int main(void) {


	initPeripherals();
	calibrateSensors();

	initBehaviors();

	initPeripherals();
	calibrateSensors();

	

	//GREEN_LED4_ON;
	while (1) {
      getMap();
	  //getData();
	  //setLeftSpeed(10);
	  //setRightSpeed(10);
	 // handleMotorsWithSpeedController();	
	}

	return(0);
}
