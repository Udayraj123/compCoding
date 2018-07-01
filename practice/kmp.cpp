#include<iostream>
//#include<stdlib.h> //for malloc
using namespace std;
#define ll long long int
/*
The trick KMP uses is that on getting a mismatch at (i,j), the substrings s[i-1-j..i-1] and p[0..j] are same!
so we can save calculations by preprocessing on p! 
how to know how many characters to be skipped. To know this, we prepare an integer array 
lps[] that tells us the count of characters to be skipped. 
name lps indicates longest proper prefix(of p) which is also suffix
*/

void preprocess(ll lps[],string p, ll m){
	ll ptr=0,i=0;
	// ptr acts as len (i.e. suffix=p[i-len..i]) as well as pointer to last matching position in p
	lps[i++]=ptr; // no PROPER prefix/suffix psble for single char
	while(i<m){
		// proper prefix = p[0..ptr]; len=ptr
		// suffix = p[i-len..i]
		if(p[ptr] == p[i]){ //last matching.
			ptr++;
			lps[i++]= ptr;// store position to go to
		}
		else{
			if(ptr!=0){
				// fall back and try again:
				ptr = lps[ptr-1];
				// try for same i again with previous match pos
			}
			else{ 
				// reached limit of falling back - then move on with setting lps[i]=0;
				lps[i]=lps[ptr];//ptr = 0, lps[0]=0
				i++;
			}
		}
	}
	//print check
	cout << "LPS: ";
	for (int i = 0; i < m; ++i){
		cout<<lps[i]<<" ";
	}
	cout<<endl;
}

void kmp(ll lps[],string p,string s,ll m,ll n){
	// two pointers
	ll i=0,j=0;
	cout<< "Substrings: ";
	while(i<n){
		if(s[i]==p[j]){
			i++;j++;
		}
		if(j==m){
			cout<< (i-m) <<".." << (i-1) << ", ";
			j=lps[m-1];
		}
		else if( i<n && s[i]!=p[j]){
			if(j)
				j=lps[j-1];
			else// reached till 0 but no match
				i++;
		}
	}
	cout<<endl;
}

int main(int argc, char const *argv[]){

	string s = "AAAAABAAABA";
	string p = "JKJKSALJKJK";
	// lps[] =  01201
	ll m=p.length(),n=s.length();
	ll lps[m];
	preprocess(lps,p,m); // 
	kmp(lps,p,s,m,n);

	return 0;
}