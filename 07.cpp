#include <iostream>
#include <string.h>

using namespace std;

int main (void){

	int aux, i;
	char *name = new char[10];
	cin >> name;
	aux = strlen(name);

	for (i = aux; i >= 0; --i){
		cout << name[i];
	}
	cout << endl;

	delete[] name;
	name = NULL;
	
	for (int i = 0; i < 10; ++i){
		cout << name[i] << endl;
	}
	return 0;
}