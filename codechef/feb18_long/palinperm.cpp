#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef DEBUG_MODE
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
Condition for a palindrome string-
even number of all characters except for atmost one

1 ≤ n ≤ 10^5
s will consist only of lowercase English letters (i.e. characters 'a' through 'z')

*/



ll printHalf(ll i,ll start,string s,ll letterCount[]){
	ll counter = letterCount[i]/2;
	for (int pos = start; pos < s.size(); ++pos){
		if(counter==0){
			start=pos;
			break;
		}
		if(s[pos]==(char)('a'+i)){
			if(DEBUG_ON)cout<<(char)('a'+i);
			else cout << (pos+1) <<" ";
			counter--;
		}
	}
	return start;
}
void printIndex(ll i,string s,ll letterCount[]){
	/// aaabbbzzzozzzbbbaaa
	if(i==26){
		//middle one
		for (int i = 0; i < 26; ++i){
			if(letterCount[i]%2){
				// test case to check repeating pos
				for (int pos = s.size()-1; pos >=0 ; --pos){
					if(s[pos]==(char)('a'+i)){
						if(DEBUG_ON)cout<<(char)('a'+i);
						else cout << (pos+1) <<" ";
						break;
					}
				}
			}
		}
		return;
	}
	ll start=0;
	start = printHalf(i,start,s,letterCount);
	printIndex(i+1,s,letterCount);
	start = printHalf(i,start,s,letterCount);
}

int main()
{
	ll t,n,flag;
	// if(!DEBUG_ON) t = 1; else 
	cin>>t; 
	string s;
	while(t--){
		ll letterCount[26];
		cin>>s;
		n=s.size();

		for (int i = 0; i < 26; ++i)letterCount[i]=0;
			for (int i = 0; i < n; ++i){
				letterCount[s[i]-'a']++;
			}
			flag=0;
			for (int i = 0; i < 26; ++i){
				if(letterCount[i]%2){
					if(flag){
					//not a palin
						flag=-1;
						break;
					}
					else flag = 1;
				}
			}

			// Generate permutation
			// 26 * O(n) traverses
			// a recursive function to print index half times before recn and half after.
			if(flag != -1){
				printIndex(0,s,letterCount);
				cout<<endl;
			}
			else{
				cout<<"-1\n";
			}

		}
		return 0;
	}