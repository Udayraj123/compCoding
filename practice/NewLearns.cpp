#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef ONLINE_JUDGE
	#define ONLINE_JUDGE_DEF true
#else
	#define ONLINE_JUDGE_DEF false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(!ONLINE_JUDGE_DEF){for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");}
#define DEBUG(x) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;

// Catalan's Number -
answer to 3 eqv problems :
>No of ways of correctly parenthesising
>Dycks words of length 2n (each prefix of the string has no of X >= no of Y)
Reduced to >Number of paths without crossing the diagonal
-> Solved by : 
	>Create a line CD parallel to the diagonal AB in the upper(crossing) side.
	> Reflection of A in line CD will be at F(-1,1). 
	>All "incorrect" paths must have a point on CD, call the first such point E.
	>

 void some_function(const vector<int>& v) { // OK 
      // ... 
 } 
If you are going to change the contents of vector in the function, just omit the ‘const’ modifier.
 void some_function(vector<int>& v) { // OK but less usual