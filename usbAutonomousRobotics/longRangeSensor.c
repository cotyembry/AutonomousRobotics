// Created on Wed Jun 22 2016

#include <stdio.h>

int main() {
	set_each_analog_state(1,0,0,0,0,0,0,0);
	sleep(0.02);
	
	while(1 == 1) {
		if(analog10(0) > 512) {
			printf("getting closer\n");
		}
		if(analog10(0) <= 512) {
			printf("getting further away\n");
		}
	}
	
	
	
	return 0;
}
