#include <iostream>

using namespace std;

class Parent{

public: //function member virtual
	virtual void message(){ //virtual == polimorfismo 
		cout << "class main" << endl;
	}
	
};

class Extends : public Parent{
public:
	virtual void message(){ //funções virtuas ou @Override //sobreposição de funçoes  
		cout << "class extends of the main" << endl;
	}
		
};

void foo_you(Parent* obj){ //force message
	obj->message();
}

int main(int argc, char *argv[]){
	Parent object;
	Extends object_ext;

	foo_you(&object);
	foo_you(&object_ext);

	return 0;
}

// Esse conceito (virtual) parte do principio que 
// mesmo a função foo_u esteja a forçar uma chamada
//pra classe principal, em tempo de execução o programa
//verifica e retorna a classe que mais se adequa devido a instanciação da var
