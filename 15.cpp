#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
//diferença da deque pra queue é que esta lib só remove do inicio
int main(void){
	queue<int> que_ue;
	queue<int> myqueue;

	que_ue.push(10);
	que_ue.push(11);
	que_ue.push(13);

	cout << que_ue.back() << endl; 
	cout << que_ue.front() << endl;

	if(que_ue.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";	

	myqueue = que_ue; //temporario apenas para remover os elementos
	//printar etc, depois só dar um delete
	while(!myqueue.empty()){
		int i = myqueue.front();
		cout << i << endl;
		myqueue.pop();
	}
	int size = que_ue.size();
	printf("%d\n", size); //mostra quantidade de indice
	printf("\n");
	return 0;
}