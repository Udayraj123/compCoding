#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
using namespace std;

/*
So here in 1 round we have atmost 2 occurences of a recipe.
n judges and n recipies. 2n tastes total.
p no of rounds, sum of the ks will be n.
M1 -n even : cycle in chunks of two i.e.
eg n=6
p = n/2 
	Round 1 : judge 1 & 2 'cover' dishes 1 & 2. 3 & 4 cover 3 & 4 and so on.
	Round 2 : 1 & 2 cover 3 & 4 and 3 & 4 cover 5 & 6,5 & 6 cover 1 & 2.
	.. p rounds
	-n odd.
	p = n
	k = n each time.
	1 = 1 & 2
	2 = 2 & 3
	3 = 3 & 1
	
	1 = 2 & 3
	2 = 3 & 1
	3 = 1 & 2

	1 = 3 & 1
	2 = 1 & 2
	3 = 2 & 3
	This can be used for even no's as well!
	So, make two pointers. 
*/
	void solve(ll n){
//  n >= 2
		ll p=n,k = n;
		//no of rounds
		cout<<p<<endl;
		ll pt1;
		for (int i = 1; i <= p; ++i)
		{
			pt1=i;
			//for each round
			cout<<k<<endl;
			for (int j = 1; j <= k; ++j)
			{
				cout<<j<<" ";
				cout<<pt1<<" ";
				pt1 = (pt1+1) % k;
				pt1 = pt1==0?k:pt1; //cycle again.
				cout<<pt1<<endl;
			}
		}
	}

	int main()
	{
		ll t,n;
		cin>>t; while(t--){
			cin>>n;
			solve(n);
		}
		return 0;
	}
