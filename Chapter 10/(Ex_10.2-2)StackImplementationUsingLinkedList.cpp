/* Ex-10.2-2 
** Implement a stack using a singly linked list L. The operations PUSH and POP should still take O(1) time.
*/

#include <iostream>
using namespace std;

struct stack{
	int val;
	stack* next;
} *head;

void push(int key);
void display(stack* h);
int top(void);
int pop(void);

int main() {
	int n;
	cin>>n;

	for (int i=0; i<n; i++){
		int key;
		cin>>key;
		push(key);
	}

	display(head);
	push(12);

	cout<<pop()<<endl;;
	cout<<pop()<<endl;
	cout<<pop()<<endl;

	display(head);

	cout<<top()<<endl;
	cout<<pop()<<endl;

	display(head);

	return 0;
}

void push(int key){

	stack* temp= new stack;
	temp->val= key;
	temp->next= head;
	head= temp;

}

void display(stack* h){

	if (h==NULL)
		cout<<"No elements!!";

	stack* temp= h;

	while(temp!=NULL){
		cout<<temp->val<<"->";
		temp= temp->next;
	}

	cout<<endl;
}

int pop(void){

	if (head==NULL){
		cout<<"UNDERFLOW!!";
		return -1;
	}

	stack* temp= head;
	head= temp->next;

	return temp->val;

}

int top(void){

	if (head==NULL){
		cout<<"no elements!!";
		return -1;
	}
	
	return head->val;
}