#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
using namespace std;

class Solution
{
public:
	int pow(int x, int n, int d);
};

int mod(long int a, int b)
{
	int r = a % b;
	return r < 0 ? r + b : r;
}

int Solution::pow(int x, int n, int d) {
	if(n==1) return mod(x,d);
	if(n==0) return (x!=0);
	long int nodd = n%2?x:1;
    // 19 > 9 > 4 > 2 > 1 > 0
    // x * x2 * x16^ 1
	return mod(Solution::pow( mod( 	(long int)x*x 	,d), n/2,d) * nodd ,d);
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}

int main()
{
	Solution s;
	// int A = 71045970;
	// int B = 41535484;
	// int C = 64735492;
	int A=1000000,B=2,C=100;
	// cout << A << endl << A*A <<endl;
	cout<< s.pow(A,B,C)<<endl;
	return 0;
}
