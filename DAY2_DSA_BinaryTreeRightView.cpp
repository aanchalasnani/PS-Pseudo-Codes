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

void rightview(node* root){

	if(root==NULL){
		return;
	}

	
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		
		int n = q.size();
		for(int i = 1 ; i <= n ; i++){
			node* temp = q.front();
			q.pop();
			if(i==n){
				cout<<temp->data<<" ";
			}
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}

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

	rightview(root);

	return 0;
}
