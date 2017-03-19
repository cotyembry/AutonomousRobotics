int main() 
{	//turn to face can
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(3,600,850);
	bmd(3);
	
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,600,2650);//drives just past the black line
	mtp(3,600,2650);
	bmd(0);
	bmd(3);

	while(analog10(1)<900){//turns left until the right
	mav(3,200);//sensor sees the black line
	}
	//follow the line
	while(analog10(0)>900 || analog10(1)>900){
		if(analog10(0)<900 && analog10(1)>900){//left sees white
			mav(0,300);//turn right
			mav(3,200);
		}
		else if(analog10(0)>900 && analog10(1)<900){//right sees w
			mav(0,200);//turn left
			mav(3,300);
		}
		else{//both see the black line
			mav(0,300);
			mav(3,300);
			}
		}

	return 0;			
}
