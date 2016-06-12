#include <math.h>

// Created on Wed Jun 8 2016
// Last modified on: 6/12/16

//Author:	John Coty Embry
//Class:	Autonomous Robotics	
//Program Comment: This will move the robot forward and around


//STANDARDS: anytime, and I mean anytime you make the bot move with code, update the global x and y coordinates

/*
To make this better:

Create a virtual 'map', literally measure out the entire course then programatically
save variables at the positions the objects are located at and then get a perfect 
calculation for each wheel rotation and if a turn/adjustment has to happen when this
hasn't been counted for (i.e. we measured and was assuming that the robot was going
to go straight and nothing else, but the robot waisted a bit of that by having to 
turn to correct its self back on track), then subtract the amount that the adjustment
took from the overall predicted movement.

This could help get a sense of where you're at in the environment as you are trying
to write code to solve the problem.

If this is done correctly, this could end up as a VOM (virtual object model) and then
a person could perform 'DOMish' methods on the robot to get positioning and how far 
away an object is and things like that
*/

/* define global variables */

//(x,y) position initialization: this will be important and should complement the way the course
//is set up based on the measurements

//*QUESTION: where is the (x, y) talking about. The front center of the robot while it is in absolute positing? For now, until this is changed, this is what I will go by and off of
int x = 20;
int y = 50;

//motors and 'config' (zero-three are the motors)
int zero = 0;
int one = 1;
int two = 2;
int three = 3;
int speed = 1000; //velocity
long delta_pos = 3000;

//ticks will be used to know on wheel turn
int ticks = 0;
//ticksHeight is the overall number of ticks on the course (and each course might be different in size)
int ticks1Height = 0;
int ticks2Height = 0;

//course data array used in loadCourse() or perhaps  the calculateRoute() functions
int course1[100];
int course2[100];
//...

//why I do blah_blah'_1' & ...'_2' here is because each course will need to have multiple coordinates to navigate to
//and we will hopefully be able to pump this into the A* search algorithm to make this work more efficiently

//TODO: figure out a way to keep track of how many variables there are here and how many will be used
//each time - especially if we want to use this same code over and over again for each course. If we 
//want to do it that way, which is what I would reccomend, I would suggest adding more dynamic content
//rather than static hard coded content, so this will need to be refactored.

//**..Or to be lazy we could just hard code one single variable to be the set value for that particular
//course and make multiple copies of this code to be used for each different course. That is what I
//will do right now until this is refactored
int course1_xyCoords_1[2];
int course1_xyCoords_2[2];
//...
int course2_xyCoords_1[2];
int course2_xyCoords_2[2];
//...

//this next variable is what I meant in the ** point above
int numOfCourse1Coords = 2;
int numOfCourse2Coords = 2;

/* end global variables */


/* define sub functions first before main */

int calculateRoute() {
	//TODO: maybe implement the A* search algorithm here to find the
	//best path to take to get to the route to navigate to
	
	return 0;
}

//next_x & next_y are literally the next (x,y) location the bot needs to go to
int findAngle(next_x, next_y) {
	//this is a stub to use for the angle that will be found during number 1. of the implementation. It will probably
	//later be known as 'orientationAngle' or something like that in the future when it actually gets implemented
	int unknownAngle = 0;
	//number 1. is probably going to be the hardest angle to get a number/calculation on
	
	
	//find the degree/amount the bot needs to turn to be able to be pointing straight at the next (x, y) coordinate
	//that it needs to navigate to
	
	//1. find the orientation/current angle of the bot somehow
	//TODO: figure out the 'somehow'.
		//this will probably consist of having to force other classes to save history of the changes to BOTH the left
		//and right wheel/motor and then this function can use that historical data to calculate and get the result
		//of the current orientation of the bot (i.e. the slop of the angle that the bot is turned with respect to the
		//x and y axis)
	
	//2. find the minimal degree that the bot needs to turn (essentially 'minimal' means turn right or turn left)
	
	//use the slope calculated from above 1. to find the result for 2.
	
	//first I will build a mental triangle in my head and solve it here to get the inside angle
	//hopefully this works for all test cases and not just the current one I have
	int a = next_x - x;
	if(a < 0) a *= -1; //we don't want to allow 'a' to be a negative value
	int b = y - next_y;
	if(b < 0) b *= -1; //we don't want to allow 'b' to be a negative value
	//a^2 + b^2 = c^2
	//now perform a sqrt() operation here. TODO: check the syntax and make sure I'm using this sqrt() function correctly
	int c = sqrt((a*a) + (b*b));
	
	//I have all of the sides calculated. now get the inside angle degree using the sides
	//ex: sin(theta) = a / c == theta = sin^(-1)(a / c) //by doing this conversion I can solve for the theta angle with sin
	
	//hint: we may want to eliminate the possibility of dividing by zero here as well. If this case comes up, we may end
	//up having to do some 'monkey patching' or something to handle these - hopefully rare - cases
	int alpha = 0; //sin^(-1)(a / c); //TODO: see if there is a built in function in C to do this arcsin function
	
	//finally, use the unknownAngle variable stub (or the real thing if it's implemented) to piece together the opposite side
	//of the inside 'alpha' angle from the triangle constructed above
	
	//alpha + theta + unknownAngle == 180 (since this is a straight line - in my test case it is anyways)
	//here the only angle I wouldn't know is theta so all we have to do is solve for theta
	int theta = 180 - (alpha + unknownAngle);
	
	//3. return the angle
	
	return theta;
}

int loadCourse() {
	//TODO: get the data structure to hold a reference to

	return 0;
}

int loadXYCoords() {
	//TODO: get the data structure to hold a reference of
	//where to navigate the bot to
	
	//right now I just have them hard coded into the arrays
	//I think I could clean this up to be:
		//course1_x_y_1 = [50, 100]; ...
	//to set both indexs of the array at once, but I dont' know if the syntax is correct
	//so I just stuck with doing it the way I know how it will for sure work
	
	//where [0] = x coordinate, [1] = y coordinate
	course1_xyCoords_1[0] = 50;
	course1_xyCoords_1[1] = 100;
	
	course1_xyCoords_2[0] = 70;
	course1_xyCoords_2[1] = 15;
	
	course2_xyCoords_1[0] = 120;
	course2_xyCoords_1[1] = 110;
	
	course2_xyCoords_2[0] = 33;
	course2_xyCoords_2[1] = 105;
	
	return 0;
}

int resolveCollision() {
	//this is for when the bot runs into something and the logic on what it should do next
	//TODO: (also remove the 1 from out of the if - I did this to remove the compiler errors)
	if(1 /* objective (x,y)'s location is closer if turning right */) {
		//i.e. turn it 'right' to be followed along the line
	}
	else {
		//i.e. turn it 'left' to be followed along the line 
	}
	return 0;
}

//I think by default the claw should be held clenched once this function is
//invoked, and the only way from there to release the claw would be to call
//the releaseClaw() function
int squeezeClaw() {
	//TODO: implement logic to squeeze the claw
	return 0;
}

int releaseClaw() {
	//TODO: implement logic to release/open the claw all the way back up
	return 0;
}

int loadObjectives() {
	//TODO: pretty much implement all of this
	
	//1. go to the 'store' to load the 'course' to be driven over
	loadCourse();
	
	//now that the course is loaded, this next part of the logic will be incremental
	//we need to load the (x,y) location that the bot needs to 'navigate' to only.
	//be simple and think literally one thing at a time - we can add code later for
	//the edge cases
	
	//2. load (x,y) coordinate to move the bot to
	loadXYCoords();
	
	//here is a tricky part that might require the most logic: calculating the best,
	//most optimal route to take to get to the path.
	//I think we should use the A* search algorithm. I have documents on how to use it
	
	//3. now to setup the best route to take to get to the (x,y) position
	calculateRoute();
	
	//4. once everything has been done and the movement array, or whatever data structure
	//will be used to tell the bot the direction to move and the increments and turning
	//we can finally return
	
	return 0;
}

//turnLeft will take an optional degree parameter
int turnLeft(degree) {
	//calculate making the right side of the bot's motor turn faster than the left
	//all depending on the degree specified
	
	//if 90 degrees was specified for the turn, you might have to totally stop the bot's left side motor
	//and only turn the right side motor
	
	//maybe even for every single degree that is given, just turn 'n' amount of ticks (or partial ticks)
	//i.e. a fraction of a tick, turn off the appropriate motor, let the other motor turn the specified
	//conversion of ticks to get the the degree specified for the turn then finally turn back on the
	//appropriate motor. This is slower and will not be the best approach during a race, but it is the
	//best accuracy I would say
	
	if(degree) {
		//TODO: check syntax of if: I think this is the correct code to check if degree is defined
	}
	else {
		//if here, degree paramater isn't defined so default to -90 degrees
	}
	
	return 0;
}

int turnLeftOnLine() {
	//TODO: implement turning left and also using the sensors to stay on the line
	
	return 0;
}

int turnRight(degree) {
	//calculate making the left side of the bot's motor turn faster than the right
	//all depending on the degree specified
	
	//if 90 degrees was specified for the turn, you might have to totally stop the bot's right side motor
	//and only turn the left side motor
	
	//maybe even for every single degree that is given, just turn 'n' amount of ticks (or partial ticks)
	//i.e. a fraction of a tick, turn off the appropriate motor, let the other motor turn the specified
	//conversion of ticks to get the the degree specified for the turn then finally turn back on the
	//appropriate motor. This is slower and will not be the best approach during a race, but it is the
	//best accuracy I would say
	
	if(degree) {
		//TODO: check syntax of if: I think this is the correct code to check if degree is defined
	}
	else {
		//if here, degree paramater isn't defined so default to 90 degrees
	}
	
	return 0;
}

int turnRightOnLine() {
	//TODO: implement turning right and also using the sensors to stay on the line
	
	return 0;
}


int startMovementWithVirtualRoute() {
	//declare and initialize movement helper variables
	int move_xToHere = 0;
	int move_yToHere = 0;
	
	//make sure to have a reference to the data structure that was created in the earlier
	//code that did the 'thinking' work that will be used very shortly in the code to
	//apply 'imperative' step by step code to move the bot
	
	
	
	//go through the arrays that have been set up from the loadXYCourse() function and for
	//each of the iterations through this, perform the movement on the bot that is specified
	//within the data structure
	for(int i = 0; i < numOfCourse1Coords; i++) {
		//this will be kind of confusing based on how the variables are currently
		//structured on how the control flow of this loop will need to be implemented
		//I'll do the best I can to make it simple
		
		//every 'xy_course' variable is worth 2 because each variable holds to sets of data,
		//the x data, and also the y data
		
		//every iteration will be the 'next' course1_xyCoordinate variable that holds the two
		//new x,y data values so I will use a switch statement to get the flow of the code
		//to reference the correct variable
		
		//*note: if we are going to choose hard coding the values of the variables like in
		//the bullet with the ** on it this switch statement will also need to be hard coded
		//to point at the correct variables depending on the iteration through the for loop
		
		
		/*
		//-------
		//help with movement (simulator only, I haven't tested this on the actual robot)
			//all movement is RELATIVE to the prior position
			//-up: if you specify delta_pos as a negative number, the robot will go up
			//-down: if you specify delta_pos as a positive number, the robot will go down (like y coordinates in the
			browser)
			//-right: 
			//-left: 
		//-------
	
		//examples: start movement
		
		//move_at_velocity(){}
		//mav(){}
		//mrp(<motor#>,<velocity>,<position>)
		//mrp(){}
	
		mrp(zero, speed, delta_pos);
		mrp(three, speed, delta_pos);
	
		//and when done with movement apparently you have to call bmp(...)? though I'm not sure what it does yet
		bmd(zero);
		bmd(three);
		
		//examples: end movement
		*/
		
		//before we get started moving you must call this function before starting the movement of the motor (I think)
		clear_motor_position_counter(zero);
		clear_motor_position_counter(three);
		
		//inside this switch statement is where the actual movement/function calls will be
		//it should interact with the API provided to use from the bots
		
		//*QUESTION: Is C blocking? meaning no other code will continue to execute while this code is being executed
		//if so, this switch statement within the for loop should work nicely since itll come here, perform the movement
		//of the bot (blocking the thread), then move on and go through to the next iteration of the loop and branch into
		//the next case statement
		switch(i) {
			case 0:
			
				printf("in case 0\n");
			
				//TODO: I had a though - what if when when turning to set the x position, we mess up the y position
				//a tad bit...we would need to correct for that, so I propose setting the x position first, then
				//setting the y position just to have this mental model of the issues that could happen
				//-------
			
				//first move both tires to the absolute positioning of where we need to go
				//meaning take the new value of where we need to navigate to and subtract
				//from the current y coordinate location it is at and this will tell us
				//relative to the current position how much this bot needs to move
			
					
				int angleDegree = findAngle(course1_xyCoords_1[0], course1_xyCoords_1[1]);
				
				//now that the angleDegree has been found, lets continue on and actually produce the movement
				//to move the bot to the correct position
			
				//turn bot
			
				//move bot
				
			
			
				/* //I did this part until I went back and created the findAngle(...) function. Now this code is deprecated
				//this part tells us the y amount to move
				move_yToHere = course1_xyCoords_1[1] - y; //here 'y' is a global
			
				//I don't think this if, else flow is needed, but for now I will leave it so the code can be more explicit
				//-note: this first part of the movement is only updating the y position of the bot
				if(move_yToHere < 0) {
					//negative result = go up
					mrp(zero, speed, move_yToHere);
					mrp(three, speed, move_yToHere);
					
					printf("moved up %d\n", move_yToHere);
					
					y += move_yToHere;	
				}
				else {
					//positive result = go down
					mrp(zero, speed, move_yToHere);
					mrp(three, speed, move_yToHere);
					
					printf("moved down %d\n", move_yToHere);
					
					y += move_yToHere;
				}
				
				//REMEMBER, always update y after moving the bot
				
				bmd(zero);
				bmd(three);
				
				clear_motor_position_counter(zero);
				clear_motor_position_counter(three);
				
				//now move to the x coordinate that is specified (this one is going to be a little bit harder)
				//try to use the turnLeft(degree), turnLeftOnLine(), turnRight(), and turnRightOnLine() functions
				//heavily for this part to get the turning correct
				
				//init x movement variable
				move_xToHere = 0;
				//now to see how much we need to move the x position
				move_xToHere = course1_xyCoords_1[0] - x; //here 'x' is a global
				
				//move_xToHere = 1000; //this will almost make the bot make a complete right turn
				
				if(move_xToHere < 0) {
					//negative result = go left
					//but how much? ... we need to solve for the actual angle here
					
					//angleDegree is the amount the bot needs to turn to be looking straight at the (x,y)
					//coordinate it needs to navigate to
					int angleDegree = findAngle();
					
					mrp(zero, speed, move_xToHere);
					//mrp(three, speed, move_xToHere);
					
					printf("moved %d to the left\n", move_xToHere);
				}
				else {
					//positive result = go right
					mrp(zero, speed, move_xToHere);
					//mrp(three, speed, move_xToHere);
					
					printf("moved %d to the right\n", move_xToHere);
				}
				*/
				
				
				
				
				/* -reference data not related to the current code really-
				//mrp(zero, speed, ... );
 				//mrp(three, speed, course1_xyCoords_1[1]);
				
				int x = 20;
				int y = 50;
			
				course1_xyCoords_1[0] = 50;
				course1_xyCoords_1[1] = 100;
				
				course1_xyCoords_2[0] = 70;
				course1_xyCoords_2[1] = 15;
				*/
			
				break;
			
			case 1:
				printf("in case 1\n");
			
				//mrp(zero, speed, delta_pos);
 				//mrp(three, speed, delta_pos);
			
				break;
			
			case 2: 
				break;
			
			case 3: 
				break;
			
			case 4:
				break;
			
			case 5: 
				break;
			
			case 6:
				break;
			
			case 7:
				break;
			
			default:
				break;
		}
		//end switch statement
		
		//and when done with movement apparently you have to call bmp(...)? though I'm not sure what it does yet
		bmd(zero);
		bmd(three);
		
	}
	//end for loop
	
	printf("out of for loop\n");
	
	return 0;
}

/* end sub functions */

int main() {
	
	//Time to load the 'map'/course and the routes/navigation/tasks to do and the incremental 'imperative'
	//actions that are going to have to happen for the theoretical calculations on the best path/route
	loadObjectives();
	
	
	//next let us actually take the theoretical 'values' from the data structure that were
	//just created/produced/engineered in the loadObjectives() function's logic and put it
	//to actual use that the bot will act out to be able to complete the objective(s)
	startMovementWithVirtualRoute();
	
	
	return 0;
}
