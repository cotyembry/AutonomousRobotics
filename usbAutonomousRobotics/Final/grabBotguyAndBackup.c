int grabBotguy(int moveValue, int grabberPosition, int openValue, int closeValue) {	

	//servos go from 0 to 2047
	set_servo_position(0, grabberPosition); //set the position of the claw that will clench to straight out
	set_servo_position(1, openValue); //open claw all the way up

	printf("about to move %d ticks\n", moveValue);

	//1. move forward a bit
	mrp(0, 450, moveValue);
	mrp(3, 450, moveValue);

	msleep(500);

	//2. grab bot guy
	set_servo_position(1, closeValue);

	//3. go backwards
	mrp(0, 450, -moveValue);
	mrp(3, 450, -moveValue);

	msleep(500);

	//4. open up claw
	set_servo_position(1, closeValue);

	return 0;
}

int changeMovementValue(moveValue) {
	enable_servos();

	msleep(500); //give time to enable the servos (just in case)

	int middleValueForClaw = 1000;
	set_servo_position(0, middleValueForClaw);

	int claw0Position = get_claw_position(0); //first get the position of the claw

	int ranOnce = 0;

	while(get_claw_position(0) == claw0Position) {
		//i.e. while the claw position doesn't move
		//do nothing and wait for the claw position to change
		if(ranOnce == 0) {
			printf("waiting for movement\n");
			ranOnce = 1; //make this code run one time per function call
		}
	}

	printf("movement noticed\n");

	if(get_claw_position(0) > claw0Position) {
		//go forward more next time
		printf("claw position went up\n");
		moveValue += movementAdjustment; //move more next time
	}
	else {
		//go forward less next time
		printf("claw position went down\n");
		moveValue -= movementAdjustment; //move less next time
	}

	return moveValue;
}

int main() {
	int grabberPosition = 1000;
	int openValue = 2047; //value to send to open the claw
	int closeValue = 0; //value to send to close the claw
	int moveValue = 500; //the value to start moving the bot (this may change later)

	int movementAdjustment = 25;

	grabBotguy(moveValue, grabberPosition, openValue, closeValue);

	printf("about to start dynamic alter of movementValue\n");

	while(1 == 1) {
		moveValue = changeMovementValue(moveValue); //this will function will loop until the claw is moved manually up or down to 'dynamically' increase or decrease the movementValue without having to recompile
		grabBotguy(moveValue, grabberPosition, openValue, closeValue);
	}

	printf("past dynamic alter while loop\n");

	msleep(1000); //give enough time to finish up on the servos moving

	disable_servos();

	return 0;
}
