#include<bits/stdc++.h>
#define ll int
#define pp std::pair<ll, ll> 
#define MAX 100000
#define MOD 1000000007
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);cout<<"\n";}
using namespace std;

/*
mex = minimum value of the complement set. 
Minimum EXcluded Val
>> m1 :
	sort and permute by size
*/
ll getpow(ll x,ll p){
	ll ans = 1;
	for (int i = 0; i <p ; ++i)
	{
		ans = (ans*x) %MOD;
	}
	return ans;
}
ll solve(vector<int> s,ll k, ll n){
	sort(s.begin(), s.end());
	ll k_pos=n-1;
	for (int i = 0; i < n; ++i)
	{
		if (s[i] >= k)
		{
			k_pos=i;
			break;
		}
	}
	ll c=k_pos+1;
	return (getpow(2,n-k_pos-1))*((getpow(2,k_pos+1)-1))%MOD;
}

int main(int argc, char const *argv[])
{
	ll t=1,n=2,k,t1;
	// cin>>t; 
	while(t--){
		cin>>n>>k;
		vector <int> s; 
		for (int j = 0; j < n; ++j){
			cin>>t1;s.push_back(t1);
		}
		cout<<solve(s,k,n)<<endl;
	}

	return 0;//
}
