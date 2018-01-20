#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000001

#define vi vector<ll> 
#define vii vector< vi > 

// #define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
	#define ONLINE_JUDGE_DEF true
#else
	#define ONLINE_JUDGE_DEF false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
Bruteforce 
1st WA ) - forgot to handle negatives!
2nd WA ) - forgot to remove the dbug print, damn! Use the macro
*/

bool checkSquare(ll a){
	if (a<0) return false;
	ll sq = sqrt(a);
	DEBUG(sq);
	return sq*sq == a;
} 

int main()
{
	ll t,n,k,maxNum;
	if(ONLINE_JUDGE_DEF) t = 1; else cin>>t; 
	while(t--){
		cin>>n;
		maxNum= -1 * MAX;
		for (int i = 0; i < n; ++i){
			cin>>k;
			if(!checkSquare(k))
				maxNum = max(maxNum,k);
		}

		cout<<maxNum<<endl;
	}
	return 0;

}