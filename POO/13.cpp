//Dijkstra 
#include <iostream>
#include <list>
#include <queue>
#define MAX 11234567

using namespace std; 

class Graph{
	int Vtx;
	list<pair<int, int> > *adj;

public:
	//constructor
	Graph(int Vtx){
		this->Vtx = Vtx;
		adj = new list<pair<int, int> >[Vtx];

	}
	//add edge v1 in v2
	void set_edge(int v1, int v2, int value){
		adj[v1].push_back(make_pair(v2, value)); // link two edges variable v1 in variable v2 with a weight variable VALUE

	}
	//orig -> dest
	int dijkstra (int origin, int destiny){
		int distance[Vtx], checked[Vtx];

		priority_queue <pair <int, int>, vector<pair<int, int> >, greater < pair< int, int> > >pq; 
		for (int i = 0; i < Vtx; ++i) distance[i] = MAX, checked[i] = false;
		distance[origin] = 0; 
		pq.push(make_pair(distance[origin], origin));

		while(!pq.empty()){
			pair<int, int> p = pq.top();
			int t = p.second;
			pq.pop();

			if(checked[t] == false) checked[t] = true;

			list<pair <int, int> > :: iterator it;

			for (it = adj[t].begin(); it != adj[t].end(); it++){
				int vertex = it->first;
				int value_edge = it->second;		
				if(distance[vertex] > distance[t] + value_edge){
					distance[vertex] = distance[t] + value_edge;
					pq.push(make_pair(distance[vertex], vertex));
				}
			}
		}
		return distance[destiny];
	}	

};

int main(void){
	
	Graph gr(5);
	gr.set_edge(0, 1, 4);
	gr.set_edge(0, 2, 2);
	gr.set_edge(0, 3, 5);
	gr.set_edge(1, 4, 1);
	gr.set_edge(2, 1, 1);
	gr.set_edge(2, 3, 2);
	gr.set_edge(2, 4, 1);
	gr.set_edge(3, 4, 1);

	cout << "The weight for it connection is the -> "<< gr.dijkstra(0, 2) << endl;
	return 0;
}