#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
#define FOR(x,n) for(int x = 0; x < n; ++x)

/*
So there's x,y for apples and bananas

To make everyone happy we'll first cover x a's then y b's, until we have only one kind left
^Wrong logic. check this case with x=2=y 
> aabbaabbaa*aa*aa
> aabaabaabaabaa
-- choose one with least counts as a separator X
-> Construct iteratively 
	> first do abababab
	> then if x>1, add another layer of a's to make aabaabaabab (for 7 a's)
	>> if we have ababaa, first make 'ab' chunks of minCount(a,b), then iterate the remaining character
	>> If still left (more than minCount*x  if a, minCount*y if b ) , add them to the end with kiwis
	>> if less, then fill full from left.
>> The end of the string acts like a kiwi
*/
int main(int argc, char const *argv[])
{
	ll t=1,x=1,y=2,temp,nA,nB,fulFills,fulFillRem;
	char a,b;
	string s = "aaaabbbb";
	cin>>t; 
	while(t--){
		cin>>s;
		cin>>x>>y;
		map <char,int> counts;
		counts['a']=0;
		counts['b']=0;
		FOR(i,s.length()){
			counts[s[i]]++;
		}

/*
M1 (assume a is max, similar for b) -  
	compare (a-b)/x with b,
	if less : 
		print x a's and 1 b's for (a-b)/x times, 
		next (a-b)%x a's and (a-b)%x!=0) b's
		then b-(a-b)/x times 'ab'
		no of b's = (a-b)/x + ((a-b)%x!=0) + b - (a-b)/x = b
	if more :  // we'd need kiwis too
		print x a's and 1 b's for (b) times, 
		then a-b/x times kiwi pattern, then a-b%x a's if any, else drop the last kiwi


^^ Failing 2/3 cases!

*/
		a='a';b='b';
		if (counts['a'] < counts['b']){ // a shud be bigger one
			a = 'b';b = 'a';
			temp = y;
			y=x;
			x=temp;
		}

		nA = counts[a]; // 5
		nB = counts[b]; // 2
// abab, aaa
// aabaab, a
// aabaaba


		if(nA >= nB*x){
			for (int i = 0; i < nB; ++i) // aabaab
				cout <<  string(x,a) <<  string(1,b);
			fulFills = (nA - nB * x)/x;
			fulFillRem = (nA - nB * x)%x;
			//kiwi pattern
			for (int i = 0; i < (fulFills - 1); ++i)
				cout <<  string(x,a) <<  string(1,'*');
				if(fulFills)
					cout<< string(x,a);
				if(  fulFillRem != 0 )
					cout<<(fulFills?"*":"") <<  string(fulFillRem,a);
				// cout<<endl<< string(nA,a)<< string(nB,b);
		}
		else{
			fulFills = (nA-nB)/(x-1);
			fulFillRem = (nA-nB)%(x-1);
			for (int i = 0; i < fulFills; ++i)
				cout << string(x,a) << string(1,b);
			if(fulFillRem)
				cout << string(fulFillRem,a)<<string(1,b);
			for (int i = 0; i < (nB - fulFills - (fulFillRem?1:0)); ++i)
				cout << a << b;
		}
		cout <<endl;
	}
	return 0;
}

