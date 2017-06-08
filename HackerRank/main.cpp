#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;cin>>t;while(t--){
        string str; cin>> str;
        //now traverse & print when next diff digit found.
        int now=0;int counts=1;//for first grp.
        while(str[now]!='\0'){
            int next=now+1;
            if(str[now]==str[next])counts++;//if next matches. increase count
            else{cout<<counts<<str[now]; counts=1;}//reset once matched & printed
            now++;
        }
        cout<<endl;

    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
