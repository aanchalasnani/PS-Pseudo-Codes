
void sum(int *a , int *b){
	 
	 *a=*a+*b; //1
	 *b=*a-*b; 
	 *a=*a-*b;

}

int main() {
	int a,b;
	cin>>a>>b;
	cout<<sum(&a,&b);
}


a = 4 , b= 3 ;
a = 7;
b = 4;
a = 3;


void inorder_traversal(root){
	if(root!=null){
	inorder_traversal(root->leftchild);
	cout<<root->data;
	inorder_traversal(root->rchild);
	}
}
       1
     2     4
   5  6  7   8

vector<int> leftview(root){
	if(root==Null){
		return v;
	}
	else {
	
	vector<int> v;
	v.push_back(root->data);
	leftview(root->left);
	}
}

Given a string s containing '(',')' as inputs
Check whether input string is valid I/P = "()"
O/P = TrueI/P = "())("
O/P = False	

