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
Find possible roots of the tree

Editorial visited: https://discuss.codechef.com/questions/4727/treeroot-editorial
-> Should have thought of sum cancellation here!
Learnt about bitmasks - can be stored inside integers too!

T<=50
N<=30 ---> This was to trick thinking into bruteforce. Which also is pretty hard? Use bitmasks for the trees
^^ But it was also to hint that bitmasks can be used here!

node_id ids between 1 to 1000

>> start from leaf node_ids (having sum_ids = 0)
it may equal to some sum
>> any unpaired leaf will be paired with intermediate node_id.
>> node_id having id greater than any sum is definitely a root

*/

int main(){
	// http://codeforces.com/blog/entry/5217

	// Speeds up cin/cout- But now you can't mix printf and cout coz their order of flushing is changed.
	ios_base::sync_with_stdio(0);
	// Second optimisation: Effective when large no of inputs (when cin gets used too much)
	cin.tie(NULL);

	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll _startTime,_endTime;
	_startTime = getTime();
	#endif

	ll t,n,node_id,sum_ids,sum_childs,sum_parents;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n;
		sum_parents=0;
		sum_childs=0;
		for (int i = 0; i < n; ++i){
			cin>>node_id>>sum_ids;
			sum_parents += node_id;
			sum_childs += sum_ids;
		}
		cout<< (sum_parents - sum_childs) << endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	_endTime = getTime();
	cout<<"Time Taken: " << (_endTime-_startTime) << " ms\n";
	#endif

	return 0;
}
