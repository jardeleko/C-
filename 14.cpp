#include <iostream>
#include <map>

using namespace std;

int main (void){
	pair<int, string> pairs[] = {
		make_pair(1,"Maria"),
		make_pair(2, "Mario"),
		make_pair(3, "Jose"),
		make_pair(4, "Ana")
	};
	map<int, string> maps(pairs, pairs +3);
	maps.at(3) = "Jorge";
	cout << maps[3] << endl;
	
	if(maps.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";
	
//	maps.clear();
	
	if(maps.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";
	
//	printf("%s\n", maps.count(1));
	map<int, string> :: iterator it;
	for (it = maps.begin(); it != maps.end(); ++it){
		cout << it->first << " => " << it->second << endl;
	}

	it = maps.find(2);
	maps.erase(it); //excluindo so a linha 2
	printf("\n");
	//cout << it->first << " => " << it->second << endl;
	for (it = maps.begin(); it != maps.end(); ++it){
		cout << it->first << " => " << it->second << endl;
	}
	printf("\n");

	it = maps.begin();
	maps.insert(pair<int, string>(10, "Jor"));
	for (it = maps.begin(); it != maps.end(); ++it){
		cout << it->first << " => " << it->second << endl;
	}
	//utilizando multimap

	multimap <int, string> mm; //associar chaves 
		
	mm.insert(pair<int, string> (1, "python 2"));
	mm.insert(pair<int, string> (2, "C"));
	mm.insert(pair<int, string> (2, "C++"));
	mm.insert(pair<int, string> (3, "Java"));
	mm.insert(pair<int, string> (4, "python 3"));

	multimap <int, string> :: iterator low, up, x, it_mm = mm.find(1);
	cout << it_mm->second << endl;
	low = mm.lower_bound(2); //define begin
	up = mm.upper_bound(4); //define end

	for (it_mm = mm.begin(); it_mm != mm.end(); ++it_mm){
		cout << it_mm->first << " => " << it_mm->second << endl;
	}
	printf("\n");

	for (x = low; x != up; x++){
		cout << x->first << " => " << x->second << endl;
	}
	printf("\n");
	return 0;
}