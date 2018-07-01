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

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;


/*
Graph - find min cost for each node.
Brute force: O(n^2 + nlogn) - At each node run BFS, pick first s distinct type-nodes and sum the cost for those picked nodes.

Better: O(n*k + n*k*logk) - Make a dist[n][k] array by doing BFS for each type.
>> Tweak the start Queue of BFS- add all nodes with particular type while initializing the queue.

Note: vectors are passed by value. use '&' in parameter to pass by ref
*/

#define	MAX_Ai 1000
void bfs_mod(list <int> &bfsQueue,vector < vector <int> >  adjList,int n,int k, vector < vector <int> > &dist){
    //mark sources as visited
		for( list<int>::iterator i = bfsQueue.begin(); i!=bfsQueue.end(); i++ ){
			dist[*i][k]=0;
		}
		int nbr,node,curr_dist;
		while(!bfsQueue.empty()){
            //visit current node
			node = bfsQueue.front();
			bfsQueue.pop_front();
			curr_dist=dist[node][k];
			for( vector<int>::iterator i = adjList[node].begin(); i!=adjList[node].end(); i++ ){
				nbr=*i;
				if(dist[nbr][k] == MAX){
                // visit to its neighbors
					dist[nbr][k] = curr_dist+1;					
					bfsQueue.push_back(nbr);
				}
			}
		}
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
	int n,m,k,s;
	while(t--){
		cin>>n>>m>>k>>s;
		int kval[n];
		vector < vector <int> > adjList(n);
		vector < list <int> > bfsQueues(k);
		// O(n)
		for(int i=0;i<n;i++){
			cin>>kval[i];
			bfsQueues[kval[i]-1].push_back(i);
		}

		int u,v;
		for(int i=0;i<m;i++){
			cin>>u>>v;
			adjList[u-1].push_back(v-1);
			//don't forget this reverse edge!
			adjList[v-1].push_back(u-1);
		}

		vector < vector<int> > dist(n, vector<int>(k,MAX));
		// * O(k)
		for(int k_i=0;k_i<k;k_i++){
			// O(n)
			bfs_mod( bfsQueues[k_i], adjList,n,k_i, dist);
		}
	    //now calc sum of dists for first s nodes
		int sum;
		// * O(n)
		for(int i=0;i<n;i++){
            //O{k*logk)
			sort(dist[i].begin(),dist[i].end());
			sum=0;
			//O(s)
			for(int j=0;j<s;j++)
				sum+=dist[i][j];
			cout<<sum<<" ";
		}
		cout<<endl;

	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
