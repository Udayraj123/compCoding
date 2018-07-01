#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
	#define ONLINE_JUDGE_DEF true
#else
	#define ONLINE_JUDGE_DEF false
#endif


#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
 
 partitionSumEqual for 1 to N with a missing X.
 FIRST CHECK TOTAL SUM IS EVEN.
 First, with X i.e. all nums from 1 to N.
 FOR EVEN SUMs, group them into sum/2 by (n/2+1)/2 end pairs + a number.
 (1 2) (3)	  - Even 3s
 1) (2 3) (4  - Even 5s
 1 2 3 4 5-> Odd 5s -> 4n+1 form
 1 2 3 4 5 6   - Odd 7s 
 1 2 3 7 4 5 6 - Even 7s 
 1 2 3 4 5 6 7 8 - Even 9s
 1 2 3 4 5 6 7 8 9 - Odd 9s
 1 2 3 4 5 6 7 8 9 10 - Odd 11s
 1 2 3 4 5  11 
 6 7 X 9 10 ..	- Even 11s

 Now with missing X ,
 even sum filter

M1) BF - 2^N diff partitions
    BF2 - In chunks of 4, add the extremes to 1 set, middles to another, until we reach X & continue after X till N.
	Now you will have few numbers in hand to put into the sets, possibly needing to transfer 1 (to create diff of -2),etc
    For remaining 1, 2 or 3 elements =>

     1 : N find in previous N-1 numbers
     S - p + N = S + p -> p = N/2
     
     2 : N,N-1
     3 : N,N-1,N-2

 the conjugate of X, 
 ...

 M2) 1 2 3 4 ... X-1 X X+1 ... N
	
 	 N-X is even and >= 4 &
	 	 if sum(X-1) even, then apply on LHS and on RHS. Name 1 & 2 only.
		 	 1 2 3 X 5 6 7 8 9
	 	 if sum(X-1) odd, 
		 	 1 2 3 4 5 X 7 8 9 10 11
 	 N-X is odd
		 	 1 2 3 X 5 6 7


*/
void solve ( ll n, ll x){
	if( (n*(n+1) / 2 - x) % 2) {
		cout << "impossible\n";
		return;
	}


}
int main(int argc, char const *argv[])
{
	ll t,n,x;
	cin>>t; 
	while(t--){
		cin>>x>>n;
		solve(n,x);
	}
	return 0;

}