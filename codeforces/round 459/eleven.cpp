#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef DEBUG_MODE
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif


#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;
/*
Fibonacci seq - bruteforce with mem
*/

int fib(int k, ll mem[]){
	if(k<=2)return (mem[k-1]=k);
	if(mem[k-1]==0){
		mem[k-1] = fib(k-1,mem) + fib(k-2,mem);
	}
	return mem[k-1]; 
}
int isFib(ll k, int fibForNmax, ll mem[]){
	if(k){
		for (int i = 0; i < fibForNmax; ++i){

			if(k == mem[i])
				return 1;
		}
	}
	return 0;
}

int main()
{
	ll t,n;
	int fibForNmax = 16;
	// vi mem(fibForNmax,0);
	ll mem[fibForNmax];
	for (int i = 0; i < fibForNmax; ++i)
		mem[i]=0;
	fib(fibForNmax,mem);

	if(!DEBUG_ON) t = 1; else cin>>t; 
	while(t--){
		cin>>n;
		for (int i = 0; i < n; ++i)
			cout<< (isFib(i+1,fibForNmax,mem)?'O':'o');
		cout<<endl;
	}
	return 0;
}