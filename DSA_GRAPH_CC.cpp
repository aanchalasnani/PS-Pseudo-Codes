#include<bits/stdc++.h>
using namespace std;

int cc=0;

void dfs(int cur , vector<vector<int>> &adj , vector<bool> &vis){
	vis[cur] = true;
	// cout<<cur<<" ";

	for(auto i : adj[cur]){
		if(!vis[i]){
			dfs(i,adj,vis);
		}
	}
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif

	int n; //no of nodes
	cin>>n;

	int e; //no of edges
	cin>>e;

	vector<vector<int>> adj(n+1);
	vector<bool> vis(n+1,false); 

	for(int i=0; i<e ; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// cout<<"our adjancy list ==>\n";

	// for(int i=1;i<=n;i++){
	// 	cout<<i<<" ==> ";
	// 	for(int j:adj[i]){
	// 		cout<<j<<" ";
	// 	}
	// 	cout<<"\n";
	// }

	// cout<<"\n\n\nDFS ==> \n";
	for(int i = 1 ; i <=n ; i++)
	{ 
		if(!vis[i]){
			dfs(i,adj,vis);
			cc++;
		}
		
	}

	cout<<cc<<endl;


	return 0;
}

// answer accepted on below link
// https://www.hackerearth.com/problem/algorithm/connected-components-in-a-graph/