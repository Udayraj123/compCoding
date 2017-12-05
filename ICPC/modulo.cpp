#include <bits/stdc++.h>
 
#define ll long long int
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
 
using namespace std;
///////////////////////////////////////////////////////
 
#define mod 1000000007


/*
No of increments required to make Ai%Bi == Aj%Bj equal for each i,j
1 2 3 4 
5 6 7 8

2 1 1 2
3 3 3 3

** How to determine the number to which descend to -
-> try all N modulo vals. O(n^2)
->

Firstly, reduce A to A%B (element wise mod)
**modder off min of Bi only? Nope, but modder has to be <= min(B)

M1 	- (step in) increment each no in A to max_A <- not min number
						//- compare (maxA - a) with (b - a) <- Nope
	-> just calc sum(modder - a)%b
		= min(modder * N - sum(reducedA)) //as modder <= min(B) & reducedAi <= Bi
		= min(modder)
*/


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    cout.tie(NULL);
    


    return 0;
} 