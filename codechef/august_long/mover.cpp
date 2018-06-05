#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
// utility macros-
#define print(x) printf("%d ",x);
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define printl(x) printf("%lld ",x);
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";

// #include<bits/stdc++.h>
// #include<numeric>
// numeric includes accumulate
using namespace std;

class Solution
{
public:
	ll mover(vector< ll > &A,ll d);
};
ll Solution::mover(vector< ll > &v,ll d) {
	ll meanALL,mean,sum;// = std::accumulate(v.begin(), v.end(), 0.0);
	ll n = v.size();
	sum = 0;
	for (ll i = 0; i < n; i++){
		sum+=v[i];
	}
	// if(floor(meanALL) != meanALL)return -1; //mean should be an lleger
	if(sum % n != 0)return -1; //mean should be an lleger
	meanALL = sum/n;
	
	ll ans =0,len,accdiff;
	for (ll j = 0; j < d; j++){
		sum = 0;len=0;accdiff=0;
		for (ll i = 0; i+j < n; i+=d){//in steps of d
			sum+=v[i+j];
			len++;
		}
		mean = sum / len;
		if(sum%len !=0 || mean!=meanALL)return -1;
		else{ 
			//calc gaps
			for (ll i = 0; i+j < n; i+=d){//in steps of d
				accdiff += v[i+j]-mean;
				ans+=  abs(accdiff);
			}
		}
	}
	return ans;
}


int main()
{
	Solution s;
	ll n=3,t=1,d=1,temp,step;
	// ll tmp[]={1,4,1};
	// std::vector< ll > v(tmp,tmp +ARRAY_SIZE(tmp));
	cin>>t;
	while(t--){
		std::vector< ll > v;
		cin>>n>>d;
		for (ll i = 0; i < n; ++i)
		{
			cin>>temp;			
			v.push_back(temp);
		}
		cout<< (s.mover(v,d)) <<endl;
	}

	return 0;
}
