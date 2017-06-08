#include<bits/stdc++.h>
#define ll long long int
#define MAX 10000000
#define print(x) printf("%d ",x);
#define printl(x) printf("%lld ",x);
using namespace std;

int samepts(ll x1,ll y1,ll x2,ll y2){
	return x1==x2 && y1==y2;
}
int getslope(ll x1,ll x2,ll y1,ll y2){
	if(y1==y2)return 0;
	else return -1;
}
int checkOverlapping(ll p11,ll p12,ll p21,ll p22){
	
	ll d1 = 	max(p11,p12) - min(p21,p22);
	ll d2 = 	max(p21,p22) - min(p11,p12);
	return (d1*d2 >= 0);
}
int main(int argc, char const *argv[])
{
	int t=1,flag=0, m1,m2;
	ll x11,x12,y11,y12;
	ll x21,x22,y21,y22;
	cin>>t; 
	while(t--){
		cin>>x11>>y11>>x12>>y12;
		cin>>x21>>y21>>x22>>y22;
		m1= getslope(x11,x12,y11,y12);
		m2= getslope(x21,x22,y21,y22);
		flag=0;
		if(m1==m2 && ((x11==x12 && x12==x21 && x21==x22) || (y11==y12 && y12==y21 && y21==y22))){
			//both lines on same line
			//slope inf
			if(x11==x12)
				flag = checkOverlapping(y11,y12,y21,y22);
			//slope 0 if(y11==y12)
			else 
				flag = checkOverlapping(x11,x12,x21,x22);
		}
		else{
			if(x11==x12 && y11==y12 && x21==x22 && y21==y22 )//spl case of both single cell 
				flag = (x11==x21 && y11==y21);// whether in the same line
			else if( (x11==x12 && y11==y12) || (x21==x22 && y21==y22 ))//spl case of a single cell & a vert line
				{// whether in the same line
				flag =(x11==x21) &&  checkOverlapping(y11,y12,y21,y22);
				}
			else 
				flag = (samepts(x11,y11,x21,y21) ||samepts(x11,y11,x22,y22) ||samepts(x12,y12,x21,y21) || samepts(x12,y12,x22,y22));
		}
		cout<<((flag==1)?"yes":"no")<<endl;
	}
	return 0;
}
