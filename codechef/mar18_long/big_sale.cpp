#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

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
Math problem
*/


int main()
{
	ll t,n,temp;
	double x,moneylost,price, quantity, percentD;;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n;
		moneylost=0;
		for (int i = 0; i < n; ++i){
			cin>>price;
			cin>>quantity;
			cin>>percentD;
			x = percentD/(double)100;
			moneylost += quantity*price*(1 - (1+x)*(1-x));
		}
		cout<<moneylost<<endl;
	}
	return 0;
}