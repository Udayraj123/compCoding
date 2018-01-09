#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define vi vector<ll> 
#define vii vector< vi > 
#define DEBUG(x) cout << " << " << #x << " : " << (x) << endl;
using namespace std;
const long long INF = 1e18 + 42;
//  There is a foreach in C++ 
// C++11 and higher
std::for_each(vector.begin(), vector.end(), [&] (int n) {
    sum_of_elems += n;
});

sum_of_elems = std::accumulate(a.begin(), a.end(), 0);// using 0.0 will output float sum



// Concating vectors
	vi a,b;
	b.insert(b.end(), a.begin(), a.end());


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

XOR pattern	- KiM : XoR upto n consecutive numbers = period of 4
1 = 1
1^2 = 3
1^2^3 = 0
1^2^3^4 = 4
1^2^3^4^5 = 1
1^2^3^4^5^6 = 7
1^2^3^4^5^6^7 = 0
1^2^3^4^5^6^7^8 = 8
1^2^3^4^5^6^7^8^9 = 1
1^2^3^4^5^6^7^8^9^10 = 11
1^2^3^4^5^6^7^8^9^10^11 = 0
1^2^3^4^5^6^7^8^9^10^11^12 = 12
1^2^3^4^5^6^7^8^9^10^11^12^13 = 1
1^2^3^4^5^6^7^8^9^10^11^12^13^14 = 15
1^2^3^4^5^6^7^8^9^10^11^12^13^14^15 = 0

Anti-XOR is same as XoR i.e. A^X = B => X = A^B