#include "mapping.h"

/*other headerfiles*/
#include "movement.h"
#include "usart.h"


/*local variabls*/
char stopped = 0;
unsigned char obstacleArray[4] = {0,0,0,0};
enum currentDirection_t {north, east, south, west}  currentDirection = north;



#define rows 4
#define cols 4
int mapMatrix[cols][rows] = { 	{0, 0, 0, 0},
                        		{0, 1, 0, 0},
                        		{0, 1, 0, 0},
                        		{0, 0, 0, 0}  };	


/* traverse the room and update a map with what it finds
----map value meaning ----
 0 means the grid is open and available to walk through
 1 means there is an obstacle in the grid
 2 means the grid is unexplored
 3 means the grid is the location of the goal 
*/


void mapRoom() {

 turnRight();
 stopped = 1;
 exploreGrid();

}


void exploreGrid() {
	moveForward(1);
	while(stopped) {

	stopWait(stopped);
	updateMap();
	stopped = 0;
	}

}




void updateMap() {
	for(uint16_t busyWait = 0 ; busyWait <65000; busyWait++){
		stopWait(1);
		int tempTran = mapMatrix[0][0] + 0x30;	;
		usart0Transmit(tempTran,1);	

		mapMatrix[0][0] = 3;
		tempTran = mapMatrix[0][0] + 0x30;	;
		usart0Transmit(tempTran,1);
		while(1){
		}
	}
}


void detectObstacle() {
	/*the array shows location of obstacles detected by proximity sensors
	obstacleArray[4] = {front, right, back, left};
	*/
	for (unsigned char arrayCount = 0; arrayCount < 4; arrayCount++){
		obstacleArray[arrayCount] = 0;
	}

	//detect front
	if(proximityResult[0] < 312){
			obstacleArray[0]= 1; 
	}
	
	if(proximityResult[2] < 312) {
			obstacleArray[1] = 1;
	}

	if(proximityResult[4] < 312) {
			obstacleArray[2] = 1;
	}
		
	if(proximityResult[6] < 312) {
			obstacleArray[3] = 1;
	}
 
}

void updateDirection(unsigned char directionToMove) {
	switch(currentDirection) {
		case north: 
			if(directionToMove == 'L') {
				currentDirection = west;
			}
			else if(directionToMove == 'B') {
				currentDirection = south;
			}
			else if(directionToMove == 'R') {
				currentDirection = east;
			}
			else{
				currentDirection = currentDirection;
			}

			break;

		case east:
			if(directionToMove == 'L') {
				currentDirection = north;
			}
			else if(directionToMove == 'B') {
				currentDirection = west;
			}
			else if(directionToMove == 'R') {
				currentDirection = south;
			}
			else{
				currentDirection = currentDirection;
			}

			break;

		case south:
			if(directionToMove == 'L') {
				currentDirection = east;
			}
			else if(directionToMove == 'B') {
				currentDirection = north;
			}
			else if(directionToMove == 'R') {
				currentDirection = west;
			}
			else{
				currentDirection = currentDirection;
			}

			break;

		case west:
			if(directionToMove == 'L') {
				currentDirection = south;
			}
			else if(directionToMove == 'B') {
				currentDirection = east;
			}
			else if(directionToMove == 'R') {
				currentDirection = north;
			}
			else{
				currentDirection = currentDirection;
			}

			break;

	}
	
}
