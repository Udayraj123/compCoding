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
100 strings of length max 100.
equal strings psble.


M1) group strings by length, then for each length find in its grp first, then in immediate next grp. If not, then print no
>> each grp shall have equal strings!
 DEV: Wrong Answer on test 13!
 -> bug was in substring function: overlapping mismatch and match!
 -> ab aab (when s2 has repeating part)
*/
#define	MAX_Ai 1000

bool is_substr(string s1,string s2){
	return s2.find(s1)!=string::npos;
	int l1=s1.length(), l2 = s2.length();
	if(l1>l2) return false;
	int j=0;
	for (int i = 0; i < l2; ++i) {
		if(j == l1) break;//matched early
		if(s1[j] == s2[i])
			j++;
		else{
			j=0;
		}
	}
	return (j==l1);
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
	int n,l,notFound;
	string temp,s,s1,s2;
	vector <string> strByLen (100);
	vector <int> counts(100);
	while(t--){
		cin>>n;
		for (int i = 0; i < 100; ++i){
			strByLen[i]="X";
			counts[i]=0;
		}
		notFound=0;
		for(int i=0; i<n ; i++){
			cin>>temp;
			l=temp.length()-1;
			s = strByLen[l];
			counts[l]++;
			if(s[0]!='X'){
				if(s!=temp)// diff strings of same length can't be substrings
					notFound=1;
			}
			else//new length
				strByLen[l] = temp;
		}

		for(l=0; notFound!=1 && l<100 ; ){
			while(l<100 && strByLen[l][0]=='X')l++;
			if(l==100)
				break;//reached end
			else
				s1=strByLen[l];
			l++;
			while(l<100 && strByLen[l][0]=='X')l++;
			if(l==100)
				break;//reached end
			else
				s2=strByLen[l];

			if(!is_substr(s1,s2)){
				notFound=1;
				break;
			}
		}

		if(notFound==0){
			cout<<"YES\n";
			for(int l=0; l<100 ; l++){
				while(counts[l]-- > 0)
					cout<< strByLen[l] <<endl;
			}
		}
		else
			cout<<"NO\n";
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
