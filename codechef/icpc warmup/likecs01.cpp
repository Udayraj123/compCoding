#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);printf("\n");}
using namespace std;

/*
Length os subseq > 1
26 iters.
maintain a min repeat index & max repeat index. (2 N-arrays extra)
O(n^2) -> choose the pair with overlapping intervals [m1,M1] & [m2,M2] -> m1,m2 & M1,M2 is the answer.

Completely diff subsequences not required! -> reduces to len(1)
*/

int main(int argc, char const *argv[])
{
ll t=1,n,k;
string s;
cin>>t;
while(t--){
	cin>>s;
	int counts[26];
	memset(counts, 0, 26*4);

	int flag=0,num;
	for (int i = 0; i < s.length(); ++i){
		num = s[i]-'a';
		if(counts[num]==1){
			flag=1;
			break;
		}
		else{
			counts[num]++;
		}
	}
	cout<<(flag?"yes":"no")<<endl;
}	

return 0;
}
