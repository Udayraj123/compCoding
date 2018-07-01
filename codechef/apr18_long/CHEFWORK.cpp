#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<int> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif


#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
t,a,at
min(min(at),min(a)+min(t))
*/


int main()
{
	int t,n,temp;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n;
		vi C(n,0);
		std::map<int, int> typeToMinCost;
		for (int i = 1; i < 4; ++i)
			typeToMinCost[i] =MAX;

		for (int i = 0; i < n; ++i)
			cin>>C[i];

		for (int i = 0; i < n; ++i){
			cin>>temp;
			typeToMinCost[temp]=min(C[i],typeToMinCost[temp]);
		}
		cout<< min(typeToMinCost[1]+typeToMinCost[2],typeToMinCost[3]) << endl;
	}
	return 0;
}