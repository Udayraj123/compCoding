#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define vi vector<int> 
#define vii vector< vi > 
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*
Bruteforce: find 'ch' in string
*/
bool has(string sub,string orig){
	return orig.find(sub) != std::string::npos;
}
int main(int argc, char const *argv[])
{
	ll t=1,n,counter;
// cin>>t; 
	while(t--){
		cin>>n;
		string s;
		counter=0;
		for (int i = 0; i < n; ++i){
			cin>>s;
			if ( has("ch",s) || has("he",s) || has("ef",s)) {
				counter++;
			}
		}
		cout<<counter<<endl;

	}
	return 0;

}

