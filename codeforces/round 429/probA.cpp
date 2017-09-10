#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset here.
#define ll long long int
using namespace std;
int main(){
	ll n,k,c,counts[26];
	// revised memset usage!
	memset(counts,0,26*sizeof(ll));
	cin>>n>>k;
	c=getchar();//newline
	for (int i = 0; i < n; ++i)
	{
		c=getchar()-'a';
		counts[c]++;
	}
	c=0;
	for (int i = 0; i < 26; ++i)
	{
		if(counts[i]>k){
			c=1;
			break;
		}
	}
	cout<<(c?"NO":"YES")<<endl;
	return 0;
}