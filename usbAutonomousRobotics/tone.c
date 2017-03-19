int getTicksForOneInch() {
	return 100;
}

int move(int speed, int ticks) {
	//circumference = pi * d , 1100 ticks/revolution
	//inches: distance to travel, d= diameter of wheel

	//ticks= (inches/(3.14159*d)*1100);//computes the distance from inches to ticks
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);

	mtp(0, speed, ticks);
	mtp(3, speed, ticks);

	bmd(0);
	bmd(3);

	//freeze(0);
	//freeze(3);

	return 0;
}

int main() {
	//enable_servos();
	//0 to 2047 the port position ranges

	//0 is for all the way closed and all the way up
	//set_servo_position(1, 0);
	//set_servo_position(3, 0);


	tone(800, 2);
	tone(800, 2);
	tone(800, 2);
	tone(750, 2);
	tone(800, 2);
	tone(900, 2);

	// msleep(2);

	// set_servo_position(1, 1000);
	// set_servo_position(3, 1000);

	// msleep(2);

	// set_servo_position(1, 2000);
	// set_servo_position(3, 2000);

	//ports 1 and 3 the servos are on
	//1 is for the closing part, 3 is for the up and down

}