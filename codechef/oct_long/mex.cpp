#include<bits/stdc++.h>
#define ll  int
#define MAX 100000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
run form 1 to 2*10^5
*/
int main(int argc, char const *argv[])
{
	ll t=100,t1,n=1,k=0,val,valMax,newMax,found_flag;
	ll countSort[2*MAX+1];
	cin>>t; 
	while(t--){
		memset(countSort,0,sizeof countSort);
		cin>>n>>k;
		valMax = 0;
		for (int i = 0; i < n; ++i)
		{
			cin>>val;
			countSort[val]++;
			valMax = max(valMax,val);
		}
		newMax = min(valMax+k+1,2*MAX);
		found_flag = 0;
		for (int i = 0; i <= newMax; ++i)
		{
			if(countSort[i]==0){
				if(k==0){
					cout<<i<<endl;
					found_flag = 1;
					break;
				}
				else k--;
			}
		}
		if(found_flag==0){
			cout<< (2*MAX) <<endl;
		}
	}
	return 0;
}

