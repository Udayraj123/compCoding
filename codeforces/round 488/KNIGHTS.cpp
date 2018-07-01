#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

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

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*
sort by power!
IN PROGRESS! TLE at 52
>> There's no need to keep the k-sized array sorted. Just know the one with minimum coins!
*/
#define	MAX_Ai 1000

ll index( pair< int, pair <ll,int> > d){
	return d.second.second;
}
ll coins( pair< int, pair <int,int> > d){
	return d.second.first;
}

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
	ll n,k,temp,sum, minCoinIdx,c;
	while(t--){
		set <int> `(k);
		cin>>n>>k; k++;//adjust
		vector < pair< int, pair <int,int> > > data(n);
		ll reorder[n];
		for (int i = 0; i < n; ++i){
			cin>>data[i].first;//power
		}
		for (int i = 0; i < n; ++i){
			cin>>data[i].second.first;//coins
			data[i].second.second=i;
		}
		sort(data.begin(),data.end());// by power ASC
		for (int i = 0; i < n; ++i){
			c=coins(data[i]);
			if(kMaxCoins.size()<k){
				kMaxCoins.add(c);
			}
			else{
				if(c > kMaxCoins.min()){
					kMaxCoins.removemin();
					kMaxCoins.add(c);
				}
			}
			reorder[index(data[i])]=kMaxCoins.sum();
		}

		for (int i = 0; i < n; ++i)
			cout<< reorder[i] << " ";
		cout<<endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
