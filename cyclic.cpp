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


bool dfs(int cur , vector<vector<int>> adj , vector<int> & vis , int par){

	vis[cur] = 1;

	for(int child : adj[cur]){

		if(!vis[child]){
			if(dfs(child,adj,vis,cur)){
				return true;
			}
		}
		else{
			if(child != par){   
				return true;
			}
		}
	}
	return false;

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


	if(dfs(1,adj,vis,-1)){
		cout<<"CYCLIC GRAPH"<<endl;
	}
	else{
		cout<<"NOT A CYCLIC GRAPH"<<endl;
	}





	return 0;
}
