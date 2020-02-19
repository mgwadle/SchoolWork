#include <stdio.h>

//function prototypes

int read_arr(int a[10]);
void print_arr(int a[10]);
void replace_arr(int a[10]);
void swap_arr(int a[10]);

//main function

int main(void){
	int b[10];  //declare an int array that can hold 10 numbers
	read_arr(b);  //called the read_arr function to read numbers into array
	print_arr(b);  //called print_arr function to print values entered into array
	
	replace_arr(b);  //called replace_arr function to replace odd indices
	print_arr(b);  //prints fixed array
	
	swap_arr(b);  //called swap_function to swap values in array
	print_arr(b);  //prints fixed array
}

//int function named read_arr that takes an int array with a size of 10 as the parameter

int read_arr(int a[10]){
	int i;
	
	//printf asks user to enter numbers
	
	printf("Please enter 10 numbers: \n");
	
	//for loop reads values from the user and puts them into the array
	
	for(i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
}

//void function named print_arr that takes an int array with a size of 10 as the parameter

void print_arr(int a[10]){
	int i;
	
	//for loop goes through and prints out every index of the array
	
	for(i = 0; i < 10; i++){
		printf("\n%d", a[i]);
	}
}

//void function named replace_arr that takes an int array with a size of 10 as the parameter

void replace_arr(int a[10]){
	int i = 0;
	
	//while loop says that while the int i is less than 10 then it sould continue to perform tasks inside loop
	
	while(i < 10){
		
		//if statement says that is the remainer of i divided by 2 is equal to 0 then the value at that index in the array should be 0.
		
		if(i % 2 == 0){
			a[i] = 0;
		}
		
		//increases the value of i in while loop
		
		i++;
	}
}

//void function named swap_arr that takes an int array with a size of 10 as the parameter

void swap_arr(int a[10]){
	int i;
	
	//for loop takes index locations and swaps consecutive numbers
	// index 1 and 2 switch, 3 and 4 switch, so on and so forth...
	
	for(i = 0; i < 10; i += 2){
		int c = a[i];
		int d = a[i + 1];
		
		a[i] = d;
		a[i + 1] = c;
	}
}