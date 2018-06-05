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
NUMBER OF indices pairs whose average is present in the sequence -
> Duplicates
> !Sum is Odd
Constraint: 
N <= 10^5
A <= 10^3

==> Make counts array
Do bruteforce check.
for counts > 1, ans += cC2 // duplicates
for counts > 0,

===> Getting TLE this way for n ~ 10^5
1.01 seconds is not actual execution, the process was killed after it exceeded : https://discuss.codechef.com/questions/22269/does-tle-mean-that-the-answer-was-correct-but-only-the-program-was-slow
=> N^2 not suff. make it NlogN or N
think of patterns 
> even numbers
> multiples of the avg
> pre-built sieve? nope.

DEMN, It's passing the vector by value!
changed	getCi(vi C,int i){
to   	getCi(vi &C,int i){

*/
#define	MAX_Ai 1000

int getCi(vi &C,int i){
	return C[MAX_Ai + i];
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

	ll t,n,temp,c1,c2,ans;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	ll NUM_NUMBERS=MAX_Ai*2+1;// |Ai| <= 10^3
	// NUM_NUMBERS-c-2 totalpairs
	while(t--){
		cin>>n;
		vi C(NUM_NUMBERS,0); // counts array of 2001 possible Ais
		ll MIN_Ai_in= MAX_Ai;
		ll MAX_Ai_in= -1*MAX_Ai;
		for (int i = 0; i < n; ++i){
			cin>>temp;
			C[ MAX_Ai + temp]++;
			MAX_Ai_in = max(MAX_Ai_in,temp);
			MIN_Ai_in = min(MIN_Ai_in,temp);
		}
		vector<int> pos_pos;
		for (int i = MIN_Ai_in; i <= MAX_Ai_in; ++i) {
			if(getCi(C,i)>0){
				pos_pos.push_back(i);
			}
		}
		ans=0;
		// 1 2 3
		int i,j;
		for(size_t i_idx = 0; i_idx != pos_pos.size(); i_idx++) {
			i = pos_pos[i_idx];
			c1 = getCi(C,i);
			//i==j case
			ans += (c1*(c1-1))/2;
			// dprintf("%ld) %d,%d : %d, %d\n",ans, i,i, c1,c1);

			for(std::vector<int>::size_type j_idx = i_idx+1; j_idx != pos_pos.size(); j_idx++) {
				j = pos_pos[j_idx];
				c2 = getCi(C,j);
				// numbers i and j (distinct) exist in A, and their sum is even, then check if their avg exists	
				if( (i+j)%2==0 && getCi(C,(i+j)/2) > 0 ){
					ans += c1*c2; // take one from c1, other from c2
				}
				// dprintf("%d] (%d,%d) : %d, %d\n",ans,i,j,c1,c2);
			}
		}
		cout<< ans <<endl;
	}

	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
