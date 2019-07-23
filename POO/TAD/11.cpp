#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Edge{
	int vertex_X, vertex_Y, size;

public:
	Edge(int vx, int vy, int size){
		vertex_X = vx;
		vertex_Y = vy;
		this->size = size;
	}

	int get_vx(){
		return this->vertex_X;
	}

	int get_vy(){
		return this->vertex_Y;
	}

	int get_size(){
		return this->size;
	}
	//sobrescript operator "<"

	bool operator < (const Edge& ed2) const{
		return (size < ed2.size);
	}
};

class Graph{
	int v;
	vector<Edge> eds;

public: 
	Graph(int v){
		this->v = v;
	}
	//function for add edge as

	void set_edge(int vx, int vy, int size){
		Edge ed(vx, vy, size);
		eds.push_back(ed);
	}
	
	int search(int subset[], int i){
		if(subset[i] == -1) return i;
		return search(subset, subset[i]);
	}

	void union_edge(int subset[], int v1, int v2){
		int v1_set = search(subset, v1);
		int v2_set = search(subset, v2);
		subset[v1_set] = v2_set;
	}

	void kruskal(){
		vector <Edge> tree;
		int size_ed = eds.size();

		sort(eds.begin(), eds.end());
		int *subset = new int[v];

		memset(subset, -1, sizeof(int) * v);

		for (int i = 0; i < size_ed; ++i){
			int v1 = search(subset, eds[i].get_vx());
			int v2 = search(subset, eds[i].get_vy());

			if(v1 != v2){
				tree.push_back(eds[i]);
				union_edge(subset, v1, v2); 
			}
		}

		int size_tree = tree.size();
		for (int i = 0; i < size_tree; ++i)		{
			char v1 = 'A' + tree[i].get_vx();
			char v2 = 'A' + tree[i].get_vy();
			cout << "(" << v1 << ", " << v2 << ") = "  << tree[i].get_size() << endl;
		}
	}
};

int main(int argc, char const *argv[]){
	Graph gr(7);
	gr.set_edge(0, 1, 7);
	gr.set_edge(0, 3, 5);
	gr.set_edge(1, 2, 8);
	gr.set_edge(1, 3, 9);
	gr.set_edge(1, 4, 7);
	gr.set_edge(2, 4, 5);
	gr.set_edge(3, 4, 15);
	gr.set_edge(3, 5, 6);
	gr.set_edge(4, 5, 8);
	gr.set_edge(4, 6, 9);
	gr.set_edge(5, 6, 11);

	gr.kruskal();
	return 0;
}