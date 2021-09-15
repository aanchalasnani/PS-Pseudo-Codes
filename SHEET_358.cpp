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


//this is dfs

void dfs(vector<vector<int>> adj , int curr , vector<bool> & visited)
{

	//cout<<curr<<" ";
	visited[curr]=true;

	for(int i : adj[curr]){
		if(visited[i]){
			cout<<"visi : "<<i<<" ";
		}
		if(!visited[i]){
			dfs(adj,i,visited);
		}
	}
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

		int V;cin>>V;
		int E;cin>>E;
		int i;

		vector<vector<int>> adj(V+1);
		vector<bool> visited( V+1 , false );

		loop0(i,E){
			int u,v;
			cin>>u>>v;
			adj[u].pb(v); 
			adj[v].pb(u); //undirected ke liye
		}

		dfs(adj,1,visited);

	return 0;
}
