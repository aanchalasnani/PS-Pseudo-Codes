#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>

using namespace std;


void Bfs(int starting , vector<vector<int>> adj, vector<bool> visited)
{
	//cout<<starting<<" ";
	visited[starting ]= true;
	int x;
	queue<int> q;
	q.push(starting);

	while(!q.empty()){
		x = q.front();
		cout<<x<<" ";
		q.pop();
		// visited[x] = true;
		for(int i : adj[x]){
			if(!visited[i]){
				q.push(i);
				visited[i]=true;
				//cout<<i<<" ";
				
			}
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
		Bfs(1, adj , visited);
		
		
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
//output : 
// 1 2 3 4 5 6 7 