//Name- Deshmukh Udayraj
//Roll - 150101021

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define print(x) printf("%d ",x);
#define prints(x) printf("%s ",x);
typedef struct adjNode  {
	int id;
	struct adjNode * next;
}
adjNode ;

typedef struct node {
	int id,visit,degree;
	adjNode * adjHead;
} nd;



nd* createNode(int id){
	nd* newNode = (nd*)malloc(sizeof(nd));
	newNode->id=id;
	newNode->visit=0;
	newNode->degree=0;
	newNode->adjHead = NULL;
	return newNode;
}

void makeEdge(nd * Node,int id){
	//attaches ids of connected nodes
	adjNode * adjHead1 = Node->adjHead;
	if(adjHead1==NULL){
		adjHead1 = (adjNode*)malloc(sizeof(adjNode)); // make new adjNode at end
		adjHead1 -> id = id;
		adjHead1 -> next =NULL; //set last one to NULL
		Node->adjHead=adjHead1;
	}
	else{
		while(adjHead1->next !=NULL)adjHead1 = adjHead1 -> next; //traverse to last id
		adjHead1 -> next = (adjNode*)malloc(sizeof(adjNode)); // make new adjNode at end
		adjHead1 = adjHead1 -> next;
		adjHead1 -> id = id;
		adjHead1 -> next =NULL; //set last one to NULL
	}

	Node->degree++;
}

void resetVisits(nd* nodeArray[],int N){
	int j;
	for (j=0;j<N;j++){
		nodeArray[j]->visit=0;
	}
}


void DFS_visit(nd * curr_node,nd * nodeArray[]){
	curr_node->visit++;

	adjNode * head = curr_node->adjHead;//head points to current node's adj list
	//go thru the adjList of current node
	while(head!=NULL){
		nd * near_node = nodeArray[head->id-1];

		if(near_node->visit==0){//unexplored
			DFS_visit(near_node,nodeArray);
		}

		head=head->next;
	}
	//at this point all neighbours are explored.
	curr_node->visit++;
}

int connectedPaths(nd* nodeArray[],int N){
	int v=0,j;
	nd* paths[N]; //to store heads of new connected paths.
	resetVisits(nodeArray,N);

	for (j=0;j<N;j++){
		nd* curr_node = nodeArray[j];
		if(curr_node->visit==0){
			paths[v++]=curr_node; //increment on a new visit
			DFS_visit(curr_node,nodeArray); //caution : this adds 1 to visit index
		}
	}
	return v;
}
void removeEdge(nd* nodeArray[],int j,int j2){
	// printf("remove %d->%d\n",j ,j2);
	adjNode * adjHead1 = nodeArray[j2]->adjHead;
	adjNode * adjHead2;
	if(adjHead1!=NULL){
		if(adjHead1->id == (j+1)){
			nodeArray[j2]->adjHead = adjHead1->next;
		}
		else{
			while(adjHead1->next !=NULL){
				adjHead2 = adjHead1->next;
				if(adjHead2->id == j){
					adjHead1->next=adjHead2->next;
					nodeArray[j2]->adjHead = adjHead1;
				// nodeArray[adjHead1->id-1]->degree--; //Problem demands not to reduce degree
					break;
				}
			adjHead1 = adjHead1 -> next; //traverse to last id
		}
	}
}
}

void removeNode(nd* nodeArray[],int j){
	adjNode * adjHead1 = nodeArray[j]->adjHead;
	if(adjHead1!=NULL){
		removeEdge(nodeArray,j,adjHead1->id-1);
		while(adjHead1->next !=NULL){
			removeEdge(nodeArray,j,adjHead1->id);
			adjHead1 = adjHead1 -> next; //traverse to last id
		}
	}
	nodeArray[j]->adjHead=NULL;
	// nodeArray[j]->degree=0;
}
void printG(nd* nodeArray[],int N){
	printf("%s","\nRecorded edges: \n");
	//print given data
	int j;
	for (j=0;j<N;j++){
		adjNode * head = nodeArray[j]->adjHead;
		printf("%s ","Node");printf("%d >",nodeArray[j]->id);
		while(head!=NULL){
			printf("%d ",head->id);
			head=head->next;
		}
		printf("\t\t");
	}
}
int main ( int argc, char *argv[]){
	int E=3,i,j,N=4;
	int t;
	scanf("%d",&t);
	while(t--){

		scanf("%d",&N);
		scanf("%d",&E);
		nd** nodeArray = (nd**)malloc(N * sizeof(nd));
		for (j=0;j<N;j++)
		nodeArray[j] = createNode(j+1); //initialize the nodes of the graph

	int a,b;
	for (i=0;i<E;i++){
		scanf("%d %d",&a,&b);
		makeEdge(nodeArray[a-1],b);
		makeEdge(nodeArray[b-1],a);
	}
//find number of connected components using DFS
	for (int d = 0; d < N; ++d)
	{
		for (j=0;j<N;j++){
			if(nodeArray[j]->degree <= d && nodeArray[j]->degree>0){
				removeNode(nodeArray,j);
			}
		}
		printf("%d\n",connectedPaths(nodeArray,N)-1);
	}
}

return 0;
}

/*
1 5 4 1 2 2 3 2 4 4 5
*/
