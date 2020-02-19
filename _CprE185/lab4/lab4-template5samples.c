#include <stdio.h>

//declare the number of samples (N = 5) below
//use const or #define

#define N  9

int main(void)

{
	
	//Your variable declarations below
	
	//1. Variables to store N = 5 samples
	//declare sample0, sample1, ..., sample4 below
	
	int i;
	int n = 1;
	double sum = 0;
	double balance[N]={0};
	//2. declare variable to compute the average of N samples
	
	double avg = 0;
	
	//Any other variable declarations needed by you
	//should be below
	
	
	

/******  DO NOT MODIFY BELOW LINES ********/	

   //Current time read from input file
   float curTime = 0.0;
   //current sound sample read from input file
   float curSample = 0.0;
   
	//buffer size for fgets
  const int MAX_STR_SIZE = 100; // DO NOT CHANGE THIS LINE	
  char metadata[MAX_STR_SIZE];  // DO NOT CHANGE THIS LINE

    // Scan in and print out metadata lines to the output file
    fgets(metadata, MAX_STR_SIZE, stdin);
    printf("%s",metadata);
    fgets(metadata, MAX_STR_SIZE, stdin);
    printf("%s",metadata);  
/*****************************************/
	
	// While we have more lines remaining in the input sound sample file
	// feof - test for end of file, until no more samples to read
    while (!feof(stdin)) { // use this while loop to read each line of the .dat file
		
		 //Your code to update sampleX variables
		 //Move the contents of sample3 to sample 4 and so on
		 //Move the current sample to variable sample0
		
		
		
		for(i = N; i > 1; i -= 1){
			balance[0] = curSample;
			balance[i - 1] = balance[i - 2];
			
		}
		scanf("%f %f", &curTime, &curSample);

		
		if(n >= N){
			
		//avg = (balance[0] + balance[1] + balance[2] + balance[3] + balance[4])/5;	
		
		for(i = 0; i < N; i += 1){
			sum += balance[i];
		}
		avg = sum/N;
		
		//Read the current time and the current sound sample during each 
		//iteration through the while loop
		//In every iteration, you will get one sample and the associated time
    
		
		//Your logic to compute the average of the 5 samples and print
		//to output file 
		
		
            // Print out the average to output file
            printf("%0.10f %0.10f\n", curTime, avg);
   
		}
		n += 1;
		
		
	}
	
	
	
}