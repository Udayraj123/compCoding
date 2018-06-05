#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000001

#define vi vector<ll> 
#define vii vector< vi > 

#ifdef DEBUG_RUN
	#define DEBUG_RUN_DEF true
#else
	#define DEBUG_RUN_DEF false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(DEBUG_RUN_DEF){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(DEBUG_RUN_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;

/*
unComment

Bruteforce = O(k) -> 10^12  [Wont work]

Need a pattern in the digits 
-> Yup, its the power of two in digits. s % 10, 2^s % 10,...
->  sum is d0+d1 + firstSome + (p)*( 8 + 6 + 2 + 4 ) + lastSome
k=4 and first=6 =>(d0 d1 )(6 2 4) () (8)
k=14 and first=6 => (6 2 4)	 (8624) (8624) 		(8 6 2)
				      6/2   ((k-3)- 6/2)/4	   (k-3- 6/2)%4

5,3,4 => 3	4	7	(4)	(8)
					^f
5 5 0 0 0 

5 9 9 => 9 9 8 (6 2)
5 2 2 => 2 2 4 (8 6)

*/
ll ceilDiv(ll req, ll n){
	return req/n + req%n ?1:0;
}

ll termsNum(ll d){
	return d == 8 ? 4 : ( d == 6 ? 3 : (d==2 ? 2: (d==4 ? 1 : 0)));
}

ll sumFrom(ll d){
	return d == 8 ? 20 : (d == 6 ? 12 : (d==2 ? 6: (d==4 ? 4 : 0)));
}

ll sumOf(ll d){
	return d==0 ? 0 : (d == 1 ? 8 : (d==2 ? 14: (d==3? 16 : 20)));
}

int main()
{
	ll t,n,k,d0,d1,sum, curr,first,numLastTerms,termsLeft;
	// if(!DEBUG_RUN_DEF) t = 1; else 
	cin>>t; 
	while(t--){
		cin>>k>>d0>>d1;

		sum = d0+d1;//7
		first = sum % 10;// 7
		// DEBUG(sum)

		if(first==5){
			if(k>2)
				sum+=5;
			}
		else if(first!=0){
			//875 000
			// (6 2 4) (8 6 2 4) (8 6)
			// d0 d1 first 6
			if( k >= 3 + termsNum((2 * first )% 10)){
				sum+=first;// third term
				first = (2 * first )% 10;//0, 2,4,6,8
				termsLeft = k - 3 - termsNum(first);
				numLastTerms = termsLeft%4;
				DEBUG(first) DEBUG(termsLeft) DEBUG(numLastTerms) DEBUG(sumFrom(first)) DEBUG(sumOf(numLastTerms))
				sum += sumFrom(first) + sumOf(numLastTerms) + 20 * ( termsLeft/4 ) % 3;
			}
			else{
				// 99862
				// 2 <= k < 6
				k-=2;
				while(k-- > 0){
					DEBUG(first)
					sum += first ;//third term onwards
					first = (first*2)%10;
				}
			}
		}
		DEBUG(sum)

		cout << ((sum%3 == 0)? "YES" : "NO") <<endl;
	}
	return 0;

}