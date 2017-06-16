#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*
TODO problem
*/

int main(int argc, char const *argv[])
{
	int t=100,n=1,lastCount = 1;
	cin>>t; 
	int mark[1000];
	while(t--){
		memset(mark,0,sizeof mark);
		// between 1 and 500.
		// n <= 100
		cin>>n;
		ll nums[n];
		nums[0]=1;
		mark[1]=1;
		lastCount=1;
		for (int j = 1; j < n; ++j){
			for (int i = lastCount; i < 501; ++i){
				if(mark[i]==0){
					lastCount=i;
					mark[i]=1;
					nums[j]=i;
					break;
				}
			}
			// mark the new num sums
			for (int t = 0; t < j; ++t){
				mark[nums[j]+nums[t]]=1;
			}
		}
		printla(nums,n)
	}
	return 0;
}

