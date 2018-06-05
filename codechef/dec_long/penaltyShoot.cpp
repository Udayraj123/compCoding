#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;
/*
5 each alternating shots
RGRGRG RGRGRG
if a team is impossible to win, other team immediately declared winner
if still draw, sudden death -> first 1-0 situation in atmost 5 more rounds will declare winner
 Chef's team always starts first
 sample input 
 10101001001010
*/



int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false); // this just makes cin/cout as fast as scanf/printf
	// getchar calls are significantly faster
	// cin.tie(NULL); // Turn off flushing of std::cout before std::cin accepts an input
/*
It is recommended to use cout << “\n”; instead of cout << endl;
endl is slower because it forces a flushing stream, 
which is required usually in a progress bar,etc

*/
	// int c;
	int skipDeath=0;
	int goalsA=0,goalsB=0;
	int potenzA=5, potenzB=5;
	char results[21];// given 20 bit binary string
	
	while(scanf("%20s",results) != EOF ){
	// while(true){
/*		for (int i = 0; i < 20; ++i){c = getchar(); if(c==EOF) return 0; results[i] = c;}c = getchar();//capture the newl; */
		skipDeath = 0;
		goalsA=0; goalsB=0;
		potenzA=5; potenzB=5;

		// we have the results string here.
		for (int i = 0; i < 10; i++) {
			if(results[i]=='1')
				i%2==0?(goalsA++):(goalsB++);
			i%2==0?(potenzA--):(potenzB--);
// check : if in round 9, tie condition for B, when 5-4 shouldnt skip
			// 11111111101111111110
			if( (goalsB-goalsA)>potenzA || (goalsA-goalsB)>potenzB ){//floor down was req _/
				
				cout<<"TEAM-"<<(goalsA>goalsB?"A":"B")<< " "<<(i+1)<<endl;
				skipDeath=1;
				break;
			}
		}
		if(skipDeath)continue;
		skipDeath = 0;
		//sudden death now
		for (int i = 11; i < 20; i+=2) {
			if(results[i]!=results[i-1]){
				cout<<"TEAM-"<<(results[i-1]=='1'?"A":"B")<< " "<<(i+1)<<endl;
				skipDeath = 1;
				break;
			}
		}
		if(skipDeath)continue;
		else{
			cout<<"TIE\n";
		}
	}
	return 0;
}

