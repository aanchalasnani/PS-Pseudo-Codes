#include<bits/stdc++.h>
using namespace std;

using namespace std;

// template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define f1r(i, a, b) for(int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)


// void dfs(vector<vector<int>>& grid , int i , int j){
//         if(grid[i][j]==0 || i<0 || j<0 || i>=grid.size() ||j>=grid[i].size() ){
//             return;
//         }
//         grid[i][j]=0;
//         //int xdir[] = {0,0,-1,1};
//         //int ydir[] = {-1,1,0,0};
//         //count = count + 1;
//         // for(int d=0 ; d<4 ; d++){
//         //     dfs( grid , i + xdir[d], j+ydir[d] );
//         // }
//         if((i+1)<grid.size())
//         	dfs( grid , i + 1, j+0 );
//         if((i-1)>=0)
//         	dfs( grid , i -1 , j+0 );
//         if((j+1)<grid[i].size())
//         	dfs( grid , i + 0, j+1 );
//         if((j-1)>=0)
//         	dfs( grid , i + 0, j-1 );
//         //cout<<count<<" "<<endl;
//         // if(count>=max){
//         //     max = count;
//         // }
//     }
// int maxAreaOfIsland(vector<vector<int>>& grid) {
        
//         int count = 0 ;
//         for (int i = 0 ; i < grid.size() ; i++){
             
//             for (int j = 0 ; j < grid[i].size() ; j++)
//             {
               
                
//                  if(grid[i][j] == 1){
//                      //cout<<"here"<<endl;
//                  	count++;
//                     // dfs(grid,i,j);
//                  }
//             }
//         }
//         return count;
// }

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif
		int n = 13;
		int m = 8;
		vector<vector<int>> grid;
		for(int i = 0 ; i < n ; i++ ){
			for(int j = 0 ; j < m ; j++){
				int temp;
				cin>>temp;
				grid[i].push_back(temp);
			}
		}
		for(int i = 0 ; i < n ; i++ ){
			for(int j = 0 ; j < m ; j++){
				cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
		//cout<<maxAreaOfIsland(grid)<<endl;

	return 0;
}
