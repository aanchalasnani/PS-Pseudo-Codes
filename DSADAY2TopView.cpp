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

void topview(node* root){

	if(root==NULL){
		return;
	}

	map<int,int> mp; //scale , height
	queue<pair<node*, int>> q;

	q.push({root, 0});

	while(!q.empty()){
		node* temp = q.front().first;
		int h = q.front().second;
		q.pop(); 
		
		if(mp[h]==0){
			mp[h]=temp->data;
		}
		if(temp->left){
			q.push({temp->left, h-1});
		}
		if(temp->right){
			q.push({temp->right, h+1});
		}
	}

	//print
	for(auto topnodes : mp)
	{
		cout<<topnodes.second<<" ";
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

	topview(root);

	return 0;
}
