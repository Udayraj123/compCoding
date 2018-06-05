#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
Mod seems short enough. Any short further? Some property that uses all the numbers?
*/
int main(int argc, char const *argv[])
{
ll t,a[4],flag;;
cin>>t; 
while(t--){
	for (int i = 0; i < 4; ++i)
		cin>>a[i];
	flag = 1;
	for (int i = 1; i < 4; ++i)
		if(a[i]==a[0])
			if(a[i%3+1]==a[(i+1)%3+1])
			{
				cout<<"YES\n";
				flag = 0;
				break;
			}
	if(flag)
		cout<<"NO\n";

}
	return 0;

}

