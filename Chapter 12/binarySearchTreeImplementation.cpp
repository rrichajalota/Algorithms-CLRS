// basic implementation of a Binary Search Tree
#include <iostream>
using namespace std;

struct node{
	int val;
	node* left;
	node* right;
};

node* createNode(int key);
node* insert(node* root, int key);
void display(node* root);

int main() {
	// your code goes here
	int n; //no. of nodes to be created 
	cin>>n; 
	int key;
	node *root=NULL;
	for (int i =1; i<=n; i++){
		cin>>key;
		root=insert(root, key);
	}
	display(root);
	return 0;
}

node* createNode(int key){
	node* newnode= new node;
	newnode->val=key;
	newnode->left=newnode->right=NULL;
	return newnode;
}

node* insert(node* root, int key){
	node *temp= createNode(key);
	if (root==NULL){
		root= temp;
		cout<<temp->val<<" root "<<endl;
	}
	else if (temp->val < root->val){
		root->left=insert(root->left,key);
		cout<<root->left->val<<" left "<<endl;
	}
	else{
		root->right= insert(root->right,key);
		cout<<root->right->val<<" right "<<endl;
	}
	return root;
}

void display(node* root){
	if (!root)
		return ;
	display(root->left);
	cout<<root->val<<" ";
	display(root->right);
}

