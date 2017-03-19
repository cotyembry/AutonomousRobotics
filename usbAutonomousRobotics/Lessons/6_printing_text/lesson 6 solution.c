int main() 
{
	//step 1
	//print a haiku describing the sensor used in step 2
	printf("This here example\n");//5 syllables
	printf("One more clever solution\n");//7
	printf("Written by Haiku\n");//5
	
	//step 2 / 3
	//print the value of a sensor every .1 seconds
	//quit when the black button is pressed
	while(!black_button()){//same as black_button()==0
		printf("The ____ sensor reads:\t%d\n",analog(1));
		sleep(.1);
	}
}
