#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> //memset here.
#define ll long long int
using namespace std;

/*
7
4 6 5 8 8 2 6
2 1 2 2 1 1 2
*/
int main(){
	ll n,t;
	cin>>n;
	vector <ll> A;
	vector< pair<ll,ll> > B;

	for (int i = 0; i < n; ++i) {
		cin>>t;
		A.push_back(t);
	}
	for (int i = 0; i < n; ++i) {
		cin>>t;
		B.push_back(make_pair(t,i));
	}

// for reverse sort or sort by second, pass the comparator
	sort(A.begin(),A.end(),std::greater<ll>());
	sort(B.begin(),B.end());

	ll A_new[n];
	for (int i = 0; i < n; ++i) {
		A_new[B[i].second] = A[i];
	}
	for (int i = 0; i < n; ++i)
		cout<<A_new[i]<<" ";
	cout<<endl;
	return 0;
}