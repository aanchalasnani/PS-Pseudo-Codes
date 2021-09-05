#include<bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int cur , vector<vector<int>> &adj , vector<bool> &vis , vector<int> &in , vector<int> &out){
	cout<<cur<<" ";
	vis[cur] = true;
	in[cur] = timer++;

	for(auto i : adj[cur]){
		if(!vis[i]){
			dfs(i,adj,vis,in,out);
		}
	}
	out[cur]=timer++;
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


	vector<int> in(n+1);
	vector<int> out(n+1);

	cout<<"\nDFS ==> \n";
	dfs(1,adj,vis,in,out);

	cout<<"\n\nin time ==> \n";
	for(int i=1;i<=n;i++){
		cout<<"#"<<i<<" => "<<in[i]<<endl;
	}

	cout<<"\n\nout time ==> \n";
	for(int i=1;i<=n;i++){
		cout<<"#"<<i<<" => "<<out[i]<<endl;
	}

	return 0;
}
