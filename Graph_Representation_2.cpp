#include<bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<string , list<pair<string,int>>> l;

	public :

	void addEdge(string x, string y , bool bidir , int wt){
		l[x].push_back(make_pair(y,wt));
		if(bidir){
			l[y].push_back(make_pair(x,wt));
		}
	}

	void printAdjList(){
		for(auto p : l){
			string key = p.first ;
			list<pair<string,int>> nbrs = p.second;

			cout<<key<<" => ";

			for(auto x : nbrs){

				string s = x.first;
				int dist = x.second;

				cout<<" ( "<<s<<","<<dist<<" ) ";
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

	Graph g;
	g.addEdge("A","B",true,20);
	g.addEdge("B","D",true,30);
	g.addEdge("A","C",true,10);
	g.addEdge("C","D",true,40);
	g.addEdge("A","D",false,50);

	g.printAdjList();


	return 0;
}
