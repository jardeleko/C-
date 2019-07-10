#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

typedef struct people{
	char *name;
	int age;
	int year;
}st_people;

int init_people(st_people *p){
	p->name = NULL;
	p->age = 0;
	p->year = 0;
	return 1;
}

int insert_people(st_people *p){
	st_people *pp = (st_people *)malloc (sizeof (st_people));
	cin >> pp->name;
	cin >> pp->age;
	cin >> pp->year;
	if(p->name)
		while(p->name != NULL) p = p+(sizeof(st_people));	
	p = pp;
	return 1;
}
void format_out(st_people *p){
	while(!p){
		cout << p->name << endl;
		cout << p->age << endl;
		cout << p->year << endl;
		p=p+(sizeof(st_people));
	}
}


int main (void){
	int a;
	st_people *p;
	a = init_people(p);
	a = insert_people(p);

	return 0;
}
/*compila mas ta com warning nao tratado kkk*/