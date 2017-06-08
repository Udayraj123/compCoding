#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

int getNoBits(ll temp){
	int numBits=0;
	while(temp!=0){
		numBits++;
		temp >>= 1;
	}
	return numBits;
}

ll getReversed(ll temp){
	ll revNo=0;
	while(temp!=0){
		revNo <<= 1;
		revNo+=(temp&1); //shift left the last bit of temp
		temp >>= 1;
	}
	return revNo;
}
int getNthTopBit(int i,ll temp){
	int bit2=0;
	while((temp >> i)!=0){
		bit2 = (temp & 1);
		temp >>= 1;
	}
	return bit2;
}

ll solve(std::map<int,vector<int> > nBitNum,int maxNumBits,int n,ll A[]){
	ll ans=9,temp,num;
	int numBits,bit2;
	//get the MSB that can be 1
	for (numBits = maxNumBits; numBits > 0 ; --numBits){
		//2 ,1 
		if(nBitNum[numBits].size()>=2){ //2,2,2,3,3
			if(nBitNum[numBits].size()==2)
				return nBitNum[numBits][0] & nBitNum[numBits][1];
			else
				break;
		}

	}
	int bestBitNo = numBits;//2
	vector <int> v = nBitNum[bestBitNo];

	//2,2,2,3,3
	int k = 2;
	while(v.size()>2){
		//IN next loop the numbers should get checked for next bit
		// cout<<v[0]<<" n"<<v.size()<<endl;
		vector <int> NthBitzero;
		vector <int> NthBitone;
		//Filter - 
		for(int i = 0; i < v.size(); i++) {
			num = v[i];
			// check next bit- (ineff now)
			bit2 = getNthTopBit(k,v[i]);

			if (1==(bit2 & 1)){
				NthBitone.push_back(num);
			}	
			else{
				NthBitzero.push_back(num);
			}
		}
		
		v=(NthBitone.size()<2)?NthBitone:NthBitzero;
		if (v.size()==2){
			return v[0] & v[1];
		}
		k++;
	}

	// If there are only 2 nums, return their and.
	ans=v[0] & v[1];//two single bits maybe	
	return ans;
}
int main(int argc, char const *argv[])
{
	int t=1,n = 0;
	// cin>>t; 
	// std::map<int,vector<int> > nBitNum2;
	// nBitNum2[0].push_back(15);
	// nBitNum2[1].push_back(15);
	// nBitNum2[1].push_back(152);
	// cout << nBitNum2[1][1]<<endl;
	// cout<<nBitNum2[1].size();
	// return 0;

	while(t--){
		std::map<int,vector<int> > nBitNum;
		cin>>n;
		ll A[n],rev;
		// pair<int,vector<int> > p;
		int maxNumBits=0,numBits=0;

		for (int i = 0; i < n; ++i)
		{
			cin>>A[i];	
			//Calc num of bits
			numBits=getNoBits(A[i]);
			maxNumBits = max(maxNumBits,numBits);
			//automatically creates the index if it doesn't exist
			nBitNum[numBits].push_back(A[i]); 
		}

		printf("%llu\n", solve(nBitNum,maxNumBits,n,A));
	}
	return 0;
}

