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


void DFS(int node , vector<vector<int>> & adj , vector<bool> & visited){

	cout<<node<<" ";
	visited[node] = true;

	for(int i : adj[node]){
		if(!visited[i]){
			DFS(i,adj,visited);
		}
	}

}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

		int V;
		cin>>V;

		int E; cin>>E;

		vector<vector<int>> adj(V+1);
		for(int i = 0 ; i < E ; i++){

			int u , v ;
			cin>>u>>v;

			adj[u].push_back(v);

		}

		vector<bool> visited(V+1);
		for (int i = 0; i <=V; ++i)
		{
			visited[i] = false;
		}
		int source = 1;
		DFS(source , adj , visited);
	return 0;
}
