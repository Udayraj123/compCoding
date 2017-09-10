#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
using namespace std;

/*
This one's a classic coin flip problem, min no of steps to make all coins with same face.
I remember it getting solved by greedy and probably recursion.
So, greedy would mean make the wrongs right immediately.
DDUUUDD -> 1 step for greedy.
DDUUUDDUUUDDUU -> 3 steps either way

DUDUDU -> DDUDD
*/


int main()
{
	ll t,n,counter;
	char t1,start,prev_t1;
	cin>>t; 
	string s;
	while(t--){
		cin>>s;
		n=s.length();
		counter=0;
		for (int i = 0; i < n; ++i)
		{
			t1=s[i];
			if(i==0){
				start= t1;
				prev_t1=t1;

			}
			if(t1 != prev_t1){
				counter += prev_t1==start;
			}

			prev_t1=t1;
		}
		cout<<counter<<endl;
	}
	return 0;
}
