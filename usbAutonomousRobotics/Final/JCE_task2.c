//Author:	John Coty Embry
//Date: 6/25/16
//Task 2

//approach an object and stop without touching it. Maintain a fixed distance between the robot and the object as the object moves toward or away from your robot

int move(int speed, int ticks) {
	//printf("moving forward, ticks: %d, speed: %d\n", ticks, speed);
	mrp(0, speed, ticks);
	mrp(3, speed, ticks);
		
	if(ticks < 0) ticks *= -1; //to remove any negatives

	msleep(ticks);

	return 0;
}

int main() {

	//maintain a 600 distance from object at all times


	int keepRunning = 1; //init variables
	int et_p0 = 0;

	while(keepRunning == 1) {
		et_p0 = analog_et(0);
		//if port zero is too close to object
		if(et_p0 > 600) {
			//move backwards
			//printf("analog_et = %d\n", et_p0);
			// move(500, (600 - et_p0));
			//printf("in greater than 600\n");

			//move backwards over and over until a good distance away
			while(et_p0 > 600) {
				move(500, -10);
				et_p0 -= 10;
			}
			//now to make it stop perfectly 600 away
			move(500, (600 - et_p0));
		}
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
		//printf("out of while loop: et_p0 = %d\n", et_p0);
	}
}