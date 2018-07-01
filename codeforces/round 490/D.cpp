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

c[rem = 1] more than r -> check rem-1,rem+1
>> those who are equalized need not be disturbed. 
>> check greedy works? Seems like

>> for getting the array: Always the higher counts in c are decremented i.e. unique elements of a can be incremented

TLE > maintain a set or something now
>> Instead of emptying excess for each element, just put it in an excess[] array and use it when you reach to the needing element -> making it linear


*/
ll modulo(ll a,ll N){
	return (N+a%N)%N;
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
	ll n,m,r,temp,c,ans;
	pair<ll,ll> p;
	while(t--){
		cin>>n>>m;
		ll a[n];
		vector<ll>idxWithRem[m];

		for (int i = 0; i < n; ++i){
			cin>>a[i];
			idxWithRem[a[i]%m].push_back(i);//indices
		}
		r = n/m;// equal division guaranteed
		ans = 0;
		std::vector< pair<ll,ll> > fre;
		for (int i = 0; i < 2*m; ++i){
			c = i%m;
			while( idxWithRem[c].size() > r){
				temp = idxWithRem[c].back(); 
				fre.push_back( make_pair(temp,c) ) ;//i < m will cover this loop
				idxWithRem[c].pop_back(); 
			}
			while( idxWithRem[c].size() < r && !fre.empty()){
				p = fre.back(); fre.pop_back();
				idxWithRem[c].push_back(p.first);
				a[p.first] += modulo(c - p.second,m);//positive
				ans += modulo(c - p.second,m);
			}
		}
		cout<<ans<<endl;
		for (int i = 0; i < n; ++i)
			cout << a[i]<< " ";
		cout << endl;

	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
