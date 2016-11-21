#include "pathing.h"
#include <util/delay.h>

#include "motors.h"
#define rows 4
#define cols 4


                        	
int myArray[cols][rows] = { 	{0, 0, 1, 0},
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
    		else  //(myArray[i][j] == 1)
				{
	    		
				    setLeftSpeed(0);
					setRightSpeed(0);
			        GREEN_LED1_OFF;
					
	 			}
	 	
   	handleMotorsWithSpeedController();
		//delaym();
		//_delay_ms(2000);
        }
    
 }
}

/*void delaym ()
{
	for (uint16_t counter = 0; counter<27500; counter ++ )
	{
		counter++;
	}
}
*/
