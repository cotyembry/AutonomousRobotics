//Author:	John Coty Embry
//Date: 6/25/16
//Task 5
//proud moment: do something celebratory.

int main() {
	//do a donut 
	mrp(0, 500, 3000);

	msleep(4000);

	//do another the opposite way
	mrp(3, 500, 3000);

	msleep(4000);

	//move forward
	mrp(0, 500, 500);
	mrp(3, 500, 500);

	msleep(3000);

	//move backward
	mrp(0, 500, -500);
	mrp(3, 500, -500);

	msleep(3000);
}
