//Depth-First Search
#include <iostream>
#include <list>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


class Graph{

	int v; //vertex
	list <int> *adj;
public:
	Graph(int v);

	void set_edge(int v1, int v2);
	void dfs(int v);	
	void bfs(int v);
};

Graph::Graph(int v){
	this->v = v;
	adj = new list<int>[v];
}	

void Graph::set_edge(int v1, int v2){
	printf("insere na lista\n");
	adj[v1].push_back(v2); //linked v2 in v1
}

void Graph::dfs(int v){
	stack<int> heap;
	bool checked[v];

	for (int i = 0; i < v; ++i)	{
		checked[i] = false;
	}

	while(true){
		if(!checked[v]){ 
			cout << "ckecked vertex: " << v << "\t\n";
			checked[v] = true;
			heap.push(v);
		}

		bool ret = false;
		list<int> :: iterator it;
		
		for (it = adj[v].begin(); it != adj[v].end(); it++) {
			if(!checked[*it]) {
				ret = true;
				break;
			}
		}
		if(ret){
		 	v = *it;
			printf("verifica v\n");
		}
		else{
			heap.pop();
			printf("fragmentou aqui heap.pop()\n");
			if(heap.empty()) break;
			printf("fragmentou aqui v = heap\n");
			v = heap.top();
		}
	}
}

void Graph::bfs(int v){
	queue<int> my_queue;
	bool checked[v];

	for (int i = 0; i < v; ++i)	{
		checked[i] = false;
	}

	cout << "checklist vertex" << v << "\n";
	checked[v] = true;

	while(true){
		list<int>:: iterator it_list;
		for (it_list = adj[v].begin(); it_list != adj[v].end(); it_list++)	{
			if(!checked[*it_list]) {
				cout << "ckecked true index " << *it_list << "\n"; 
				checked[*it_list] = true;
				my_queue.push(*it_list);
			}
		}
		if(!my_queue.empty()){
			v = my_queue.front(); //get the first vertex 
			my_queue.pop(); //remove 
		}
		else 
			break;		
	}
}

int main (void){
	int v = 10;

	Graph graphs(v);
	
	graphs.set_edge(0, 1);
	graphs.set_edge(0, 2);
	graphs.set_edge(1, 3);
	graphs.set_edge(1, 4);
	graphs.set_edge(2, 5);
	graphs.set_edge(2, 6);
	graphs.set_edge(6, 7);

	graphs.bfs(0);

	return 0;
}
	//compilando mas segmentada 
//Depth-First Search

