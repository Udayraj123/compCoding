#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef DEBUG_MODE
	#define DPRINT_ALLOW true
#else
	#define DPRINT_ALLOW false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(DPRINT_ALLOW){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(DPRINT_ALLOW){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*

[INCOMPLETE]

Number of pretty substrings <= nC2
-> those which can become a closed bracket seq. 

2 <= n <= 5000
=> answer is nonzero and

=> Recursiveness?

// func("((??))") = func("((??") + crossFunc("((??","))")+ func("))")


Test cases-
random -
????????
(()()())
))))((((
((??

thought-
??))
((??
))??

??(())

(??)
(?)) <--

--> qCount will not only compensate for negative count, it can for positives as well
--> NOTE: ')' immediately requires the judgement, if its negative, no need to scan further
--> after the last ')', qCount shud remain even
*/

bool isPretty(string subSignal){
	ll n = subSignal.size();
	if(n%2 == 1)return 0;
	else{
		ll breakFlag = 0, counter = 0,qCount = 0;
		for (int i = 0; !breakFlag && i < n; ++i)
		{
			switch(subSignal[i]){
				case '(':
				counter++;
				break;
				case ')':
				counter--;
				if(counter<0){
					// breakFlag breakout only if qCount cant help
					if(qCount==0){
						breakFlag=1;	
					}
					else{
						//revive
						qCount--;
						counter++;
					}
					// break;// redundant
				}
				break;
				case '?':
				// qCount can generate +qCount to -qCount in even steps
				if(counter>0)
					counter--;
				else
					qCount++;
				break;
				default:
				DEBUG("SHUD NOT REACH HERE");
				break;
			}
		}
		if(breakFlag==0 && counter==0 && qCount%2 == 0){
			return 1;
		}
		else{
			DEBUG(subSignal)
			return 0;
		} 
	}
}
ll calcCoordinate(string signal){
	DEBUG(signal);
	int n = signal.size();
	ll counter = 0;
	for (int i = 0; i < n-1; ++i){
		for (int j = i+2; j <= n; ++j)
		{
			counter += isPretty(signal.substr(i,j-i)); 
		}
	}
	return counter;
}

int main()
{
	ll t;
	if(!DPRINT_ALLOW) t = 1; else cin>>t; 
	while(t--){
		string signal;
		cin>>signal;
		cout<<calcCoordinate(signal)<<endl;
	}
	return 0;
}
/*
stack imple
bool isPretty(string subSignal){
	ll n = subSignal.size();
	if(n%2)return 0;
	else{
		vi myStack;
		ll flag = 1;
		for (int i = 0; i < n; ++i)
		{
			switch(subSignal[i]){
				case '(':
				myStack.push_back(1);
				case ')':
				if(myStack.empty() || (myStack.back()!=1)){
					flag = 0;
					break;
				}
				myStack.pop_back();
				break;
				case '?':
				// maintain some count
				break;
				default:
				DEBUG("SHUD NOT REACH HERE");
				break;
			}
		}
		if(flag && myStack.empty()){
			return 1;
		}
		else return 0;
	}
}

*/