#include <iostream>
#include <exception>
#include <string.h>

using namespace std;

class Except_Customs : public exception{

protected:
	char message[100];

public:
	Except_Customs(const char *err){
		strcpy(this->message, err);
	}
	virtual const char * call_back(){
		return this->message;
	}
	
};

int fat(int n){

	if(n < 0) throw Except_Customs("Numero negativo");
	if(n == 0 || n == 1) return 1;
	return n * fat(n-1);
}

int main (void){

	try{
		cout << "Fatorial de 5:" << fat(5) << endl;
		cout << "Fatorial de -5:" << fat(-5) << endl;

	}catch(Except_Customs err){
		cerr << "Exception: " << err.call_back() << endl;
	}catch(...){
		cerr << "inesperado" << endl;
	}

	return 0;
}
