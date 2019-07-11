#include <iostream>
#include <string.h>

using namespace std;

class  Student{
public:
	int age; 
	char *name;


	Student(){
		this->age = 0; 
	}

	Student(const char* name){  //method constructor
		int size = strlen(name) + 1;
		this->name = new char[size];
		strcpy(this->name, name);
	}

	Student(const Student &e){ //constructor copy
		int size = strlen(e.name) + 50;
		this->name = new char[size];
		strcpy(this->name, "Copia de ");
		strcat(this->name, e.name);
	}

	Student(int n){
		this->age = n;
	}
	
	~Student(){
		cout << "Destruct" <<name <<endl;
		delete[] name;
		name = 0;
	}

	const char * get_name(){
		return name;
	}
};


void foo_you(Student e){

}

void foo_deu(){
	Student studany("All_seu");
	foo_you(studany);
	cout << studany.get_name() << endl;

}

int main (void){

	Student x("xibalais");
	Student e;
	Student d(15);
	foo_deu();
	cout << "Age:" << e.age << endl;
	cout << "Age:" << d.age << endl;
	cout << "Name:" << x.name << endl;
	cout << "Age:" << x.age << endl;
	return 0;
}