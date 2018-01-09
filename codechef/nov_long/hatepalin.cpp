#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*

Longest palin substring = L,
give a string s consisting of first A letters, which minimizes the L,
aaababb
aababb

N = 8 A = 2
aaaabbbb /4
aaababbb /3

N = 9 A = 2
trivi = aaaaabbbb
compr1= aaaababbb
compr2= aaababbaa /3

N = 11 A = 2
trivi = aaaaaabbbbb /6
compr1= aaaaababbbb /5
compr2= aabbabaabbb /4
compr3= aaababbaaba /4

N = 13 A = 2
trivi = aaaaaaabbbbbb /7
compr1= aaaaaababbbbb /6
compr2= aaabbabababbb /5
compr3= aaababbaababb /4


*/



int main(int argc, char const *argv[])
{
	ll t=1,n,a;
	cin>>t; 
	string keyPattern = "abaabb";
	ll keyL = keyPattern.length();
	while(t--){
		cin>>n>>a;
		if(a==2){
			switch(n){
				case 1: cout<<"1 a";break;
				case 2: cout<<"1 ab";break;
				case 3: cout<<"2 aab";break;
				case 4: cout<<"2 aabb";break;
				case 5: cout<<"3 aaabb";break;
				case 6: cout<<"3 aaabbb";break;
				case 7: cout<<"3 aaababb";break;
				case 8: cout<<"3 aaababbb";break;
				default: cout<<"4 ";for (int i = 0; i < n; ++i) cout<<keyPattern[i%keyL];break;
			}
		}
		else{
			cout<< ((a==1)?n:1) << " ";
			for (int i = 0; i < n; ++i)
				cout<< ((char) (('a' + i%a)));
		}
		cout<<endl;
		
		}
	return 0;
}

