#include <iostream>
#include <vector>

using namespace std;

int main (void){
	vector<int> f(3); //obs: () != []
/*	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
*/
	for (int i = 0; i < f.size(); ++i){
		f[i] = i*10;
	}
	vector<int> x(2, 50); //2 posições preenchidas com valor 20
	vector<int> y(3, 1024);//3 posições preenchidas com valor 1024
	vector<int>::iterator nil = f.begin();
	f.insert(nil + 3, 30); //insere na 3 posição do array
	x.swap(y); //inverte o valor dos arrays

	for (int i = 0; i < x.size(); ++i){
		cout << x[i] <<"\t" ;
	}
	printf("\n");

	for (int i = 0; i < y.size(); ++i){
		cout << y[i] <<"\t" ;
	}	
	int i = 0;
	if(!f.empty()){
		cout << f.back() << endl; //finally
		cout << f.front() << endl; //init
		cout << f.at(2) << endl;
	}
	else printf("vazio\n"), f.push_back(50);
	f.erase(f.begin());
	for (int i = 0; i < f.size(); ++i){
		cout << f[i] <<"\t" ;
	}
	f.clear(); 
	printf("\n");
	cout << f.size() << endl;
	/*vector<int> :: reverse_iterator r_it;

	for (r_it = f.rbegin(); r_it != f.rend(); r_it++)	{
		printf("%d\t", *r_it);
	}
	printf("\n");*/

/*
	for (nil = f.begin(); nil < f.end(); nil++)	{
		printf("%d ->\t", *nil);
	}
	printf("end\n");*/

	return 0;
}