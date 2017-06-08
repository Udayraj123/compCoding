#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

int main(int argc, char const *argv[])
{
	int t=1,n,numBits = 0;
	cin>>t; 
	while(t--){
		cin>>n;
		ll bi,temp=0,n1=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>bi; //Calc num of bits
			if(bi>0)n1++;//only such bi are decreasible
			temp += bi;
		}
		cout << ((temp-100)>=0 && (temp-100) < n1?"YES":"NO") <<endl;
	}
	return 0;
}

