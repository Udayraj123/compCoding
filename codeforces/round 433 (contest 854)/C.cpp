#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);printf("\n");}
using namespace std;

/*
Need permutation A of the numbers k+1 to n + k
such that the sum (Ci*(Ai-i)) is minimized

Greedy?
- Why not -> set zero delay for highest weight

*/


ll calcmax(ll n,ll k){
	ll sepa= n/3;
	ll rem_sepa = n%3;;
	ll oneextra = ( (k - sepa) == 1  && (rem_sepa == 2) );// one extra
	if( k <= sepa ) return (2*k);
	else
		return (2*sepa + oneextra - max((ll)0,k - sepa - rem_sepa) );
	
}

int main(int argc, char const *argv[])
{
ll t=1,n,k;
// cin>>t;
while(t--){
	cin>>n>>k;
	cout<<(k!=n)<<" "<< calcmax(n,k)  <<endl;
}	

return 0;
}
