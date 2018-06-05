#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
all next numbers be within bound_up & bound_down.
*/
int main(int argc, char const *argv[])
{
	ll t=1,n,r,temp,bound_down,bound_up,flag;
	cin>>t; 
	while(t--){
		/*
5 890
5123 3300 783 1111 890
		*/
		cin>>n>>r;
		bound_up = MAX; bound_down = 0; flag = 1;
		for (int i = 0; i < n-1; ++i) {
			cin>>temp;
			if(bound_up<temp || bound_down > temp){
				// cout << bound_up<< " " << bound_down<< " " << temp<< " " ;
				// cout<<i<<endl;
				flag=0;
				// break;
			}
			if( temp < r ) 
				bound_down = max(temp,bound_down);
			if( temp > r ) 
				bound_up = min(temp,bound_up);
		}
		cin>>temp;
		cout<< (flag?"YES":"NO")<<endl;
	}
	return 0;
}

