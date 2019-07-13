#include <iostream>
#include <vector>
using namespace std;

class Distance{
public:
	int x, y;

	Distance(int x, int y){
		this->x = x;
		this->y = y;
	}
			
};

int main (void){
	vector<Distance *> array;
	vector<Distance *> :: iterator it;

	Distance * d1 = new Distance(1, 2);
	Distance * d2 = new Distance(3, 4);

	array.push_back(d1);
	array.push_back(d2);

	for (it = array.begin(); it < array.end(); it++)	{
		cout <<"(" << (*it)->x << ", " << (*it)->y << ")\n"; 		
	}
	return 0;
}