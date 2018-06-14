#include<iostream>
//#include<stdlib.h> //for malloc
using namespace std;

void swap(int*a,int*b){
	int t=*b;
	*b=*a;
	*a=t;
}

void insertion_sort(int a[],int n){
// make empty array, insert elements into it one by one at correct positions
//.. 
}
void selection_sort(int a[],int n){
	//swap with min, continue on rest
	int t,t_j;
	for (int i = 0; i < n-1; ++i){
		t=a[i];t_j=i;
		for (int j = i+1; j < n; ++j){
			if(t > a[j]){
				t=a[j];t_j=j;
			}
		}
		swap(&a[i],&a[t_j]);
	}
}
void bubble_sort(int a[],int n){
	// swap neighbors
	for (int i = 0; i < n-1; ++i){
		for (int j = 0; j < n-1-i; ++j){
			if(a[j] > a[j+1])
				swap(&a[j],&a[j+1]);
		}
	}
}

void merge(int a[],int s,int e,int m){
	int n1 = m-s+1,n2=e-m;
//copy into
	int L[n1],R[n2];
	for (int i = 0; i < n1; ++i)L[i]=a[s+i];//
	for (int i = 0; i < n2; ++i)R[i]=a[m+1+i];//

		int i=0,j=0,k=s;
//merge
	while(i<n1 && j<n2){
		if(L[i]<R[j])
			a[k++]=L[i++];
		else
			a[k++]=R[j++];
	}
	while(i<n1)a[k++]=L[i++];
	while(j<n2)a[k++]=R[j++];

}

void merge_sort(int a[],int s,int e){
	if(s>=e)return;
// recurse acc to key
	int m = s+(e-s)/2;// e-s > 1 guaranteed here		
	merge_sort(a,s,m);
	merge_sort(a,m+1,e);
	merge(a,s,e,m);
}

void quick_sort(){
//TODO: partitioning--

}

int main(int argc, char const *argv[]){
	int a[]={51,12,12141,12,4,3,0};
	// selection_sort(a,sizeof(a)/4);
	merge_sort(a,0,sizeof(a)/4 -1);
	for (int i = 0; i < sizeof(a)/4; ++i){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}