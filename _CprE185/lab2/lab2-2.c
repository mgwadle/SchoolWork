#include <stdio.h>
#include <math.h>

int main(){
	
	//a. int = 6427 + 1725
	printf("a. %d + %d = %d\n", 6427, 1725, 6427 + 1725);
	
	//b. int = (6971 * 3925) - 95
	printf("b. (%d * %d) - 95 = %d\n", 6971, 3925, ((6971 * 3925)-95));
	
	//c. double = 79 + 12/5
	printf("c. %lf + (%lf) = %lf\n", 79.0, (12.0/5.0), 79.0 + (12.0/5.0));
	
	//d. double = 3640.0/107.9
	printf("d. %lf / %lf = %lf\n", 3640.0, 107.9, 3640.0/107.9);
	
	//e. int = (22/3) * 3
	printf("e. (%d/%d)*%d = %d\n", 22, 3, 3, ((22/3) * 3));
	
	//f. int = 22 / (3 * 3)
	printf("f. %d / (%d * %d) = %d\n", 22, 3, 3, (22/(3 * 3)));
	
	//g. double = 22/(3*3)
	printf("g. %lf / (%lf * %lf) = %lf\n", 22.0, 3.0, 3.0, (22.0 / (3.0 * 3.0)));
	
	//h. double = 22/3*3
	printf("h. %lf / %lf * %lf = %lf\n", 22.0, 3.0, 3.0, 22.0 / 3.0 * 3.0);
	
	//i. double = (22.0/3) * 3.0
	printf("i. (%lf / %d) * %lf = %lf\n", 22.0, 3, 3.0, 22.0 / 3 * 3.0);
	
	//j. int - 22.0 / (3 * 3.0)
	printf("j. %lf / (%d * %lf) = %lf\n", 22.0, 3, 3.0, 22.0 / (3 * 3.0));
	
	//k. double = 22.0/3.0*3.0
	printf("k. %lf / %lf * %lf = %lf\n", 22.0, 3.0, 3.0, 22.0 / 3.0 * 3.0); 
	
	
	//l. Calculate the area of a circle with circumference 23.567
	
	double area, circumference;
	
	printf("Enter in a circumference: ");
	scanf("%lf", &circumference);
	
	area = ((pow(circumference, 2)) / (4 * M_PI));
	printf("The area of the circle with a circumference of %lf is %lf", circumference, area);
	
	
	//m. Convert 14 feet into meters.
	
	double feet, meters;
	
	printf("Enter length in feet: ");
	scanf("%lf", &feet);
	
	meters = feet * 0.3048;
	printf("%lf feet is equal to %lf meters.", feet, meters);
	
	
	//n. Covert 76 degress Farenheit to Centigrade.

	double degreeF, degreeC;
	
	printf("Enter degree in Fahrenheit: ");
	scanf("%lf", &degreeF);
	
	degreeC = ((degreeF - 32.0) / 1.8);
	printf("%lf Fahrenheit = %lf Centigrade", degreeF, degreeC);
	
	
	
}