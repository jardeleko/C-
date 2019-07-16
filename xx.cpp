#include <iostream>
#include <set>
using namespace std;

int main(void){
	int array[] = {70, 10, 24, 11, 13, 50};
	set<int> myset(array, array + 6);
	set<int> :: iterator it = myset.begin();

	cout << "Elements" << endl;
	while(it != myset.end()){
		cout << *it << "\t";
		it++;
	}
	printf("\n");

//	myset.erase(it);


/*	while(it != myset.end()){
		cout << *it << "\t";
		it++;
	}*/
	//myset.clear();
	if(myset.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";
	
	it = myset.find(50);
	if(it == myset.end()) printf("Não existe\n");
	else cout << "\nexiste\n" << endl;
	
	int aux = myset.size();

	printf("%d\n", aux);
	return 0;
}