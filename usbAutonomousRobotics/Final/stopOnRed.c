//this doesnt work

int main() {
	int keepRunning = 1;
	int p5 = analog10(5);
	int p6 = analog10(6);
	while(keepRunning == 1) {
		if(p5 > 625 && p5 < 700) {
			keepRunning = 0;
			ao(); //stop since sensor sees red color
			printf("p5 seen it: stopping now\n");
		}
		if(p6 > 770 && p6 < 830) {
			ao();
			keepRunning = 0;
			printf("p6 seen it: stopping now\n");
		}
		if(keepRunning == 1) {
			mrp(0, 450, 25);
			mrp(3, 450, 25);
		}
	}
}