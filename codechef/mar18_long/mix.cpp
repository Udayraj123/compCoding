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
Make all elements of A distinct using min no of Mix.
Mix(x,y)=(x,x+y)

M1) Separate distincts and repeats.
	On k repeats, we have to make k-1 of them different i.e. they go in place of y. => Atleast k-1 Mixes req
	So, for x in desc_sort(distincts): Mix(x,repeats[k--]) until k==0

calc for 1 1 1 1 1 => 8->7->4
Nope: 11111 --+4> 12222 --+3> 12344 --+1> 12345
Nope: 11111 --+4> 12222 --+2> 12342 --+1> 12345
Yeah: 11111 --+1> 11112 --+1> 11132 --+1> 11432 --+1>15432


=> You'll req exactly k-1 mixes to make them distinct, relatively!
Sort the nums : 
11223344 => 10
Nope: 11223344 --+4> 12243648==12234468 -+2> 12434868==12344688 -+2> 1234868(16)==123468816 -+1>123481616 -+1>12348(16)(32)
11223344==12341234 -+4> 12345678
Note constraints: T<=10, N<=10^5, Colors can "become" >= 10^9
Bruteforce: Try every possible mixtures having distinct numbers and return the one with minimum operations

A mix op changes only one number.

Is the Mix operation valid if x is equal to y?
- Doesn't matter. You won't use it for distincts, and on repeats anyway you can find x==y
*/



int main()
{
	ll t,n,temp;
	// if(!DPRINT_ALLOW) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n;
		vi A(n,0);
		for (int i = 0; i < n; ++i){
			cin>>A[i];
		}
		sort(A.begin(),A.end());
	}
	return 0;
}
/*


*/