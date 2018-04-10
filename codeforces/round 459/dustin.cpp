#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef DEBUG_MODE
	#define DPRINT_ALLOW true
#else
	#define DPRINT_ALLOW false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(DPRINT_ALLOW){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(DPRINT_ALLOW){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
just make a myMap!

*/



int main()
{
	ll t,n,m;
	if(!DPRINT_ALLOW) t = 1; else cin>>t; 
	while(t--){
		string name,sv,cmd;
		std::map<string, string> myMap;
		cin>>n>>m;
		for (int i = 0; i < n; ++i){
			cin>>name>>sv;
			// myMap.insert(make_pair(sv,name));
			// myMap.insert(pair<string,string>(sv,name));
			myMap[sv]=name;
		}
		
		for (int i = 0; i < m; ++i){
			cin>>cmd>>sv;
			cout<<cmd<<" "<<sv<<" #"<< myMap[sv.substr(0,sv.size()-1)]<<endl;
		}

	}
	return 0;
}