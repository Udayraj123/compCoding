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
	int rainBow(vector< int > &A);
};
int Solution::rainBow(vector< int > &v) {
	int n,temp,flag=1;
	int flags[7];memset(flags,0,7);
	n = v.size();
	int mid=(n)/2;
	if (v[mid]!=7) return 0;

	for (int i = 0; i < mid; ++i){
		temp=v[i];
		if(temp>7 || temp<1 || (i>0 and temp<v[i-1]) || temp!=v[n-i-1]){
			flag=0;
			break;
		}
	}
	for (int i = 0; i <= mid; ++i)
		flags[v[i]-1]=1;

	for (int i = 0; i < 7; ++i)
		if(flags[i]==0)return 0;
	return flag;
}

int main()
{
	Solution s;
	int n,t,temp,flag;
	// int tmp[]={1,221,2113,3,45,5};
	// std::vector< int > v(tmp,tmp +ARRAY_SIZE(tmp));
	cin>>t;
	while(t--){
		std::vector< int > v;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>temp;			
			v.push_back(temp);
		}
		cout<< (s.rainBow(v)?"yes\n":"no\n");
	}

	return 0;
}
