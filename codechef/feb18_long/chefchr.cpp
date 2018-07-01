#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef DEBUG_MODE
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif


#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
Constraints
1 ≤ T ≤ 200,000
1 ≤ |s| ≤ 500,000
sum of |s| for all test cases ≤ 2,000,000
s contains only lowercase English letters

no of possible ways- check overlapping,
-> slide a 4-window
*/


void fill(int window[], char c){
	switch(c){
		case 'c':window[0]=1;break;
		case 'h':window[1]=1;break;
		case 'e':window[2]=1;break;
		case 'f':window[3]=1;break;
		default:window[4]=1;break;
	}
}
int main()
{
	ll t,n,flag,counter;
	// if(!DEBUG_ON) t = 1; else 
	cin>>t; 
	string sentence;
	while(t--){
		int window[5];
		cin>>sentence;
		n=sentence.size();
		
		counter=0;
		for (int i = 0; i < n-3; ++i){
			//slide the window.

			for (int j = 0; j < 4; ++j)
				window[j]=0;
			
			for (int j = 0; j < 4; ++j)
				fill(window,sentence[i+j]);
			
			flag=1;
			for (int j = 0; j < 4; ++j){
				if(window[j]==0)
					flag=0;
			}
			counter+=flag;
		}
		if(counter)
			cout<<"lovely "<<counter<<endl;
		else
			cout<<"normal\n";

	}
	return 0;
}