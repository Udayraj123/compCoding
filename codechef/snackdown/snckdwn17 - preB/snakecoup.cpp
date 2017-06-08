#include <bits/stdc++.h> //#include<bits/stdc++.h>// is cool one in c++ only, includes whatever required as need of the code.
using namespace std;

int main(){
	int t = 1,n=5,m=2,horiz,n_empty,r;
	cin>>t;
	char t1;
	while(t--){
		
		cin>>n;
		
		int mat[m][n];
		r = 0;
		for (int i = 0; i < n; i++) {
			cin>>t1;
			mat[r][i]= (t1=='*');
		}
		r=1;n_empty=0;horiz=0;
		for (int i = 0; i < n; i++) {
			cin>>t1;
			mat[r][i]= (t1=='*');
			if(mat[1][i] && mat[0][i])
				horiz=1;
			else if(!(mat[1][i] || mat[0][i]))
				n_empty++;
		}
		cout<< max((horiz+ n -1 - n_empty),0)<<endl;
			/*

		If two vert snakes, horiz line for sure.
		No of vert fences =  n - no of empty - 1

			*/
	}

	return 0;
}
