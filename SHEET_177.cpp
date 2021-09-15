#include<bits/stdc++.h>
using namespace std;



typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int) (x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define resz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define loop(i, a, b) for(int i = (a); i < (b); ++i)
#define loop0(i, a) loop(i, 0, a)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i,0,a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto& a : x)

int h = 0;

void levelOrder(vector<vector<int>> adj , int n , int root){

	vector<bool> visited(n+1,false);
	queue<int> que;
	visited[root] = true;
	que.push(root);

	while(!que.empty()){
		
		int curr = que.front();
		cout<<curr<<" ";
		que.pop();

		for(int i : adj[curr]){
			//cout<<"i : "<<i<<" ";
			if(!visited[i]){
				visited[i]=true;
				que.push(i);
			}
		}
	}



}

void RevLevel(vector<vector<int>> adj , int n , int root){

	
	vector<bool> visited(n+1,false);
	stack<int> S;
	S.push(root);

	queue<int> que;
	visited[root] = true;
	que.push(root);

	while(!que.empty()){

		int curr = que.front();
		//cout<<curr<<" ";
		que.pop();

		for(int i : adj[curr]){
			//cout<<"i : "<<i<<" ";
			if(!visited[i]){
				visited[i]=true;
				que.push(i);
				S.push(i);
			}
		}
	}

	cout<<"\n\n";
	cout<<"Reverse Level Order ==>";
	while(!S.empty()){
		cout<<S.top()<<" ";
		S.pop();
	}
}

// int Height(vector<vector<int>> adj , int n , int root){

// 	//since it is for binary tree so max child can only be 2

// 	if(root>n){
// 		return 0;
// 	}
// 	else{
// 		int lchild = Height(adj , n , adj[root][0]);
// 		int rchild = Height(adj , n , adj[root][1]);

// 		if(lchild>rchild){
// 			return(lchild + 1);
// 		}
// 		else {
// 			return(rchild + 1);
// 		}
// 	}
	
// }

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output1.txt","w",stdout);
	#endif

	//need to create a tree

	int n;
	cin>>n;

	vector<vector<int>> adj(100);

	// n is no of nodes

	//In a tree there are always and always node - 1 edges
	//tree is undirected means it is bidirectional
	for(int i = 0 ; i < n-1 ; i ++){
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	//our tree is now read

	for(int i = 0 ; i < n ; i ++){
		
		if(adj[i].size()==0){
			continue;
		}
		cout<<i<<" ==>  ";
		for(int j : adj[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n";

	//we will be doing level order traversal
	//level order traversal is nothing but same as bfs of a graph 
	cout<<"Level Order ==>";
	levelOrder(adj,n,1);

	//reverse level order traversal
	
	RevLevel(adj,n,1);

	//height of tree
	//Height(adj,n,1);
	cout<<"\n";
	cout<<h<<endl;
	return 0;
}
