#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#ifdef DEBUG_MODE
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
KMP on array of ints!

KMP is -
preprocess substr => make lps[] (len of longest proper prefix till i which is also a suffix of substr)
loop on main string - fallback on full match, fallback if psble or move on if mismatched,

*/
#define MAX_SIZE 200001
ll str[MAX_SIZE];
ll substr[MAX_SIZE];
ll lps[MAX_SIZE];
int n,m,temp,pre;

void preprocess(){
	int i=0,ptr=0;
	lps[i++]=ptr;
	while(i<m){
		if(substr[i] == substr[ptr]){
			ptr++;
		}
		else if(ptr){
			ptr=lps[ptr-1];
			continue;
		}
		lps[i++]=ptr;
	}
}

void kmp(){
	//
	int i=0,j=0,count=0;
	while(i<n){
		if(str[i]==substr[j]){
			i++;j++;
		}
		if(j==m){
			// cout << (i-j) <<".." << (i-1) <<endl;
			count++;
			j=lps[j-1];//fallback on full match
		}
		else if(i<n && str[i]!=substr[j]){
			//fallback on mismatch
			if(j)
				j=lps[j-1];
			else
				i++;
		}
	}
	cout <<count<<endl;

}


int main(){
	// http://codeforces.com/blog/entry/5217

	// Speeds up cin/cout- But now you can't mix printf and cout coz their order of flushing is changed.
	ios_base::sync_with_stdio(0);
	// Second optimisation: Effective when large no of inputs (when cin gets used too much)
	cin.tie(NULL);

	ll t;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		cin>>n>>m; 
		for (int i = 0; i < n; ++i){
			cin>>temp;
			if(i)
				str[i-1]= temp - pre;
			pre=temp;
		}
		for (int i = 0; i < m; ++i) {
			cin>>temp;
			if(i)
				substr[i-1]= temp - pre;
			pre=temp;
		}
		if(m==1) {
			cout<<n<<endl;
		}
		else{
			n--;m--;//difference arrays
			preprocess();
			kmp();
		}
	}
	return 0;
}
