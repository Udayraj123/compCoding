#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define MOD 1000000007
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
A = 1,2,3
B = 2,4,8
C = 1,6,21
sum of (Y>=X && Y>=Z)?(X+Y)*(Z+Y):0 where X from A,etc
	for each Y, find candidate set X,Z using sort/partition according to elements of B
		sum+= sum(XZ) + sum(X+Z )*Y + Y^2*p
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
ll add(ll a,ll b){
	return (a+b)%MOD;
}
ll mult(ll a,ll b){
	return (a*b)%MOD;
}
ll solve(ll x[],ll Y[],ll z[],ll p,ll q,ll r){
	ll ans=0,sumX,sumZ;
	ll sumXupto[p];
	ll sumZupto[r];
	memset(sumXupto,-1,sizeof sumXupto);
	memset(sumZupto,-1,sizeof sumZupto);
	ll ptX=0,ptZ=0,p_,r_;
	//we get sorted arrays here. 
	for (int i = 0; i < q; ++i)
	{
	//get candidates
		while(ptX< p && x[ptX] <= Y[i])ptX++;
		while(ptZ< r && z[ptZ] <= Y[i])ptZ++;
		// But if ptX and ptZ reached end with numbers bigger than Y, then don't sum up.
		if(ptX*ptZ==0)continue;//spl cases
		if(x[ptX-1]>Y[i] || z[ptZ-1]>Y[i])continue;//spl cases
		sumX = sum(x,ptX-1,sumXupto);
		sumZ = sum(z,ptZ-1,sumZupto);

			// ans += (sumX*sumZ) + Y[i] * (sumX*r + sumZ*p) + (p*r)*Y[i]*Y[i];
		p_=min(ptX,p);
		r_=min(ptZ,r);
		ans += (add( mult(sumX,sumZ), mult(Y[i], add(mult(sumX,r_),mult(sumZ,p_)))) + mult(mult(p_,r_),mult(Y[i],Y[i])))%MOD;
	}
	return ans;
}

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

