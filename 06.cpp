#include <iostream>

using namespace std;

int main (void){
	int var = 10;
	int *array = new int[10];

	for (int i = 0; i < 10; ++i){
		array[i] = i;
	}
	for (int i = 0; i < 10; ++i){
		cout << array[i] << endl;
	}
	var = 20;

	cout <<var<< endl;

	delete[] array;
	array = NULL;
	
	for (int i = 0; i < 10; ++i){
		cout << array[i] << endl;
	}
	return 0;
}