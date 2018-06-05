#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000000
const long long INF = 1e18 + 42;

#define vl vector<ll> 
#define vvl vector< vl > 
#define vi vector< int > 
#define vvi vector< vi > 

#ifdef ONLINE_JUDGE
	#define ONLINE_JUDGE_DEF true
#else
	#define ONLINE_JUDGE_DEF false
#endif

#define dprintf(...) if(!ONLINE_JUDGE_DEF)printf(__VA_ARGS__);
#define printa(x,n) for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
#define DEBUGA(x,n) if(!ONLINE_JUDGE_DEF){for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";}
#define DEBUG(x) if(!ONLINE_JUDGE_DEF){cout << ">> " << #x << " : " << (x) << endl;}
using namespace std;

WOAH, double prints scientific notation by default! : 0.0000001 is printed as 1e-007
// precision: default is 6
cout<<std::fixed<<std::setprecision(8)<<curr_time<<endl;


DEMN, passing the vector by value can cause TLE!
changed getCi(vi C,int i){
to    getCi(vi &C,int i){


// https://stackoverflow.com/questions/1861294/how-to-calculate-execution-time-of-a-code-snippet-in-c
// (Linux) Snippet for timing execution in the program- 
#include <sys/time.h>
typedef unsigned long long timestamp_t;
static timestamp_t
get_timestamp (){
  struct timeval now;
  gettimeofday (&now, NULL);
  return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}
...
timestamp_t t0 = get_timestamp();
// Process
timestamp_t t1 = get_timestamp();
double secs = (t1 - t0) / 1000000.0L;
//

i++ is not the same as i+=1, it returns value but ++i returns reference


//  There is a foreach in C++ 
// C++11 and higher
std::for_each(vector.begin(), vector.end(), [&] (int n) {
	sum_of_elems += n;
});

j = *(strstr(line, " == ") + 5) - '0';
sum_of_elems = std::accumulate(a.begin(), a.end(), 0);// using 0.0 will output float sum

// The ".*" tells printf() to take the maximum-
printf("    %s = %0.*s\n", tempvar = newname(), yyleng, yytext );
//C string array
char  *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };   


// Concating vectors
vl a,b;
b.insert(b.end(), a.begin(), a.end());

// Catalan's Number -
answer to 3 eqv problems :
>No of ways of correctly parenthesising
>Dycks words of length 2n (each prefix of the string has no of X >= no of Y)
Reduced to >Number of paths without crossing the diagonal
-> Solved by : 
>Create a line CD parallel to the diagonal AB in the upper(crossing) side.
> Reflection of A in line CD will be at F(-1,1). 
>All "incorrect" paths must have a point on CD, call the first such point E.
>

 void some_function(const vector<int>& v) { // OK 
      // ... 
 } 
 If you are going to change the contents of vector in the function, just omit the ‘const’ modifier.
 void some_function(vector<int>& v) { // OK but less usual

 	XOR pattern	- KiM : XoR upto n consecutive numbers = period of 4
 	1 = 1
 	1^2 = 3
 	1^2^3 = 0
 	1^2^3^4 = 4
 	1^2^3^4^5 = 1
 	1^2^3^4^5^6 = 7
 	1^2^3^4^5^6^7 = 0
 	1^2^3^4^5^6^7^8 = 8
 	1^2^3^4^5^6^7^8^9 = 1
 	1^2^3^4^5^6^7^8^9^10 = 11
 	1^2^3^4^5^6^7^8^9^10^11 = 0
 	1^2^3^4^5^6^7^8^9^10^11^12 = 12
 	1^2^3^4^5^6^7^8^9^10^11^12^13 = 1
 	1^2^3^4^5^6^7^8^9^10^11^12^13^14 = 15
 	1^2^3^4^5^6^7^8^9^10^11^12^13^14^15 = 0

 	Anti-XOR is same as XoR i.e. A^X = B => X = A^B



//template function
 	void listDir(char * directory){
 		
 		DIR *dp = NULL;
 		struct dirent *dptr = NULL;
    // Open the directory stream
 		if(NULL == (dp = opendir(directory)) )
 		{
 			printf("\n Cannot open Input directory [%s]\n",directory);
 			exit(1);
 		}
 		else
 		{
 			printf("\n The contents of directory [%s] are as follows \n",directory);
        // Read the directory contents
 			while(NULL != (dptr = readdir(dp)) )
 			{
 				if( !strcmp(dptr->d_name,".") && !strcmp(dptr->d_name,".."))
 					printf(" [%s] ",dptr->d_name);
 			}
        // Close the directory stream
 			closedir(dp);
 		}
 	}
