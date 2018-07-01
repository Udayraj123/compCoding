#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<ll> 
#define vll vector< vl > 

using namespace std;

#ifdef DEBUG_MODE
	#include "../../getTime.h"
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif


#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}

/*
Make plane from QP and d -> get the n^
Find center C' of circle formed by projection of the sphere at C
-> C' = Cq - (Cq.n^)n^
Find the tangent...


// for 2D -  Y  = MX + C
U0 = p[0]-c[0]
U1 = p[1]-c[1]
V = R*R + U0*U0 + U1*U1
// M = (-U0*U1 +- sqrt( (U0*U1)*(U0*U1) - (U0*U0 - V)(U1*U1 - V) )) / (U1*U1 - V)
---> M = (-U0*U1 +- sqrt( V*(U0*U0 - U1*U1) - V*V )) / (U1*U1 - V)
C = p[1] - M*p[0]
t = (q[0]*M + C - q[1])/(d[1] - d[0]*M)

Note: IN PROGRESS

*/

int main()
{

	// Speeds up cin/cout- But now you can't mix printf and cout coz their order of flushing is changed.
	ios_base::sync_with_stdio(0);
	// Second optimisation: Effective when large no of inputs (when cin gets used too much)
	cin.tie(NULL);

	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif

	int t;
	ll n, p[3],q[3],d[3],c[3],r;
	double ans;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		for (int i = 0; i < 3; ++i)cin>>p[i];//3
		for (int i = 0; i < 3; ++i)cin>>q[i];//3
		for (int i = 0; i < 3; ++i)cin>>d[i];//3
		for (int i = 0; i < 3; ++i)cin>>c[i];//3
		cin>>r;//1
		ans = 0;
		//p[0],p[1]
		//c[0],c[1], r
		cout << ans << endl;
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif
	
	return 0;

}
