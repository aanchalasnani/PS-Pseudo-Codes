#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int t = 0;
int outime[6];

void Dfs(int start , vector<vector<int>> &adj , vector<bool> &visited , stack<int> &to)
{
	visited[start] = true;
	cout<<start<<" ";

	for (int i : adj[start])
	{
		if(!visited[i]){
			Dfs(i,adj,visited,to);
			
		}
		
	}
	// to[start] = i++;
	outime[start] = t++;
	//cout<<start<<" ";
	to.push(start);
	
}
int main()
{


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	int n , m ;
	cin>>n>>m ;

	// n is vertices 
	//m is edges
	vector<vector<int>> adj(n+1);
	vector<bool> visited(n+1 , false);
	
	stack<int> to;
	
	
	for (int i = 0; i < m; ++i)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v); // directed graph 
	}
		
		

	
	Dfs(1,adj,visited,to);
	//map<int,int> mp;
	for (int i = 1; i <=n ; ++i)
	{
		//cout<<i<<" time : "<<outime[i]<<endl;
		//cout<<to.top()<<" ";
		to.pop();
	}

	//unordered_map<int,int>:: iterator it  = mp.end();
	
	// reverse travelling a graph 
	// for(auto it = mp.rbegin() ; it!= mp.rend() ; it++){
	// 	cout<<it->second<<" ";
	// }

	return 0;
}
