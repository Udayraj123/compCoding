#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
#define	MAX_Ai 1000

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<int> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif

#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<(x)[i]<<"\t";cout<<"\n";}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;
/*
inputs
s n

> t = repeat s n times 
|t|<= (|s|<=10^3)*(|n|<=10^9)

Count the number of non-empty prefixes of t which contain more a-s than b-s

Bruteforce(10^12 here): write accum_sum on t; scan |s|*n wherever num is positive.

--> repeat s two times to see the pattern.
when sum < 0, all terms of accum_sum will be reduced by sum in next iter.
so sum(positives/-1*sum) will be total capped by n;
when sum > 0, |s|*n - sum(-1*negatives/sum)

--> Can make use of vector to contain negative accum_sum pos's.

WA was because of taking ans as int, be careful about that.
And this-
changed	ans+= min(n, accum_sum[*i]/abs(sum) + (accum_sum[*i]%abs(sum)) );
to		ans+= min(n, accum_sum[*i]/abs(sum) + (accum_sum[*i]%abs(sum) ? 1 : 0) );


3
aba 2
baa 3
bba 3

aaaaaabbbbbbbb 2
aaaaaabbbbbbbb aaaaaabbbbbbbb
6 + 4
*/

int main()
{
	ll t,n,temp,l,sum,ans;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	string s;
	while(t--){
		cin>>s>>n;
		l = s.length();
		vi accum_sum (l,0);
		std::vector<int> non_positives;
		std::vector<int> positives;
		sum=0;
		for (int i = 0; i < l; ++i){
			s[i % l]=='a'?sum++:sum--;
			accum_sum[i]=sum;
			if(sum>0){
				positives.push_back(i);
			}
			else{
				non_positives.push_back(i);
			}
		}
		DEBUGA(accum_sum,l);
		DEBUGV(positives);
		DEBUGV(non_positives);	
		ans=0;
		if(sum>0){
			// 1 0 -10 -8 4

			//the periodic ones 
			ans += positives.size()*n;
			// the rejunevated ones
			for(std::vector<int>::iterator i = non_positives.begin();i!=non_positives.end();i++)
				ans+= max((ll)0,n - (abs(accum_sum[*i])/sum + 1));
		}
		else if (sum==0){
			//the periodic ones only
			ans += positives.size()*n;
		}
		else{
			// 1 2 3 4 5 6 5 4 3 2 1 0 -1 -2 
			// Till they die (if any)
			for(std::vector<int>::iterator i = positives.begin();i!=positives.end();i++){
				ans+= min(n, accum_sum[*i]/abs(sum) + (accum_sum[*i]%abs(sum) ? 1 : 0) );
				DEBUG(ans);
			}
		}
		cout<< ans <<endl;
	}
	return 0;
}