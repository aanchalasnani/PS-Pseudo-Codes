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

int  isItSafe(int n, int m ,vector<vector<int>> a,int i , int j)
{
	return a[i][j]==1 && i<n && j<m && i>=0 && j>=0; 
}


void solve(int n, int m ,vector<vector<int>> &a,int i , int j){

	if(!isItSafe(n,m,a,i,j)){
		return;
	}
	
	a[i][j]=0;

	int xdir[] = {-1,1,0,0};
	int ydir[] = {0,0,1,-1};

	for(int k=0;k<4;k++){
		//if(isItSafe(n,m,a,i+xdir[k],j+ydir[k])){
		//if((i+xdir[k] < n && j+ydir[k]<m))
			solve(n,m,a, i+xdir[k] , j+ydir[k] );
		//}
	}

}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

		int n,m,cnt=0;
		cin>>n>>m;

		//int arr[n][m];

		vector<vector<int>> a;

		for(int i=0;i<n;i++){
			vector<int> temp1;
			for(int j=0;j<m;j++){
				int temp2;
				cin>>temp2;
				temp1.push_back(temp2);
				//cin>>arr[i][j];
			}
			a.push_back(temp1);
		}

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1){
					solve(n,m,a,0,0);
					cnt++;
				}
				//cout<<a[i][j]<<" ";
			}
			//cout<<endl;
		}

		cout<<"total number of connected components ==> "<<cnt<<endl;
		

	return 0;
}
