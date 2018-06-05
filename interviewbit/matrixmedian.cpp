#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
// utility macros-
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define print(x) printf("%d ",x);
#define printl(x) printf("%lld ",x);
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";

using namespace std;

class Solution
{
public:
	int findMedian(vector<vector<int> > &A);
};
int Solution::findMedian(vector<vector<int> > &A) {
	int medianpos = (A[0].size()*A.size()+1)/2;
	// The minimum lies in the first col
	// The next min will be in that row, or in first col & so on.
	// sort the rows by first col?
	// first get the column in which the number lies.
/*

1 	2	3
 	  3	  7	  9
  	   4   5   6

shud be better than QS method
*/
}

int main()
{
	Solution s;
	int tmp[] = {1,2,3,4,5,6};
	vector<int> A(tmp,tmp + ARRAY_SIZE(tmp));
	std::vector< vector<int> > v;
	v.push_back(A);
	v.push_back(A);
	printa(A,A.size());
	return 0;
}
