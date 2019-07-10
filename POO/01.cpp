#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

class People{ //class == struct  

public: //private: //protected: 
	char name[40];
	char numb[20];
	int age; 

	
};

int get_age(People *p, int n, char *search){
	int i;
	for (i = 0; i < n; ++i){
		if(strcmp(p[i].name, search) == 0) return i;	
	}
	return -1;
}


int main (void){
	int i, n;
	People *p1; //objeto pessoa
	char search[40];

	cout << "init the number of the peoples:" << endl;  
	cin >> n;
	p1 = (People *)malloc(n * sizeof(People));

	for (i = 0; i < n; ++i){
		cin >> p1[i].name;
		printf("\n");
		cin >> p1[i].numb;
		printf("\n");
		cin >> p1[i].age;
		printf("\n");
	}
	/* code */
	cout << "set the name search:" << endl;  
	cin >> search;
	printf("\n");
	int aux = get_age(p1, n, search);
	if(aux){
		cout << p1[aux].name;
		printf("\n");
		cout << p1[aux].numb;
		printf("\n");
		cout << p1[aux].age;
		printf("\n");
	}

	printf("\n");
	printf("all Peoples");
	printf("\n");
	
	for (i = 0; i < n; ++i){
		cout << p1[i].name;
		printf("\n");
		cout << p1[i].numb;
		printf("\n");
		cout << p1[i].age;
		printf("\n");

	}

	free(p1);
	return 0;
}