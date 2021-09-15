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

#define f1r(i, a, b) for(int i = (a); i < (b); ++i)
#define f0r(i, a) f1r(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)

int totalTours = 0;

bool isItSafe(vector<vector<int>> &grid,int row , int col ,int n, vector<vector<bool>> &visited)
{
	return row>=0 and col>=0 and row<n and col<n and visited[row][col]==false;
}

void display(vector<vector<int>> grid , int n){

	for(int i = 0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cout<<grid[i][j]<<"   ";
		}
		cout<<"\n";
	}
}
void KnightTour(vector<vector<int>> &grid , int row , int col , int n , int count , vector<vector<bool>> &visited)
{

	//base case :
	if(count == n*n - 1){
		//we have found one sol ==>
		totalTours++;
		display(grid,n);
		cout<<"\n\n";
		return;
	}

	if(count>= n*n){
		return;
	}

	//we need to make all the possible calls to all the possible locations that a knight can reach ==>

	int xdir[] = {-1 , -1 , -2 ,-2 ,1 ,1,2,2}; //8 pos
	int ydir[] = {2 , -2 , -1 , 1 , 2,-2,1,-1}; //8 pos

	grid[row][col]=count;
	visited[row][col]=true;
	for(int i = 0 ; i <8 ; i ++){

		if(isItSafe(grid,row+xdir[i],col+ydir[i],n,visited))
		{
			KnightTour(grid,row+xdir[i],col+ydir[i],n,count+1,visited);
		}
	}
	//grid[row][col]=-1;
	visited[row][col]=false;
	
}


int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

		int n;
		cin>>n;
		int cnt=0;
		vector<vector<int>> grid(n, vector<int> (n,-1));
		vector<vector<bool>> visited(n, vector<bool> (n,false));

		KnightTour(grid , 0 , 0 ,n,cnt , visited);
		//cout<<"TOTAL COUNT : "<<cnt<<endl;
		cout<<"TOTAL TOURS : "<<totalTours<<endl;

	return 0;
}
