#include<bits/stdc++.h>
#define ll long long int
#define MAX 1000000007

#ifdef DEBUG_MODE
	#define DEBUG_ON true
#else
	#define DEBUG_ON false
#endif

#define dprintf(...) if(DEBUG_ON)printf(__VA_ARGS__);
#define DEBUGA(x,n) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(int i = 0; i < n; ++i)cout<<x[i]<<"\t";cout<<"\n";}
#define DEBUG(x) if(DEBUG_ON){cout << ">> " << #x << " : " << (x) << endl;}
#define DEBUGV(x) if(DEBUG_ON){cout << ">> " << #x << " : \t";for(typeof((x).begin()) i = (x).begin();i!=(x).end();i++)cout<<(*i)<<"\t";cout<<"\n";}

#define printa(x,n) cout<<#x<<": ";for(int i = 0; i < n; ++i)cout<<x[i]<<" ";cout<<"\n";
using namespace std;

/*
~100k strings,
enumerate if not unique.
STL : vector and vector.find? nope- they say a unordered_map  shall hash:  unordered_map<string, int >, storing the count

without:  Read'em as integers! 
>> Nope, its 32 bytes not bits! - Each request is a non-empty line, and consists of not more than 32 characters (with lowercase letters i.e. no prob of negative ints)
>> but distinct characters are only 26 
^^No problem - we're taking modulo anyway, rather store strings in nodes then
This one hash psble: https://gist.github.com/ducngtuan/4332979
Official: https://www.quora.com/What-is-the-C++-STL-default-hashing-function-algorithm-for-string-types

And hash the ints.
List method: hashing using simple modulo function and linear insert and search
>> The node shall contain count!
^^NOTE: Runtime error on test 7
*/
#define MOD 100000
#define MAX_CHARS 32
int n,m;
ll temp;
char s[MAX_CHARS+1];
typedef struct node{
	char data[MAX_CHARS+1];
	int count;
	struct node* next;
} node;

node* newNode(char data[]){
	node* n =  new node();//(node*)malloc(sizeof(node));
	strcpy(n->data,data);
	n->count=0;
	n->next = NULL;
	return n;
}

void insert(node** head, char data[]){
	// insert first in list
	node* temp=*head;
	*head = newNode(data);
	(*head)->next=temp;
}

//find first occurence
int find_and_insert(node** head, char val[]){
	node* temp=*head, *prev = NULL;
	if(!temp){
		insert(head,val);
		return 0;
	}
	while(strcmp(temp->data,val)!=0 && !temp->next){
		prev = temp;
		temp = temp->next;
	}
	//end of list
	if(strcmp(temp->data,val)!=0){
		insert(head,val);
		return 0;
	}
	else// found at temp
		temp->count++;
	return temp->count;
}


int str2int(char s[]){
	int r=0;
	// sscanf(s,"%d",&r);// differs on actual integer input
	// this is what scanf %d does if input is not digits.
	for (int i = 0; i < strlen(s); ++i) {
		r |= (s[i] << (i*8));//copy ith byte to r
	}
	return r;
}
ll hashStr(char s[]){
	ll r=0;
	// each value <= 26 --> 5 bits, 32*5=160bits
	for (int i = 0; i < strlen(s); ++i) {
		r += (s[i]-'a')*26;
	}
	return r;
}
inline size_t __stl_hash_string(const char* __s)
{
	ll __h = 0; 
    //65*5 > 255
	for ( ; *__s; ++__s)
		__h = (5*__h + *__s)%MOD; 
	return size_t(__h);
}
int main(){
	node* hashtable[MOD];
	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>> s;
		temp = __stl_hash_string(s)%MOD;
		temp = find_and_insert(&hashtable[temp],s);
		if(temp)
			cout<<s<<temp;
		else cout<<"OK";
		cout<<endl;
	}

	return 0;
}
