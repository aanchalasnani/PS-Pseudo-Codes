#include<bits/stdc++.h>
using namespace std;


bool dfs(int cur ,int par, vector<vector<int>> &adj , vector<bool> &vis ){
	vis[cur] = true;
	

	for(auto i : adj[cur]){
		if(!vis[i]){
			bool res = dfs(i,cur,adj,vis);
			if(res == false){
				return false; // cycle found
			}
		}
		else
			if(i!=par){
				return false; // cycle found
			} 
	}
	return true; // not a cycle
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

	// cout<<"\n\n\nDFS ==> \n";
	if(dfs(1,-1,adj,vis)){
		cout<<"Cycle Not found"<<endl;
	}
	else{
		cout<<"Cycle Found"<<endl;
	}


	return 0;
}
