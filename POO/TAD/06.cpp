#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


class Graph{

	int v; //vertex
	list <int> *adj;
	list <int> *ax;

public:
	Graph(int v);

	void set_edge(int v1, int v2);
	int size_out(int v);
	int size_in(int v); 
	bool is_linked(int v1, int v2);  
	
};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
	ax = new list<int>[v];
}	

void Graph::set_edge(int v1, int v2){
	printf("insere na lista\n");
	adj[v1].push_back(v2); //linked v2 in v1
	ax[v2].push_back(v1); 

}

int Graph::size_out(int v){
	return this->adj[v].size();
}

int Graph::size_in(int v){
	return this->ax[v].size();
}


bool Graph::is_linked(int v1, int v2){
	if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end()) return true;
	return false;
}

int main (void){
	Graph graphs(4);

	graphs.set_edge(0, 1); 
	graphs.set_edge(0, 3); 
	graphs.set_edge(1, 2);
	graphs.set_edge(3, 1);
	graphs.set_edge(3, 2);

	list<int> :: iterator it;


	cout <<"Grau de Entrada: " << graphs.size_in(1) << endl; //size access input edge x -> y
	cout <<"Grau de saida: " << graphs.size_out(1) << endl; // size access out edge x <- y
	cout <<"This Relation: " <<graphs.is_linked(3, 2) << endl; //return 1 if a relationship is true 
	
	Depth-First Searchreturn 0;
}
	
//grafos com arestas não valoradas

