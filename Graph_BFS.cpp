#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

void bfs(int start , vector<vector<int>> adj , vector<bool> visited)
{
	queue<int> q;
	q.push(start);
	visited[start]=true;
	int s ;
	while(!q.empty()){
		s = q.front();
		cout<<s<<" ";
		q.pop();

		for (int i : adj[s])
		{
			if(!visited[i]){
				visited[i] = true;
				q.push(i);
				
			}
		}
	}
}

int main()
{


	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n ;
	cin>>n ;

	
	vector<vector<int>> adj(n+1);
	vector<bool> visited(n+1 , false);

	
	
	for (int i = 0; i < 6; ++i)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
		
		

	// for (int i = 0; i <=n ; ++i)
	// {
	// 	visited[i]=false;
	// }
	bfs(2,adj,visited);

	return 0;
}
/* 
4
0 1
0 2
1 2
2 0 
2 3
3 3


output : 2 0 3 1 

*/