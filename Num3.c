#include <iostream>
#include <ctime>
using namespace std;

//functions declaration
void staticArray();
void onHeap(int n);
void onStack(int n);

int main(){
	//declare variables for start and end time
	unsigned int start ,stop;

	//record start time
	start = clock();
	//call method staticArray() 10000 times
	for(int i=0;i<10000;i++)
	staticArray();
	//record end time
	stop = clock();
	//print total time taken
	cout<<"Time taken by static method: "<<(stop - start)<<" ms"<<endl;
	  
	//record start time
	start = clock();
	//call method onStack() 10000 times
	for(int i=0;i<10000;i++)
	onStack(100000);
	//record end time
	stop = clock();
	//print total time taken
	cout<<"Time taken by onStack method: "<<(stop - start)<<" ms"<<endl;

	//record start time
	start = clock();
	//call method onHeap() 10000 times
	for(int i=0;i<10000;i++)
	onHeap(100000);
	//record end time
	stop = clock();
	//print total time taken
	cout<<"Time taken by onHeap method: "<<(stop - start)<<" ms"<<endl;

}

void staticArray(){
	//create static array of size 100000
	static int array[100000];
}

void onHeap(int n){
	//create dynamic array of size 100000
	int *array = new int[n];
}
void onStack(int n){
	//create local array of size 100000
	int array[n];
}
