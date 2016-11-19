#include "communication.h"
#include "irCommunication.h"

int i;


void getData()
{
	
switch (demoState) {
case 0:
	irCommInit();

	irCommRobotsNum = 4;	// total number of robots that exchange data
	irCommRobotId = 3;	
		// choose the id of the robot (a different id for each robot), from 0 to 254 (255 is reserved)
	if(irCommRobotId==0) {	// robot with id 0 starts the transmission of information
		irCommSendData(0x01);
		GREEN_LED5_ON;
		demoState = 1;
		} 
		else {
			demoState = 2;
		}
 case 1: 
    irCommTasks();
	if(irCommDataSent()==1) {
		if(irCommRobotId < (irCommRobotsNum-1)) {
			irCommSendData(irCommRobotId+1);
		} else {
			irCommSendData(0x00);
		}							
	}
}
}
			
	
		

