#include <iostream>
#include <string.h>

using namespace std;

class Animals{

protected:
	 char *name;
	 bool fly;
	 int paw;

public:
	Animals(){
		this->name = 0;
		this->fly = false;
		this->paw = 0;	
	}

	Animals(const char *name){
		cout << "class root" << endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->fly = false;
		this->paw = 0;		
	}
	
	~Animals(){
		delete[] name;
		name = 0;
	}

	void set_name(const char *name){	
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);	
	}

	const char *get_name(){
		return this->name;
	}	

	void set_fly(bool fly){
		this->fly = fly;
	}

	bool get_fly(){
		return this->fly;
	}

	void set_paw(int paw){
		this->paw = paw;
	}

	int get_paw(){
		return this->paw;
	}


};

class Cat : public Animals{ //extends parent class 

protected: 
	int age;

public:
	Cat() : Animals(){
		this->age = 0;
	}

	Cat(const char *name) : Animals(name){
		cout << "class extends" <<endl;
	 	age = 0;
	}	
	int get_age(){
	 	return this->age;
	}

	void set_age(int age){
	 	this->age = age;
	}
};

int main (void){
	Cat c;
	char *nomeCAT;
	int age;
	int patita;
	bool voa_fia;
	
	nomeCAT = new char[30];
	cout << "name:" <<endl;
	cin >> nomeCAT;
	c.set_name(nomeCAT);
	cout << "1 or 0" <<endl;
	cin >> voa_fia;
	c.set_fly(voa_fia);
	cout << "int patita" <<endl;	
	cin >> patita;
	c.set_paw(patita);
	cout << "age" <<endl;
	cin >> age;
	c.set_age(age);

	printf("Name: ");
	cout << c.get_name() << endl;
	if(c.get_fly()) cout <<  "Avoa" << endl;
	printf("idade: ");
	cout << c.get_age() << endl;
	printf("patitas: ");
	cout << c.get_paw() << endl;
	return 0;
}