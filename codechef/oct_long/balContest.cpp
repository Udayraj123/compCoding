#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*
Bruteforce
*/
int main(int argc, char const *argv[])
{
	ll t=100,t1,n=1,p=0,easy,hard,val;
	cin>>t; 
	while(t--){
		cin>>n>>p;
		easy = 1;
		hard = 2;
		for (int i = 0; i < n; ++i)
		{
			cin>>val;
			if(val >= p/2)easy--;
			if(val <= p/10)hard--;
		}
		if(easy == hard and easy == 0)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}

