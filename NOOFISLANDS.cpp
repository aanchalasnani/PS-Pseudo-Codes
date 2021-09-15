#include<bits/stdc++.h>
using namespace std;



int issafe(vector<vector<int>> &M , int r , int c , int i , int j){

	return i>=0&&j>=0&&i<r&&j<c&&(M[i][j]==1);

}

void DFS(vector<vector<int>> &M ,int  r ,int  c , int i , int j){

	 //visited

	if(!issafe(M,r,c,i,j)){
		return;
	}

	M[i][j]=0;
	//cout<<"ii : "<<i<<" jj : "<<j<<endl;

	int xdir[] = {1,-1,0,0,1,-1,-1,1};
	int ydir[] = {0,0,1,-1,1,-1,1,-1};

	for(int k = 0 ; k <8 ; k ++){
		DFS(M , r , c , i+xdir[k] , j+ydir[k] );
	}

}

int countIslands(vector<vector<int>> &M , int r , int c)
{
	int paths = 0 ;
	for (int i = 0; i < r; ++i)
	{
		for(int j = 0 ; j<c; j++){

			if(M[i][j]==1){

				// cout<<"i : "<<i<<"j : "<<j<<endl;
				DFS(M,r,c,i , j );
				paths++;
			}
		}
	}
	return paths;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

    // int M[][5] = { { 1, 1, 0, 0, 0 },
    //                  { 0, 1, 0, 0, 1 },
    //                  { 1, 0, 0, 1, 1 },
    //                  { 0, 0, 0, 0, 0 },
    //                  { 1, 0, 1, 0, 1 } };

	vector<vector<int>> M {

					 { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } // expected count = 5
	};

	// vector<vector<int>> M;
	// int a;

	// for(int i = 0 ; i < 5 ; i++)
	// {
	// 	for(int j = 0 ; j < 5 ; j++){
	// 		cin>>a;
	// 		M[i].push_back(a);
	// 	}
	// }


	// for (int i = 0; i < 5; ++i)
	// {
	// 	for(int j = 0 ; j < 5 ; j++){
	// 		cout<<M[i][j];
	// 	}
	// }
    cout << "Number of islands is: " << countIslands(M, 5, 5)<<endl;

    return 0;
}
