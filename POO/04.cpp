#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class lenguage{
	friend void class_friend(lenguage *);
protected: 
	char name[20];
private:
	int since;

public:
	void set_name(char* word){
		strcpy(this->name, word);
	}

	char* get_name(){
		return this->name;
	}

	void set_since(int date){
		this->since = date;
	}

	int get_since(){
		return this->since;
	}
};

void class_friend(lenguage * l){
	cout << "try:" << l->name << endl;
}

int main (void){
	char *ret, *word;
	int date, am;

	word = (char *)malloc(sizeof(20));
	lenguage l;
	cin >> word;
	l.set_name(word);
	ret = l.get_name();
	cout << ret <<endl;	
	cin >> date;
	l.set_since(date);
	am = l.get_since();
	cout << am << endl;

	class_friend(&l);

	return 0;
}	
