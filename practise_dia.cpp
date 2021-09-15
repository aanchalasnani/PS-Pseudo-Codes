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


int maxD , maxNode;

void dfs(int cur , int d , vector<vector<int>> & adj , vector<int> & v){

	v[cur] = 1;

	if(d>maxD){
		maxD = d;
		maxNode = cur;
	}

	for(int neigh : adj[cur]) {
		if(!v[neigh]){
			dfs(neigh , d+1 , adj , v);
		}
	}


}

int ans;

void dia(vector<vector<int>> adj ){

	

}


int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	vector<vector<int>> adj(n+1);
	vector<int> vis(n+1,0);

	for(int i = 0 ; i<n-1 ; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//max dia:

	maxD = -1;

	dfs(1,0,adj,vis);


	maxD = -1 ;

	for(int i = 0 ; i <= n ; i ++) {
		vis[i] = 0;
	}

	dfs(maxNode , 0 , adj , vis);

	cout<<"Diameter : "<<maxD<<endl;







	return 0;
}
