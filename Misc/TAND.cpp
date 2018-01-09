#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;
#define maxn 300111

int n, a[maxn], res;

int calc(int pattern) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if ((pattern & a[i]) == pattern) cnt++;
	return cnt;
}

int main(int argc, char const *argv[])
{
	int t=1,n = 0;
// cin>>t;
	ll res;
	int betterNo,bitNo;
	while(t--){
		std::map<int,vector<int> > nBitNum;
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>a[i];	

		res = 0;
		for (int bit = 30; bit >= 0; bit--) {
			bitNo=(1 << bit);
			betterNo=(res | bitNo); // update ith bit
			if (calc(betterNo) >= 2){
		        res = betterNo; 
		        cout<<betterNo<<endl;
			}
		    //make ith bit one of the res(initially 0) if on doing that, that pattern on ANDing with two or more numbers gives the same pattern.
		}
		cout << res << endl;
	}
	
	return 0;
}

