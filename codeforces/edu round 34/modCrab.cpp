#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);printf("\n");
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);printf("\n");
using namespace std;

/*
Player - h1,a1
Enemy -  h2,a2
Health per potion = c1.
Max health = Infi

Battle is over if anyone's health drops to <= 0 
A phase consists of first Player's move, then Enemy's move.
Enemy has no Health potion.
Minimize no of phases.

c1 > a2


10 6 100
17 5
-> P needs to survive 2 attacks so that he can do 3rd attack. 
-> But E can kill him down in 2. So P needs 1 health potion
-> It will be better to take all c potions at start.
-> How to calc this c ? 

11 6 100
12 5
P needs 2 attacks, and can survive 3. So no potion.

P needs 3 attacks, and can survive 3. So no potion.
P needs 4 attacks, and can survive 3. So need 1 potion.
P needs 5 attacks, and can survive 3. We need max 2 potions, but 1 potion might survive k>1 attacks
	h2/a1 is 5; 	h1/a2 is 3;		find k = (c1+h1%a2)/a2

TAG : Greedy  - does it need?

case 4 - 
79 4 68
9 65
-> S = 2, A = 3
1 potion => nop. attack2 happens again.
heals req = 
STRIKE - 14, 5
HEAL - 17, 5
HEAL - 20
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
HEAL
STRIKE
STRIKE

*/
ll ceil(ll x, ll y) {
    return x / y + (x % y > 0);
}

void printSteps(ll h1,ll a1,ll c1,ll h2,ll a2){
ll numSteps = ceil(h2,a1);
ll surviveSteps = ceil(h1,a2);

// (numSteps - surviveSteps) * a2 = (c*c1+h1%a2);
ll c = numSteps>surviveSteps?ceil((numSteps - surviveSteps) * a2 - h1 % a2 , c1-a2) : 0; // check a2 extra? 

cout<<(numSteps + c)<<endl;
for (int i = 0; i < c; ++i)cout<<"HEAL\n";
for (int i = 0; i < numSteps; ++i)cout<<"STRIKE\n";
}

int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false); // this just makes cin/cout as fast as scanf/printf
	// cin.tie(NULL); // simply guarantees the flushing of std::cout before std::cin accepts an input
	ll h1,a1,c1,h2,a2;
	cin>>h1>>a1>>c1>>h2>>a2;
	printSteps(h1,a1,c1,h2,a2);
	return 0;
}

