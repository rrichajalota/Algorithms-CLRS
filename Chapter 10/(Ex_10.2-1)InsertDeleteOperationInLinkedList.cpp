/* Ex-10.2-1 
** Implementation of Insert and Delete operation on a singly linked list in O(1) time.
*/

#include <iostream>
using namespace std;

struct node{
	int val;
	node* next;
} *head;

void insert(int key);
void display(node* h);
void deletenode(void);

int main() {
	int n;
	cin>>n;
	for (int i=0; i<n; i++){
		int key;
		cin>>key;
		insert(key);
	}
	display(head);
	deletenode();
	display(head);
	deletenode();
	display(head);
	deletenode();
	display(head);
	deletenode();
	display(head);
	deletenode();
	display(head);
	return 0;
}

void insert(int key){
	node* temp= new node;
	temp->val= key;
	temp->next= head;
	head= temp;
}
void display(node* h){
	node* temp= h;
	while(temp!=NULL){
		cout<<temp->val<<"->";
		temp= temp->next;
	}
	cout<<endl;
}
void deletenode(void){
	if (head==NULL)
		return ;
	node* temp= head;
	head= temp->next;
}