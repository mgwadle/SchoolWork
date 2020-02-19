/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
double mag(double ax, double ay, double az);
int minutes(int t);
int seconds(int t);
int millis(int t);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
		printf("Echoing output: %d, %lf, %lf, %lf\n", t, ax, ay, az);

// 	CODE SECTION 1 
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az));  
// 	CODE SECTION 2
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az)); 

	}

return 0;
}

/* Put your functions here */

double mag(double ax, double ay, double az){
	
	double total;
	
	total = sqrt(pow(ax, 2) + pow(ay, 2) + pow(az, 2));
	return total;
}

int minutes(int t){
	int time1;
	
	time1 = (t/60000);
	return time1;
}

int seconds(int t){
	int time2;
	
	time2 = ((t%60000)/1000);
	return time2;
}

int millis(int t){
	int time3;
	
	time3 = ((t%60000)%1000);
	return time3;
}