#include <bits/stdc++.h>
 
#define ll long long int
#define ld long double
 
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(v) (v).begin(),(v).end()
 
using namespace std;
///////////////////////////////////////////////////////
 
#define mod 1000000007


/*
Generate an array with size N, with std dev k, having 1 <= N,k <=10^5
	
	N * k^2 = sum((Ai - Mean)^2)
** array elements are real numbers.
so k^2 * N 
N = even => make all Ai = mean +/- k, so 10^8 > mean > k
N = odd => float
	N = 1 -> corner
*/


int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);    cout.tie(NULL);
    
ll t,n;
ld k,Mean,Ai;
cin>>t;
cout<<std::setprecision(15);
while(t--){
	cin>>n>>k;
	if(n==1)
		cout << ((k==0)?"0":"-1")<<endl;
	else{
		if(n%2==0){ //even case
			Mean = 0; 
			for (int i = 0; i < n/2; ++i)
				cout<<(Mean-k)<< " "<<(Mean+k)<< " ";
			cout<<endl;
		}
		else{//odd case
			Ai = k * sqrt((ld)n/(ld)2);
			for (int i = 0; i < n-2; ++i)
				cout<<"0 ";
			cout<< (Ai)<<" "<< (-1*Ai)<<endl;
		}
	}
}

    return 0;
} 