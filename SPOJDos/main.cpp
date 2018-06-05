#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stack>
using namespace std;


int Palinum(int bhalf,int odd){int i=0,rev_num=0;int digits=0,div=1;while(div<=bhalf){digits++;div*=10;}
div=1;i=odd%2;if(odd)div*=10;
while(div<=bhalf){rev_num+=((bhalf/div)%10)*pow(10,digits-(++i));div*=10;}// get reveresed array
i=odd;return bhalf*pow(10,digits-i)+rev_num;}


int Palindrom(int lim){
int digit=0,div=1;while(div<=lim){digit++;div*=10;}//get digit, div = 10^digit
int betterhalf=lim/pow(10,digit/2),odd=digit%2;//set half, the better half,etc. //odd?l=half+1:l=half;//int except=//div -1;
for(int i=1;i<5;i++){int ans=Palinum(betterhalf,odd);if(ans>lim){return ans;}else if(betterhalf==div-1){return ans+2;} betterhalf++;}
}



int main() {//int n;cin>>n;int A[n];while(n--){cin>>A[n];cout<<Palindrom(A[n])<<endl;}}

    int t,length=35000;
    int a[length]; //array will have the capacity to store 200 digits.
    int n,i,j,m;
    scanf("%d",&t);int digitm=0,carry=0;a[0]=1;

    while(t--)
    {    cin>>n;digitm=0;carry=0;a[0]=1;m=1;
    for(i=1;i<=n;i++){//multiply n by i,from 1 to n-1.
        for(j=0;j<m;j++){//j<m will optimize no of calculations. //multiply that i to each digit of n, then add carry to it. Neutralise the carry ahead.
        digitm=a[j]*i+carry;//add prev carry too current digit.
        carry=digitm/10;//get next carry from digit multn
        a[j]=digitm%10;//set unit digit of multn.
        }
        while(carry>0)//To finish the number. //To handle carry of higher digits(since i will not be single digit, will increase till n)
        {a[m++]=carry%10;
        carry /=10;}
    }
  for(i=m-1;i>=0;i--) //printing answer
              printf("%d",a[i]);
              cout<<"\n";
    }

    /*
    1 2 3 -> n
    * 1 2 -> i
    ''''''
        36->6,3 carry
        24+3->7, 2 carry
        12+2->4, 1 carry
        ans=1476*/




    //int n;cin>>n;int A[n];while(n--){cin>>A[n];cout<<Palindrom(A[n])<<endl;}
}

/*


//while(i<digits){rev_num+=D[i++]*pow(10,digits-i);}//i++ in (i+1)
int l,i1=0;digit%2?i1++,l=(digit+1)/2:l=digit/2;//initialise
void Info(int lim,int D[]){int digits=0,div=1,i=0;
while(div<=lim){D[i++]=(lim/div)%10;digits++;div*=10;}i=0; //make the reveresd array
while(i<digits){cout<<D[digits-i-1]<<" ";i++;}cout<<"\t"; //Print the digits array
cout<<Palindrom(lim,digits)<<"\n";//execute palindrom
}
void RPN(char A[],int Size){//int i,j=1,k=1;int B[Size]={0};i=0;while(i<Size){ }
}


void Roman(){stack<int> mystack;

}*/


