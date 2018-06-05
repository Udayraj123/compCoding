#include<bits/stdc++.h>
#define ll int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);printf("\n");}
using namespace std;

/*
div by 64 == 1000000
=> having length >= 7, starting from leftmost 1
*/
int main(int argc, char const *argv[])
{
	ll t=0;
	cin>>t;
	string s;
	while (t--){
		cin>>s;
		start = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i]==1){
				cout<< (((s.length() - i)>=7)?"yes":"no")<<endl;
				break;
			}
		}

	}	

	return 0;
}
