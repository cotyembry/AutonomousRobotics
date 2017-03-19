//functions
void turn(int side);//
void straight(int distance, int speed);

void main(){
	while(!a_button()){;}//pauses the program until the a button is pressed
	straight(2600,700);
	turn(0);//turn left
	straight(800,700);
	turn(1);//turn right
	straight(1000,1000);
	
}

void turn(int side){
	//0=left, 1=right
	if(side==0){//turn left
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,300,-700);
		mtp(3,300,700);
		bmd(0);
		bmd(3);
	}
	else if(side==1){
		clear_motor_position_counter(0);
		clear_motor_position_counter(3);
		mtp(0,300,-700);
		mtp(3,300,700);
		bmd(0);
		bmd(3);
	}
}

void straight(int distance, int speed){
	clear_motor_position_counter(0);
	clear_motor_position_counter(3);
	mtp(0,speed,distance);
	mtp(3,speed,distance);
	bmd(0);
	bmd(3);
}
	
