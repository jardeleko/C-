#include <iostream>
#include <list>
#include <stack>

using namespace std;
//cycles

class Graph{
	int Vtx; 
	list<int> *adj;

public:
	Graph(int Vtx);
	void set_edge(int v1, int v2);
	bool dfs(int v);
	bool is_cycle_linked();
};

Graph::Graph(int Vtx){
	this->Vtx = Vtx;
	adj = new list<int>[Vtx];
}

void Graph::set_edge(int v1, int v2){
	adj[v1].push_back(v2); //linked degrees peer to peer
	/*adj[v2].push_back(v1);*/
}

bool Graph::dfs(int v){
	stack<int> heap;
	bool checked[Vtx], ret_heap[Vtx];

	for (int i = 0; i < Vtx; ++i)	checked[i] = ret_heap[i] = false;
	
	while(true){
		bool parent_true = false;
		list <int> ::iterator it;

		if(!checked[v]){
			heap.push(v);
			checked[v] = ret_heap[v] = true;

		}

		for (it = adj[v].begin(); it != adj[v].end(); it++)	{
			if(ret_heap[*it]) return true;
			else if(!checked[*it]){ 
				parent_true = true;
				break;
			}
		}
		if(!parent_true){
			ret_heap[heap.top()] = false;
			heap.pop();
			if(heap.empty());
				break;
			v = heap.top();
		}else v = *it;
	}
		return false;
}
bool Graph:: is_cycle_linked(){
	for(int i = 0; i < Vtx; i++){
		if(dfs(i)) return true;
	}
	return false;
}

int main (void){
	Graph graphs(4);
	graphs.set_edge(0, 1);
	graphs.set_edge(0, 2);
	graphs.set_edge(1, 3); //is true, is me
	graphs.set_edge(3, 0);

		if(graphs.dfs(2)) printf("is cycle linked\n");
		else printf("no cycle\n");

		if(graphs.is_cycle_linked()) printf("is cycle linked\n");
		else printf("no cycle\n");
	return 0;
}
 