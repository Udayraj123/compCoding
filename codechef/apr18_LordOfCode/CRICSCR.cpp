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
curr>=prev
*/
#define	MAX_Ai 1000

int getCi(vi &C,int i){
	return C[MAX_Ai + i];
}

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

	ll t,n,r,r1,w,w1,flag;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	ll NUM_NUMBERS=MAX_Ai*2+1;// |Ai| <= 10^3
	// NUM_NUMBERS-c-2 totalpairs
	while(t--){
		cin>>n;
		r1=0;w1=0,flag=1;
		vi C(NUM_NUMBERS,0); // counts array of 2001 possible Ais
		for (int i = 0; i < n; ++i){
			cin>>r>>w;
			if(r<r1 || w < w1)
				flag=0;
			r1=r;w1=w;
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
