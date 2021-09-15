#include<bits/stdc++.h>
#include<iostream>
#include<stdlib.h>

#define  vi vector<int> 

using namespace std;




int c=0,maxx = 0;
vi level,subtree_size;


void dfs(int cur,int par,vector<vector <int>> adj)
{
	
	//marked[cur] = 1;
	//cout<<cur<<endl;
	level[cur] = level[par] + 1;
	//subtree_size[cur] = 1;
	for(int neighb:  adj[cur])
	{
	  //neigh can be parent or it can be child
		if(neighb == par){
			continue;
		}
		
		dfs(neighb,cur,adj);

		//subtree_size[cur] += subtree_size[neighb];
	}

	
}	
int main()
{


	#ifndef ONLINE_JUDGEB
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		int t; cin>>t ;
		while(t--) 
	{int x ;
		int n;
		cin>>n;
		vector<vi> adj;
		int a[n+1];
		for (int i = 1; i <= n; ++i)
		{
			cin>>a[i];
		}
		//cin>>x;
		adj.resize(n+1);
		level.resize(n+1);
		for(int i = 0;i<n-1;++i){
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		//root is 1;
		level[0] = -1;
		//int marked[n+1];
	
		// for (int i = 0; i <=n; ++i)
		// {
		// 	marked[i]=0;
		// }
		dfs(1,0,adj);
		//cout<<"count : "<<c;
		// for(int i = 1; i<=n;++i)
		// 	cout<<i<<'\t' <<level[i] <<'\n';
		int e=0,o=0;
		//int  j = 1;
		for (int i = 1; i <=n ; ++i)
		{
			if(level[i]%2==0){
				e = a[i]+e;
			}
			else {
				o = a[i]+o;
			}
			//j++;
		}
		cout<<abs(e-o)<<endl;}
	return 0;
}