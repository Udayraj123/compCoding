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
increasing subsequence of size 3
n>=3,si,ci>=1
bruteforce=O(n^3):  try nC3 triples and return the min cost.

make it n^2 by ->
O(n) for each si to find out the minCi corresponding to a compatible si Before and After it.
Click: 3 ptrs -> 1 in middle, 1 to the right, one to the left

n<=3000

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
	int n;
	while(t--){
		cin>>n;
		int s[n],c[n];
		for(int i=0; i<n ; i++){
			cin>>s[i];
		}

		for(int i=0; i<n ; i++){
			cin>>c[i];
		}

		int minSumCost=MAX,sum,minL,minR,foundL,foundR,compatible=0;
		for(int i=0; i<n ; i++){
			sum=0;
			minL=MAX,foundL=0;
			for(int j=0; j<i ; j++){
            //check compatible
				if(s[j]<s[i]){
					foundL=1;
                //check Ci
					minL = minL > c[j]? c[j]: minL;
				}
			}
			minR=MAX,foundR=0;
			for(int k=i+1; k<n ; k++){
            //check compatible
				if(s[k]>s[i]){
					foundR=1;
                //check Ci
					minR = minR > c[k]? c[k]: minR;
				}
			}
			if(foundL && foundR){
				compatible=1;
				sum = c[i]+minL+minR;
				minSumCost=min(sum,minSumCost);
			}
		}
		cout<< (compatible ? minSumCost : -1) << endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
