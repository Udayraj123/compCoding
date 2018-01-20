#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000001

#define vl vector<ll> 
#define vvl vector< vl > 
#define vi vector< int > 
#define vvi vector< vi > 

// #define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
	#define ONLINE_JUDGE_DEF true
#else
	#define ONLINE_JUDGE_DEF false
#endif


#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";printf("\n");
#define DEBUGA(x,n) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << ": \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";printf("\n");}
#define DEBUG(x) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << ": " << (x) << endl;}
using namespace std;
/*
THIS A QUESTION THAT TELLS FIRST WRITE THE BRUTEFORCE ALGO, THEN MOVE TO BETTER ALGOS



You are given two positive integer numbers a and b. Permute (change order) of the digits of a to construct maximal number not exceeding b. 
No number in input and/or output can start with the digit 0.

Numbers are positive.

M1) sort a's digits.
if(digits(a) < digits(b))
	print digits in desc order
if(digits(a) = digits(b))
	
	A BF method - will take steps upper bounded by 9!
	for each eligible digA for a digB, permute all unique possiblities,
	 but in decreasing order i.e. cover all cases of biggest eligible digA first


	still a not possible case - like 999876 890012, but it's guaranteed not to come in Q
else Not possible

10! * 18 storage req -> less than 10 digits _/

*/
int digits(ll a){
	int digits = 0;
	do{
		a/=10;
		digits++;
	}while(a>0);
	return digits;
}

vl digitsArr(ll a){
	int i=0,digs = digits(a);
	vl arr(digs);

	do{
		arr[i++] = a%10;
		a/=10;
	}while(a>0);

	reverse( arr.begin(), arr.end());
	return arr;
}

void printNum(vl A,vl markedA,int digsA){
	int flag = 0;
	for (int i = 0; i < digsA; ++i){
			flag=0;
			for (int j = 0; j < digsA; ++j)
			{
				if(markedA[j]==i+1){
					cout<<A[i];
					flag = 1;
					break;
				}
			}
			if(!flag)cout<<"_";
		}
}


bool checkAns(vl A, vl B,int start,int digsA, int digsB, vl markedA){
	if(start == digsB)return false;//*
	vl copy = markedA;
	DEBUGA(markedA,digsA)
	printNum(A,markedA,digsA);cout<<endl;
	int temp=1;
	for (int i = 0; i < digsA; ++i){
		if(markedA[i]==0){
			temp = 0;
			break;
		}
	}
	if( temp == 1 )return true;//all digits placed

	for (int j = start; j < digsB; ++j)
	{
		for (int i = 0; i < digsA; ++i)
		{
			if(!markedA[i] && A[i] <= B[j]){
				markedA[i]=start+1;//sequence of A indices (1-based)
				if(checkAns(A,B,start+1,digsA,digsB,markedA))
					return true;
			}
		}

	}
	markedA = copy;
	return false;
}
void printMaximally(ll a, ll b){
	int digsA = digits(a),digsB = digits(b);
	// get digits in an array
	vl B = digitsArr( b ); 	
	vl A = digitsArr( a );
	vl markedA(digsA,0);
	//desc sort them
	sort( A.begin(), A.end());
	reverse( A.begin(), A.end());
	DEBUGA(A,digsA)
	DEBUGA(B,digsB)
	if(digsA == digsB){
		if(!checkAns(A, B,0,digsA, digsB, markedA))
			cout<< " Answer not found! \n";
		//should return true at end, with non-zero indices in markedA
		printNum(A,markedA,digsA);
	}
	else{
		for (int i = 0; i < digsA; ++i)
			cout<<A[i];
	}
	cout<<endl;
}

int main()
{
	ll t,a,b;
	if (!ONLINE_JUDGE_DEF) cin>>t; 
	else t = 1;
	while(t--){
		cin>>a>>b;
		printMaximally(a,b);
	}
	return 0;

}