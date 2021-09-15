#include<bits/stdc++.h>
using namespace std;



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

#define loop(i, a, b) for(int i = (a); i < (b); ++i)
#define loop0(i, a) loop(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)

int cnt = 0 ;

void display(vector<vector<bool>> grid , int n){

	for(int i = 0 ; i < n ; i++){
		cout<<"| ";
		for(int j=0 ; j < n ; j ++){
			
			if(grid[i][j]){
				cout<<"Q ";
			}
			else{
				cout<<"_ ";
			}
			
		}
		cout<<" |";
		cout<<endl;
	}
}

bool isSafe(vector<vector<bool>> &grid,int n,int row,int col){

	for(int i = row-1 ; i >=0 ; i --){
		if(grid[i][col]){
			return false;
		}
	}

	for(int i=row-1,j=col-1 ; i>=0 and j>=0 ; i--,j--){
		if(grid[i][j]){
			return false;
		}
	}

	for(int i=row-1,j=col+1 ; i>=0 and j<n ; j++,i--){
		if(grid[i][j]){
			return false;
		}
	}

	return true;

}
void Nqueens(vector<vector<bool>> &grid , int n , int cur_row){

	//base case
	if(cur_row==n){
		cnt++;
		display(grid,n);
		cout<<"\n\n";
		return;
	}

	for(int i = 0 ; i < n ; i ++){
		if(isSafe(grid , n , cur_row , i))
		{
			grid[cur_row][i]=true;
			Nqueens(grid,n,cur_row+1);
			grid[cur_row][i]=false;
		}
	}
}


int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

		int n;
		cin>>n;

		vector<vector<bool>> grid(n , vector<bool>(n,false));

		Nqueens(grid,n,0); // 0 is the initial or the starting row

		cout<<"Total Possible Arrangements :==> "<<cnt<<endl;

	return 0;
}
