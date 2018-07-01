#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

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

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*
If the two squares only share one common point, they are also considered to intersect.
The first line contains the coordinates of the square with sides parallel to the coordinate axes, the second line contains the coordinates of the square at 45 degrees.

>> reorganize points to be from top corner (topleft for parallel), clockwise
>> If they intersect, atleast one's corner point would be on or inside the other.

DONE - WA at 8 : 
-5 -5 5 -5 5 5 -5 5
6 0 0 6 -6 0 0 -6
*/

int findC(int x,int y, int m){
	//y-m*x = c
	return y - m*x;
}
bool check1(int x,int y,int maxX,int minX,int maxY,int minY){
	// parallel sq - sorted coords do
	return y <= maxY && y >= minY && x >= minX && x <= maxX;
}
bool check2(int x,int y,int maxC,int minC,int maxC_1,int minC_1){
	// slant sq - check c vals
	return check1(findC(x,y,1),findC(x,y,-1),maxC,minC,maxC_1,minC_1);
}


bool intersect(int p1X[],int p1Y[],int p2X[],int p2Y[]){
	int minC, minC_1, minX, minY, maxC, maxC_1, maxX, maxY;
	minC= minC_1= minX= minY= MAX;
	maxC= maxC_1= maxX= maxY= -1*MAX;
	float avg1X,avg1Y,avg2X,avg2Y;
	avg1X=avg1Y=avg2X=avg2Y=0;
	for (int i = 0; i < 4; ++i){
		maxX=max(maxX,p1X[i]);
		minX=min(minX,p1X[i]);
		maxY=max(maxY,p1Y[i]);
		minY=min(minY,p1Y[i]);
		avg1X+=p1X[i];
		avg1Y+=p1Y[i];
	}
	avg1X/=4; avg1Y/=4;
	for (int i = 0; i < 4; ++i){
		maxC=max(maxC,findC(p2X[i],p2Y[i],1));
		minC=min(minC,findC(p2X[i],p2Y[i],1));
		maxC_1=max(maxC_1,findC(p2X[i],p2Y[i],-1));
		minC_1=min(minC_1,findC(p2X[i],p2Y[i],-1));
		avg2X+=p2X[i];
		avg2Y+=p2Y[i];
	}
	avg2X/=4; avg2Y/=4;
	
	//inside parallel
	for (int i = 0; i < 4; ++i)
		if(check1(p2X[i],p2Y[i],maxX,minX,maxY,minY))
			return true;
	//inside 45
	for (int i = 0; i < 4; ++i)//
		if(check2(p1X[i],p1Y[i],maxC,minC,maxC_1,minC_1))
			return true;

		// test 8
		if(check1(avg2X,avg2Y,maxX,minX,maxY,minY))return true;
		if(check2( avg1X,avg1Y,maxC,minC,maxC_1,minC_1))return true;

	return false;//
}

int main(){
	// http://codeforces.com/blog/entry/5217

	// Speeds up cin/cout- But now you can't mix printf and cout coz their order of flushing is changed.
	ios_base::sync_with_stdio(0);
	// Second optimisation: Effective when large no of inputs (when cin gets used too much)
	cin.tie(NULL);
	//Timing debugs
	#ifdef DEBUG_MODE
	unsigned ll startTime,endTime;
	startTime = getTime();
	#endif

	ll t;
	if(!DEBUG_ON) t = 1; else //codeforces line.
	cin>>t; 
	ll n;
	int pts1X[4],pts2X[4];
	int pts1Y[4],pts2Y[4];
	while(t--){
		for (int i = 0; i < 4; ++i)
			cin>>pts1X[i]>>pts1Y[i];//horiz
		
		for (int i = 0; i < 4; ++i)
			cin>>pts2X[i]>>pts2Y[i];//slant
		
		cout << (intersect(pts1X,pts1Y,pts2X,pts2Y)? "YES\n" : "NO\n");
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Run Time: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
