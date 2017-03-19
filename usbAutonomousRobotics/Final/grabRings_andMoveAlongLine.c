int grabGreenRings() {
	printf("in grabbingRings\n");
	turnLeft(450, 200);
	// moveForward(450, 0, 1);
	while(analog_et(0) < 600) {
		printf("analog_et = %d\n", analog_et(0));
		moveForward2(450, 20);
	}
	//2. grab it
	set_servo_position(1, 270);

	turnRight(450, 200);

	moveForward(450, 0, 1);

}

int moveForward2(int speed, int ticks) {
	mrp(0, speed, ticks);
	mrp(3, speed, ticks);

	printf("moveForward2, ticks: %d\n", ticks);

	bmd(0);
	bmd(3);
}

int moveForward(int speed, int ticks, int grabbingRings) {
	int ranIfElseBlock = 0;

	printf("in moveForward: light value = %d\n", analog10(1));

	//first check to see if I'm already in the process of grabbing the rings
	//1. go get rings
	if(analog10(1) < 900 && grabbingRings == 0) {
		//if I'm not, get on tract to grab it
		grabGreenRings();
		ranIfElseBlock = 1;
	}
	//2. get back on the line
	else if(analog10(1) < 900 && grabbingRings == 1) {
		//if here I should already have the rings in the claw
		//and just need to get back on the line

		while(analog10(1) < 900) {
			printf("light says turn left\n");
			turnLeft(450, 100);
		}

		int p6 = analog10(6);
		if(!(p6 > 915 && p6 < 1000)) {
			
			p6 = analog10(6);

			turnRight(450, 100);
			moveForward(450, 30, 1);
		}
		ranIfElseBlock = 1;
	}
	else if(analog10(1) >= 900 && grabbingRings == 1) {

		//light is off
		int p6 = analog10(6);
		while(!(p6 > 915 && p6 < 1000)) {
			p6 = analog10(6);

			printf("now getting back on tape\n");
			moveForward2(450, 30);
		}
		int whileLoopInc = 15;
		//now that the sensor has seen the tape, lets make sure to get on it completely
		turnRight(450, (whileLoopInc + whileLoopInc));

	}


	if(ranIfElseBlock == 0) {
		mrp(0, speed, ticks);
		mrp(3, speed, ticks);
	}

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
			moveForward(450, ticksInc, 0);
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