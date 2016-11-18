#include "communication.h"

int i;

void getData()
{
	switch (demoState) {
	case 12:	// IR local communication: 2 or more robots pass information between them in sequence
				switch(demoState) {
					case 0:
						irCommInit();
						irCommRobotsNum = 4;	// total number of robots that exchange data
						irCommRobotId = 3;		// choose the id of the robot (a different id for each robot), from 0 to 254 (255 is reserved)
						if(irCommRobotId==0) {	// robot with id 0 starts the transmission of information
							irCommSendData(0x01);
							updateBlueLed(255);
							updateRedLed(255);
							updateGreenLed(128);
							demoState = 1;
						} else {
							demoState = 2;
						}
						break;

					case 1: // led is on
							// transmission: continuously send the next robot id to tell him to turn on the led
							// reception: listen for 0xFF and then turn off the led; when I receive 0xFF it means the next robot has
							// received its id, thus it has turned on its led
						irCommTasks();
						if(irCommDataSent()==1) {
							if(irCommRobotId < (irCommRobotsNum-1)) {
								irCommSendData(irCommRobotId+1);
							} else {
								irCommSendData(0x00);
							}							
						}
						if(irCommDataAvailable()==1) {
							if(irCommLedToggle==0) {
								irCommLedToggle = 1;
								updateBlueLed(255);
								updateRedLed(255);
								updateGreenLed(128);
							} else {
								irCommLedToggle = 0;
								updateBlueLed(255);
								updateRedLed(255);
								updateGreenLed(235);
							}
							i = irCommReadData();
							if(i == 0xFF) {
								demoState = 2;
								updateBlueLed(255);		
								updateRedLed(255);
								updateGreenLed(255);		
							}
						}	
						break;

					case 2: // led is off
							// transmission: continuously send my robot id to tell the next robot I turned off the led
							// reception: listen for my robot id and then turn on the led				
						irCommTasks();
						if(irCommDataSent()==1) {
							irCommSendData(irCommRobotId);							
						}
						if(irCommDataAvailable()==1) {
							if(irCommLedToggle==0) {
								irCommLedToggle = 1;
								updateRedLed(255);
							} else {
								irCommLedToggle = 0;
								updateRedLed(235);
							}
							i = irCommReadData();
							if(i == irCommRobotId) {
								updateBlueLed(255);
								updateRedLed(255);
								updateGreenLed(128);
								irCommSendData(0xFF);
								demoState = 3;					
							}							
						}
						break;

					case 3:	// led is on
							// transmission: send 0xFF untill the previous robot is turned off
							// reception: I know that it is turned off when I receive the previous robot id 
						irCommTasks();
						if(irCommDataSent()==1) {
							if(irCommDataAvailable()==1) {
								if(irCommLedToggle==0) {
									irCommLedToggle = 1;
									updateBlueLed(255);
									updateRedLed(255);
									updateGreenLed(128);
								} else {
									irCommLedToggle = 0;
									updateBlueLed(255);
									updateRedLed(255);
									updateGreenLed(235);
								}
								i = irCommReadData();
								if(irCommRobotId == 0) {
									if(i == (unsigned int)(irCommRobotsNum-1)) {
										demoState = 1;
									} else {
										irCommSendData(0xFF);
									}
								} else {
									if(i == (unsigned int)(irCommRobotId-1)) {
										demoState = 1;
									} else {
										irCommSendData(0xFF);
									}
								}
								
							}
						}						
						break;

				}
				break; 

}
}

			
	
		

