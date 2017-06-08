#include <bits/stdc++.h> 
using namespace std;

int main(){
	int t = 1,n=5,m=2,t1,t2;
	cin>>t;
	while(t--){
		cin>>n>>m;
		while(m--){
			cin>>t1>>t2;
		}
		cout<<(n%2?"no":"yes")<<endl;
	}

	return 0;
}