#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*
A..B..B..A -> 2 4
prev_char......curr_char


*/
int main(int argc, char const *argv[])
{
	ll t=1,counter;
	cin>>t; 
	string s;
	char prev_char;
	std::map<char, int> counts;
	while(t--){
		cin>>s;
		counter = 0;
		prev_char = '\0';
		counts['A']=0;
		counts['B']=0;
		for (int i = 0; i < s.length(); ++i)
		{
			if(s[i]=='.'){
				if(prev_char == '\0')
					continue; //neglect starting dots
				else 
					counter++;
			}
			else {
				counts[s[i]]++; // add the existing A & B separately
				if(prev_char == s[i]){
					counts[s[i]]+=counter;
				}
				counter = 0;

				prev_char=s[i];
			}
		}
		cout << counts['A'] << " " << counts['B'] <<endl;

	}
	return 0;
}

