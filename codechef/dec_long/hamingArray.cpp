#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
#define printa(x,n) for(int i = 0; i < n; ++i)printf("%d ", x[i]);cout<<"\n";
#define printla(x,n) for(int i = 0; i < n; ++i)printf("%lld ", x[i]);cout<<"\n";
using namespace std;


// #include <sstream>
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

/*

	shuffle A such that A[i]!=B[i]
	M-1] sort A & its indices, reverse them and regenerate B from indices. 
	Then swap those repeating with the extremes.
	corner case 1 : All same elements ?! Nope - 
Given : The frequency of each integer in the array A will be at most 2.
	corner case 2 : Palindromes ?! Nope


1 2	
2 1

1 2 1   
1 1 2
2 1 1
2 1 1

2 6 5 2
2 2 5 6
6 5 2 2
6 2 2 5

		// Note(Deallocation) :: destructor of vector is called at closure of this stack of its declaration, smart!

C++ multimap - same as map, but allows duplicate keys. hence [] assignment not allowed, used .insert(pair<__,__>(__,__))
multimap::find() -> 
it=mymultimap.find ('e');
it->second
  mymultimap.erase (it);

1	 23  114 123 123 321 1321
1321 321 123 123 114 21  1

123 1321 23 114 1 321 123
123 1 321 123 1321 23 114

   pair<multimap<string, int>::iterator, multimap<string, int>::iterator> ppp;
// equal_range(b) returns pair<begin iterator,end iterator> representing the range of element with key b
   ppp = m.equal_range("b");



*/
int main(int argc, char const *argv[])
{

	// ios_base::sync_with_stdio(false); // this just makes cin/cout as fast as scanf/printf
	// cin.tie(NULL); // Turn off flushing of std::cout before std::cin accepts an input
	ll t,n,hamming;
	string output;
	cin>>t;
	while(t--){
		cin>>n;
		std::multimap <int,int> mymultimap;
		std::vector<int> a(n,0); //n ints with value 0
		std::vector<int> orig(n,0); //n ints with value 0
		for (int i = 0; i < n; ++i){
			cin>>a[i];
			orig[i]=a[i];
		}
		sort(a.begin(),a.end());
		// std::iter_swap(a.begin() + n/2, a.begin() + n-1);
		// 1 1 2 2
		// 2 2 1 1
		// 1 1 2 2 3 3
		// 3 3 2 2 1 1
		// std::swap(a[n/2], a[n-1]);
		// we have to swap the mapping, not the array
		if(n%2){
			for (int i = 0; i < n; ++i){
				if(i==n/2)mymultimap.insert(pair<int,int>(a[n/2],a[0]));//n-1 - (n - 1)
				else if(i==n-1)mymultimap.insert(pair<int,int>(a[n-1],a[n/2]));
				else mymultimap.insert(pair<int,int>(a[i],a[n-1-i]));
			}
		}
		else{
			if(a[n/2]==a[n/2-1]){
			for (int i = 0; i < n; ++i){
				if(i==n/2 || i==n/2-1)mymultimap.insert(pair<int,int>(a[i],a[i+1 - n/2]));//n-1 - (n - 1)
				else if(i==n-1 || i==n-2)mymultimap.insert(pair<int,int>(a[i],a[n/2]));
				else mymultimap.insert(pair<int,int>(a[i],a[n-1-i]));
			}
			}
			else{
				//n = 4, 11 22 type
				for (int i = 0; i < n; ++i)
					 mymultimap.insert(pair<int,int>(a[i],a[n-1-i]));

			}
		}
		// use of A is done.
		// Note (Deallocation):: destructor of vector is called at closure of this stack of its declaration, smart!
		std::multimap <int,int>::iterator it;
		output = "";
		// Given : The frequency of each integer in the array A will be at most 2.
		// so check the mid 2 elem if n is even, swap with extremes
		hamming=0;
		for (int i = 0; i < n; ++i){
			it=mymultimap.find (orig[i]);
			if(orig[i]!=(it->second))hamming++;
			output += patch::to_string(it->second);
			output += " ";
			mymultimap.erase (it);
		}
		cout<<hamming<<"\n"<<output<<"\n";
	}
	return 0;
}

