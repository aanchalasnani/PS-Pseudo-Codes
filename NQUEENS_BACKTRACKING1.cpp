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

int cnt=0;

bool isItSafe(vector<vector<bool>> &grid, int row , int col , int n)
{
	//column check
	for(int i=row-1 ; i>=0 ; i--){
		if(grid[i][col]){
			return false;
		}
	}

	//right diagonal
	for(int i = row-1,  j=col+1 ; i>=0 && j<n ; i--,j++){
		if(grid[i][j]){
			return false;
		}
	}

	//left diagonal
	for(int i = row-1, j=col-1 ; i>=0 && j>=0 ; i--,j--){
		if(grid[i][j]){
			return false;
		}
	}

	return true;
}


void displayGrid(vector<vector<bool>> grid, int n){

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(grid[i][j]){
				cout<<" Q ";
			}
			else{
				cout<<" _ ";
			}
		}
		cout<<"\n";
	}
}

void NQueens(vector<vector<bool>> &grid, int cur_row , int n){

	//BASE CASE :
	if(cur_row == n){
		//we have found one sol
		displayGrid(grid,n);
		cout<<"\n\n";
		cnt++;
		return;
	}

	//place queen 1 by 1 to every spot/column

	for(int i=0 ; i<n ; i++){

		if(isItSafe(grid,cur_row,i,n)){
			grid[cur_row][i] = true;
			NQueens(grid,cur_row+1,n);
			grid[cur_row][i] = false;
		}
	}
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

	int n ;
	cin>>n;
	vector<vector<bool>> grid(n , vector<bool>(n,false));

	NQueens(grid,0,n);
	cout<<"POSSIBLE ANSWERS : "<<cnt<<endl;


	return 0;
}
