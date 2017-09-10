#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset here.
#define ll long long int
using namespace std;


/*
1 way to win is remove all elements
the parity is switched only by odd numbers
Game cannot run more than 3 moves\
if sum is odd, First wins.
if its even, 
	if all no's are even, Second player wins.
	else First player will try making the 
		sum odd i.e. there should be a odd no in the list
		then even player will try making it even sum again i.e. take this odd no away.

*/
		int main(){
			ll n;
			cin>>n;
			ll nums[n],sum=0,alleven=1;
			for (int i = 0; i < n; ++i)
			{
				cin>>nums[i];
				sum+=nums[i];
				alleven = alleven && (nums[i]%2==0);
			}
			string ans= alleven==1?"Second":"First";
			
			cout<<ans<<endl;
			return 0;
		}