#include "mapping.h"
#include "movement.h"


/*local variabls*/
char stopped = 0;

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




void updateMap(){
	for(uint16_t busyWait = 0 ; busyWait <65000; busyWait++){
	}
}


void detectObstacle() {
	unsigned char frontObstacle = 0;
	unsigned char rightObstacle = 0;
	unsigned char backObstacle = 0;
	unsigned char leftObstacle = 0;
	
	//detect front
	if(proximityResult[0] < 312){
			frontObstacle = 1; 
	}
	
	if(proximityResult[2] < 312) {
			rightObstacle = 1;
	}

	if(proximityResult[4] < 312) {
			backObstacle = 1;
	}
		
	if(proximityResult[6] < 312) {
			leftObstacle = 1;
	}
 
}
