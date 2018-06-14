#include <iostream>
#include <vector>
#include <utility> //for pair
#include <list>
#include <string>

#define NUM_CHARS 58 //122 - 65 + 1
using namespace std;

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

string g_answer;

/*
* node Declaration
*/
struct node
{
	char data;
	int index;
	bool isEnd;
	node *child[NUM_CHARS];
	node* parent;
	node()
	{
		for(int i = 0; i < NUM_CHARS; i++)
			child[i] = NULL;
		isEnd = false;
		parent = NULL;
	}
};

/*
* trie class Declaration
*/
class trie
{
private:
	node *root;
public:
	trie()
	{
		root = new_node('X',0,NULL); //the only node with null parent
	}

	node *new_node(int data, int index,node* parent=NULL)
	{
		node *Q = new node;
		Q->data = data;
		Q->index = index;	
		Q->parent = parent;
		return Q;
	}

	void add(string S,int index)
	{
		node *cur = root;
		for(unsigned int i = 0; i < S.length(); i++)
		{
			if(!cur->child[S[i] - 'A'])
				cur->child[S[i] - 'A'] = new_node(S[i],0,cur);
			cur = cur->child[S[i] - 'A'];
			// end of string:
			if(i == S.length() - 1){
				cur->index = index;
				cur->isEnd = true;
			}
		}
	}


	int printNextNearest(node* cur, int r){
		if(cur->isEnd){ // && cur->index <= r) {
			return 1;
		}
		// if cur is not a satisfying end node, look further down!
		node* child;
		for(int i = 0; i < NUM_CHARS; i++){//recursive search into the children
			child = cur->child[i];
			if(child && printNextNearest(child, r)) {
				g_answer = child->data + g_answer;
				return 1;
			}
		}
		// No satisfying node found
		return 0;
	}

	int check(node *cur, string p,int r, unsigned int i)
	{
		//cout << cur->data;
		node* temp;
		if(i < p.length()){
			node* child = cur->child[p[i] - 'A'];
			if(child){
				//dig further
				if(check(child, p, r, i + 1)){
					g_answer = child->data + g_answer;
					return 1;
				}
				// else print while backtracking (below)
			}
		}
		
		//couldn't print at child's common prefix. try here.
		return printNextNearest(cur, r);
		//^ or last common node.
		//^ or p finished
	}

	void checkroot(string p, int r)
	{
		node* child = root->child[p[0] - 'A'];
		if(child){
			check(child, p, r, 1);//shall sure return 1
			g_answer = child->data + g_answer;//something common
		}
		else
			printNextNearest(root,r);//smallest S if p starts with totally diff character
	}
};

/*
// smallest string that has maximum common prefix with p
// modified to search till index < r and output full string than just the longest prefix
 
Find the longest prefix, store whole list of nodes of it
Then recursively search for the nearest satisfying node.
// creating a trie for each r is pretty expensive
 
 
The recursive search shall take atmost TOTAL_CHARS=NUM_CHARS*max(|p|) = 580 i.e. constant time
There will be atmost 10 such searches. It shall work!
 

M2 -> Offline compute!!
sort R's, keep indices
Insert and store answer for each possible r value

*/

 #define R_MAX 100001
int main()
{
	int t;
	//    cin>>t;
	int n, q, r,r_max;
	t = 1;
	while(t--){		
		cin >> n;
		string s[n];
		for(int i = 0; i<n; i++){
			cin >> s[i];
		}
		cin >> q;
		// sort R's <- count_sort!
		r_max = 1;
		std::vector< std::vector< pair<string,int> > > p_r(R_MAX); // O(q + |p|*q)
		for(int i = 0; i<q; i++){
			string p;	
			cin >> r >> p;
			p_r[r].push_back( make_pair(p,i) );
			r_max=max(r_max,r);
		}

		trie dict;
		string answer[q];
		for(int i = 1; i<=r_max; i++){
			dict.add(s[i-1],i);
			// for each p corr to this r, calc answer.
			for ( std::vector< pair<string,int> >::iterator it = p_r[i].begin(); it != p_r[i].end(); ++it){
				g_answer = "";
				dict.checkroot((*it).first, i); // O(|p|)
				answer[(*it).second]=g_answer;
			}
		}
		for(int i = 0; i<q; i++)
			cout << answer[i] <<endl;

	}
	return 0;
}
