#include<bits/stdc++.h>
using namespace std;

int c = 0;

// recursion 
// dfs
// graph 
// dfs
// optimization


void rat_maze(int n , int i , int j , vector<vector<int>> grid){

	//base cases :
	if(i==n-1 && j==n-1) // this is required pos
	{
		c+=1;
	}
	if(i < 0 || j < 0 || i>=n || j >=n) // out of bound
	{
		return;
	}

	// up r = r-1 and c = c
	// down r = r + 1 and c = c
	// right c = c + 1 and r = r
	// left c = c -1 and r = r

	int r[] = {-1 , 1 , 0, 0 };
	int c[] = {0 , 0 , 1 , -1};

	for(int k=0 ; k < n ; i++){
		rat_maze(n,i + r[k] , j + c[j] , grid);
	}


}


int main() {

	

}