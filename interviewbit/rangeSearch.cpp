#include<bits/stdc++.h>
#define ll long long int
#define MOD 10//00000007
#define MAX 100000
using namespace std;

int endBin(int s,int e,const vector <int> &A,int B){
    //assume A is sorted
    if(s>=e){
        if(A[s]==B)return s;
        else return -1;
    }
    int mid = (s+e)/2,temp;
    if(A[mid] == B){
    	//look right.
    	temp = endBin(mid+1,e,A,B);
    	if(temp!= -1)
    		mid = temp;
    	return mid;
    }
    if(A[mid] < B)return endBin(mid+1,e,A,B);
    else return endBin(s,mid-1,A,B);
}
int startBin(int s,int e,const vector <int> &A,int B){
    //assume A is sorted
    if(s>=e){
        if(A[s]==B)return s;
        else return -1;
    }
    int mid = (s+e)/2,temp;
    if(A[mid] == B){
    	//look left.
    	temp = startBin(s,mid-1,A,B);
    	if(temp != -1)
    		mid = temp;
    	return mid;
    }
    else if(A[mid] < B)return startBin(mid+1,e,A,B);
    else return startBin(s,mid-1,A,B);
}

vector<int> searchRange(const vector<int> &A, int B) {
    //binary find 8, go left and right.
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    ans.push_back(startBin(0,A.size()-1,A,B));
    ans.push_back(endBin(0,A.size()-1,A,B));
    return ans;
}
int main()
{
vector<int> A;
A.push_back(1);
A.push_back(2);
A.push_back(3);
A.push_back(3);
A.push_back(3);
A.push_back(3);
A.push_back(3);
A.push_back(9);
cout<< searchRange(A,3)[0] << " "<<searchRange(A,3)[1] <<endl;
	return 0;
}
