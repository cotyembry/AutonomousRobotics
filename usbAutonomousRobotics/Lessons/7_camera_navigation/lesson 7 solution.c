//red in color model 0
int main(){
	int red = 0;
	
	track_update();
	while(track_x(red , 0)!=80){	
		if(track_x(red , 0) > 80){//if centroid is right,
			mav(0,100);//turn right
			mav(3,-100);
		}
		else if(track_x(red,0) < 80){//centroid is left
			mav(0,-100);//turn left
			mav(3,100);
		}
		track_update();
	}
	ao();
	printf("Blob centered at 80\n");
	
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
}
