#include <iostream>
#include <string>

using namespace std;
// Todos os conceitos sobre a string 
// string != string.h

int main(int argc, char const *argv[]){

	string tmp = "maggie";
	cout << "name:" << tmp << endl;
	cout << "size:" << tmp.size() << endl; //str.length()
	cout << "print pos(int):" << tmp.at(1) << endl;
	tmp.append(" silva "); //adc string
	tmp.push_back('L'); //adc char 
	tmp.append(" de Linda ");
	cout << tmp << endl;
	tmp.insert(0, "GATA ->"); //desloca o array tmp e insere a partir da posição setada
	cout << tmp << endl;
	tmp.insert(tmp.size()-1, "<- GATA"); //começa no fim do array
	cout << tmp << endl;
	tmp.erase(0, 7); //apagando os 7 primeiros bits
	cout << tmp << endl;
	tmp.clear();
	if(tmp.empty()) printf("vazia\n");
	else cout << tmp << endl;
	getline(cin, tmp);
	tmp+= " string"; //concatena desta forma também 
	cout << tmp << endl;

	return 0;
}