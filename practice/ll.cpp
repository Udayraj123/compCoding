#include<iostream>
//#include<stdlib.h> //for malloc
using namespace std;

typedef struct node{
	int data;
	struct node* next;
} node;

node* newNode(int data){
	node* n =  new node();//(node*)malloc(sizeof(node));
	n->data=data;
	n->next = NULL;
	return n;
}

int insert(node** head, int data, int index){
	node* temp=*head;
	if(index==0){
		*head = newNode(data);
		(*head)->next=temp;
		return 1;
	}
	else if(!*head)return 0;

	for (int i = 1; i < index; ++i){
		if(!temp->next){//last element 
			if(i==(index-1))//reached pre-index
				break;
			else // index too far
				return 0;
		}
		temp=temp->next;
	}
	node* next = temp->next;
	temp->next = newNode(data);
	temp->next->next = next;//middle or end same code
	
}


//del_node first occurence
int del_node(node** head, int val){
	node* temp=*head, *prev = NULL;
	while(temp->data!=val && !temp->next){
		prev = temp;
		temp = temp->next;
	}
	if(temp->data!=val)
		return 0;	
	else {
		if(!prev)//first node
			*head = (*head)->next;		
		else
			prev->next = temp->next;
	}
	return 1;
}

void print(node* head){
	node* temp=head;
	while(temp){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

int main(int argc, char const *argv[]){
	node* head = NULL;
	insert(&head,0,0);		print(head);
	insert(&head,1,1);	print(head);
	insert(&head,2,2);	print(head);
	insert(&head,3,3);	print(head);
	insert(&head,1,0);	print(head);
	insert(&head,2,0);	print(head);
	insert(&head,3,0);	print(head);
	return 0;
}