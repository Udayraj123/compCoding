#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;


// #include <sstream>
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

/*
Given the array,
sub-array A[i,j] s.t. i=0 always,
need - XoR of first k elements
-> XoR is commutative = DP - Nope, coz K can vary upto a million
Note1 : XoR 0 terms will add to remaining terms

Lets write bruteforce and get a feel.
each output will take O(n) time

If we keep 0-XoR ranges, O(n) storage, it can help a bit
** XOR patterns KiM 

constraints say 2D NxN array will cost 10^10 space.


CURRENT STATUS - Getting WA for higher numbers?!

*/

void updateXorArr(ll xorTill[],ll a[],ll zeroXorIndices[],ll minIndex,ll n){
	
	for (int i = minIndex-1; i < n; ++i)
			if(i>0){
				xorTill[i]=a[i]^xorTill[i-1];
				zeroXorIndices[i] = xorTill[i]==0?1:0;
			}
}
int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false); // this just makes cin/cout as fast as scanf/printf
	// cin.tie(NULL); // simply guarantees the flushing of std::cout before std::cin accepts an input
	ll t,n,q,a1,a2,ans;
	cin>>n>>q;

	ll a[n], xorTill[n];
	ll zeroXorIndices[n];
	ll store2D[n][n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
		zeroXorIndices[i] = 0;
	}

	xorTill[0]=a[0];
	updateXorArr(xorTill,a,zeroXorIndices,2,n);

	ll minIndex = n,toUpdate=0;
	for (int i = 0; i < q; ++i) {
		cin>>t>>a1>>a2;// a1 is 1-indexed
		if(t==1){
			a[a1-1]=a2;
			toUpdate = 1;
			minIndex = min(minIndex,a1);
		}
		else{
			if(toUpdate){
				//lazy Update
				toUpdate=0;	
				updateXorArr(xorTill,a,zeroXorIndices,minIndex,n);
			}
			ans = 0;
			for (int i = 0; i < n; ++i)
				if(xorTill[i]==a2)ans++;//a2 is k here
			cout<<ans<<endl;
		}
	}
	return 0;
}

