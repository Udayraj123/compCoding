#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

int main(int argc, char const *argv[])
{
	ll t=1,n=10;
	cin>>t; 
	while(t--){
		cin>>n;
		string s;
		cin>>s;
		int flag=0;
		int Hcame=0;
		for (int i = 0; i < n; ++i)
		{
			switch(s[i]){
				case '.':
				break;
				case 'H':
				if(Hcame==1){
					flag=1; //invalid move detected
					break;
				}
				Hcame=1;
				break;
				case 'T':
				if(Hcame==0){
					flag=1; //invalid move detected
					break;
				}
				Hcame=0;
				break;
				default:
				cout<<"wrong input"<<endl;
				break;
			}
		}
		cout<<((Hcame==0 && flag==0)?"Valid":"Invalid")<<endl;
	}
	return 0;
}
