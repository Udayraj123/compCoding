#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<ll> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#include "../../getTime.h"
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif

#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}

#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*
powers of 2 till 10^9 = log(10^9) ~= 30

set of powers whose sum is also a power = itself only _/
1,1 = 2 
2,2 = 4
4,4 = 8 and so on.

Given input numbers are distinct
^so answer is max 3, least 1
## IN PROGRESS
-> make NxN gaps matrix. for each row, check for 2^k number, if found check for 2^k in that numbers row and so on.
==> make edges between the indices if their diff is 2^k & find longest SCC

*/
#define	MAX_Ai 1000

int main(){
	// http://codeforces.com/blog/entry/5217

	// Speeds up cin/cout- But now you can't mix printf and cout coz their order of flushing is changed.
	ios_base::sync_with_stdio(0);
	// Second optimisation: Effective when large no of inputs (when cin gets used too much)
	cin.tie(NULL);
	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif

	ll t;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	ll n,k,temp,sum,flag;
	while(t--){
		cin>>n;
		ll a[n];
		for (int i = 0; i < n; ++i)
			cin>>a[i];
		
		for (int i = 0; i < n-1; ++i)
			for (int j = i+1; j < n; ++j)
				mat[i][j] = mat[j][i] = ispow2(abs(a[i]-a[j]));
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
