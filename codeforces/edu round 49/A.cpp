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
In one second she can choose arbitrary position in any word and replace its character with some uppercase Latin letter.
Ksenia can't remove or add letters in any of the words.
Minimize no of moves for it:
n <= 100 -> BF
>> Length-wise counts
 It is also guaranteed that Ksenia can produce list b from the list a 
 => check one side diff only
 => 
 MSL
 357
 582

*/

string sizes[]={"M","S","L","XS","XL","XXS","XXL","XXXL","XXXS"};

void solve(){
	ll n,sum=0;
	std::map<string, int> count1,count2;//default is 0 (virtually: as its lazily set)
	cin>>n;
	string temp;
	FOR(i,n){cin>>temp;count1[temp]++;}
	FOR(i,n){cin>>temp;count2[temp]++;}

	//add positive sums only
	FORG(i,0,8) sum += max(0,count2[sizes[i]]-count1[sizes[i]]);
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
