#include <stdio.h>
#include <ctime>

void staticArray();
void heapArray();
void stackArray();

int main(){
	
	int startClock=0; //records time of when for loops beggin
	int endClock=0; //records time of when for loops ends

	
	startClock = clock(); //record time before for loop begins
	for(int i=0;i<200000;i++){ //for loop calls staticArray 200000 times
		staticArray();
	}
	endClock = clock(); //record time after for loop ends
	printf("Completion time for static array: %d ms\n",endClock-startClock); //print message with time result
	startClock = clock(); //record time before for loop begins
	//call method onStack() 10000 times
	for(int i=0;i<200000;i++){ //for loop calls stackArray 200000 times
		stackArray();
	}
	endClock = clock(); //record time after for loop ends
	printf("Completion time for stack array: %d ms\n",endClock-startClock); //print message with time result

	startClock = clock(); //record time before for loop begins
	for(int i=0;i<200000;i++){ //for loop calls heapArray 200000 times
		heapArray();
	}
	endClock = clock(); //record time after for loop ends
	printf("Completion time for heap array: %d ms\n",endClock-startClock); //print message with time result

}

void staticArray(){
	static int array[200000]; //initialize static int array with size 200000
}


void stackArray(){
	int array[200000]; //initialize stack int array with size 200000
}

void heapArray(){
	int *array = new int[200000]; //initialize heap int array with size 200000
}







