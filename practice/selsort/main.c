#include <stdio.h>
void shift(int A[],int index,int length)
{
    int i=0;
    while(index++<length)
    {
        A[length-i-1]=A[length-i-2];//from end. Shift length - index times ~|
        i++;
    }
}

void Mergesort(int A[],int B[],int l1,int l2){
int i,j,l;
if(l1<l2)l=l1;else l=l2;//min l.
for(i=0;i<l;i++){

//merge must involve shifting ?
}

}

int BinSearch(int SortedInc[],int start,int end,int x){
int mid=(start+end)/2;
int temp=SortedInc[mid];
if(temp==x){printf("found %d first at index: %d\n",x,mid);return mid;}
else if(temp>x){return BinSearch(SortedInc,start,mid,x);}
else {return BinSearch(SortedInc,mid,end,x);}
}

void insort(int B[], int length)//SHALL BE IN-PLACE??
{
    //int B[length];    B[0]=A[0];
    int sortL=1;
    while(sortL<length) //select elements 1 by 1 starting from 2nd.
    {
        int query= B[sortL],flag=1,j;
        for(j=0; j<sortL; j++) //loop thru sorted B
        {
            if(query<B[j])  //for increasing order.
            {
                flag=0;
                shift(B,j,sortL+1);//shift all further,
                B[j]=query;//put the selection at its place.
                break;
            }
        }
        if(flag==1)B[sortL]=query;//if ending wala.
        sortL++;//since we put one element everytime.
    }
    int l=length;
    while(l--)printf(" %d ",B[5-l]);
    printf("\n");
}
int main()
{
    int l=6,A[l];
    printf("Enter 6 elements: ");
    while(l--)scanf("%d",&A[5-l]);
    insort(A,6);
    BinSearch(A,0,5,5);
    return 0;
}
