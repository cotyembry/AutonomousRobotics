//stop on specified color

int main() {
	int keepRunning = 1;

	while(keepRunning == 1) {
		if(analog10(3) > 400) {
			//color found
			keepRunning = 0;
		}
	}
}