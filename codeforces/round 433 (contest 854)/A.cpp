#include<bits/stdc++.h>
#define ll int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);cout<<"\n";}
using namespace std;

/*

try nby2/n-nby2, nby2-1/n-(nby2-1), ... , 1/n-1
common divisor => check div by prime factors of their difference?

*/
ll is_proper(ll a, ll b){
	if(a>=b)
		return 0;
	for (int fac = 2; fac <= sqrt(b); ++fac){
		if(b%fac==0 && a%fac==0)
			return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
ll t=1,n;
// cin>>t;
while(t--){
	cin>>n;
	for (int i = n/2; i > 0 ; --i) {
		if(is_proper(i,n-i)){
			cout<<i<<" "<<(n-i)<<endl;
			break;
		}
	}
}	

return 0;
}
