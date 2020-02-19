/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
int total(int a, int b, int c, int d, int e);

int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;	


	while (TRUE) {
		scanf("%d, %d, %d, %d, %d, %d", &a, &b, &c, &d, &e);
		
		printf("Number of buttons pressed: %d\n", total(a, b, c, d, e));
	}

return 0;
}

/* Put your functions here */

int total(int a, int b, int c, int d, int e){
	int max = 0;
	
	max = (a + b + c + d + e);
	
	return max;
}