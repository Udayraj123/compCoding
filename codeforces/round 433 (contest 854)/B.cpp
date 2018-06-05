#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);cout<<"\n";}
using namespace std;

/*

maximize => trying for a gap of two or one atleast.
	1	2	3	4	5	6
	.	*	.	.	*	.  2,4
	*	*	.	.	*	.  3,3

test> N = 16.
	.	*	.	.	*	.	.	*	.	.	*	.	.	*	.	.  5,10
	.	*	.	.	*	.	.	*	.	.	*	.	.	*	.	*  6,10
	
test> N = 17.
	.	*	.	.	*	.	.	*	.	.	*	.	.	*	.	.	.  5,10
	.	*	.	.	*	.	.	*	.	.	*	.	.	*	.	.	*  6,11
	.	*	.	.	*	.	.	*	.	.	*	.	.	*	.	*	*  7,10
	
test> N = 20.
	.	*	.	.	*	.	.	*	.	.	*	.	.	*	.	.	*	.	.	*  7,13
	

=> 2k if k <= n/3, else 
no new ones can be generated, only excess existing can be reduced.

minimize => all contigous and towards an end
	1	2	3	4	5	6
	.	.	.	* 	*	*
=> 1 if k != n else 0

*/
ll calcmax(ll n,ll k){
	ll ideal= n/3;
	ll excess = k - ideal;
	ll answer = 2*k;
	if(excess>0){
		ll to_dcr = max((ll)0,excess - n%3); 
		ll oneextra = (n%3==2 && excess == 1);
		answer = 2*ideal - to_dcr + oneextra;
	}
	return answer;
}

int main(int argc, char const *argv[])
{
ll t=1,n,k;
// cin>>t;
while(t--){
	cin>>n>>k;
	cout<<(k!=n && k!=0)<<" "<< calcmax(n,k)  <<endl;
}	

return 0;
}
