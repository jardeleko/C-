#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class lenguage{
protected: 
	char name[20];

public:
	void set_name(char* word){
		strcpy(this->name, word);
	}

	char* get_name(){
		return this->name;
	}
};


int main (void){
	char *ret, *word;
	word = (char *)malloc(sizeof(20));
	lenguage l;
	cin >> word;
	l.set_name(word);
	ret = l.get_name();
	cout << ret <<endl;

	return 0;
}	
