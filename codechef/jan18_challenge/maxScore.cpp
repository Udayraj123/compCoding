#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define vi vector<int> 
#define vii vector< vi > 
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
Pick a number E(i) from each of the N sequences such that E(i) > E(i-1)
OUTPUT ONLY THE SUM OF SUCH Ei

M1)Sort all Rows or make a function pickNextMax, start from Nth row, add the rightmost num which is strictly less than prev, if no nums left, return -1
Corner cases - N=1 shud output the same no

*/
int main(int argc, char const *argv[])
{
ll t,n;
cin>>t; 
while(t--){
	cin>>n;
	if(n==1){
		cin>>n;
		cout<<n<<endl;
		continue;
	}
	vi b(n,0);
	vii a(n,b);
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j)
			cin>>a[i][j];
		sort(a[i].begin(),a[i].end());
	}

	ll prev = a[n-1][n-1] + 1,sum=0,flag=0;
	
	for (int i = n-1; i >= 0; --i){
		if(flag == 0){
			for (int j = n-1; j >= 0; --j){
				if(a[i][j] < prev){
					prev = a[i][j];
					sum += prev;
					break;
				}
				else if(j==0){
					flag = 1;
					//break; //redundant tho
				}
			}
		}
		else{
			break;
		}
	}
		cout<<(flag?-1:sum)<<endl;

}
	return 0;

}

