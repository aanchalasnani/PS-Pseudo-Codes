#include<bits/stdc++.h>
using namespace std;

class Graph{

	int V;
	list<int> *l;

	public :

	Graph(int V){
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int u,int v){ //edge connecting u and v
		l[u].push_back(v);
		l[v].push_back(u);
	}

	void printAdjList(){

		for(int i=0;i<V;i++){
			cout<<"Vertex : "<<i<<" => ";
			for(int X : l[i]){
				cout<<X<<",";
			}
			cout<<"\n";
		}
	}
};

int main() {
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("outputtt.txt","w",stdout);
	#endif
		Graph g(4);
		g.addEdge(0,1);
		g.addEdge(0,2);
		g.addEdge(2,3);
		g.addEdge(1,2);
		g.printAdjList();
	return 0;
}
