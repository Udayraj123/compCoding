#include<bits/stdc++.h>
#define ll int
#define pp std::pair<ll, ll> 
#define MAX 100000
#define MOD 1000000007
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);printf("\n");}
using namespace std;

/*
KiM from now on again -
fn(int n,void *x)
int (*mark)[n] = static_cast< int(*)[n] > (x);

*/
ll getprod(ll s[],ll i,ll j,ll** prods){
	if(i==j)return s[j];
	if(prods[i][j]!=0)return prods[i][j];
	else prods[i][j]= s[i] * getprod(s,i+1,j,prods);
	return prods[i][j];
}
pp solve(ll j,ll s[],ll counts[],ll ans[],ll** prods,ll n){
	/*
	Calc suum L to R. Recursion for product part.
	*/
	ll sum=0,counter=0;
	if(n-j==0) return make_pair(1,0);
	if(n-j==1) return make_pair(1,s[j]);
	if(n-j==2) return make_pair(2,s[j]*s[j+1]+s[j]+s[j+1]);
	if(ans[j]!=0)return make_pair(counts[j],ans[j]);
	pp x = solve(j+1,s,counts,ans,prods,n);
	counter = x.first;
	sum = counter * s[j] + x.second; //sum part
	ll prod = s[j];
	pp inner;
	counter *= 2; //current counter from previous
	for (int i = 2; i < n-j+1; ++i)
	{
		prod =  getprod(s,j,j+i-1,prods);
		inner = solve(j+i,s,counts,ans,prods,n);
		sum = (sum + prod * inner.first + inner.second) % MOD ; //mult part
	}
	counts[j]=counter; ans[j]=sum;
	return make_pair(counter,sum);
}

int main(int argc, char const *argv[])
{
	ll t=1,n=2;
	cin>>t; 
	while(t--){
		cin>>n;
		ll s[n];
		ll counts[n];
		ll ans[n];
		memset(ans,0,sizeof ans);
		memset(counts,0,sizeof counts);
		int **prods = (int **)malloc(n * sizeof(int *));for (int i=0; i<n; i++) {prods[i] = (int *)malloc(n * sizeof(int)); 
		memset(prods[i],0,sizeof prods[i]);
		}
		for (int j = 0; j < n; ++j){
			cin>>s[j];
		}
		pp p = solve(0,s,counts,ans,prods,n);
		cout<<p.second<<endl;
	}

	return 0;//
}
