#include<bits/stdc++.h>
using namespace std;

struct node{

	struct node* left;
	int data;
	struct node* right;

	node(int data){
		this->data = data;
		left = right = NULL;
	}
};

void Iterative_preorder(node * root){

	stack<node*> s;
	s.push(root);

	while(!s.empty()){
		node * curr = s.top();
		cout<<curr->data<<" ";
		s.pop();

		if(curr->right!=NULL){
			s.push(curr->right);
		}
		if(curr->left!=NULL){
			s.push(curr->left);
		}
		
	}
	cout<<"\n";

}

//using 2 stacks
void Iterative_postorder(node * root){

	stack<node*> s;
	s.push(root);
	stack<int> postorder;

	while(!s.empty()){
		node * curr = s.top();
		postorder.push(curr->data);
		s.pop();

		
		if(curr->left!=NULL){
			s.push(curr->left);
		}
		if(curr->right!=NULL){
			s.push(curr->right);
		}
		
	}

	while(!postorder.empty()){
		cout<<postorder.top()<<" ";
		postorder.pop();
	}
	cout<<"\n";

}

//using single stack
void postorder(node* root){

	stack<node*> s;
	while(1){
		while(root != NULL){
			s.push(root);
			s.push(root);
			root = root->left;
		}
	
		if(s.empty()) return;
		root = s.top();
		s.pop();

		if(!s.empty() && s.top()==root){
			root = root->right;
		}
		else{
			cout<<root->data<<" ";
			root = NULL;
		}
	}
}


// using single stack
void Iterative_inorder(node* curr){

	stack<node*> s;
	while(curr!=NULL || !s.empty()){

		if(curr!=NULL){
			s.push(curr);
			curr = curr->left;
		}
		else{
			curr = s.top();
			s.pop();
			cout<<curr->data<<" ";
			curr = curr->right;
		}
	}
	cout<<"\n";
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif


	struct node * root = new node(10);
	root->left = new node(20);
    root->right = new node(50);
	root->left->left = new node(30);
	root->left->right = new node(40);
	root->right->left = new node(60);
	root->right->right = new node(70);

		//   	    10
		//      20		50
		//   30   40  60   70

	Iterative_preorder(root);
	Iterative_postorder(root);
	Iterative_inorder(root);
	postorder(root);
	// 10 20 30 40 50 60 70 
	// 30 40 20 60 70 50 10 
	// 30 20 40 10 60 50 70 

	return 0;
}
