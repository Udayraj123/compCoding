#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
#define FOR(x,n) for(int x = 0; x < n; ++x)

/*
So there's x,y for apples and bananas
To make everyone happy we'll first cover x-1 a's then y-1 b's, until we have only one kind left
e.g. x = 2, y = 3,  input = 5a's 10b's
	abbabbabbabbabb _/ kiwis = 0

*/
int main(int argc, char const *argv[])
{
	ll t=1,x=1,y=2,rem_x,rem_y;
	string s = "aaaaabb";
	// cin>>t; 
	while(t--){
		// cin>>s;
		// cin>>x>>y;
		map <char,int> counts;
		counts['a']=0;
		counts['b']=0;
		FOR(i,s.length()){
			counts[s[i]]++;
		}

// // first make it whole
		rem_x = counts['a'] % (x);
		rem_y = counts['b'] % (y);
		cout<< (string(rem_x,'a'))<<(string(rem_y,'b'));
		counts['a']-=rem_x;
		counts['b']-=rem_y;

		while(counts['a'] * counts['b'] > 0){
			cout<< (string(x-1,'a'))<<(string(y-1,'b'));
			counts['a']-=(x-1);
			counts['b']-=(y-1);
		}

		if(counts['b'] == 0){
			//use count/x kiwis if count > x;
			if((x-1)){
				FOR(i,counts['a']/(x-1)){
					cout<< (string(x-1,'a')) << '*';
					counts['a']-=(x-1);
				}
			}
			
			FOR(i,counts['a'])cout<<'a';
		}
// 		else{
// 			FOR(i,counts['b']/(y-1)){
// 				cout<< (string(y-1,'b')) << '*';
// 				counts['b']-=(y-1);
// 			}
		
// 			FOR(i,counts['b'])cout<<'b';
// 		}



	}
	return 0;
}

