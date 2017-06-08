#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
using namespace std;
typedef pair<int,int> p;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N,i,a,b,cnt=0,l=MAX;
		vector<p> v;
		scanf("%d",&N);
		for(i=0;i<N;i++)
		{
			scanf("%d%d",&a,&b);
			v.push_back(p(b,a));
			if(a<l)l=a;
		}
		l--;
		sort(v.begin(),v.end());// sort by end  times
		for(i=0;i<N;i++)
		{
			if(v[i].second > l) // v.L > prevR( initially leftmost ) goto v.R and put one bomb in appr place covering max Places.
			{
				//Cover the length(No other v ending after v_i)
				l=v[i].first;
				//place the bomb
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
// /*
// int main(int argc, char const *argv[])
// {
// 	int t=1,n,ai,bi;
// 	// cin>>t; 


// 	set <int> s;
// 	s.insert(12);
// 	s.insert(5);
// 	set <int>::iterator it = s.find(5);
// 	for(set <int>::iterator it=s.begin();it!=s.end();it++){
// 		cout<<*it<<endl;
// 	}

// 	return 0;

// 	//declaring vector of pairs
// 	vector< pair <int,int> > vect;
// 	pair <int,int> set1,set2;
// 	set1=make_pair(2,4);
// 	set2=make_pair(1,3);

// 	return 0;

// 	map<string,string> myDict;
// 	myDict["Name"]="Udayraj";
// 	myDict["Name2"]="Udayraj";
// 	myDict.insert(pair<string,string>("g","sa"));
// 	myDict.erase(myDict.find("g"));
// 	for(map<string,string>::iterator it = myDict.begin(); it!= myDict.end();it++){
// 		cout<< it->first << "=>" << it->second<<endl;
// 	}

// 	return 0;
// 	while(t--){
// 		cin>>n;
// 		for (int i = 0; i < n; ++i)
// 		{
// 			cin>>ai>>bi; //Calc num of bits
// 		// Entering values in vector of pairs
// 			// if()
// 			vect.push_back( make_pair(ai,bi) );
// 		}
// include<map>
// C++ maps <=> Associative array (key value pairs)
// foreach loop in cpp = using map iterator.
// C++ pair <=> 2-tuples 


// 		// Printing the vector
// for (int i=0; i<n; i++)
// {
// 		    // "first" and "second" are used to access
// 		    // 1st and 2nd element of pair respectively
// 	cout << vect[i].first << " "
// 	<< vect[i].second << endl;
// }
// }
// return 0;
// }

