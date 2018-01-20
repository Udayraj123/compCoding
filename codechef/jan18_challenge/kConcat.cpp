#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000001
 
#define vi vector<ll> 
#define vii vector< vi > 

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
	#define ONLINE_JUDGE_DEF true
#else
	#define ONLINE_JUDGE_DEF false
#endif
 
 
#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
	maximum sum subarray  -> NxN DP? Nope, Linear DP! using sumUpto, minTill & maxFrom.
	Here run the above on [A,A]. And if sum(A)>0, add (K-2)*sum(A) to the Total.
	Corner cases - 
 
	Single elements having max sum
	A = -9 -9 -1 
 
	Single size array
	A = -1
 
 
*/
 
ll maxSumSubOf(vi a){
	ll n = a.size();
	if (n==1) return a[0];
 
	vi sumUpto(n),minTill(n),maxFrom(n);
	sumUpto[0]=a[0];
 
	for (int i = 0; i < n-1; ++i)
		sumUpto[i+1] = sumUpto[i]+a[i+1];

	DEBUGA(a,n)
	DEBUGA(sumUpto,n)

	ll maxNum = sumUpto[n-1];
	for (int i = n-1; i >= 0; --i){
		maxFrom[i] = maxNum;
		if(sumUpto[i] > maxNum ){
			maxNum = sumUpto[i];
		}
	}
 
	ll minNum = 0;//sumUpto[0];
	for (int i = 0; i < n; ++i){
		minTill[i] = minNudm;
		if(sumUpto[i] < minNum ){
			minNum = sumUpto[i];
		}
	}
	minTill[0]=0;

	DEBUGA(maxFrom,n);
	DEBUGA(minTill,n);
 	
	ll maxSum = sumUpto[0];//first element
	for (int i = 0; i < n; ++i){
		maxSum = max(maxSum, maxFrom[i] - minTill[i]);
	}
	DEBUG(maxSum)
	return maxSum; // mp(maxIndex,minIndex)
}
 
int main(int argc, char const *argv[])
{
ll t,n,k,clippedSum,maxSumSingle,maxSumDouble;
cin>>t; 
while(t--){
	cin>>n>>k;
	vi a(n,0);
	for (int i = 0; i < n; ++i)
		cin>>a[i];
	
	clippedSum = max(0,std::accumulate(a.begin(), a.end(), 0));// 0 is initial values of sum. using 0.0 will output float sum
	
	maxSumSingle = maxSumSubOf(a);
	
	a.insert(a.end(), a.begin(), a.end());
	
	cout<<( k > 1 ? maxSumSubOf(a) + (k-2)*(ll)clippedSum : maxSumSingle )<<endl;
}
	return 0;
 
}