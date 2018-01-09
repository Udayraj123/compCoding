#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*
Room numbers repeat in diagonal lines
Room diamonds = diff in evenNumSum and oddNumSum
for N, room numbers range
1+1 to N+N,

Total diamonds = sum((Diamonds in Room k)*(N-abs(N+1-k))
each slant line

	12345

1	23456
2	34567
3	45678
4	56789
5	678910

	123456

1	23456		7
2	34567		8
3	45678		9
4	56789	   (10)
5	678910	   (11)

6	789.10.11.12

N = 6 => 7 ... 11
N = 7 => 8 ... 13 -> subtract 1, add 2 room's diamonds each time = constant time.

adding memoization - 

*/
ll calcRoomDiamonds(ll k){
	//this is CONSTANT TIME
	ll prevO=0,prevE=0,digit;
	// constant time - since 6 digits max
	while( k ){// calc even/odd sums for n+1 once
			digit = k%10;
			if(digit%2) prevO += digit; else prevE += digit;
			k/=10;
	}	

	return abs( prevE - prevO);
}
ll diamondDiff(ll k, ll *prevE, ll *prevO){
	//THIS IS JUST A SPEED UP, order remains same.
	// check parity change of last digit of k-1, if its 9, recalculate OR check 2nd last digit
	
	ll kMinus = k-1; //sublime highlights camelcase varNames prefixed with k
	ll digit,digitMinus;
	// 789 788
	// 1000 0999

	// O(digits) = constant
	while( k!=kMinus ){
		digit = k%10;
		digitMinus = kMinus%10;
		
		if(digit%2)
			*prevO = *prevO + digit; // 9-8, 1-0		
		else 
			*prevE = *prevE + digit; // 8-7, 0-9
		
		if(digitMinus%2)
			*prevO = *prevO - digitMinus; // 9-8, 1-0		
		else 
			*prevE = *prevE - digitMinus; // 8-7, 0-9
		k/=10;
		kMinus/=10;
	};
	//check for nums ending with 0
	return abs( *prevE - *prevO);
}

/*
2nd level DP here - 
	[2] 3|	 4|	 	5|
	 3__4|	 5|	 	6|
	 
	 4__5____6|	 	7|


	 5__6____7______8|
	 boundaryVals[2] = 3 , 3 , 4
	 boundaryVals[3] = 4 , 4 , 5 , 5 , 6
	 boundaryVals[4] = 5 , 5 , 6 , 6 , 7 , 7 , 8
	 boundaryVals[5] = 6 , 6 , 7 , 7 , 8 , 8 , 9 , 9 , 10
	 boundaryVals[6] = 7 , 7 , 8 , 8 , 9 , 9 , 10, 10, 11, 11, 12
	 boundaryVals[7] = -7 -7 + boundaryVals[6]				+	12 + 13*2 + 14
	 boundaryVals[n] = boundaryVals[n-1] + rooms[2*n - 4] + for(k=1 to 3)rooms[2*n-k)]- rooms[7]*2
	*/
ll calcBoundaryDiamonds(ll n,ll boundaryVals[]){
	if(boundaryVals[n]!=0)return boundaryVals[n];
	if(n==2)return 3*2+4;//N+1 to 2*N
// n = 3, 3*2 + 4 + 2
	ll boundary =  calcBoundaryDiamonds(n-1,boundaryVals)  - calcRoomDiamonds(n)*2	+ 
				   calcRoomDiamonds(2*n - 2) + 2*calcRoomDiamonds(2*n - 1) + calcRoomDiamonds(2*n);
	boundaryVals[n] = boundary;
	return boundary;
}


ll calcTotalDiamonds(ll n,ll totalDiamonds[], ll boundaryVals[]){
	ll boundary;
		if(totalDiamonds[n]!=0)return totalDiamonds[n];
		else{
			// boundary =  N*2 + 2*(k for k in N+1,...,2N-1)
			boundary = calcBoundaryDiamonds(n,boundaryVals); //n>= 2
			totalDiamonds[n] = calcTotalDiamonds(n-1,totalDiamonds,boundaryVals) + boundary;
			return totalDiamonds[n];
		}

}

int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false); // this just makes cin/cout as fast as scanf/printf
	// cin.tie(NULL); // simply guarantees the flushing of std::cout before std::cin accepts an input
	ll t,n;

	// NOTE - int totalDiamonds[1000001] doesn't work as stack cant hold it.
	// malloc works with type casting.
	ll* totalDiamonds = (ll*) malloc(1000001*sizeof(ll));
	memset(totalDiamonds,0,1000001*sizeof(ll));
	totalDiamonds[1]=2;//base value row + col = 1 + 1
	//boundaryVals[i] stores diamonds from [i+1 to 2*i]
	ll* boundaryVals = (ll*) malloc(1000001*sizeof(ll));
	memset(boundaryVals,0,1000001*sizeof(ll));
	cin>>t;
	while(t--){
		cin>>n;
		cout<<calcTotalDiamonds(n,totalDiamonds,boundaryVals)<<endl;
	}
	return 0;
}

