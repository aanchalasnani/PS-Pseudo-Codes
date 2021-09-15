#include<bits/stdc++.h>

using namespace std;

//creating the structure of a single node in a tree using structures in C++
struct node {

	struct node* left;
	int data;
	struct node* right;

	node(int data){

		this->data = data;
		left = right = NULL;

	}
};

void recursive_preorder(struct node* root)
{
	if(root!=NULL){
		cout<<root->data<<" ";
		recursive_preorder(root->left);
		recursive_preorder(root->right);
	}
}

void recursive_inorder(struct node* root)
{
	if(root!=NULL){
		recursive_inorder(root->left);
		cout<<root->data<<" ";
		recursive_inorder(root->right);
	}
}

void recursive_postorder(struct node* root){
	if(root!=NULL){
		recursive_postorder(root->left);
		recursive_postorder(root->right);
		cout<<root->data<<" ";
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("outputt.txt", "w", stdout);
	#endif

	struct node * root = new node(10);
	root->left = new node(20);
    root->right = new node(50);
	root->left->left = new node(30);
	root->left->right = new node(40);
	root->right->left = new node(60);
	root->right->right = new node(70);

			// 	    10
			//  20		50
		 //  30   40  60   70

	recursive_preorder(root);
	cout<<endl;
	recursive_inorder(root);
	cout<<endl;
	recursive_postorder(root);


}


// output : 

// 10 20 30 40 50 60 70 
// 30 20 40 10 60 50 70 
// 30 40 20 60 70 50 10 