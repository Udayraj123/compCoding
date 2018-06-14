#include <iostream>
 
using namespace std;
 
int main()
{
    int t;
    cin>>t;
    double n,a,b,t1,nA,nB;
    while(t--){
        cin>>n>>a>>b;
        nA=0,nB=0;
        for(int i=0;i<n;i++){
            cin>>t1;
            if(t1==a)nA++;
            if(t1==b)nB++;
        }
        cout<< (nA/n)*(nB/n) <<endl;
    }
    return 0;
}
 