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
trivial nos
N>K
N>M*X
nE
nO

*/

int main()
{
	ll t,n,m,k,x,nE,nO,rem,fullE,fullO;
	// if(!DPRINT_ALLOW) t = 1; else 
	cin>>t; 
	string sentence;
	while(t--){
		char c;
		cin>>n>>m>>x>>k;
		nE=0;nO=0;
		for (int i = 0; i < k; ++i){
			cin>>c;
			c=='E'?nE++:nO++;
		}
		//atleast n/x times we need full forces
		// we have M/2 even months and M - M/2 odd months

		if(n>k || n>m*x){
			cout<<"no\n";
		}
		else{
			//we have ( n <= m/2*x+(m-m/2)*x) and n <= nE+nO
			fullE = min(m/2,  nE/x);
			fullO = min(m-m/2,nO/x);
			// if months used up, n will be covered.
			// if full-even months used up, but odd left (m/2>nE/x)
			// then rem-even months = max(m/2-nE/x, 0);
			// 5,5,5,4,1
			rem =  n - (fullE+fullO)*x - ( (m/2 > nE/x ? nE%x : 0) + ((m-m/2) > nO/x ? nO%x : 0));
			cout << ( rem>0?"no\n":"yes\n" );
		}
	}
	return 0;
}