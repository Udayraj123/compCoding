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
k sequences
output indices i, j of sequences off which indices x,y be removed to obtain same sum.
>> sum of lengths of all given sequences don't exceed 2⋅10^5
>> store sum of k seqs.
>> store sumWithoutMe for each input seq.
>> find two

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
	int n,k,temp;
	while(t--){
		cin>>k;
		std::vector< vector<int> > seq(k);
		for (int i = 0; i < k; ++i){
			cin>>n;
			sum=0;
			for (int j = 0; j < n; ++j){
				cin>>temp;
				seq[i].push_back(temp);
				sum+=temp;
			}
			for (int j = 0; j < n; ++j)
				seq[i][j] = sum - seq[i][j];
		}
		for (int i = 0; i < k; ++i)
			for (int j = 0; j < n; ++j)
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
