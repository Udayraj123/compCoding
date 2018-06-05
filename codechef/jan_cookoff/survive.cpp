#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000001

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef DEBUG_RUN
	#define DEBUG_RUN_DEF true
#else
	#define DEBUG_RUN_DEF false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(DEBUG_RUN_DEF){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(DEBUG_RUN_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*



*/
bool surviveSunday(ll n, ll k){
	return (n*6 >= k*7);
}

ll ceilDiv(ll req, ll n){
	return req/n + (req%n ?1:0);
}

int main()
{
	ll t,n,k,s,flag,req;
	// if(!DEBUG_RUN_DEF) t = 1; else 
	cin>>t; 
	while(t--){
		cin>>n>>k>>s;
		req = k*s;
		cout<< (k > n ? -1 : ( k == n ? (s < 7 ? s : -1) : 
			 surviveSunday(n,k) ? ceil( (float)k*s/(float)n) : -1 )) <<endl;
		}
		return 0;

	}