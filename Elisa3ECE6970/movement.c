
#include "movement.h"

void turnRight() {
		//spin for 90 degrees
		for (uint16_t turnCounter = 0; turnCounter<27500; turnCounter ++ ){
			setLeftSpeed(10);
			setRightSpeed(-10);
			handleMotorsWithSpeedController();  
		}

}
