#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

ll solve(int n,ll A[]){

	ll colorSum[n][n]; 
	ll cost[n][n]; 

	for (int i = 0; i < n; ++i) {
		// Fill the upper triangle only i<j
		colorSum[i][i]=A[i];
		cost[i][i]=0;
		for (int j = i+1; j < n; ++j) {
			colorSum[i][j] = (colorSum[i][j-1]+A[j]) % 100;
		}
	}
	ll minVal;
	ll temp;

// Go like in a pyramid -
	for (int h = 2; h <= n; ++h) { //Height Should not start from 1 (think!)
		for (int i = 0; i < n-h+1; ++i) {
			int j= i+h-1;//01 12
			cost[i][j]=MAX;
			for (int k = i; k < j; ++k) {
				temp = colorSum[i][k] * colorSum[k+1][j] + cost[i][k] + cost[k+1][j];
				if(temp<cost[i][j])
					cost[i][j]=temp;
			}
		}
	}

	return cost[0][n-1];
}

int main(int argc, char const *argv[])
{
	int n;
	while( cin>>n ){
		ll A[n];
		for (int i = 0; i < n; ++i)
			cin>>A[i];		

		printf("%llu\n", solve(n,A));
	}
	return 0;
}
