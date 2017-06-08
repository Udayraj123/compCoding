
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;
int markPaths(int thisCounter, int i,int j,vector<vector<int> > marked, vector<vector<char> > a,int counter,int w,int h){
  int currCounter= thisCounter;
  if(i<h && j<w && i>=0 && j>=0 && marked[i][j]==0){
    if(a[i][j] == '.'){
      marked[i][j]= counter;
      currCounter++;
    }
    else {
      marked[i][j]= -1; //mark stars as -1 & hence not visited again.
      return currCounter;
    }

//up
    currCounter = markPaths(currCounter,i,j-1,marked,a,counter,w,h);
//down
    currCounter = markPaths(currCounter,i,j+1,marked,a,counter,w,h);
//left
    currCounter = markPaths(currCounter,i-1,j,marked,a,counter,w,h);
//right
    currCounter = markPaths(currCounter,i+1,j,marked,a,counter,w,h);
//LD
    currCounter = markPaths(currCounter,i-1,j-1,marked,a,counter,w,h);
//LU
    currCounter = markPaths(currCounter,i-1,j+1,marked,a,counter,w,h);
//RD
    currCounter = markPaths(currCounter,i+1,j-1,marked,a,counter,w,h);
//RU
    currCounter = markPaths(currCounter,i+1,j+1,marked,a,counter,w,h);

  }

  return currCounter;
}

int solve(vector<vector<char> > &a,int w,int h){

  vector<char> t;
  char x;
  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++){
      cin>>x;
      t.push_back(x);
    }
    a.push_back(t);
    t.clear();
  }
  vector< vector<int> > marked;
  vector<int> t2;

  for (int i=0;i<h;i++){
    for (int j=0;j<w;j++)
      t2.push_back(0);
      marked.push_back(t2);
      t2.clear();
    }

    int counter = 1,finalCounter=0,temp;
    for (int i=0;i<h;i++){
      for (int j=0;j<w;j++){
        if(marked[i][j]==0){ //unvisited -
          temp = markPaths(0,i,j,marked,a,counter,w,h);
          finalCounter = max(finalCounter,temp);
        }
        else if(marked[i][j]!=-1) //non stars
          counter++;
      }
    }

    return finalCounter;
  }

  int main() {
  // Declare the variable
    int n,m;

  // Read the variable from STDIN
    cin >> n>>m;
    // declare 2D vector
    vector< vector<char> > a;

  // Output the variable to STDOUT
    cout << solve(a,n,m)<<endl;

    return 0;
  }

/*#include <iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include <cstdlib>
 using namespace std;

int main()
{
printf("Welcome to Printf world!\nLet's try few options: \n");
char s[]="Iam11string";
char s2[]="Iam11string";
printf(s);
printf("%15s\n",s);
printf("%-15s\n",s);
printf("%.5s\n",s);
printf("%.6s\n",s2);
printf("%15.5s\n",s);

//system ("cls");
//cout << "\x1b[2J\x1b[1;1H" ;
cout<<flush;
int a=1237;
float b=123;
printf("%15d\n",a);// add spaces
printf("%-15d\n",a);
printf("%.9d\n",a);//add zeros
printf("%.4f\n",b);
printf("%.f\n",b);


    return 0;
}
*/
