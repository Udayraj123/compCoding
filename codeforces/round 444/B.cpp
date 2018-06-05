#include<bits/stdc++.h>
#define ll int
#define MAX 100000
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);printf("\n");}
using namespace std;

/*
Sort each row
Adhoc for constraint - 1<= N <= 3
The union of remaining rows should cover 0-9

mark fill[i][1] for each input int.
if all fill[i][1] are 0, itd be clean


If union is covered, mark fill[n][2]=0 for each n in that row.
if not, put the highest covered int - h at that place.

Loop over fill[i][2] to get the answer i_h
if all fill[i][2] are 0,

look for 3 digits now. 

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
