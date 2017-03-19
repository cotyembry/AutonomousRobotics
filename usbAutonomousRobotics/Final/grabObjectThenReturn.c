//approach object, grab it. turn 180 degrees and stop
int move(int speed, int ticks) {
	//printf("moving forward, ticks: %d, speed: %d\n", ticks, speed);
	mrp(0, speed, ticks);
	mrp(3, speed, ticks);
		
	if(ticks < 0) ticks *= -1; //to remove any negatives

	msleep(ticks);

	return 0;
}

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
	int et_p0 = 0;
	int keepRunning = 1;
	int inc = 0;

	//first setup the claw to be in a good position to pick the object up
	enable_servos();

	
	set_servo_position(1, 1910); //open the claw all the way 
	
	msleep(500);
	
	set_servo_position(0, 1100); //position the claw to be perfectly flat/horozontal/level
	
	msleep(500);

	//1. approach object
	// mrp(0, 450, 500);
	// mrp(3, 450, 500);

	//now approach the object and maintain a fixed distance
	while(keepRunning == 1) {
		et_p0 = analog_et(0);
		if(et_p0 > 600) {
			//move backwards
			//printf("analog_et = %d\n", et_p0);
			// move(500, (600 - et_p0));
			//printf("in greater than 600\n");

			while(et_p0 > 600) {
				move(500, -10);
				et_p0 -= 10;
			}
			//now to make it stop perfectly 600 away
			move(500, (600 - et_p0));
		}
		// printf("out of if: %d\n", analog_et(0));
		else if(et_p0 < 600) {
			//move forwards
			// move(500, (600 - et_p0));
			//printf("in less than 600\n");
			while(et_p0 < 600) {
				move(500, 10);
				et_p0 += 10;
			}
			//now to make it stop perfectly 600 away
			move(500, (et_p0 - 600));
		}
		else {
			//do nothing
			//printf("in do nothing..?: %d\n", et_p0);
		}


		// now check and see if the while loop should stop
		if((et_p0 + 20) > 600 || (et_p0 - 20) < 600 || et_p0 == 600) {
			keepRunning = 0;
			printf("in final if. et_p0 = %d\n", et_p0);
		}
		// inc++;
		// if(inc > 9) {
		// 	keepRunning = 0;
		// }
	}

	

	//2. grab it
	set_servo_position(1, 270);

	msleep(500);

	//3. turn 180 degrees and stop
	//turn180(500);
}