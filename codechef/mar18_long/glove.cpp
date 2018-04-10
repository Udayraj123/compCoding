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
Array reversion and comparision
*/


int main()
{
	ll t,n,temp,front,back;
	// if(!DPRINT_ALLOW) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n;
		vi L(n,0);
		for (int i = 0; i < n; ++i)
			cin>>L[i];
		front=1;back=1;
		for (int i = 0; i < n; ++i){
			cin>>temp;
			if(temp<L[i])front=0;
			if(temp<L[n-i-1])back=0;
		}

		if(front == 1 && back == 0 ) cout << "front\n";
		else if(front == 0 && back == 1 ) cout << "back\n";
		else if(front == 1 && back == 1 ) cout << "both\n";
		else 							  cout << "none\n";
	}
	return 0;
}