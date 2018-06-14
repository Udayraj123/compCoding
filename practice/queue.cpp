#include<iostream>
//#include<stdlib.h> //for malloc
using namespace std;

void swap(int*a,int*b){
	int t=*b;
	*b=*a;
	*a=t;
}

/*
using LL
-> is a list with front and rear pointers (no intermediate insertion).
-> empty when rear=front==NULL
-> full when rear=capacity

using Array
-> circular queue

constructor
isFull/isEmpty
enQueue/deQueue

    struct QNode *front, *rear;
*/

int main(int argc, char const *argv[]){
	int a[]={51,12,12141,12,4,3,0};
	// selection_sort(a,sizeof(a)/4);
	for (int i = 0; i < sizeof(a)/4; ++i){
		q.add(a[i]);
	}
	return 0;
}