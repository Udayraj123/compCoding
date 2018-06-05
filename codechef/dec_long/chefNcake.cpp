#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
2-coloring with weights
structure = grid
output = min Cost

-> there are always two patterns, both alternating. one starts from R, other from G. 
calc cost in making both
RGRGRGRG
GRGRGRGR
RGRGRGRG
GRGRGRGR
and
GRGRGRGR
RGRGRGRG
GRGRGRGR
RGRGRGRG
then give the minimum
*/



int main(int argc, char const *argv[])
{
	ll t=1,n,m;
	char temp,expect;	
	std::map<char, int> colorCost;
	colorCost['R']=5;
	colorCost['G']=3;
	cin>>t; 
	while(t--){
		cin>>n>>m;
		int cake[n][m];
		int cost1=0,cost2=0;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < m; ++j){
				cin>>temp;
				cake[i][j] = (temp == 'G')?1:0;
				expect = ((i+j)%2)?'G':'R';
				if(temp == expect) (cost1+=colorCost[expect]); else (cost2+=colorCost[temp]);
			}
		}
		cout<<min(cost1,cost2)<<endl;
		}
	return 0;
}

