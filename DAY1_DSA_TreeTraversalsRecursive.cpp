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

int cnt =0 ;

void find_leafNodes(struct node* root)
{
	if(root!=NULL){
        if(root->left==NULL && root->right==NULL )
		  cout<<root->data<<" ";
		find_leafNodes(root->left);
		find_leafNodes(root->right);
        cnt++;
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("outputt.txt", "w", stdout);
	#endif

	struct node * root = new node(1);
	root->left = new node(2);
    root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);
	root->right->right = new node(7);

		
	find_leafNodes(root);
    cout<<"\nTotal no of nodes : "<<cnt<<endl;
	cout<<endl;


}

