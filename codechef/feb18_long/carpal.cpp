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
N tunnels, Each D meters apart on a single road,Tunnel lengths negligible.
C cars having S speed, stops for Ai seconds at the ith tunnel (toll booth)

Ch..C..R. r1__R__ D _____ . ____ D _____ . ____ ..N.. ____ . _____ . ____ D _____ . ____ D _____ .

if car1 leaves A1 before car2 arrives ( i.e. A0 >= A1 ),
	then car2 doesn't wait because of car1 i.e. the delay still remains A0
if car1 is still waiting when car2 arrives, 
	then car2 has to wait an extra A1-A0 time.
  

time for first car to reach : sum(A) + (N*D)/S
time for next car to reach  : sum(A) + (N*D)/S + max(A)
time for next car to reach  : sum(A) + (N*D)/S + 2*max(A)
time for Cth car to reach  : sum(A) + (N*D)/S + (C-1)*max(A)

1 ≤ T ≤ 100
1 ≤ N ≤ 10.5
1 ≤ Ai ≤ 10.9 for each valid i
2 ≤ C ≤ 10.6
1 ≤ D, S ≤ 10.9


Corner case - A(n) is too long => Delay is (C-1)*A(n)


*/


int main()
{
	ll t,n,flag,c,d,s;
	double sum,max;
	// if(!DEBUG_ON) t = 1; else 
	cin>>t; 
	while(t--){
		cin>>n;
		vi A(n,0);
		for (int i = 0; i < n; ++i)
			cin>>A[i];
		// sum = std::accumulate(A.begin(), A.end(), 0.0);// using 0.0 will output double sum
		max = (double) *std::max_element( A.begin(), A.end());
		cin>>c>>d>>s;
		double ans = ((double)(c-1))*max;
		cout<< ans <<endl;
	}
	return 0;
}