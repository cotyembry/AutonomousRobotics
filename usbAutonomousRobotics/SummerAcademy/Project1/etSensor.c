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
	
	int ticks = getTicksForOneInch();

	move(500, ticks);

	printf("ticks = %d\n", ticks);

	int stayRunning = 1; //initialize to 'true'


	while(stayRunning == 1) {
		//printf("analog10 value = %d\n", analog10(0));
		if(analog_et(0) >= 600) {
			//move forward some amount, creep though..
			printf("keep moving forward\n");
			move(300, 25);
			
		}
		else if(analog_et(0) < 600) {
			printf("Its getting closer!! Backup!!!\n");
			move(300, -25);
		}
	}
}


/*
int main() {
	int distance;
	while(1) {
		distance = analog_et(0);
		printf("ET: %d\n", distance);
	}
	return 0;
}
*/
