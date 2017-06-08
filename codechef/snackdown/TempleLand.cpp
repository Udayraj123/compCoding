	#include<bits/stdc++.h>
	#define ll long long int
	#define MAX 100000
	using namespace std;

	int main(int argc, char const *argv[])
	{
		ll t=1,n=10,mid=0,h=1,temp=0,flag=0;
		cin>>t; 
		while(t--){
			cin>>n;
			h=1; mid=(n-1)/2; flag=0;
			for(int i=0;i<n;i++){
				cin>>temp;
				if(n%2){
					if(h!=temp)flag=1;
					if(i<mid)h++;
					else h--;
				}
				else
					flag=1;//even lengths
			}
			cout<<((flag==0)?"yes":"no")<<endl;
		}
		return 0;
	}
