#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>

using namespace std;


void dfs(int starting , vector<vector<int>> adj, vector<bool> visited)
{
	cout<<starting<<" ";
	visited[starting]= true;

	for (int i : adj[starting])
	{
		if(!visited[i]){
			dfs(i,adj,visited);
		}
	}	
}	
int main()
{


	#ifndef ONLINE_JUDGEB
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	
		int n;
		cin>>n;
		vector<vector<int>> adj;
		
		adj.resize(n+1);
		//level.resize(n+1);
		for(int i = 0;i<n-1;++i){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		vector<bool> visited;
		visited.resize(n+1);
		for (int i = 0; i < n+1; ++i)
		{
			visited[i]=false;
		}
		dfs(1, adj , visited);
		
		
	return 0;
}

// input : 
// 7
// 1 2
// 1 3
// 1 4
// 1 5
// 2 6
// 2 7
// Output : 
// 1 2 6 7 3 4 5 