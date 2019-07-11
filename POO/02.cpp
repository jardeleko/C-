#include <iostream>
#include <string.h>
#define MAX 10

using namespace std;

class Car{
	public: 
	char name[50];
	char color[20];
	char id[10];
	double price;

};

void bubblesort_in_name(Car cars[], int n){
	int i, j;
	Car aux;

	for (i = n; i >= 0; i--){
		for (j = 0; j <= i; j++){
			if(strcmp(cars[j-1].name, cars[j].name) == 1){
				aux = cars[j - 1];
				cars[j - 1] = cars[j];
				cars[j] = aux;
			}	
		}	
	}
}

//ordena a lista de carros em ordem alfabetica, porem 
//o algoritmo com complexidade de O(n²) 
//uma bosta, nunca usem bubblesort 
//o nome é legal porque lembra o bulbasaur

int main (void){
	Car cars[MAX];
	int i = 0;

	while(true){
		char on;
		cout << "Marc the Car:" << endl;
		cin >> cars[i].name;
		cout << "Set color the car:" << endl;
		cin >> cars[i].color;
		cout << "set the price:" << endl;
		cin >> cars[i].price;
		cout << "Enter the plate(LFA-1020):" << endl;
		cin >> cars[i].id;
		cout << "insert new car? Y(yes)/n(no)" << endl;
		cin >> on;
		if((on) == 'n') break;	
		i++;
	}
	printf("\n");
	printf("\n");
	
	for (int x = 0; x <= i; ++x){
		cout << cars[x].name << endl;
		cout << cars[x].color << endl;
		cout << cars[x].price << endl;
		cout << cars[x].id << endl;
		printf("\n");
	}

	printf("\n");
	printf("\n");
	printf("\n");

	bubblesort_in_name(cars, i);

	for (int x = 0; x <= i; ++x){
		cout << cars[x].name << endl;
		cout << cars[x].color << endl;
		cout << cars[x].price << endl;
		cout << cars[x].id << endl;
		printf("\n");
	}

	return 0;
}

//Ordenando com Bubblesort 