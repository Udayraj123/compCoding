#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
// #define ll_MAX 18446744073709551615
#define ll_MAX std::numeric_limits<unsigned long long>::max()

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<int> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#define DPRINT_ALLOW true
#else
	#define DPRINT_ALLOW false
#endif

#define dprintf(...) if(DPRINT_ALLOW)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DPRINT_ALLOW){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(DPRINT_ALLOW){cout << ">> " << #x << " : " << (x) << endl;}

#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
using namespace std;
/*

So the weight is Last Digit - First digit

Find no of N-digit positive numbers with weight W
N can be as high as 10^18
>> Make use of Fermat's Little theorem
	a^n = a (mod n).
	a^(n*q + r) = a^(n*q) * a^r = a^(q+r)
OR
>> Use the logn power function - https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/

|W| <= 300 ?! 
Actual limits-
9-1 = 8
0-9 = -9
  
  // Dn,D1
8 // 9,1 0 = 1
.
.
1 // 9,8 ... 2,1 = 8
0 // 9,9 ... 2,2, 1,1 = 9
-1 // 8,9 ... 0,1 = 9
-2 // 7,9 ... 0,2 = 8
.
.
-8 // 1,9, 0,8 = 2
-9 // 0,9 = 1

Note: The number is D1...Dn and not Dn...D1
i.e. 9>=D1>0 and 9>=Di>=0 for i>1
*/

/* Iterative Function to calculate (x^y)%p in O(log y) */
ll iter_power(ll x, ll y, ll p)
{
    ll res = 1;      // Initialize result
 
    x = x % p;  // Update x if it is more than or 
                // equal to p
 
    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;
 
        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;  
    }
    return res;
}

/* Function to calculate x raised to the power y in O(logn)
// overflow issues yet
int rec_power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = rec_power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
*/

int main()
{
	ll t,n,w,temp,c1,c2,ans;
	// if(!DPRINT_ALLOW) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n>>w;
		map <int,int> counts; //weight to no of digit pairs

		// counts are mirrored around 0-1
		for (int i = 0; i < 9; ++i){//counts[0] to counts[8]
			counts[i]= 9 - i;
		}
		for (int i = 1; i <= 9; ++i){//counts[-1] to counts[-9]
			counts[-1*i] = counts[i];
		}

		if( w < -9 || w > 8) cout<<0<<endl;
		else{
			cout<< ( (counts[w]*iter_power(10,n-2,MAX)) % MAX) <<endl;
		}
	}
	return 0;
}