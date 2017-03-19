int main() 
{
	mav(0,300);//turns the robot in an arc around the stationary wheel
	//mav(3,300);//when the opposite wheel speed is the same, the robot goes straight.  Everything between that and 0 is an arc
	sleep(2);
	
	//moving in straight lines with turns in place
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,300,3600);
	mtp(3,300,3600);
	bmd(0);
	bmd(3);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,300,-700);
	mtp(3,300,700);
	bmd(0);
	bmd(3);
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,300,3600);
	mtp(3,300,3600);
	bmd(0);
	bmd(3);
	
}


