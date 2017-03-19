//approach object, grab it. turn 180 degrees and stop

int turn180(speed) {

	// mtp(0, speed, -305); //this worked at the college
	// mtp(3, speed, 305);  //this worked at the college

	mrp(0, speed, -654);
	mrp(3, speed, 654);

	msleep(-654);

	printf("left motor: -654, right motor: 654\n");

	return 0;
}

int main() {
	//first setup the claw to be in a good position to pick the object up
	enable_servos();

	
	set_servo_position(1, 1910); //open the claw all the way 
	
	msleep(500);
	
	set_servo_position(3, 1100); //position the claw to be perfectly flat/horozontal/level
	
	msleep(500);

	//1. approach object
	mrp(0, 450, 1300);
	mrp(3, 450, 1300);

	msleep(1000);

	while(analog_et(0) < 600) {
		printf("analog_et = %d\n", analog_et(0));
		
		
	}
	//2. grab it
	set_servo_position(1, 270);

	

	msleep(3000);

	//3. turn 180 degrees and stop
	//turn180(500);

	printf("moving backwards %d\n", 5000);
	mrp(0, 450, -5000);
	mrp(3, 450, -5000);

	msleep(5000);

	return 0;
}