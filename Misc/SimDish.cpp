#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

int main(int argc, char const *argv[])
{
	int t=1,n,numBits = 0;
	cin>>t; 
	while(t--){
		n=4;
		set <string> s;
		string temp;
		for (int i = 0; i < 4; ++i) {
			cin>>temp;	
			s.insert(temp);
		}
		int foundCount=0;
		for (int i = 0; i < 4; ++i) {
			cin>>temp;	
			set <string>::iterator it = s.find(temp);
			if(it != s.end())
				foundCount++;
		}
		cout<<((foundCount>=2)?"":"dis")<<"similar"<<endl;
	}
	return 0;
}

