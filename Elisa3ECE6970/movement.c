
#include "movement.h"




void turnRight() {
		//spin for 90 degrees
		for (uint16_t turnCounter = 0; turnCounter<turn90count; turnCounter ++ ){
			setLeftSpeed(10);
			setRightSpeed(-10);
			handleMotorsWithSpeedController();  
		}
		
		stopWait(1);

}


/*stop where robot is and set motor speed to 0, wait while stop = 1
*/
void stopWait(char stop) {
	while(stop) {
			setLeftSpeed(0);
			setRightSpeed(0);
			handleMotorsWithSpeedController();
	}

}



/*----------helper functions *-----------/


/* tell if the front ground sensors detect a gridEdge. 
Returns 1 if and edge is detected and returns 0 if no edge detected.
*/

char gridEdgeDetected() {

	// tell whether a gridEdge is detected or not
	if(proximityResult[9] > CLIFF_THR || proximityResult[10] > CLIFF_THR) {
		return 1; //it sees the white line
	} else {
		return 0;
	}
}


/*move forwared 1 grid step
*/
void moveForward(){

	while(gridEdgeDetected()) {
			setLeftSpeed(10);
			setRightSpeed(10);
			handleMotorsWithSpeedController();
	}

	stopWait(1);
	
}

