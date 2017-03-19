//Author:	John Coty Embry
//Date: 6/25/16
//Task 4
//approach object, grab it. turn 180 degrees and stop

int turn180(int speed) {

	// mtp(0, speed, -305); //this worked at the college
	// mtp(3, speed, 305);  

	mrp(0, speed, -654); //this worked with new wheels
	mrp(3, speed, 654);

	msleep(654);

	printf("left motor: -654, right motor: 654\n");

	return 0;
}

int main() {
	//first setup the claw to be in a good position to pick the object up
	enable_servos();

	
	set_servo_position(1, 1910); //open the claw all the way 
	
	msleep(500);
	
	set_servo_position(3, 1130); //position the claw to be perfectly flat/horozontal/level
	
	msleep(500);

	//1. approach object
	mrp(0, 450, 1300);
	mrp(3, 450, 1300);

	msleep(1000);

	//while the sensor isn't a good distance from the object
	while(analog_et(0) < 600) {
		printf("analog_et = %d\n", analog_et(0));
		//the bot will be coasting here and the claw will grab the object right after this while loop ends (i.e. when the object is close enough to grab)
	}
	//2. grab it
	set_servo_position(1, 270);

	msleep(2000);

	//pick it up a little
	set_servo_position(3, 500);
	msleep(3000);

	//3. turn 180 degrees and stop

	printf("doing 180 turn\n");
	mrp(0, 450, -654);
	mrp(3, 450, 654);

	msleep(5000);

	return 0;
}