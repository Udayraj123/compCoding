#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
const long long INF = 1e18 + 42;
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
Speedups to BF -
M1. Store product upto i of d[i]. Then check divisibilty from the end, and take that 
	as starting point. Still O(n^2)

M2. (After editorial) Demn, ((107/2)/3)/4) will be same as 107/(2*3*4), 
	because the fractional parts will never change the quotient!
-> This problem is more about overflow;
AND IF p overflows 10^9, the answer is surely 0 (as X[i] is limited).
*/

int main(int argc, char const *argv[])
{
	ll t=100,n=1,q,temp;
	ll d,p;
	cin>>t; 
	while(t--){
		cin>>n>>q;
		p=1;
		for (int i = 0; i < n; ++i){
			cin>>d;
			// can ignore to store if d==1
			if(d > INF/p)p=INF;
			else p *= d;
		}

		for (int i = 0; i < q; ++i){
			cin>>temp;
			cout<< (temp/p) <<" ";
		}
		cout<<endl;
	}
	return 0;

}

