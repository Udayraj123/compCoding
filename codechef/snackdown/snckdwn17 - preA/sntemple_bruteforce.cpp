#include <bits/stdc++.h> //#include<bits/stdc++.h>// is cool one in c++ only, includes whatever required as need of the code.
#define ll long long int
#define MAX 10000000
#define print(x) printf("%d ",x);
#define printl(x) printf("%lld ",x);

using namespace std;

ll solve(ll n,ll *height){
	int breakMark;
	ll sum=0,diff,req,min_cost=MAX,h_i,h_req;
	for (int i = 0; i < n; ++i)
	{
		sum=0;
		breakMark=0;
		h_i=height[i];
		/* assume ith block is the highest one. */
		//shud reach 1 by the end
		h_req = min((int)i+1,(int)n-i);
		//clip it
		if(h_i > h_req){
			sum+=h_i - h_req;
			h_i = h_req;
		}
			//forward trav
		for (int r = 1; r < n-i; ++r)
		{
			req = (h_i - r)>0?(h_i - r):0;
			diff = height[i+r] - req ;
			if(diff<0){
				breakMark=1;
				break;
			}
			sum+=diff;
		}
			//backward trav
		if(!breakMark){

			for (int r = 1; r <= i; ++r)
			{
				req = (h_i - r)>0?(h_i - r):0;
				diff = height[i-r] - req ;
				if(diff<0){
					breakMark=1;
					break;
				}
				sum+=diff;
			}

		}
		if(!breakMark)
			min_cost = min(min_cost,sum);
	}
	return min_cost;
}

int main(){
	ll t = 1,n=5;
	cin>>t;
	char t1;
	while(t--){
		cin>>n;
		ll * heights = (ll*)malloc(sizeof(ll)*n);
		for (int i = 0; i < n; i++) {
			cin>>heights[i];
		}
		cout<<solve(n,heights)<<endl;

	}
	return 0;
}