/*input:First line of input contains a single integer T, the number of test cases.
Each test starts with a line containing a single integer N.
The next line consists of N space separated integers (Ai).
output:For each test case, output on a separate line the total number of factors of the product of given numbers.

*/
#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

int numbers[11];//array to store the numbers
bitset<MAX> primes;
long long int array[MAX];

void initializePrimes(){
	primes.set();
	for(long long int i=2;i<=MAX;i++){
		if(primes[i]==1){
			for(long long int j=2*i;j<=MAX;j+=i){
				if(primes[j]==1)
					primes.reset(j);
			}
		}
	}
}

void solve(int n){
	memset(array,0,sizeof(array));
	long long int maxPrime=1;

	for(int i=0;i<n;i++){
		long long int currNum=numbers[i];
		long long int j2 =2;
		while(currNum%j2==0){
			array[j2]++;	
				//array stores the number of factors.
			currNum /= j2;
		}

		for(long long int j=3;j<=sqrt(currNum);j+=2){
			while(currNum%j==0){
				array[j]++;//array stores the number of factors.
				currNum /= j;
				maxPrime = max(maxPrime,j);
			}
		}

		if(currNum>2){
			array[currNum]++;
			maxPrime = max(maxPrime,currNum);
		}

	}
	long long int ans=1;
	for(long long int i=2;i<=maxPrime;i++){
		//printing the answer
		if(array[i])
			ans=ans*(array[i]+1);
	}
	cout<<ans<<endl;

}





int main(){
	int t;
	cin>>t;
	initializePrimes();
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>numbers[i];
		solve(n);

	}

	return 0;
}
