#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
// utility macros-
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define print(x) printf("%d ",x);
#define printl(x) printf("%lld ",x);
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");

using namespace std;

class Solution
{
public:
	int search(vector<int > &A, int B);
};
int mod(long int a,int b){
	int r = a % b;
	return r>0?r:r+b;
}
int binS(int s,int e,int n,vector <int> A,int B){
    //assume A is sorted
	if(s==e){
		if(A[s]==B)return s;
		else return -1;
	}
	int mid = mod((s+e)/2,n);
	print(mid)
	if(A[mid] == B)return mid;
	if(A[mid] < B)return binS(mod((mid+1),n),e,n,A,B);
	else return binS(s,mod((mid-1),n),n,A,B);
}

int Solution::search(vector<int > &A, int B) {
	// The minimum lies in the first col
	// The next min will be in that row, or in first col & so on.
	// sort the rows by first col?
	// first get the column in which the number lies.
	int n =A.size();
	int start = 0;
	for (int i = 0; i < n; ++i)
	{
		if (A[start] > A[i])
			start = i ;//grab the first min
	}
	return binS(start, mod((start-1),n),n,A,B);
}

int main()
{
	Solution s;
	// int B = 4;
	// int tmp[] = {5,6,1,2,3,4};
	int B = 202;
	// 19 numbers, start = 10, end = 9.
	int tmp[] = {101, 103, 106, 109, 158, 164, 182, 187, 202, 205, 2, 3, 32, 57, 69, 74, 81, 99, 100};
	vector<int> A(tmp,tmp + ARRAY_SIZE(tmp));
	cout<<s.search(A,B)<<endl;
	// M1 - rotate the array back.
	// Any shorter way?
	// rotation wont affect things modulo, just need to pass in 
	// shift pointers start = index of min(A), end = (start + 1) % N
	return 0;
}
