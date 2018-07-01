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
divisible by 25 if it ends with 00,25,50 or 75
>> Take input as string- make arr of digits
Note that you can swap only adjacent digits in the given number.

Adjacent swaps 
=> for 1 digits it will take as much as the distance
51110
15110
11510
11150
=> for 2 digits minimal would be move the closest first.
512111
511211
511121
511112 //additional - only if they need cross
151112 
115112 
111512 
111152 
111125 //9

// because them crossing one another would add 1 swap
51211
15211
12511
15211

WA on test8 ==> after each move the number you have cannot contain any leading zeroes
-> But whats the counter example? : 50112
-> still WA8! -> 50267
-> WA23! -> 500111117
	
*/


int tryXY(string s, char p1,char p2){
// disallow first swap if 0 at 2nd place
// guaranteed that 1st num is not 0
	int pos1=0,pos2=0,l=s.length();
	for (int i = 1; i <= l ; ++i){
		if( !pos2 && s[l-i]==p2)pos2=i;
		if( !pos1 && pos2!=i && s[l-i]==p1)pos1=i;
	}
	int extracase = 0;
	if(l>1 && s[1]=='0' && pos2==l && p1!='0'){
		int e = 1;
		 //reach next nonzero
		while(e<l && s[e]=='0') e++;
		extracase = e-1;
	}
	if (!(pos1 && pos2))
		return -1;
	else if (pos1==1) return extracase + pos2 - 1;//one saved instead of additional
	else return (pos1 < pos2) + (pos1!=l-2 && extracase) + abs(pos1-2) + (pos2-1);
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
	int temp,temp2;
	string s;
	while(t--){
		cin>>s;
		temp = 100;//max swaps = 2*n-4 = 32
		temp2=tryXY(s,'0','0'); if(temp2>-1) temp=min(temp,temp2);
		temp2=tryXY(s,'2','5'); if(temp2>-1) temp=min(temp,temp2);
		temp2=tryXY(s,'5','0'); if(temp2>-1) temp=min(temp,temp2);
		temp2=tryXY(s,'7','5'); if(temp2>-1) temp=min(temp,temp2);
		cout<< (temp==100?-1:temp) <<endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
