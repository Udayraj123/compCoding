#include<bits/stdc++.h>
#define ll int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);printf("\n");}
using namespace std;

/*

Contigous Subarray having Product == Sum
->
Note: n is max 50.
M1 -> make two matrices M[i][j] & S[i][j] 

1 1 1 1
0 1 1 1
0 0 1 1
0 0 0 1

*/

int main(int argc, char const *argv[]){
	ll t,temp,n,counter;
	cin>>t;
	while (t--){
		cin>>n;
		ll A[n],M[n][n],S[n][n];
		for (int i = 0; i < n; ++i){
			cin>>A[i];
			M[i][i]=A[i];
			S[i][i]=A[i];
		}
		counter = n;
		for (int i = 0; i < n; ++i){
			for (int j = i+1; j < n; ++j){
				M[i][j] = M[i][j-1] * A[j];
				S[i][j] = S[i][j-1] + A[j];
				if(S[i][j] == M[i][j]) 
					counter++;
			}
		}
		cout<<counter<<endl;
	}

	return 0;
}
