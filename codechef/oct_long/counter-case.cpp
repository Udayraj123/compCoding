#include<bits/stdc++.h>
#define ll long long int
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
#define MODULO (1ULL<<32) // 2^32 
#define MAX_N 100000 // 10^5
#define MOD_BY_MAX_N (MODULO/MAX_N)
#define FOR(x,n) for(int x = 0; x < n; ++x)

/*



A counter case having ~10^5 numbers so that index of their minimum is not the index of min of modulo of (their modulo sum + ith num)

ad-hoc

here MODULO = 2^32 = ~4.29 * 10^9

=> Make a set of n numbers having sum = 2^32 - 2
=> min index is of '1', while the modulo min index is of '2'
=> (2^32)/(10^5)  = 42949 numbers will be 10^5,remaining N-42949 ( range : 57042-57051) should sum up to 67296-2 
	=> 42949 numbers will be 10^5, N-42949-2 numbers are 1, 1 is 67296-(N-42949) -2, the last is 2
check : above sum is 42949 * 10^5 + -2 + 67296 - 2 + 2 = 67296 - 2 = 2^32 - 2


*/
int main(int argc, char const *argv[])
{
	ll t=1,t1,n=MAX_N,hp=0,p=0,countn=0,negs;
	cin>>t; 
	while(t--){
		cin>>n;
		// MOD = 42949 67296
		// MAX = 100000

		// MOD_BY_MAX_N = 42949
		FOR(i, MOD_BY_MAX_N ){
			cout<<(MAX_N)<<" ";
		}
		// UNTIL NOW SUM = 4294900000

		FOR(i, n - MOD_BY_MAX_N - 2){
			cout<<(1)<<" ";
		}
		cout << (( MODULO%MAX_N ) - (n-MOD_BY_MAX_N) -2 )<< " ";
		cout << 2 <<endl;


	}
	return 0;
}

