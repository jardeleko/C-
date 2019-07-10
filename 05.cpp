#include <iostream>
#include <string.h>

using namespace std;

int main(void){
	char name[] = "jardelOke";
	int aux = strlen(name);
	char palavra[20];
	cin >> palavra;

	for (int i = 0; i < sizeof(palavra); ++i){
		palavra[i] = tolower(palavra[i]); //ToUpper 
	}

	cout << palavra << endl;
	cout << aux <<endl;

	if(isalpha(name[0])) cout <<"alphabetic"<<endl;
	else cout <<"others"<< endl;

	if(isdigit(name[6])) cout <<"numeric"<<endl;
	else cout <<"others"<< endl;

	if(isupper(name[6])) cout <<"is Uppercase" << endl; //islower
	else cout << "other" << endl;
	
	return 0; 

}