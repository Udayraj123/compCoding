#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
#define	MAX_Ai 1000

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<int> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#define DPRINT_ALLOW true
#else
	#define DPRINT_ALLOW false
#endif

#define dprintf(...) if(DPRINT_ALLOW)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DPRINT_ALLOW){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(DPRINT_ALLOW){cout << ">> " << #x << " : " << (x) << endl;}

#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
using namespace std;
/*
NUMBER OF indices pairs whose average is present in the sequence -
> Duplicates
> !Sum is Odd
Constraint: 
N <= 10^5
A <= 10^3

==> Make counts array
Do bruteforce check.
for counts > 1, ans += cC2 // duplicates
for counts > 0,

3 
2 2 2
3 2 1 3 
6 4 2 5 1 3 5

*/
int getCi(vi C,int i){
	return C[MAX_Ai + i];
}

int main()
{
	int t,n,temp,c1,c2,ans;
	// if(!DPRINT_ALLOW) t = 1; else //codeforces line.
	cin>>t; 
	int num_numbers=MAX_Ai*2+1;// |Ai| <= 10^3
	// num_numbers-c-2 totalpairs
	while(t--){
		cin>>n;
		// vi A(n,0); //for indices
		vi C(num_numbers,0); // counts

		int MIN_Ai_in= MAX_Ai;
		int MAX_Ai_in=-1*MAX_Ai;
		for (int i = 0; i < n; ++i){
			cin>>temp;
			// A[i]=temp;
			MAX_Ai_in = max(MAX_Ai_in,temp);
			MIN_Ai_in = min(MIN_Ai_in,temp);
			C[ MAX_Ai + temp]++;
		}
		ans=0;
		// 1 2 3
		for (int i = MIN_Ai_in; i <= MAX_Ai_in; ++i) {
			c1 = getCi(C,i);
			if(c1 > 0){// i exists
				ans += (c1*(c1-1))/2;//i==j case
				dprintf("%d] (%d,%d) : %d, %d\n",ans,i,i,c1,c1);
				for (int j = i+1; j <= MAX_Ai_in; ++j) {
					c2 = getCi(C,j);
					// numbers i and j (distinct) exist in A, and their sum is even
					if( c2>0 && 
						(i+j)%2==0 && getCi(C,(i+j)/2) > 0 )
						ans += c1*c2; // take one from c1, other from c2
					dprintf("%d] (%d,%d) : %d, %d\n",ans,i,j,c1,c2);
			}
		}
	}
	cout<< ans <<endl;
}
return 0;
}