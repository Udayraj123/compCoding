#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define MOD 1000000007
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
Sum of log_i(A[j])
where X<=i<=Y && i is Prime,L<=j<=R
*/
void swap(ll* a,ll* b){
	ll t = *b;
	*b = *a;
	*a = t;
}
ll sum(ll a[],ll j,ll dp[]){
	if(j==0)
		return a[j];
	if(dp[j]== -1)
		dp[j] = a[j]+sum(a,j-1,dp);
	return dp[j];
}
ll add(ll a,ll b)


int main(int argc, char const *argv[])
{
	ll t=100,n=1,p,q,r;
	cin>>t; 
	int mark[1000];
	while(t--){
		cin>>p>>q>>r;
		ll a[p]; ll b[q]; ll c[r];
		for (int j = 0; j < p; ++j)
			cin>>a[j];
		for (int j = 0; j < q; ++j)
			cin>>b[j];
		for (int j = 0; j < r; ++j)
			cin>>c[j];

		sort(a,a+p);
		sort(b,b+q);
		sort(c,c+r);
		cout<<solve(c,b,a,r,q,p)<<endl;
	}
	return 0;
}

