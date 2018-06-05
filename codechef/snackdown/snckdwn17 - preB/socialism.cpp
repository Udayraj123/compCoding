#include<bits/stdc++.h>
#define ll int
#define MAX 100000
#define print(x) printf("%d ",x);
#define printl(x) printf("%lld ",x);
#define printm(m,n,x) for (int i = 0; i < m; ++i){for (int j = 0; j < n; ++j)printf("%d ",x[i][j]);cout<<"\n";}
using namespace std;

/*
KiM from now on again -
fn(int n,void *x)
int (*mark)[n] = static_cast< int(*)[n] > (x);

*/

ll getn_hours(int m,int n, int** mark,int inicountmarks){
	ll hours=0;
	/*
		What matters is its max or not.
	*/
	int countmarks=inicountmarks,breakFlag=0,i1,j1;
	int marknext[m][n];
	while(countmarks!=m*n){
		hours++;
		for (int i = 0; i < m; ++i){
			for (int j = 0; j < n; ++j){
				marknext[i][j]=mark[i][j];
			// mark
				breakFlag=0;
				if(mark[i][j]!=1){
					for (int k1 = -1; k1 < 2; ++k1){
						for (int k2 = -1; k2 < 2; ++k2) {
							i1=i-k1;j1=j-k2;
							if( i1>= 0 && i1<m &&  j1>= 0 && j1<n ){
								if(mark[i1][j1]==1){
									countmarks++;
									marknext[i][j]=1;
									breakFlag=1;
									break;
								}
							}
							if(breakFlag)
								break;
						}
						if(breakFlag)
							break;
					}
				}
			}
		}
		//update after the iter
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				mark[i][j]=marknext[i][j];
	}
	return hours;
}

int main(int argc, char const *argv[])
{
	ll t=1,n=2,m=2,t1;
	cin>>t; 
	ll maxT=0,countmarks=0;
	while(t--){
		maxT=0;
		cin>>m>>n;
		ll s[m][n];
		// declare parsable 2d array
		int **mark = (int **)malloc(m * sizeof(int *));for (int i=0; i<m; i++)mark[i] = (int *)malloc(n * sizeof(int));

		for (int i = 0; i < m; ++i)//
			for (int j = 0; j < n; ++j){
				cin>>t1;
				s[i][j]=t1;
				maxT=max(maxT,t1);
			}
		countmarks=0;//
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j){
				mark[i][j]= (s[i][j]==maxT);
				countmarks += (s[i][j]==maxT);
			}
			cout<<getn_hours(m,n,mark,countmarks)<<endl;
		}

	return 0;//
}
