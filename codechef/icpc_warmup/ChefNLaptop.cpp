#include<bits/stdc++.h>
#define ll int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);printf("\n");}
using namespace std;

/*

the unique min
*/

int main(int argc, char const *argv[]){
	ll t,temp,n;
	cin>>t;
	while (t--){
		cin>>n;
		ll mark[101],skip[101];
		// first mark the uniques
		for (int i = 0; i < 100; ++i)mark[i]=skip[i]=0;
		for (int i = 0; i < n; ++i){
			cin>>temp;
			if(mark[temp]==1)
				skip[temp]=1;
			mark[temp]=1;
		}
		for (int i = 1; i < 101; ++i)if(mark[i]!=0 && skip[i]==0){cout<<i<<endl;break;}
	}	

	return 0;
}
