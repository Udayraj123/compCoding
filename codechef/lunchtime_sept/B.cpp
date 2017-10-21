#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
using namespace std;

/*

so we figure each Top number has the next Top number as one of its four adjacents.
-> We shall make a 6 vertice graph, it shall have 4 edges for each of its vertex. And a total of 4*3 = 12 undirected edges
If more edges are there, the dice is not possible
if lesser edges are there, multiple dices possible.

The opposite of the number is the one not having its edge.


Note: VECTOR IS PASSED BY REFERENCE BY DEFAULT, JUST LIKE PYTHON ARRAYS

*/
void make_edge(int a, int b,vector<vector<int> >  edges){
	edges[a][b]=1;
	edges[b][a]=1;
}

int validate(vector<vector<int> >  edges){
	//check for four edges in each.
	ll count_row;
	for(int j=0;j<6;j++){
		count_row=0;
		for(int k=0;k<6;k++){
			if(edges[j][k]==1){
				count_row++;
			}
		}
		if(count_row!=4)return 0;
	}

	return 1;
}

int main()
{
	ll t,n,counter,temp;
	cin>>t; 
	while(t--){
		cin>>n;
		ll num[n];
		vector <int> zero_row(6,0);
		vector< vector<int> > edges (6, zero_row);
		for(int i = 0; i<n; i++){
			cin>>temp;
			num[i]=temp-1;
			if(i)
				make_edge(num[i],num[i-1],edges);
		}
		
		if(validate(edges))
		{
			for(int j=0;j<6;j++){
				for(int k=0;k<6;k++){
					if(edges[j][k]!=1 && j!=k){
						cout<<(k+1)<<endl;
						break;
					}
				}
			}
		}
		else cout<< (-1) <<endl;
	}
	return 0;
}

