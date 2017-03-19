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


	//1. approach object
	mrp(3, 450, 300);


}