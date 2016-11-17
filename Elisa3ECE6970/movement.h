
#ifndef MOVEMENT_H
#define MOVEMENT_H


#include "variables.h"
#include <avr\io.h>
#include <avr\interrupt.h>
#include "behaviors.h"
#include "speed_control.h"

/*----variables for file-----*/
static uint16_t turn90count = 27500; //nonmagnetic surface counter

//turns 90 degrees to the left
//void turnLeft();

/*turns 90 degress to the right
*/
void turnRight();

/*
//turn 180 degrees and face the direction it came from
turn180();

/*move forwared 1 grid step
*/
void moveForward();

/*

moveForward(uint4_t gridSteps); //move forward gridSteps amount of gridsteps
	for gridsteps > 0 
	setLeft and Right speed until gridEdgeDetected()
	stop&wait 
	gridsteps-- 

gridFollow();

/*stop where robot is and set motor speed to 0, wait while stop = 1
*/
void stopWait(char stop);


//go back until 
moveBackward();

/* tell if the front ground sensors detect a gridEdge. 
Returns 1 if and edge is detected and returns 0 if no edge detected.
*/
char gridEdgeDetected();

/*if front ground sensor < CLIFF_threshold
	return gridEdgeDetected


*/
#endif
