#include <iostream>
#include <iomanip>

using namespace std;

class People{
public:
	string name;
	int age;
	
	People(const string& name, const int &age){
		this->name = name;
		this->age = age;
	}
};

int main (void){

	People p1("Jardel Osprio Duarte", 27);
	People p2("Maria FPF", 25);
	People p3("Pedro STF", 59);

	//FORMAT TABLE
	cout <<setw(20) <<"Name: " << setw(10) << "Age:" <<endl;
	cout <<setw(20) << p1.name << setw(10) << p1.age <<endl;
	cout <<setw(20) << p2.name << setw(10) << p2.age <<endl;
	cout <<setw(20) << p3.name << setw(10) << p3.age <<endl;
	return 0;

}