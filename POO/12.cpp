#include <iostream>
#include <queue>

using namespace std;

class People{
private:
	int age;
	string name;

public:
	People(string name, int age){
		this->name = name;
		this->age = age;
	}

	int get_age(){
		return this->age;
	}
	string get_name(){
		return this->name;
	}

};


struct checked{
	bool operator() (People& p1, People& p2) {
		return bool(p1.get_age() < p2.get_age());
	}
	
};

int main (void){

	priority_queue<People, vector<People>, checked > my_queue; 	
	People p1("Jota", 90), p2("Maria", 50), p3("Joaquim", 55);

	my_queue.push(p1);
	my_queue.push(p2);
	my_queue.push(p3);

	People top = my_queue.top();
	//mostra a prioridade pela idade
	//o maior entre as 3 pessoas inseridas
	cout << top.get_name() << endl << top.get_age() << endl;
	return 0;
	
}