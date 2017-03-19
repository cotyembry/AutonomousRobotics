int turn180(int speed) {
	mtp(0, speed, -550);
  	mtp(3, speed, 550);

	return 0;
}

int turn90degLeft(int speed) {
	mtp(0, speed, -275); //300 was too much at the college
  	mtp(3, speed, 275);

  	return 0;
}

int grabGreenRings() {
	int turnHistory = 0;

	while(analog10(1) < 900) {
		//while light is saying 'turn more'
		turnLeft(450, 15);
		turnHistory += 15;
	}

	int keepWhileLoopRunning = 1;

	enable_servos();

	set_servo_position(1, 1910); //open the claw all the way
	
	set_servo_position(3, 1100);

	msleep(4000);

	while(analog_et(0) < 600 && keepWhileLoopRunning == 1) {
		printf("analog_et = %d\n", analog_et(0));
		goForward(450, 20);

		//this if statement isn't needed here, but it gives more control over the bot without touching it physically
		if(analog10(1) < 900) {
			//if light is ever sensed
			keepWhileLoopRunning = 0;
		}
	}

	//2. grab it
	set_servo_position(1, 270);

	turnRight(450, turnHistory); //lets get back on track to get back to the tape

	msleep(4000);

	int whileLoopRan = 0;

	// while(analog10(0) < 900) {
	// 	printf("turning back right\n");
	// 	turnRight(450, 20);
	// 	whileLoopRan = 1;
	// }

	int p5 = analog10(5);
	while(!(p5 > 970 < 1020)) {
		//while not sensing the line, keep moving forward
		goForward(450, 20);
		p5 = analog10(5);
	}
	//now black tape has been found by port 5
	//get back on the line
	
	//p5 > 970 && p5 < 1020
	p5 = analog10(5);
	while(p5 > 970 && p5 < 1020/* p5 sees black tape */) {
		//get off of the tape and onto the line
		goForward(450, 15);
		p5 = analog10(5);
	}
	//now the p5 & p6 sensors should be on either side of the black tape

	return 0;
}

int goForward(int speed, int ticks) {
	mrp(0, speed, ticks);
	mrp(3, speed, ticks);

	printf("goForward, ticks: %d\n", ticks);

	bmd(0);
	bmd(3);
}

int moveForward(int speed, int ticks, int grabbingRings) {
	//to measure distance, add up and keep track of the amount
	//of ticks moved within this function (+ or - bc of left and right turns)

	int lightFound = 0;

	printf("in moveForward: light value = %d\n", analog10(1));

	if(analog10(1) < 900) {
		//if light is on, turn left until the light is no longer on
		// turnRight(450, 30);

		lightFound = 1;
	}
	//get close
	// while(analog_et(0) < 600) {
	// 	goForward(450, 30);
	// }

	if(lightFound == 1) {
		grabGreenRings(); //heres where the branches get to
	}




	mrp(0, speed, ticks);
	mrp(3, speed, ticks);
	

	printf("moveForward, ticks: %d\n", ticks);

	bmd(0);
	bmd(3);
	// msleep(ticks);
	return 0;
}

int turnLeft(int speed, int ticks) {
	mrp(0, speed, ticks);
	// msleep(ticks);

	printf("turnLeft, ticks: %d\n", ticks);

	bmd(0);


	return 0;
}

int turnRight(int speed, int ticks) {
	mrp(3, speed, ticks);
	// msleep(ticks);

	printf("turnRight, ticks: %d\n", ticks);

	bmd(3);

	return 0;
}

int port5_seesTape() {
	//this function defines port 5's range
	if(analog10(5) > 970 && analog10(5) < 1020) {
		return 1;
	}
	else {
		return 0;
	}
}

int port6_seesTape() {
	//this function defines port 6's range
	if(analog10(6) > 915 && analog10(6) < 1000) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	//start flags
	int didTurnLeft = 0;
	int didTurnRight = 0;
	//end flags

	int ticksInc = 25;
	int whileLoopInc = 15;
	int keepRunning = 1;

	//start adjustment offset data
	int turnedLeftCount = 0;
	int turnedRightCount = 0;
	//end adjustment offset data

	int p5StateTo_p6 = 0;
	int p6StateTo_p5 = 0;

	int p5 = 0; //initialize variables
	int p6 = 0;
	while(keepRunning == 1) {
		p5 = analog10(5);
		if(p5 > 970 && p5 < 1020) {
			//p5 sees black: ~996
			//turn right
			p6StateTo_p5 = 0; //init before using
			int localTurnCounter = 0;
			while(port5_seesTape() == 1) {
				turnRight(450, whileLoopInc);
				localTurnCounter++;
				p6StateTo_p5 += whileLoopInc;
				if(localTurnCounter > 5) {
					printf("giving local adjusment\n");
					localTurnCounter = 0;
					int temp = whileLoopInc + whileLoopInc;
					turnRight(450, temp);
				}
			}

			didTurnLeft = 1;

			turnedRightCount++; //these variables will help me with letting the bot make a more smooth turn and get it off the line when its stuck on a hard turn
		}

		p6 = analog10(6);
		if(p6 > 915 && p6 < 1000) {
			//p5 sees black: ~935 - ~980
			//turn left
			p5StateTo_p6 = 0; //init before using
			int localTurnCounter = 0;
			int temp = whileLoopInc + whileLoopInc;
			while(port6_seesTape() == 1) {
				turnLeft(450, temp);
				localTurnCounter++;
				p5StateTo_p6 += whileLoopInc;
				if(localTurnCounter > 5) {
					printf("giving local adjusment\n");
					localTurnCounter = 0;
					
					turnLeft(450, temp);
				}
			}

			didTurnRight = 1;

			turnedLeftCount++;
		}

		printf("p5: %d, p6: %d\n", p5, p6);
		if(didTurnLeft == 0 && didTurnRight == 0) {
			moveForward(450, ticksInc, 0); //this is where most of the code starts to branch
		}

		int turnResult = turnedLeftCount - turnedRightCount;
		if(turnResult < 0) turnResult *= -1; //to remove any negative values
		
		printf("turnResult = %d\n", turnResult);

		if(turnResult >= 2) {
			printf("giving adjustment boost\n");
			

			if(turnedLeftCount > turnedRightCount) {
				//fix by giving a burst to turning left
				turnLeft(450, 200);
				//now check the adjustment to see if the sensor went over the black line
				if(port6_seesTape() == 1) {
					//if it did see it, make another adjustment back the other way
					turnRight(450, 100);
				}
			}
			else {
				//fix by giving a burst to turning right
				turnRight(450, 200);
				if(port5_seesTape() == 1) {
					turnLeft(450, 100);
				}
			}

			turnedLeftCount = 0;
			turnedRightCount = 0;
		}

		didTurnLeft = 0; //reset my flags for use during the next iteration
		didTurnRight = 0;
		//msleep(500);
	}
}
