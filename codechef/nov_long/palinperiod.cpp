#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*

r = N/P
if r==1 || r==n -> aaaaaa...
else n > r > 1 -> 


*/



int main(int argc, char const *argv[])
{
	ll t=1,n,r,p,temp,flag;
	cin>>t; 
	while(t--){
		cin>>n>>p;
		if(p<3)cout<<"impossible\n";
		else{
			for (int k = 0; k < n/p; ++k)
			{
				if(p%2){
				for (int i = 0; i < p/2; ++i) cout<<"a";
					cout<<"b";
				for (int i = 0; i < p/2; ++i) cout<<"a";
					
				}
				else{
					for (int i = 0; i < p/2-1; ++i) cout<<"a";
					cout<<"bb";
					for (int i = 0; i < p/2-1; ++i) cout<<"a";
				}
			}
			cout<<endl;
			}
	}
	return 0;
}

