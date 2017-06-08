#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

void rev_binary(ll temp){
	do{
		cout<<(temp & 1);
		temp >>= 1;
	}while(temp!=0);
}

int main(int argc, char const *argv[])
{
	ll t=1,n=4,pos1,pos2,type=0;
	cin>>n>>t; 
	ll notter=0,zero[n];
	memset(zero,0,sizeof zero);

	while(t--){
		cin>>type>>pos1>>pos2;
		if(type==0){
			for (int i = pos1; i <= pos2; ++i) {
				zero[i] = !zero[i];
				// cout << zero[i];
			}
			// cout<<endl;

		}
		else{
			notter = 0;
			for (int i = pos1; i <= pos2; ++i) {
				// cout << zero[i];
				notter += zero[i];
			}
			// cout<<" : ";
			cout<<notter<<endl;
		}
	}
	return 0;
}

/*
Shifting - Works For smaller numbers-

ll t=1,n=4,pos1,pos2,type=0,bitNo,temp;
ll notter=0,zero=0;
cin>>n>>t; 
while(t--){
	cin>>type>>pos1>>pos2;
	if(type==0){
	// 2^diff -1
		notter = (1<<(pos2-pos1+1))-1; 
		notter <<= pos1;
		// rev_binary(zero); cout << " XOR "; rev_binary(notter); cout << " = ";
		zero = zero ^ notter;
		// rev_binary(zero); cout<<endl;
	}
	else{
		bitNo = 0;
		notter =0;
		// rev_binary(zero);
		temp=zero >> pos1;
		while(temp!=0){
			if(bitNo > (pos2-pos1) )
				break;
			notter += (temp & 1);
			bitNo++;
			temp >>= 1;
		}
		cout<<notter<<endl;
	}
}


*/
