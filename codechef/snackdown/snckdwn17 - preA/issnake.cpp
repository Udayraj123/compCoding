#include <bits/stdc++.h> //#include<bits/stdc++.h>// is cool one in c++ only, includes whatever required as need of the code.
using namespace std;
enum headState { ANY, UP, DOWN };

int issnake(int n,int *mat){
	headState head=ANY;
	int start = 0, end = 0,p1,p2;
	for (int i = 0; i < n; i++){
		p1=*(mat+i);p2=*(mat+n+i);
		if(p1 || p2)start=1;
		if(end && (p1 || p2))// got hash again after 2 dots
			return 0;

		if(p1 && p2){
			//toggle
			head = (head==ANY)?ANY:((head==UP)?DOWN:UP);
		}
		else if(p1){
			if(head==ANY)
				head = UP;
			else if(head!=UP)
				return 0;
		}
		else if(p2){
			if(head==ANY)
				head = DOWN;
			else if(head!=DOWN)
				return 0;
		}
		else//got 2 dots with hash already occurred, no hash further
			if(start)end=1;
	}
	return 1;
}

int main(){
	int t = 1,n=5;
	cin>>t;
	char t1;
	while(t--){
		
		cin>>n;
		
		int * mat = (int*)malloc(sizeof(int)*2*n);
		for (int r = 0; r < 2; r++) 
			for (int i = 0; i < n; i++) {
				cin>>t1;
				*(mat + n*r + i)= (t1=='#')?1:0;
			}
			cout<<(issnake(n,mat)%2?"yes":"no")<<endl;
		}

		return 0;
	}