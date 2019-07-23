//Depth-First Search
#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;


class Graph{

	int Vtx; //vertex
	list <int> *adj;
public:

	Graph(int Vtx);
	void set_edge(int v1, int v2);
	void dfs(int v);	
};

Graph::Graph(int Vtx){
	this->Vtx = Vtx;
	adj = new list<int>[Vtx];
}	

void Graph::set_edge(int v1, int v2){
	adj[v1].push_back(v2); //linked v2 in v1
}

void Graph::dfs(int v){
	stack<int> heap;
	bool checked[Vtx]; //list of the checked

	for (int i = 0; i < Vtx; i++)	checked[i] = false;

	while(true){
		if(!checked[v]){ 
			cout << "ckecked vertex: " << v << "\t\n";
			checked[v] = true;
			heap.push(v);
		}

		bool ret = false;
		list<int> :: iterator it;
		//list node isnt ckecked 
		for (it = adj[v].begin(); it != adj[v].end(); it++) {
			if(!checked[*it]) {
				ret = true;
				break;
			}
		}
		if(ret)	v = *it;
		else{
			heap.pop();
			if(heap.empty()) break;
			v = heap.top();
		}
	}
}


int main (void){
	int Vtx = 8;

	Graph graphs(Vtx);
	
	graphs.set_edge(0, 1);
	graphs.set_edge(0, 2);
	graphs.set_edge(1, 3);
	graphs.set_edge(1, 4);
	graphs.set_edge(2, 5);
	graphs.set_edge(2, 6);
	graphs.set_edge(6, 7);

	graphs.dfs(0);

	return 0;
}
	//stabilishing version  
//Depth-First Search

