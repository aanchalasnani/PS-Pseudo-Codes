#include<bits/stdc++.h>
using namespace std;

void printSubset(int a[] ,int i, int n , string osf){

	if(i==n){
		cout<<"["<< osf <<"]"<<endl;
		return;
	}
	printSubset(a,i+1,n,osf+to_string(a[i]));
	printSubset(a,i+1,n,osf);

}

void printCons(int n , int i ,string osf){
	if(i==n){
		cout<<osf<<endl;
		return;
	}
	if(osf[0]!='1')
	{
		printCons(n, i+1 , "0"+osf);
		printCons(n, i+1 , "1"+osf);
	}
	
	if(osf[0]=='1'){
		printCons(n,i+1,"0"+osf);
	}

}


int totalP = 0;

void MazePath(int n , int m , int i , int  j , string osf){

	if(i == n-1 && j== m-1){
		cout<<osf<<endl;
		totalP += 1;
		return;
	}
	if(i >= n || j >= m){
		return;
	}

	MazePath(n,m,i+1,j,osf+"D"); // downward move
	MazePath(n,m,i+1,j+1,osf+"\\"); // diagonal move
	MazePath(n,m,i,j+1,osf+"R"); //rightward move
}

int Path =0 ;
void SixJumps(int n , int  i , string osf ) // dicepath
{

	if(n-1 == i){
		cout<<osf<<endl;
		Path += 1;
		return;
	}
	if(i>=n){
		return;
	}
	SixJumps(n,i+1,osf + '1'+"->");
	SixJumps(n,i+2,osf + '2'+"->");
	// SixJumps(n,i+3,osf + '3'+"->");
	// SixJumps(n,i+4,osf + '4'+"->");
	// SixJumps(n,i+5,osf + '5'+"->");
	// SixJumps(n,i+6,osf + '6'+"->");
}

void LexicoGraphiOrder(int n  , int  i )
{
	if(i>n){
		return ; 
	}
	cout<<i<<endl;
	//cout<<" : "<<osf;
	for (int j = (i==0?1:0); j < 9; ++j)
	{
		//LexicoGraphiOrder(n , i+1 , osf+to_string(j));
		LexicoGraphiOrder(n , 10*i+j);
	}
		
}

void UniqueStringPermutation(string s , string osf)
{
	if(s.size()==0){
		cout<<osf<<endl;
		return;
	}
	unordered_set<char> sett ;

	for (int i = 0; i < s.size(); ++i)
	{
		char ch = s[i]; //current character
		if(sett.count(ch)==0)
		{
		string ros = s.substr(0,i) + s.substr(i+1);//rest of string after cutting out ch
		sett.insert(ch);
		UniqueStringPermutation(ros ,osf+ch);
	}
	}
	
}

void swap(char *str1 ,char *str2){
	char temp;
	temp = *str1;
	*str1=*str2;
	*str2=temp;
}

void Permutation_Recursive(string str , int j){
	if(str.size()-1 == j){
		cout<<str<<endl;
		return;
	}
	for (int i = j; i < str.size(); ++i)
	{
		swap(&str[i] , &str[j]);
		Permutation_Recursive(str,j+1);
		swap(str[i],str[j]);
	}
}


int RattotalPaths=0;

bool isItSafe(int i , int j , int  n , vector<vector<bool>> &visited)
{
	return i>=0 && j >= 0 && i<n && j<n && visited[i][j]==false;
}

void helper(int  i ,int j , int n ,vector<vector<int>> &grid ,vector<vector<bool>> &visited)
{
	if(i== n-1 && j == n-1){
		RattotalPaths++;
	}
	if(!isItSafe(i,j,n,visited)){
		//pruning
		return;
	}
	visited[i][j]=true;
	// 0 means open // 1 means blocked
	if(i+1<n && grid[i+1][j]==0) //down
	{
		helper(i+1,j,n,grid,visited);
	}
	if(j+1<n &&grid[i][j+1]==0) //right
	{
		helper(i,j+1,n,grid,visited);
	}
	if(j-1 >=0 && grid[i][j-1]==0) //left
	{
		helper(i,j-1,n,grid,visited);
	}
	if(i-1>=0 && grid[i-1][j]==0) //up
	{
		helper(i-1,j,n,grid,visited);
	}
	visited[i][j]=false;
	return;
	
}

void CountMaze(vector<vector<int>> &grid){
	int n = grid.size();
	vector<vector<bool>> visited(n,vector<bool>(n,false));
}

int n = 3;

void tictactoe(int i , int j , string s){

}

int main()
{


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

		int t;
		cin>>t;
		while(t--){

			char s[3][3];
			
		}
		
		
}