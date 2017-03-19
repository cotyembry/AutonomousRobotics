#include <stdio.h>

int main() {
	
	/*
	tone(800, 500);
	tone(800, 500);
	tone(800, 500);
	tone(755, 500);
	tone(800, 500);
	tone(960, 500);
	*/
	/*
	800, 800, 800, 755, 800, 960
	*/

	//explain this code before running it
	/*
	//move along black line
	while(analog10(1) < 900){ //turns left until the right
		mav(3,200);	//sensor sees the black line
	}
	//follow the line
	while(analog10(0) > 900 || analog10(1) > 900) {
		if(analog10(0) < 900 && analog10(1) > 900) { //left sees white
			mav(0,300); //turn right
			mav(3,200);
		}
		else if(analog10(0) > 900 && analog10(1) < 900) {
			mav(0,200);         //^^^right sees white //turn left
			mav(3,300);
		}
		else {//both see the black line
			mav(0,300);
			mav(3,300);
		}
	}
	*/
	
	return 0;
}
