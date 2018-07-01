#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#ifdef DEBUG_MODE
	#include "../../getTime.h"
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif
#define FAST ios_base::sync_with_stdio(0);cin.tie(NULL);
#define FOR(i,n) for (int i = 0; i < n; ++i)
#define FORG(x,a,b) for (int i = a; i <= b; ++i)
#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}
#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;
/*
Store two phase optimals. Then decide where to insert a node.
" at moment 0 turns power and light on"
0<a1<a2<⋯<an<M
01010101010101
0.101010101010

phase1: 0..4 6..7 10
phase2: 0 4..6 7..10

*/

void solve(){
	ll n,sum=0,M;
	cin>>n>>M;
	ll a[n],phase1Till[n],phase2From[n];
	FOR(i,n){
		cin>>a[i];
		phase1Till[i]=phase2From[i]=0;
	}
	phase1Till[0]=a[0];// always starts with on
	>>FOCUS>> phase2From[n-1]=M - a[n-1];// always ends with off
	FORG(i,1,n-2)	{
		if(i%2){
			phase1Till[i]= a[i]-a[i-1] + phase1Till[i-1];
		}
		else{
			phase1Till[i]=phase1Till[i-1];

		}
	}
	cout<<sum<<endl;
}

// FIXED CODE BELOW
int main(){
	FAST;
	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif
	int t;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		solve();
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif
	return 0;
}
