#include<bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;

ll getm_svotes(int n, char s[]){
	int Scame=1;
	int Mcame=0;
	char t0,t1,t2;
	for (int i = 1; i < n-1; ++i)
	{
		t0=s[i-1]; t1=s[i]; t2=s[i+1];
		if(t0=='s' && t1=='s' && t2=='m'){
			
		}
		else if(t0=='s' && t1=='s' && t2=='m'){
			
		}
	}

	return 1;
}

int main(int argc, char const *argv[])
{
	ll t=1,n=10;
	cin>>t; 
	char t1;
	int counts[2];
	while(t--){
		cin>>n;
		char s[n];
		counts[0]=0;counts[1]=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>t1;s[i]=t1;
			counts[t1=='m']++;
		}
		// max eatable = numM
		if(counts[0] > counts[1]*2)cout<<"snakes"<<endl;
		else{
			ll	m_svotes = getm_svotes(n,s);
			cout<<m_svotes<<s;
			cout<<((m_svotes != 0)?((m_svotes>0)?"mongooses":"snakes"):"tie")<<endl;
		}
	}
	return 0;
}
