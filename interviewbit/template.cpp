#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string  largestNumber(const vector<int > &A);
};

//
int digits(int n){
	if(!n)return 1;
	if(n<0)n*=-1;
	int c=0;
	while(n){c++;n/=10;};
	return c;
}
bool cmp(int a,int b){
/*same no of digits*/
	ostringstream s1,s2;
	s1<<a<<b;
	s2<<b<<a;
	return s1.str()>=s2.str();
}
string Solution::largestNumber(const vector<int> &A) {
	int n=A.size();
	std::vector<int> A2(A);
	sort(A2.begin(),A2.end(),cmp);
	ostringstream ans;
	int flag=0;
	for (int i = 0; i < n; ++i) {
		if(A2[i])flag=1;
		ans<<A2[i];
	}
	return  flag==0?"0":ans.str();  
}

int main()
{
	Solution s;
	int tmp[] = {0,1,9,0,0,0,0};
	// int tmp[] = {99,91,921,911,91};
	vector<int> A(tmp,tmp + sizeof(tmp)/4);
	// s.largestNumber(A);
	cout << s.largestNumber(A)<<endl;
	return 0;
}
