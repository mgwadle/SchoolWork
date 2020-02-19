#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main (void){


//instance variables

float mean;
float sd, sd1, sd2, sd3, sd4, sd5;
int range1 = 0;
int range2 = 0;

srand((int)time(0));

//Print 5 random numbers

//Below sets a random interger equal to varable name RandNum1, RandNum2, and so on.
//After receiving a random number randNum1 is set equal to randNum1%125 so that the range for the numbers is 0 and 125.

int randNum1 = rand();
randNum1 = randNum1%125;
int randNum2 = rand();
randNum2 = randNum2%125;
int randNum3 = rand();
randNum3 = randNum3%125;
int randNum4 = rand();
randNum4 = randNum4%125;
int randNum5 = rand();
randNum5 = randNum5%125;

//Following printf statements print the random numbers between 0 and 125

printf("Random Number 1 = %d\n", randNum1);
printf("Random Number 2 = %d\n", randNum2);
printf("Random Number 3 = %d\n", randNum3);
printf("Random Number 4 = %d\n", randNum4);
printf("Random Number 5 = %d\n", randNum5);



//mean of 5 numbers


//first variable mean is equal to all of the random numbers generated divided by the the total number of numbers.
mean = ((randNum1 + randNum2 + randNum3 + randNum4 + randNum5)/5);


//next is the Standard Deiviation.
//I used sd1, sd2, and so on to represent each randNum int the process

//Each value is equal to a randNum minus the mean squared

sd1 = (pow((randNum1 - mean),2));
sd2 = (pow((randNum2 - mean),2));
sd3 = (pow((randNum3 - mean),2));
sd4 = (pow((randNum4 - mean),2));
sd5 = (pow((randNum5 - mean),2));

//Standard Deviation of 5 numbers
//sd is equal to all of the above values added to gether and found the square root of the number.

sd = sqrt((sd1 + sd2 + sd3 + sd4 + sd5));

//printf statements print the results of the mean and Standard Deviation.

printf("\nMean of Random numbers = %fl\n", mean);
printf("Standard deviation = %lf\n", sd);





//Numbers between 0 and 90, then 91 to 125
//For each randNum i used an if else statement to check the numbers.
//If the number is greater or equal to that 0 but less than or equal to 90, then 1 is added to the instance variable range1
//If the statement is false then 1 is added to the instance variabe range2.
//Range1 is equal to the number of numbers between 0 and 90.
//Range2 is equal to the number of numbers between 91 and 125.


if(randNum1 >= 0 && randNum1 <= 90){
	range1 = range1 + 1;
}
else{
	range2 = range2 + 1;
}

if(randNum2 >= 0 && randNum2 <= 90){
	range1 = range1 + 1;
}
else{
	range2 = range2 + 1;
}

if(randNum3 >= 0 && randNum3 <= 90){
	range1 = range1 + 1;
}
else{
	range2 = range2 + 1;
}

if(randNum4 >= 0 && randNum4 <= 90){
	range1 = range1 + 1;
}
else{
	range2 = range2 + 1;
}

if(randNum5 >= 0 && randNum5 <= 90){
	range1 = range1 + 1;
}
else{
	range2 = range2 + 1;
}


//printf statements prints the values for range 1 and range 2 to show number of numbers in each range.

printf("\nRange[0, 90] = %d\n", range1);
printf("Range[91, 125] = %d\n", range2);
}