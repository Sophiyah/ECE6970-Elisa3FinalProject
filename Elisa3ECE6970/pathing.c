#include "pathing.h"
#include <util/delay.h>
#include "motors.h"
#include "movement.h"

#define rows 4
#define cols 4
/*----variables for file-----*/
static uint16_t turn90count = 2750; //nonmagnetic surface counter
static uint16_t gridMoveCount = 33000; 


                        	
int myArray[cols][rows] = { 	{0, 0, 1, 0},
                        		{0, 1, 0, 0},
                        		{0, 1, 0, 0},
                        		{0, 0, 0, 0}  };							

void getMap() {
    
/*
		for (uint16_t turnCounter = 0; turnCounter<turn90count; turnCounter ++ ){
 			setLeftSpeed(10);
 			setRightSpeed(-10);	
 			GREEN_LED1_ON;
		handleMotorsWithSpeedController();
		}
        //delaym();
     }
*/
   for (int i = 0; i < cols; i++) {
    	for (int j = 0; j < rows; j++) {
	      	   
    		if (myArray[i][j] == 0)
				{
       			    setLeftSpeed(10);
					setRightSpeed(10);	
					GREEN_LED1_ON;
					
							
	 			}                 
    		else  if (myArray[i][j] == 1)
				{
	    		
				    setLeftSpeed(0);
					setRightSpeed(0);
			        GREEN_LED1_OFF;
				
					
	 			}
	 	
   			handleMotorsWithSpeedController();
		    stopWait(1); 
		
        }

      }
	  	 
    
}

void delaym ()
{
	for (uint16_t counter = 0; counter<27500; counter ++ )
	{
		 setLeftSpeed(0);
		setRightSpeed(0);
	}
}


