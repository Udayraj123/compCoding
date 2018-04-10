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
just make a map!
*/

int main()
{
	ll t,n,m;
	string name,sv,cmd;
	if(!DPRINT_ALLOW) t = 1; else cin>>t; 
	while(t--){
		std::map<string, string> map;
		cin>>n>>m;
		for (int i = 0; i < n; ++i){
			cin>>name>>sv;
			DEBUG(name)
			DEBUG(sv)
			// map.insert(make_pair(sv,name));
			// map.insert(pair<string,string>(sv,name));
			map[sv]=name;
		}
		for (std::map<string,string>::iterator i = map.begin(); i != map.end(); ++i)
			cout<< i->first << " : " << i->second <<"\n";
		
		for (int i = 0; i < m; ++i){
			cin>>cmd>>sv;
			cout<<cmd<<" "<<sv<<" #"<< map.find(sv)->second <<endl;
		}

	}
	return 0;
}