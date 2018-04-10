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


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(DPRINT_ALLOW){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DPRINT_ALLOW){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*

[INCOMPLETE]

1 ≤ n < 2^1000
=> input is in binary representation of N.
=> int n cannot be stored

operation  N -> b where b = number of 1's in binary repr. of N
special number => min no of operations required to reduce to 1 is exactly k
=> At max log*(n) = 5 operations required;
n->1000->9.7->3->1.5->1-


-> Any power of 2 reduces to 1 immediately
output = (no of spl numbers <= n)%MAX

thinking of a recursive n--op - 
let p = nearest power of 2 < n
then p-1 has maximum number of bits 


11:20PM -
How about breaking n in batches of m = 30;
n = 11111111
 op(11XXXXXX)
num of steps will change by atmost one for reaching p


Is there a pattern in number of bits ?
from 1 to 2 -
1
from 2 to 4 -
1 2 
from 4 to 8 -
1 2 2 3
from 8 to 16 -
1 2 2 3 2 3 3 4 
from 16 to 32 -
1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 
from 32 to 64 -
1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 
from 64 to 128 -
1 2 2 3 2 3 3 4 2 3 3 4 3 4 4 5 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 2 3 3 4 3 4 4 5 3 4 4 5 4 5 5 6 3 4 4 5 4 5 5 6 4 5 5 6 5 6 6 7
max numbits = 1000
=> 997 998 998 999 998 999 999 1000
*/

int operation(string n){
	int len = n.length(),counter=0;
	for (int i = 0; i < len; ++i){
		if(n[i]=='1')
			counter++;
	}
	return counter;
}
string binary(int op){
	string bin = "";
	do{
		bin =( op%2 ?"1":"0") + bin; //add in reverse order
		op/=2;
	}while(op);
	return bin;
}

ll calcSteps(ll op){
	//arg op is at max 1000, so the binary won't take long.
	ll steps = 0;
	while( op != 1 ){
		steps++;
		op = operation(binary(op));
	}
	return steps;
}

int main()
{
	ll t;
	string n;
	ll len,k,op,steps;
	if(!DPRINT_ALLOW) t = 1; else cin>>t; 
	while(t--){
		cin>>n>>k;
		op = operation(n);

		steps = 1 + calcSteps(op);
		DEBUG(op)
		DEBUG(steps)
		DEBUG(steps==k)
	}
	return 0;

}