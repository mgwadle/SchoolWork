/* Lab 5 Skeleton Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1


int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	
	double data1, data2, data3, data4;
	int t, millis, minutes, second;
	double seconds, average;
	double  ax, ay, az; 
	double accl;

	//Your other variable declarations below
	
	

	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
// modify the printf below for appropriate formatted output

seconds = (t*0.001);

		printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", seconds, ax, ay, az);

/* 	CODE SECTION 1 
*/

accl = sqrt((pow(ax,2))+(pow(ay,2))+(pow(az,2)));

// declare appropriate variable type for accl
//write an expression to compute accl, see Lab handout


		printf("At %d ms, the acceleration's magnitude was: %lf\n", t, accl);  
			
/* 	CODE SECTION 2 */
// Convert the time expressed in milliseconds in variable t into
// three parts - minutes, seconds and milliseconds
// declare appropriate variables for each of the three parts - minutes, seconds, millis

minutes = (t/60000);
second = ((t%60000)/1000);
millis = ((t%60000)%1000);
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes, second , millis, accl); 
		
		
		
		data4 = data3;
		data3 = data2;
		data2 = data1;
		
		data1 = accl;
		average = ((data1 + data2 + data3 + data4)/4.0);
		
		printf("%lf\n", average);
		
		if(average < 1.0 && average > 0.9){
			printf("CONSTANT ACCLN\n");
		}
		else if(average > 1.0){
			printf("SPEEDING UP\n");
		}
		else if(average < 0.9){
			printf("SLOWING DOWN\n");
		}

	}

return 0;
}


