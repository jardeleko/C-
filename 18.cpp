#include <iostream>
#include <stack> //Last in first out

using namespace std;

int main (void){

	stack<int> heap;
	heap.push(10);
	heap.push(100);
	heap.push(111);
	heap.push(101);
	heap.push(1);
	heap.push(0);

	stack<int> aux;
	aux = heap;

	while(!aux.empty()){
		int x = aux.top();
			printf("%d\t ", x);
			printf("Quem sai é o: %d\n", x); 
		aux.pop();
	}
	printf("\n");

	return 0;
}