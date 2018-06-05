#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
Due to negative numbers, the answer can't be the whole set's happiness.
First collect the nonnegatives together. Then add negatives*1
*/
int main(int argc, char const *argv[])
{
	ll t=100,t1,n=1,hp=0,p=0,countn=0,negs;
	cin>>t; 
	while(t--){
		cin>>n;
		p=0;
		countn=0;
		hp=0;
		std::vector<ll> hn;
		for (int i = 0; i < n; ++i)
		{
			cin>>t1;
			if(t1>=0){
				hp+=t1;
				p++;
			}
			else{
				hn.push_back(t1);
				countn++;
			}
		}
		negs = 0;
		sort(hn.begin(),hn.end());
		for (int i = countn-1; i >=0 ; --i)
		{
			if((hp+hn[i])*(p+1) > hp*p){
				// 8 * 7 > 10 * 5
				hp+=hn[i];p+=1;
				//updating it immediately 
			}
			else{
				//negs * 1
				negs+=hn[i];
			}
		}
		cout<<(negs+hp*p)<<endl;

	}
	return 0;
}

