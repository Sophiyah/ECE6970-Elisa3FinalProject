
#ifndef MAPPING_H
#define MAPPING_H

/* File Contains the algorithm for searching through and updating a map of the room*/ 

/* traverse the room and update a map with what it finds
----map value meaning ----
 0 means the grid is open and available to walk through
 1 means there is an obstacle in the grid
 2 means the grid is unexplored
 3 means the grid is the location of the goal 
*/
void mapRoom();

#endif
