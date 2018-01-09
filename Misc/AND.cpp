#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

ll solve(int numBitsA[],int n,ll A[]){
	ll ans=0,temp;

	int maxNumBits=0;
	for (int i = 0; i < n; ++i) 
		maxNumBits = max(maxNumBits,numBitsA[i]);
	
	ll f[maxNumBits];
	memset(f,0,sizeof f);

	for (int i = 0; i < n; ++i) {
		//build f.
		temp = A[i];
		// cout<<A[i]<<" -> ";
		for (int j = 0; j < numBitsA[i]; ++j) {
			// cout<<(temp & 1);
			f[j] += (temp & 1); //ith bit
			temp = temp >> 1;
		}
		cout<<endl;
	}
	for (int j = 0; j < maxNumBits; ++j) {
		temp = f[j]*(f[j]-1)/2;
		temp = temp << j; // multiply by 2^i
		ans+=temp;
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	int t=1,n,numBits = 0;
	// cin>>t; 
	while(t--){
		cin>>n;
		int numBitsA[n];
		ll A[n],temp;
		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];	
				//Calc num of bits
			temp = A[i];
			numBits = 0;
			while(temp!=0){
				numBits++;
				temp >>= 1;
			}
			numBitsA[i]=numBits;
		}
		printf("%llu\n", solve(numBitsA,n,A));
	}
	return 0;
}

