#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<ll> 
#define vll vector< vl > 

using namespace std;

#ifdef DEBUG_MODE
	#include "../../getTime.h"
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif


#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}

/*
A to B using min operations having steps-
1. prefix 0's to A -> 000A
2. shuffle bits
3. add 1

All WA updates-

> swap n1 and n2
> n2>=n1 than n2>n1
> a==b case
> cin>>t codeforces line!
> X 0  and X 1 case
> 10^18 -> 59.8 == 60 bits <- only long long (64 bit)! (long is 32)
> 0 1 special case!
> ll in function call!

*/


// runs only as many steps as there are 1s
int kerniGhan(ll a){
	int c=0;
	while(a){
		c++;
		a &= (a-1);
	}
	return c;
}
//logn
int count1s(ll a){
	return kerniGhan(a);
	int c =0;
	while(a){
		c += a & 1;
		a >>= 1;
	}
	return c;
}


int main()
{

	// Speeds up cin/cout- But now you can't mix printf and cout coz their order of flushing is changed.
	ios_base::sync_with_stdio(0);
	// Second optimisation: Effective when large no of inputs (when cin gets used too much)
	cin.tie(NULL);

	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif

	int t;
	ll n, a,b,n1,n2,ans;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){		
		cin >> a>>b;
		if (a==b)
			ans=0;
		else if(b==0 || (b==1 && a!=0))
			ans= -1;
		else{
			n1 = kerniGhan(a);
			//https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
			// n1 = __builtin_popcount (a); //gcc's built in lookup :  probably from its optimisations
			n2 = kerniGhan(b-1);
			ans = 1;//pre-move
			ans += (n2 >= n1)? (n2 - n1) : 1; // increasing takes 1 per bit, decreasing possible in 1 move.
		}
		cout << ans << endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif


	return 0;

}
