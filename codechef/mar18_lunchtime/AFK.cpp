#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
#define vi vector<int> 
#define vii vector< vi > 
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;
/*
A,B,C given
-10^9 ≤ A, B, C ≤ 10^9
make them an AP using min no of (addOne() or subOne());
Note: addOne to B equals addOne to A + addOne to C
first check if it's AP
if it's not,
So, change A or C only if sum is odd. Else change B

>51 23 10
61/2 = 30 (sum--)
23 -> 30

>-5 7 6
1/2 = 1 (sum++)
7 -> 1 (+6==7)

My corner case found-
70 79 92 : 2
-70 -79 -92 : 3 

exp_B = (A+C)/2 - ((A+C)<0);
The case when A+C is even, but negative- now resolved
exp_B = (A+C)/2 - (sum_odd && (A+C)<0);


*/
ll calcOp(ll A,ll B,ll C){
	ll counter,sum_odd,exp_B;
	counter=0;
	if(B - A != C - B){
	// Noting ll can handle –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
		sum_odd = (A+C)%2;
		exp_B = (A+C)/2 - (sum_odd && (A+C)<0);
		counter+= sum_odd?(B <= exp_B):0; //sum-- is counted explicitly, sum++ implicitly
		counter+= abs(B - exp_B);
	}
	return counter;
}

int main(int argc, char const *argv[])
{
	ll t=1,n,counter,counter2,A,B,C,sum_odd,exp_B;

	cin>>t; 
	// srand(time(0));
	while(t--){
		cin>>A>>B>>C;
		// A = rand()%100; B = rand()%100; C = rand()%100;
		counter = calcOp(A,B,C);
		// counter2 = calcOp(-1*A,-1*B,-1*C);
		// if(counter!=counter2)cout << A << " "<< B << " "<< C << " : "<<counter<<" "<<counter2<<" \n";
		cout<<counter<<endl;
	}
	return 0;
}

