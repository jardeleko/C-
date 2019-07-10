#include <iostream>

using namespace std;

int main (void){
	
	int fat = 1, i, num;

	cin >> num;

	for (i = 1; i < num; ++i){
		fat *= (i + 1);
	}

	cout << fat <<endl;
	return 0;
}