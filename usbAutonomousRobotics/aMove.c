//91 ticks will move the big black tire 2 inches
//~45 will move the big black tire 1 inch



int zero = 0, three = 3;
int speed = 1000;

void getTicks(distanceInInches) {

}

long getTicksToMoveOneInch() {
	/*
	long ticks = 0;

	//circumference = pi * d , 1100 ticks/revolution
	float inches = 12;//inches: distance to travel, d= diameter of wheel
	float d = 2.6875;
	//here ticks is the amount to move 17 inches
	ticks = ((inches/(3.14159*d)*1100) / 17);//computes the distance from inches to ticks
	
	long ans = (12/(3.14159*2.6875)*1100);
	printf("%d ticks will go 17 inches\n", ans);
	*/

	return 45;
}











void move(ticks) {
	clear_motor_position_counter(zero);
	clear_motor_position_counter(three);
	mtp(zero, speed, ticks); //'move_to_position'
	mtp(three, speed, ticks);
	bmd(zero); //finish up for motor movement
	bmd(three);
}

int main() {
	long ticks = getTicksToMoveOneInch();
	
	ticks = ticks * 12;
	
	printf("about to move %d ticks\n", ticks);

	move(ticks);

}
