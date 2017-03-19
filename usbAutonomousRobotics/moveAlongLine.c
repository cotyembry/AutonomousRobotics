int main() {
	int ticksInc = 25;
	int keepRunning = 1;

	int printf1Helper = 0;
	int printf2Helper = 0;

	while(keepRunning == 1) {
		int p5result = analog10(5); // do this to printf the current value out later
		if(p5result > 610 && p5result < 790) { //630 - 690
			//turn left
			while(analog10(5) > 610 && analog10(5) < 790) {
				mrp(3, 450, ticksInc);
				// msleep(500);
				bmd(0);
				bmd(3);
			}
			//printf("port 5 found line, %d\n", analog10(5));

			printf1Helper = 1;
		}

		int p6result = analog10(6);
		if(p6result > 730 && p6result < 890) { //750 - 850
			//turn right
			while(analog10(6) > 730 && analog10(6) < 890) {
				mrp(0, 450, ticksInc);
				// msleep(500);
				bmd(0);
				bmd(3);
			}
			//printf("port 6 found line, %d\n", analog10(6));

			printf2Helper = 1;
		}

		//now for the printf statement helper code to print the code/results out neatly
		if(printf1Helper == 1 && printf2Helper == 1) {
			printf("both p5 & p6 found line, p5: %d, p6: %d\n", p5result, p6result);
		}
		else if(printf1Helper == 1) {
			printf("p5 found line: %d\n", p6result);
		} 
		else if(printf2Helper == 1){
			printf("p6 found line: %d\n", p6result);
		}

		mrp(0, 450, ticksInc);
		mrp(3, 450, ticksInc);

		printf1Helper = 0; //re-init variables to be used during the next iteration through the loop
		printf2Helper = 0;

		// msleep(500);
		bmd(0);
		bmd(3);
	}
}