#include "pathing.h"
#include <util/delay.h>
#include "movement.h"

#define rows 4
#define cols 4


                        	
int myArray [cols] [rows] = { 	{0, 0, 1, 0},
                        		{0, 1, 0, 0},
                        		{0, 1, 0, 0},
                        		{0, 0, 0, 0}  };							

void getMap() {
    
  

    for (int i = 0; i < cols; i++) {
    	for (int j = 0; j < rows; j++) {
	      	   
    		if (myArray[i][j] == 0)
				{
       			    setLeftSpeed(10);
					setRightSpeed(10);	
					GREEN_LED1_ON;			
	 			}                 
    		else if (myArray[i][j] == 1)
				{
	    		//for (uint16_t counter = 0; counter<27500; counter ++ ){	    
				 // stopWait(1); 
				    setLeftSpeed(0);
					setRightSpeed(0);
					//GREEN_LED3_ON;
					GREEN_LED1_OFF;
					//updateRedLed(255);		
	 			}
	 	//	stopWait(0);
    		//	}
		  
		handleMotorsWithSpeedController();
		_delay_ms(4000);
        }
     }
 
}
