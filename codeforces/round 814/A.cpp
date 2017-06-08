#include<bits/stdc++.h>
#define ll int
#define MAX 100000
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
ll satisfy(ll ans,ll counter,ll LT,ll GT,ll k1,std::vector<int> k){
	ll satisfied= 0;
	if(ans >= k1)return 0;
	//k is increasingly sorted.
	// return 1 if fits in perfectly.
	// 'ans' is start index
	ll ct=0,condition;
	for (int i = ans; i < k1; ++i){
		condition = (k[i]>GT && k[i]<LT);

		if (condition && ct<=counter){
			ct++;
		}
		else if (!condition && ct==counter){
			return i;//scanned one more.
		}
		else return 0;
		satisfied=i+1;
	}
	return satisfied;
}


void solve(ll n1, std::vector<ll> n,ll k1,std::vector<ll> k){
	// n is increasing if removed the zeros.
	ll ans = 0,counter=0,reset=0;
	ll zs=0,ze=1;
	ll GT=0,LT=MAX;
	for (int i = 0; i < n1; ++i)
	{
		if(n[i]==0)counter++;
		else reset=1;
		if(counter>1){
			// cause even if they fit, they can be rearranged.
			cout<<"Yes"<<endl;
			return;
		}
		if(!zs && n[i]==0){ //zeros started
			zs=1;
			if(i>0)GT=n[i-1];
			else GT=0;
		}
		else if(zs){
			if( n[i]!=0){//zeros ended
				zs=0;
				LT=n[i];
				ans= satisfy(ans,counter,LT,GT,k1,k);
				if(ans==0)break;
			}
			else if(i==n1-1){//zeros till the end
				zs=0;
				LT=MAX;
				ans= satisfy(ans,counter,LT,GT,k1,k);
				if(ans==0)break;
			}
		}


		if(reset){
			counter=0;
			reset=0;
		}
	}

	cout<<(ans==0?"Yes":"No")<<endl;
}
/*

M1- accumulate the constraints - GT x or LT x
	sort k.
	if n already not increasing, output yes
	10 ... 20 34 . 36
	If any one fails, break & report,
	>> SO : for each stream of zeros (length>=1), scan thru sorted k optimally for satisfying numbers.
			fail case will also include overfilling of the numbers.



*/
int main(int argc, char const *argv[])
{
	ll n1=2,k1=2,t_prev=0,t=0,inc=1;
	cin>>n1>>k1;
	std::vector<ll> n; std::vector<ll> k;
	for (int i = 0; i < n1; ++i){
		cin>>t; n.push_back(t); 
		if(t!= 0){
			if(t < t_prev){
				inc=0; 
			}
			t_prev=t;
		}
		if(i && n[i]==0 && n[i-1]==0){
			inc =0;
		}
	}
	for (int j = 0; j < k1; ++j){
		cin>>t; k.push_back(t); 
	}
	if(inc == 0 ){
		cout<<"Yes"<<endl;
		return 0;
	}
	else{
		sort(k.begin(),k.end());
		solve(n1,n,k1,k);
	}
	return 0;
}
