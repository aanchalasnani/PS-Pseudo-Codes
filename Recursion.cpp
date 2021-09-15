#include<bits/stdc++.h>
using namespace std;

void pattern(int n,int i ){

	if(n==0) return;

	if(i<n)
	{
		// print column
		cout<<"* ";
		pattern(n,i+1);
	}
	else {
		//change the row
		cout<<endl;
		pattern(n-1,0);
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<"* ";
	// }
	// cout<<"\n";

	// pattern(n-1);



}

void pattern1(int n , int i ){
	if(n==0) return;

	if(i>=n){
		cout<<"* ";
		pattern1(n,i-1);
	}
	else{
		cout<<endl;
		pattern1(n-1,7);
	}

}

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
	SixJumps(n,i+3,osf + '3'+"->");
	SixJumps(n,i+4,osf + '4'+"->");
	SixJumps(n,i+5,osf + '5'+"->");
	SixJumps(n,i+6,osf + '6'+"->");
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

void StrPermutation(string s , int n , int i , int j){

	if(i<0){
		return;
	}
	cout<<s;
	StrPermutation(s,n,i,j+1);

}

int main()
{


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif


		int n ;
		//cin>>n ;
		//pattern1(7,7);
		//return 0;

		//int a[] = {1,2,3};
		//printSubset(a,0,3,"");
		//printCons(4,0," ");
		//vector<<vector<int>> v;

		//MazePath(3,3,0,0,"");
		//cout<<"Total Paths : "<<totalP<<endl;

		//SixJumps(4, 0 , "");
		LexicoGraphiOrder(13,0);
		//cout<<"Paths  : "<<Path<<endl;
		
}