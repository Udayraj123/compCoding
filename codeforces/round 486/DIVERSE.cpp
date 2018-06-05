#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<ll> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#include "../../getTime.h"
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif

#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}

#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*
sort, take k
bruteforce _//

*/
#define	MAX_Ai 1000

int main(){
	// http://codeforces.com/blog/entry/5217

	// Speeds up cin/cout- But now you can't mix printf and cout coz their order of flushing is changed.
	ios_base::sync_with_stdio(0);
	// Second optimisation: Effective when large no of inputs (when cin gets used too much)
	cin.tie(NULL);

	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif

	ll t;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	int n,k,count,temp;
	while(t--){
		cin>>n>>k;
		int s[n];
		std::vector<int> c;
		int flag;
		for(int i=0; i<n ; i++){
			cin>>temp;
			s[i]=temp;
			flag=0;
			for(int j=0; j<i ; j++)
				if(temp==s[j])
					flag=1;
			if(flag==0)
				c.push_back(i+1);
		}
		if(c.size() < k)
			cout<<"NO";
		else{
			cout<<"YES\n";
			for(int i=0; i<k ; i++)
				cout<<c[i]<<" ";
		}
		cout<<endl;

	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
