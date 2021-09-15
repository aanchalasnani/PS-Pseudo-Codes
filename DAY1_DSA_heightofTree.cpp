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

int TreeHeight(node *root){

	if(root == NULL){
		return 0;
	}
	int l = TreeHeight(root->left);
	int r = TreeHeight(root->right);

	if(l>r){
		return l+1;
	}
	else{
		return r+1;
	}
}

int ans = 0;

int  TreeDiameter(node * root){

	if(root == NULL){
		return 0;
	}
	int l = TreeDiameter(root->left);
	int r = TreeDiameter(root->right);

	int temp = max(l,r)+1;
	int res = max(l+r+1 , temp);
	ans = max(ans, res);

	return temp;
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

	cout<<"Height of Tree : "<<TreeHeight(root)<<endl;
	TreeDiameter(root);
	cout<<"Diameter of Tree : "<<ans<<endl;
	
	return 0;
}
