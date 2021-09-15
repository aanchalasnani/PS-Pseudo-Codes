// bipartite graph also known as bigraph special graph
// such that you can divide the vertex set into two
//disjoints set such that :
// 1.) each vertex belongs to exactly one of the 2 sets
// 2.) each edge connects vertex of 2 different sets 



#include<bits/stdc++.h>
using namespace std;

bool dfs(int cur ,int colr, vector<vector<int>> &adj , vector<bool> &vis , vector<int> &col){
	vis[cur] = true;
	// cout<<cur<<" ";
	col[cur] = colr; // graph coloring

	for(auto i : adj[cur]){
		if(!vis[i]){
			bool res = dfs(i,!colr,adj,vis,col);
			if(res == false){
				return false;
			}
		}
		else
			if(col[i]==col[cur]){
				return false; // true means it is bipartite graph
			} 
	}
	return true; // not a bipartite graph
}

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputt.txt","w",stdout);
	#endif
	int t;
	cin>>t;

	for(int z=1;z<=t;z++){

		cout<<"Scenario #"<<z<<":\n";
		int n; //no of nodes
		cin>>n;

		int e; //no of edges
		cin>>e;

		vector<vector<int>> adj(n+1);
		vector<bool> vis(n+1,false); 
		vector<int> col(n+1,0);

		for(int i=0; i<e ; i++){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bool theory = true;

		for(int i=1;i<=n;i++){
			if(!vis[i]){
			 	
			 	bool res = dfs(i,0,adj,vis,col);
			 	if(res==false){
			 		theory = false;
			 	}
			}
		}
		if(theory == false){
			cout<<"Suspicious bugs found!"<<endl;
		}
		else{
			cout<<"No suspicious bugs found!"<<endl;
		}


		adj.clear();
		for(int i=0;i<=n;i++){
			vis[i]=0;
		}
		col.clear();
	}
	


	return 0;
}
