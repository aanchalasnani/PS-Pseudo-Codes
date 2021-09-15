#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void levelOrder(Node* root){

	if(root!=NULL){

		stack<int> s;

		queue<Node*> q;
		q.push(root);

		while(!q.empty()){


			Node * cur = q.front();
			s.push(cur->data);

			//cout<<cur->data<<" ";

			q.pop();

			if(cur->left != NULL){
				q.push(cur->left);
			}
			if(cur->right != NULL){
				q.push(cur->right);
			}
		}

		//this is for reverse level order traversal
		while(!s.empty()){
			cout<<s.top()<<" ";
			s.pop();
		}
		cout<<"\n";
	}

}

int hgt(Node * root){

	if(root!=NULL){
		int lchild = hgt(root->left);
		int rchild = hgt(root->right);

		if(lchild>rchild){
			return(lchild+1);
		}
		else{
			return(rchild+1);
		}
	}
	return 0;
	
}


void Rpreorder(Node * root){

	if(root!=NULL){
		cout<<root->data<<" ";
		Rpreorder(root->left);
		Rpreorder(root->right);
	}

}


void Rpostorder(Node * root){

	if(root!=NULL){
		Rpostorder(root->left);
		Rpostorder(root->right);
		cout<<root->data<<" ";
	}

}


void Rinorder(Node * root){

	if(root!=NULL){
		Rinorder(root->left);
		cout<<root->data<<" ";
		Rinorder(root->right);
		
	}

}


void Ipreorder(Node * root){

	if(root!=NULL){
		//cout<<root->data<<" ";
		stack<Node*> s;
		s.push(root);

		while(!s.empty()){
			Node * cur = s.top();
			cout<<cur->data<<" ";
			s.pop();

			if(cur->right){
				s.push(cur->right);
			}

			if(cur->left){
				s.push(cur->left);
			}
			
		}
	}
}

void Ipostorder(Node * root){

	stack<int> temp;
	if(root!=NULL){
		//cout<<root->data<<" ";
		stack<Node*> s;
		s.push(root);

		while(!s.empty()){
			Node * cur = s.top();
			//cout<<cur->data<<" ";
			temp.push(cur->data);
			s.pop();

			if(cur->left){
				s.push(cur->left);
			}
			if(cur->right){
				s.push(cur->right);
			}
		}

		while(!temp.empty()){
			cout<<temp.top()<<" ";
			temp.pop();
		}
	}
}

void Iinorder(Node* root){

	

}


int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif


	struct Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->left->right->left = new Node(7);
	root->left->right->right = new Node(8);

	//created a tree
	levelOrder(root);

	cout<<"Height ==> "<<hgt(root)<<endl;

	cout<<"\nPreorder traversal Recursively ==> \n";
	Rpreorder(root);

	cout<<"\n\nPostorder traversal Recursively ==> \n";
	Rpostorder(root);

	cout<<"\n\nInorder traversal Recursively ==> \n";
	Rinorder(root);

	cout<<"\n\nIterative Preorder ==> \n";
	Ipreorder(root);

	cout<<"\n\nIterative Postorder ==> \n";
	Ipostorder(root);



}