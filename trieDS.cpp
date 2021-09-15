#include<bits/stdc++.h>
using namespace std;

struct node {
	vector<node *> children;
	char ch;
	bool isEnd ; 
};


node* create_new(char ch = 0){
	node * root  = (node *)malloc(sizeof(node));
	root->isEnd = false ; //this is by default set to false 
	return root;
}

node * root = create_new();

node * insert_char(node * root , char c ){


	int found = -1 ; // initially we are assuming it to be not found
	for(int i=0; i< root->children.size() ; i++){
		if(root->children[i]->ch == c){
			found = i;
		}
	}
	if(found == -1){ //we need to create found
		node * new_node = create_new();
		root->children.push_back(new_node);
		return root;
	}
	//we need to return that available node
	return root->children[found];
}

void insert_word(node * root, string & word ){
	for(int i=0;i<word.size();i++)
	{
		char c = word[i];
		// we need to insert this charater to trie
		node * new_root = insert_char(root, c);
		root = new_root;

		if(i+1 == word.size()) // the last character
		{
			root->isEnd = true;
		}
	}
}

node* goto_next(node* root, char c)
{
	// iterate through root->children . If there is child, then take it.
	for(int i =0 ; i < root->children.size() ; i++){
		if(root->children[i]->ch == c){
			return root->children[i];
		}
	}
	return NULL ; 
}

node * find_word(node* root , string word)
{
	for(int i=0;i<word.size();i++){
		char ch = word[i];

		node* new_root = goto_next(root, ch);

		if(new_root == NULL){
			//not found;
			cout<<"NOT FOUND"<<endl;
			return NULL;
		}

		root = new_root;

		// we also need to check if there is a word ending here

		if(i==word.size()-1){ //last character
			if(root->isEnd == true){
				cout<<"FOUND"<<endl;
				return root;
			}
		}
	}
	return NULL;
}

int main(){

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputtt.txt","w",stdout);
	#endif

	while(true) {


		string type , word ;
		cin>> type >> word;

		if(type == "i" || type == "I"){
			insert_word(root, word);
		}
		else if( type == "f" || type == "F"){
			node * r = find_word(root , word);
			cout<< bool(r) << endl ;
		}
	}
}