int getTicksForOneInch() {
	return 100;
}


int main() {
	//circumference = pi * d , 1100 ticks/revolution
	int inches=12, ticks;//inches: distance to travel, d= diameter of wheel
	float d=1.2;
	//ticks= (inches/(3.14159*d)*1100);//computes the distance from inches to ticks
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	

	//ticks = 42; //this went like 2 centimeters 
	//ticks = 450; //this went (4 inches + 10[ticks])
	//ticks = 425; //this went (4 inches + 7[ticks])
	
	//3[ticks] on the inches side of the ruler == 25 movement ticks

	//i want to go 1 inch
	//1 inch is is 16[ticks]. So, 25 ticks == 3/16 == 0.1875 inches
	//75 ticks * 3 == 100 ticks // ((3/16) * 3) = 12/16 == 0.75 inches
	//ticks = 33; //this goes 0.25 inches i.e. 4/16ths

	ticks = getTicksForOneInch() * 12;


	mtp(0,300,ticks);
	mtp(3,300,ticks);

	bmd(0);
	bmd(3);

	freeze(0);
	freeze(3);
	
	printf("ticks = %d\n", ticks);

	// mtp(0,300,0);
	// mtp(3,300,0);
	
	// bmd(0);
	// bmd(3);
}