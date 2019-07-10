#include <iostream>

using namespace std;

int main (void){
	int age, age2;
	age = 27;
	age2 = -age;

	if(age > 28) cout <<age<< endl;
	else if(age2 < 0) cout << "date"<< endl;
	else exit(1);

	cout <<"Hello World"<< endl; //cout == printf endl == \n

	return 0;
}
