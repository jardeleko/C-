#include <iostream>
#include <list>
#include<string.h>
using namespace std;

int main (void){

	list<int> l1;
	list<int> l2(3,10);
	list<int> :: iterator it;
	l1.push_back(10);
	l1.push_front(20);
	l1.push_back(40);

	for (it = l1.begin(); it != l1.end(); it++){
		printf("%d\t", *it);
	}
	printf("\n");
/*	for (it = l2.begin(); it != l2.end(); it++){
		printf("%d\t", *it);
	}*/
	printf("\n");
	l1.pop_back();//remove o ultimo elemento
	
	for (it = l1.begin(); it != l1.end(); it++){
		printf("%d\t", *it);
	}

	l1.pop_front(); //remove o primeiro
	for (it = l1.begin(); it != l1.end(); it++){
		printf("%d\t", *it);
	}
	while(!l2.empty()) l2.pop_front();
	printf("\n");

	cout << l2.size() <<endl;
	int array[] = {4, 16, 32, 123, 64};
	l2.assign(array, array + 5);
	l2.insert(l2.begin(), 100);
	it = l2.begin(), it++;
	l2.insert(it, 200); //operação pode ser usada com 3 parametros passando a quantidade de vezes para inserir
	it = l2.begin(), it++, it++; //andando dois valores pra apontar o fim da remoção
	l2.erase(l2.begin(), it);
	for (it = l2.begin(); it != l2.end(); it++) printf("%d\t", *it);
	printf("\n");
	l2.clear();//old function clear() kkk
	list<int> list_1(2, 5);
	list<int> list_2(7, 20);
	it = list_1.begin();
	list_1.splice(it, list_2);
	cout << list_2.size() << endl;
	list_1.remove(5);
	l2.sort();
	for (it = list_1.begin(); it != list_1.end(); it++) printf("%d\t", *it);
	printf("\n");
	//l2.remove_if(/*condition*/);
	for (it = l2.begin(); it != l2.end(); it++) printf("%d\t", *it);
	printf("\n");
	int array_x[] = {10, 60, 5, 20, 50};
	list<int> list4(array_x, array_x + 5);
	list4.sort(); //ordena
	for (it = list4.begin(); it != list4.end(); it++)	printf("%d\t ", *it);
	printf("\n");
	list<string> list5;
	list<string>::iterator str_it;
	list5.push_back("palavra");
	list5.push_back("significado");
	list5.push_back("abc");
	list5.push_back("tita_ni_c");
	list5.push_front("ovelha negra");
	list5.sort();
	//list5.sort(/*list5.size()*/); //pode-se estar criando uma função para ordenaçao
	for (str_it = list5.begin(); str_it != list5.end(); str_it++){
		cout << *str_it << endl;
	}

	return 0;
}