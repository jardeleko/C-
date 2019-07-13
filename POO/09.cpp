#include <iostream>
#include <string.h>

using namespace std;

class People {

private:
	char *name;
	int id;

public:
	void init_(const char *name, int id){
		int size;
		size = strlen(name);
		this->name = new char[size + 1];
		strcpy(this->name, name);
		this->id = id;
	}

	void free_(){
		delete[] name;
		name = 0;
	}
	People(const char *name, int id){
		/*int size;
		size = strlen(name);
		this->name = new char[size + 1];
		strcpy(this->name, name);
		this->id = id;
		*/
		init_(name, id);
	}
	People(People &p){
		init_(p.name, p.id);
	}

	virtual ~People(){
		free_();
	}
	People& operator=(People& p){ //faz com que o ponteiro para de apontar para o mesmo bloco de memoria
		if(this != &p) free_(), init_(p.name, p.id);
		return *this;
	}

	const char * get_name(){
		return this->name;
	}
	int get_id(){
		return this->id;
	}
	void set_new_char(char c){
		name[0] = c;
	}
};

int main (void){
	People p1("name", 1);
	People p2("other_name", 6);
	
	p1 = p2;

	p2.set_new_char('X');
	cout << p1.get_name() << " " << p1.get_id() << endl;
	cout << p2.get_name() << " " << p2.get_id() << endl;
	return 0;
}