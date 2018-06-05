#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
// #define ll_MAX 18446744073709551615
#define ll_MAX std::numeric_limits<unsigned long long>::max()

#define vd vector<double> 
#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<int> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#include "../../getTime.h"
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif

#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}

#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;
/*

**IN-PROGRESS

Find non-negative Di <= K such that when added to Ai and taken product of A's elements ProdA
sum(ProdA%P[i]) is maximised
Return the new A[i] whose product is taken
==> find a prodA > prod(A) which maximizes obj func
==> If none of A[i]+D[i] be divisible by any P[j]
*/
int main(){
	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif

	int t,n,m,temp;
	ll k;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n>>m>>k;
		vl a(n,0);
		vl p(m,0);
		for (int i = 0; i < n; ++i){cin>>a[i];}//
		for (int i = 0; i < m; ++i){cin>>p[i];}// Consecutive primes!
		printa(a,n);//
		//
	}

	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif
	return 0;
}