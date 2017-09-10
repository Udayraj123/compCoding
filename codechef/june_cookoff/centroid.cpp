#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
using namespace std;

/*
Centre = A vertex at the middle of the diameter of the tree.
	Method to find :

Centroid = A vertex on removal of which the tree breaks into p trees with at most N/2 vertices (where p is no of its children).
	Method to find :
		Pick an arbit vertex v, 
		get sub-tree sizes using a DFS call, 
			if v has children with subtree sizes atmost N/2, return v.
			elses recurse into the only child that has N/2 or more size.
*/

		ll get_vertex(ll n,std::vector< std::vector<int> > edges){
//  e=n-1
...
			return 0;


		}

		int main()
		{
			ll t,n,v1,v2;
			cin>>t; while(t--){
				cin>>n;

//intialize vector using round brackets
				std::vector< std::vector<int> > edges (n+1,std::vector<int>(n+1,0));
				std::vector<int> visits(n+1,0);
				for (int i = 0; i < n-1; ++i)
				{
				//n-1 edges
					cin>>v1>>v2;
				//this works without problems now
					edges[v1][v2]=1;
					edges[v2][v1]=1;
				}
				cout<<get_vertex(n,edges)<<endl;
			}
			return 0;
		}
