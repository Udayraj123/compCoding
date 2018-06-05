#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
	#define ONLINE_JUDGE_DEF true
#else
	#define ONLINE_JUDGE_DEF false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
 Given K and numbers ai,
 Nope - output min number of ai required to reach K. (Can reuse the ais)
 - Choose 1 bucket that fills the whole K
*/

int main(int argc, char const *argv[])
{
	ll t=1,n,k,ans,temp;
	// cin>>t; 
	while(t--){
		cin>>n>>k;
		ans = k;// will get updated
		for (int i = 0; i < n; ++i){
			cin>>temp;
			if(k%temp==0){
				ans = min(ans,k/temp);
			}
		}
		cout << ans<<endl;

	}
	return 0;

}