
#include "motors.h"
#include "movement.h"

/*----variables for file-----*/
static uint16_t turn90count = 27500; //nonmagnetic surface counter
static uint16_t gridMoveCount = 33000; 
volatile uint16_t turnCounter = 0;

/*turns 90 degrees to the left
*/
void turnLeft() {
		
		//spin for 90 degrees
		if (turnCounter<turn90count) {
			setLeftSpeed(-10);
			setRightSpeed(10);
			//handleMotorsWithSpeedController();  
			turnCounter ++;
		}
		else {
			turnCounter = 0;
			setLeftSpeed(0);
			setRightSpeed(0);
		}

}

/*turns 90 degrees to the right
*/
void turnRight() {

		//spin for 90 degrees
		for (uint16_t turnCounter = 0; turnCounter<turn90count; turnCounter ++ ){
			setLeftSpeed(10);
			setRightSpeed(-10);
			handleMotorsWithSpeedController();  
		}

}

/*
turn 180 degrees and face the direction it came from
*/
void turn180() {
		//stopWait(0); //run
		
		//spin for 90 degrees
		for (uint16_t turnCounter = 0; turnCounter < (turn90count*2); turnCounter ++ ){
			setLeftSpeed(10);
			setRightSpeed(-10);
			handleMotorsWithSpeedController();  
		}
		

}



/*stop where robot is and set motor speed to 0, wait if stop = 1
*/
void stopWait(char stop) {
	if(stop) {
			setLeftSpeed(0);
			setRightSpeed(0);
			handleMotorsWithSpeedController();
	}

}


/*move forwared x amount grid step
*/
void moveForward(int gridSteps) {
	for (int gridStepCounter = 0; gridStepCounter < gridSteps; gridStepCounter ++) {
		moveForwardOne();
	}
}




/*----------helper functions ------------------*/


/* tell if the front ground sensors detect a gridEdge. 
Returns 1 if and edge is detected and returns 0 if no edge detected.
*/

char gridEdgeDetected() {

	// tell whether a gridEdge is detected or not
	if(proximityResult[9] > 600  || proximityResult[10] > 600) {
		return 1; //it sees the white line
	} else {
		return 0;
	}
}


/*move forwared 1 grid step
*/
void moveForwardOne(){

//	while(gridEdgeDetected()) {
	for (uint16_t gridMoveCounter = 0; gridMoveCounter < gridMoveCount; gridMoveCounter ++ ){
			setLeftSpeed(15);
			setRightSpeed(15);
			handleMotorsWithSpeedController();
	}

//	stopWait(1);
	
}

