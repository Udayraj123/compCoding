#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;

/*

*/
bool isLinCombination(ll n,ll a, ll b){
	// O(n) time - coz divisibility takes constant time
	if(n<0)return false;
	// if div by any one, return true
	if (n % a == 0 || n % b == 0)return true;

	else return isLinCombination(n-a,a,b) || isLinCombination(n-b,a,b);
}

int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false); // this just makes cin/cout as fast as scanf/printf
	// cin.tie(NULL); // simply guarantees the flushing of std::cout before std::cin accepts an input
	ll t,n;
	cin>>t;
	while(t--){
		cin>>n;
		cout<< (isLinCombination(n,3,7)?"YES":"NO")<<endl;
	}
	return 0;
}

