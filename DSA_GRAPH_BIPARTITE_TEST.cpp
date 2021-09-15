// bipartite graph also known as bigraph special graph
// such that you can divide the vertex set into two
//disjoints set such that :
// 1.) each vertex belongs to exactly one of the 2 sets
// 2.) each edge connects vertex of 2 different sets 



#include<bits/stdc++.h>
using namespace std;

int col[10]; //color array

bool dfs(int cur ,int colr, vector<vector<int>> &adj , vector<bool> &vis ){
	vis[cur] = true;
	// cout<<cur<<" ";
	col[cur] = colr; // graph coloring

	for(auto i : adj[cur]){
		if(!vis[i]){
			bool res = dfs(i,!colr,adj,vis);
			if(res == false){
				return false;
			}
		}
		else
			if(col[i]==col[cur]){
				return false; // false means it is not a bipartite graph 
			} 
	}
	return true; // yes it is bipartite graph
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
	if(dfs(1,0,adj,vis)){
		cout<<"bipartite graph "<<endl;
	}
	else{
		cout<<"Not a bipartite graph "<<endl;
	}


	return 0;
}
