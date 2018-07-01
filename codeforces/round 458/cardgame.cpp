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
if the player chooses the i-th card, he removes that card and removes the j-th card for all j such that aj < ai.
=> Remove ai & all aj<ai (note some ak having same numerical value as ai will s=not get removed)
A player loses if he cannot make a move on his turn, that is, 
he loses if there are no cards left. Predict the outcome of the game, assuming both players play optimally.

ais are positive < 10^5

Mistake that cozed hack1 - Numbers other than maxNum will never be selected - Nope
3 3 2 1 = 2,3,3
-> use nextMax at first & flip the win
-> but then same case for nextMax
3 3 2 2 1 = 2,2,3,3 - nope, 1,2,2,3,3 = win
3 3 2 2  = 3,3 or 2,3 lose any way
ANSWER -> make counts & check all even for lose case

Conan takes first turn
-> Choose the max number, if its unique he wins
-> if multiple max rem, if their count is odd he wins

Agasa gets second turn

*/

int main()
{
	ll t,n,k,flag,temp, max_a = 100000;
	if(!DEBUG_ON) t = 1; else cin>>t; 
	while(t--){
		cin>>n;
		vi counts(max_a,0);
		
		for (int i = 0; i < n; ++i){
			cin>>temp;
			counts[temp-1]++;
		}
		flag = 0;
		for (int i = 0; i < max_a; ++i)
			if(counts[i]%2)
				flag = 1;
		//odd wins

			cout<<(flag==1?"Conan":"Agasa")<<endl;
		}
		return 0;

	}