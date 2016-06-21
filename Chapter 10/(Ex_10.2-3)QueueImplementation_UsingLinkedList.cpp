/* Ex-10.2-3
** Implement a queue by a singly linked list. The opeartions ENQUEUE and DEQUEUE should still take O(1) time.
*/

#include <iostream>
using namespace std;

struct queue{
	int val;
	queue* next;
} *head=NULL, *tail=NULL;

void enqueue(int key);
void display(queue* h);
int dequeue(void);

int main() {

	int n;
	cin>>n;

	for (int i=0; i<n; i++){
		int key;
		cin>>key;
		enqueue(key);
	}

	display(head);
	cout<<dequeue()<<endl;;
	cout<<dequeue()<<endl;
	cout<<dequeue()<<endl;
	display(head);
	enqueue(12);
	display(head);
	cout<<dequeue()<<endl;
	display(head);

	return 0;
}

void enqueue(int key){

	queue* temp= new queue;
	temp->val= key;
	temp->next= NULL;

	if (head==NULL && tail== NULL){
		head= tail= temp;
	}

	else{
		tail->next= temp;
		tail= temp;
	}

}

void display(queue* h){

	if (h==NULL)
		cout<<"No elements!!";

	queue* temp= h;

	while(temp!=NULL){
		cout<<temp->val<<"<-";
		temp= temp->next;
	}

	cout<<endl;

}

int dequeue(void){

	if (head==NULL){
		cout<<"UNDERFLOW!!";
		return -1;
	}

	queue* temp= head;

	if (head==tail){    // only 1 element left
		head= tail= NULL;
		return temp->val;
	}

	head= temp->next;
	int value= temp->val;
	delete(temp);

	return value;
}

