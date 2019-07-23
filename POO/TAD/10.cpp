#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int search(int subset[], int v){
	if(subset[v] == -1) return v;
	return search(subset, subset[v]);
}
void linked(int subset[], int v1, int v2){
	int v1_set = search(subset, v1);
	int v2_set = search(subset, v2);
	subset[v1_set] = v2_set;
}

int cycle(int graph[3][3]){
	int * subset = (int *) malloc(3 * (sizeof(int)));
	memset(subset, -1, sizeof(int) * 3);
	for (int i = 0; i < 3; ++i)	{
		for (int j = i; j < 3; ++j){
			if(graph[i][j] == 1){
				int v1 = search(subset, i);
				int v2 = search(subset, j);
				if(v1 == v2) return 1;
				else linked(subset, v1, v2);
			}		
		}
	}
	return 0; 
}
int main(void){
	int Graph[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	Graph[0][1] = 1;
	Graph[1][0] = 1;
	Graph[1][2] = 1;
	Graph[2][1] = 1;
	Graph[2][0] = 1;
	Graph[0][2] = 1;

	if(cycle(Graph)) printf("cycle\n");
	else printf("no cycle\n");
	return 0;
}