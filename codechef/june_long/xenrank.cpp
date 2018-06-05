#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*

The ranks are simply along the diagonal.
So U,V will always have the max rank
Rank of U,V will be p*(p+1)+U+1, where p = U+V

*/
int main(int argc, char const *argv[])
{
	ll t=100,u=1,v=1,p = 1;
	cin>>t; 
	while(t--){
		cin>>u>>v;
		p=u+v;
		cout<< (p*(p+1)/2 + u + 1)<<endl;

	}
	return 0;
}

