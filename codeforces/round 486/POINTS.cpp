#include<iostream>
#include<stdio.h>
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

bool ispow2(ll x){	
	//constant time 
	return x && (!(x&(x-1)));
	// int c=0;
	// while(x){
	// 	c = x&1;
	// 	x >>= 1;
	// 	if (c && x)return false;
	// }
	// return true;
}
typedef struct node
{
	int data;
	struct node* next;
} node;

node* newnode(int data){
	node* n = (node*)malloc(sizeof(node));
	n->data=data;
	n->next=NULL;
	return n;
}

class list {
public:
	node* head;
	int size;
	list(){
		//empty head;
		head = NULL;
		size=0;
	}
	void push(int val){
		size++;
		node* temp = newnode(val);
		if(!head)
			head = temp;
		else{
			node* curr = head;
			while(curr->next)
				curr=curr->next;
			curr->next=temp;
		}

	}
	int find(int val){
		node* curr = head;
		int i = -1;
		while(curr){
			i++;
			if(curr->data==val)
				return i;
			curr=curr->next;
		}
		return -1;
	}
};
class Graph {
public:
	list* adjList;
	Graph(int n){
		//init adjList array
		adjList = new list[n];
	};

	void add(int i,int j){
		adjList[i].push(j);
	}

};

enum Color{ WHITE,GRAY,BLACK};

void getCycle(int i,Graph g,Color* visited,int l){
	if(l==0)return;
	visited[i]=GRAY;
	node* curr = g.adjList[i].head;
	while(curr){//visit the neighbours
		if(visited[curr->data]==WHITE)
			getCycle(curr->data,g,visited,l-1);
		else if(visited[curr->data]==GRAY){
			//cycle found
			cout<<"Cycle found!\n";
			break;
		}
		curr=curr->next;
	}
	visited[i]=BLACK;

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
	ll n,k,temp,sum,flag;
	while(t--){
		cin>>n;
		Color visited[n];
		Graph g(n);
		ll a[n];
		for (int i = 0; i < n; ++i){
			cin>>a[i];
			visited[i]=WHITE;
		}
		for (int i = 0; i < n-1; ++i){
			for (int j = i+1; j < n; ++j){
				if(a[i]>a[j]){
					if(ispow2(a[i]-a[j]))
						g.add(i,j);
				}
				else {
					if (ispow2(a[j]-a[i]))
						g.add(j,i);
				}
			}
		}

		// now find longest SCC 
		// for SCC-> first get topo order, then DFS in that order on reversed edge graph

		//Or you can find max length by DFS of depth 3 - whether cycle exists
		for (int i = 0; i < n; ++i){
			if(visited[i]==WHITE)
				getCycle(i,g,visited,3);
		}
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
