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

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*
k sequences
output indices i, j of sequences off which indices x,y be removed to obtain same sum.
>> sum of lengths of all given sequences don't exceed 2⋅10^5
>> store sum of k seqs.
>> store sumWithoutMe for each input seq.
>> sort them rows of sumWithoutMe
>> find two

M2)
>> sort all the numbers together keeping seqno paired withem

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
	ll n,k,temp,sum,flag;
	pair<int,  pair<int,int> > curr,next;
	while(t--){
		cin>>k;
		std::vector< pair<int,  pair<int,int> > > allnums;
		for (int i = 0; i < k; ++i){
			cin>>n;
			sum=0;
			int temp_arr[n];
			for (int j = 0; j < n; ++j){
				cin>>temp;
				temp_arr[j] = temp;				
				sum+=temp;
			}
			for (int j = 0; j < n; ++j){
				allnums.push_back(make_pair(sum - temp_arr[j],make_pair(i + 1, j+1)));
			}
		}
		sort(allnums.begin(),allnums.end());//default is via first key
		flag = 0;
		for (int i = 0; i < allnums.size()-1; ++i){
			curr=allnums[i];
			next=allnums[i+1];
			if(curr.first==next.first && curr.second.first !=next.second.first ){
				flag = 1;
				cout<<"YES\n";
				cout<< curr.second.first << " " << curr.second.second<<endl;
				cout<< next.second.first << " " << next.second.second<<endl;
				break;
			}
		}
		if(flag==0)cout<<"NO\n";
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
