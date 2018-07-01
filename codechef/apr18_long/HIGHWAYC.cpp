#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007
// #define ll_MAX 18446744073709551615
#define ll_MAX std::numeric_limits<unsigned long long>::max()

#define vd vector<double> 
#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<int> 
#define vll vector< vl > 

#ifdef DEBUG_MODE
	#include "../../getTime.h"
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif

#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;
/*
Crossing be done greedily? Yup.
Can waiting be combined for two lanes?
	There isn't point in waiting if you can cross, wait at the next if req!

while(not reached):
	if(safe to cross lane):
		cross lane
	else:
		wait till its safe

Corner cases:
> When car just touches before chef crosses.
> And for large N, where floats may loose precision
> negating (directions and positions) shall give same ans
> P[i]s are 0 but lengths are huge

So the WA was because double printed small ans in scientific notation

1≤N≤10
1≤S≤10
1≤Vi≤200
1≤Y≤1000
1≤Ci≤1000
|Pi|≤10^9 

M1-
Store list of times at which cars block his path. Then traverse that list
// 0 =   P[i]  + D[i]*V[i]*t
// negative time means never meets
//Nope, If 0 velocities psble, div by double handles it and gives inf

M2 (ayushjain2809's) - 
First make chef's ghost cross the highway, without waiting at all.
Find out if next car is gonna hit it by checking back_pos*front_pos < 0
If yes he has to wait, else curr_time += single_cross
Also, if chef has to wait, he must leave at the time when the next lane car's back just crosses x-axis.
=> Do curr_time = c_end, than curr_time += c_end

*/
int checkOverlap(double a,double a_end,double c,double c_end){
	// return (a <= c_end) && (c <= a_end);
	return  (a-c_end <= 0.000001) && (c-a_end <= 0.000001);
}
double calcWaitTime(double a,double a_plus,double c,double c_end){
	// [a,a+a_plus] on [c,c+c_plus]
	if (checkOverlap(a,a+a_plus,c,c_end)){
		//you can only cross when it completely goes past you
		dprintf("wait: %.2f --> %.2f\n",a,c_end)
		return c_end - a;
	}
	else 
		return 0;
}

int main(){
	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif

	int t,n,s,y,temp;
	double single_cross,curr_time,abs_Pi;
	// if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	while(t--){
		//chef is at y=0 all time.
		cin>>n>>s>>y;//num lanes, chef speed, lane_width
		single_cross = (double)(y)/(double)s;
		vd V(n,0);for (int i = 0; i < n; ++i)cin>>V[i];// Car Speed
		vi D_inv(n,0);for (int i = 0; i < n; ++i){cin>>temp;D_inv[i]=temp==1?-1:1;}// Car Direction(Inverted)
		vd P(n,0);for (int i = 0; i < n; ++i)cin>>P[i];// Start pos of 'Front' of car
		vd C(n,0);for (int i = 0; i < n; ++i)cin>>C[i];// Length
		vd block_start_times(n,0),block_end_times(n,0);
		for (int i = 0; i < n; ++i){			
			abs_Pi=abs(P[i]);
			bool away_orig = P[i]*D_inv[i]<0;
			if(V[i]==0){//Not the case in this problem, but still can handle it
				abs_Pi = away_orig ?( C[i]>abs_Pi?0:1 ): abs_Pi;
				block_start_times[i]=  abs_Pi==0? -1*MAX: MAX ;
				block_end_times[i]= MAX;
			}
			else if(away_orig){//away from origin, check if car covers orig partially
				block_start_times[i]= C[i]>abs_Pi ? (-1*abs_Pi/V[i]) : MAX;
				block_end_times[i]= block_start_times[i] + C[i]/V[i];
			}
			else{//towards origin
				block_start_times[i]= abs_Pi/V[i];
				block_end_times[i]= block_start_times[i] + C[i]/V[i];
			}
		}
		DEBUGV(block_start_times)
		DEBUGV(block_end_times)
		//cross
		curr_time= 0;
		for (int i = 0; i < n; ++i){
			dprintf("%d)T: [%.2f,%.2f], car: [%.2f,%.2f]\n",i,curr_time,curr_time+single_cross,block_start_times[i],block_end_times[i])
			curr_time+=calcWaitTime(curr_time,single_cross,block_start_times[i],block_end_times[i]);
			dprintf("cross: %.2f --> %.2f\n",curr_time,curr_time+single_cross)
			curr_time+=single_cross;
		}
		// precision: default is 6
		// double prints scientific notation by default!
		cout<<std::fixed<<std::setprecision(8)<<curr_time<<endl;
	}

	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif
	return 0;
}