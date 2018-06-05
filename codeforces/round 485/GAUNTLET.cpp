#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#define vi vector<int> 
#define vii vector< vi > 
#define vl vector<ll> 
#define vll vector< vl > 

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

#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*
x,y are prime naturals(logx,logy>0) & x==y => x^y == y^x coz there's unique prime factorization of x^y
but say x=2,y=4 => x^y==y^x
if x,y are coprime - still would do!

 x^y >=< y^x
 ^(1/xy)
 x^1/x >=< y^1/y
 1<x,y<e -> increasing => x>y => x^1/x > y^1/y
 x,y>e => x<y => x^1/x > y^1/y
 if they are opposite-

*/
void manual(int x,int y){
//one of them is < 3
	int t1 = 1;for(int i=0;i<y;i++)t1*=x;
	int t2 = 1;for(int i=0;i<x;i++)t2*=y;

	cout << (t1==t2?"=":(t1<t2?"<":">"))<<endl;
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
	int n;
	while(t--){
		cin>>n;
		std::map<char,bool> mmap;
		std::map<char,string> smap;
		char colors[] = { 'p','g','b','o','r','y'};
		string gems[] = {"Power","Time","Space","Soul","Reality","Mind"};
		string temp;
		for(int i=0;i<6;i++)
			smap[colors[i]]=gems[i];

		for(int i=0;i<n;i++){
			cin>>temp;
			mmap[temp[0]]=true;
		}
		cout<<(6-n)<<endl;
		char c;
		for(int i=0;i<6;i++){
			c=colors[i];
			if(mmap[c]==false){
				cout<<smap[c]<<endl;
			}
		}
	}
	//Timing debugs
	#ifdef DEBUG_MODE
	endTime = getTime();
	printf("Time Taken: %ld ms\n",(endTime-startTime));
	#endif

	return 0;
}
