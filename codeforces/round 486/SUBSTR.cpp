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
100 strings of length max 100.
equal strings psble

M1) group strings by length, then for each length find in its grp first, then in immediate next grp. If not, then print no
>> each grp shall have equal strings!
 DEV: Wrong Answer on test 13!
*/
#define	MAX_Ai 1000

bool is_substr(string s1,string s2){
	int l1=s1.length(), l2 = s2.length();
	if(l1>l2)return false;
	int j=0;
	for (int i = 0; i < l2; ++i) {
		if(j == l1) break;//early
		if(s1[j] == s2[i])
			j++;
		else
			j=0;
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
	int n,l,flag,notFound;
	string temp,s,s1,s2;
	while(t--){
		cin>>n;
		vector <string> strByLen (100, "X");
		vector <int> counts(100, 0);
		notFound=0;
		for(int i=0; i<n ; i++){
			cin>>temp;
			l=temp.length()-1;
			s = strByLen[l];
			if(s[0]!='X'){
				if(s!=temp)// diff strings of same length can't be substrings
					notFound=1;
				else
					counts[l]++;
			}
			else//new length
				strByLen[l] = temp;
		}

		for(int l=0; l<100 ; ){
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
				s = strByLen[l];
				if(s[0]!='X'){
					while(counts[l]-- >= 0)
						cout<< s <<endl;
				}
			}
		}
		else
			cout<<"NO\n";
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
