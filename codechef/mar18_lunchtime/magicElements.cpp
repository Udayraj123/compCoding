#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define vi vector<int> 
#define vii vector< vi > 
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*
Bruteforce: 
Ai + K > S - Ai
K > S - 2*Ai

*/
int main(int argc, char const *argv[])
{
	ll t=1,n,counter,S,k;
	cin>>t; 
	while(t--){
		cin>>n>>k;
		vi a(n,0);
		for (int i = 0; i < n; ++i){
			cin>>a[i];
		}
		S = std::accumulate(a.begin(), a.end(), 0);
		counter=0;
		for (int i = 0; i < n; ++i){
			if ( k > (S - 2*a[i])) {
				counter++;
			}
			else{
				// printf("A%d + K=%lld isn't greater than S-A%d=%lld\n",i+1,a[i]+k,i+1,S-a[i]);
			}
		}
		cout<<counter<<endl;

	}
	return 0;

}

