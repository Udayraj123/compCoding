#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

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

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*

min edges for Reachability in directional
1<= n,m<= 5000
>> count of SCC! - Nope
>> From Source s we need- dfs first from s
>> for remaining unvisiteds- find the source from which max unvisited can be found- via Bellman Ford?

>> make SCC graph
	> get topo order in stack
	> in reverse edge(transpose) order do dfs on each popped node and get new scc on new visit
>> countNewVisits on SCC graph!!

WA at 4
> approach was slightly wrong. We need no of SCCs with 0 in-degree (Sources), as any SCC having >0 in-degree will be reachable (once the 0node connected to it gets an edge) [Think!].
DONE > source is 's-1'!!

*/
#define MAX_NODES 5000
#define M_PLUS 5001
bool adj[M_PLUS][M_PLUS];
bool visited[M_PLUS];
stack <int> topo;
ll n,m,a,b,s,temp;

bool adjSCC[M_PLUS][M_PLUS];
bool visitedSCC[M_PLUS];
int sccLabels[M_PLUS];// for constructing SCC graph
int indegree[M_PLUS];
int labelCount;

void dfsPush(int node){
	visited[node]=1;
	for (int i = 0; i < n; ++i){
		if(adj[node][i] && !visited[i])
			dfsPush(i);
	}
	topo.push(node);//finishing time!!
}

void dfsRev(int node){
	visited[node]=1;
	for (int i = 0; i < n; ++i){
		if(adj[i][node] && !visited[i])//edges reversed
			dfsRev(i);
	}
	sccLabels[node]=labelCount;//current count serves as the label
}

void makeSCC(){
	//Kosaraju Algo
	//reset
	for (int i = 0; i < n; ++i) 
		visited[i]=0;
	// Step 1
	for (int i = 0; i < n; ++i) {
		if(!visited[i]){
			dfsPush(i);
		}
	}
	//reset
	for (int i = 0; i < n; ++i) 
		visited[i]=0;
	//Step 2
	labelCount=0;
	while(!topo.empty()){
		temp = topo.top();topo.pop();
		if(!visited[temp]){
			// SCC node
			dfsRev(temp);
			labelCount++;
		}
	}	

	//reset SCC edges
	for (int i = 0; i < labelCount; ++i) {
		for (int j = 0; j < labelCount; ++j) {
			adjSCC[i][j]=0;
		}
		indegree[i]=0;
	}
	// construct SCC graph edges
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(sccLabels[i]!=sccLabels[j] && adj[i][j]){
				adjSCC[sccLabels[i]][sccLabels[j]]=1;
				indegree[sccLabels[j]]++;
			}
		}
	}

}

void dfsSCC(int node){
	visitedSCC[node]=1;
	for (int i = 0; i < labelCount; ++i){
		if(adjSCC[node][i] && !visitedSCC[i])
			dfsSCC(i);
	}
}
ll countSources(ll s){
	for (int i = 0; i < labelCount; ++i)
		visitedSCC[i]=0;
	dfsSCC(sccLabels[s]);//good ones
	ll count = 0;
	for (int i = 0; i < labelCount; ++i) {
		if( !indegree[i] && !visitedSCC[i])
			count++;
	}
	return count;
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

	ll t;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n>>m>>s;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j)
				adj[i][j]=0;
		}
		for (int i = 0; i < m; ++i){
			cin>>a>>b;
			adj[a-1][b-1]=1;
		}
		makeSCC();
		cout << countSources(s-1)<<endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
