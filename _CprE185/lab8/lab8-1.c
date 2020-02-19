#include <stdio.h>
#include <math.h>

double mag(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);
double x1(double g, double t);

const double g = 9.8; // m/sec^2

int main(void){
	int t, i;
	double g, ax, ay, az;
	char period = '.';
	char ex = '!';
	
	printf("Ok, I'm now receiving data\n\n");
	printf("I'm waiting");
	
	scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az); 
	
	while(close_to(0.2, 1, mag(ax, ay, az)) == 1){
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az); 
		i++;
		if(i%10 == 0){
			printf("%c", period);
			fflush(stdout);
		}
	}
	
	int tStart = t;
	
	printf("\n\nHelp me! I'm falling");
	
	while(close_to(0.2, 1, mag(ax, ay, az)) != 1){
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
		i++;
		if(i%10 == 0){
			printf("%c", ex);
			fflush(stdout);
		}
	}
	
	printf("\nOuch! I fell %lf meters in %lf seconds\n", (((t - tStart)/1000.0) * ((t - tStart)/1000.0) * 9.81 * 0.5), (t - tStart)/1000.0);
	
	return 0;
}

double x1(double g, double t){
	double total = g * t * t * 0.5;
	return total;
}

double mag( double ax, double ay, double az){
	double mag = sqrt(pow(ax, 2) + pow(ay, 2) + pow(az, 2));
	return mag;
}

int close_to(double tolerance, double point, double value){
	double upTolerance;
	double downTolerance;
	
	upTolerance = point + tolerance;
	downTolerance = point - tolerance;
	
	if(value < upTolerance && value > downTolerance){
		return 1;
	}
	return 0;
}