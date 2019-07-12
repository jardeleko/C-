#include <iostream>

using namespace std;

int fat(int n){

	if(n < 0) throw "denominador negativo";
	if(n == 0 || n == 1) return 1;
	return n * fat(n-1);
}

int main (void){

	try{
		cout << "Fatorial de 5:" << fat(5) << endl;
		cout << "Fatorial de -5:" << fat(-5) << endl;

	}catch(const char* err){
		cerr << "Exception: " << err << endl;
	}catch(...){
		cerr << "inesperado" << endl;
	}

	return 0;
}