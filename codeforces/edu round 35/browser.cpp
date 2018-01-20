#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000001

#define vi vector<ll> 
#define vii vector< vi > 

#define ONLINE_JUDGE

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
 Tabs 
 |		|		|  l	|	..	|	pos	|	..	|	..	|	r	|		|		|
 Target : Leave tabs l..r open
 She can close all (contigous unclosed tabs) to the left/right or move the cursor by 1

M1 -
Go to nearest l/r, close all in that extreme, goto another extreme and close on that side

*/

int main(int argc, char const *argv[])
{
	ll t,n,pos,l,r, ans;
	if (!ONLINE_JUDGE_DEF) cin>>t; 
	else t = 1;
	while(t--){
		cin>>n>>pos>>l>>r;
		/*
		6 3 2 4
		6 3 1 3
		5 2 1 5
		*/
		if(l==1 && r==n) ans = 0;
		else{
			if(l==1)ans = abs(pos-r)+1;
			else if(r==n)ans = abs(pos-l)+1;
			else ans = min(abs(pos-r),abs(pos-l)) + 2 + abs(r-l);
		}

		cout << ans<<endl;
	}
	return 0;

}