#include <iostream>
#include <queue>
using namespace std;
//prioridade altera por tamanho do inteiro atribuido a variavel
int main (void){

	priority_queue<int> ue;
	priority_queue<int, vector<int>, greater<int> > eu, ax; //priridade do menor ao maior

	ue.push(13);
	ue.push(21);
	ue.push(111);

	eu.push(13);
	eu.push(21);
	eu.push(111);

	cout << ue.top() << endl; //mostra o topo 
	if(ue.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";

	priority_queue<int> aux;
	aux = ue;
	while(!aux.empty()){
		cout << aux.top()<< "\n";
		aux.pop();
	}
	printf("\n");
	
	ax = eu;
	while(!ax.empty()){
		cout << ax.top()<< "\n";
		ax.pop();
	}
	printf("\n");
	return 0;

}
//priory queue