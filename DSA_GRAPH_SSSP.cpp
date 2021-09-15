//single source shotest path using dfs for trees only

#include<bits/stdc++.h>
using namespace std;

vector<int> dis(5, 0);

void dfs(int cur ,int d , vector<vector<int>> &adj , vector<bool> &vis){
	vis[cur] = true;
	cout<<cur<<" ";
	dis[cur] = d;
	// if(dis[cur]==0)
	
	for(auto i : adj[cur]){
		if(!vis[i]){
			// if(dis[i]==0)
				
			dfs(i,dis[cur]+1,adj,vis);
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

	cout<<"our adjancy list ==>\n";

	for(int i=1;i<=n;i++){
		cout<<i<<" ==> ";
		for(int j:adj[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}

	cout<<"\n\n\nDFS ==> \n";
	// dis[1] = -1;
	dfs(1,0,adj,vis);

	cout<<"\n\nDistances ==> \n";
	for(int i=1 ; i<=n ; i++){
		cout<<dis[i]<<" ";
	}


	return 0;
}
