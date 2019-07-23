#include <iostream>
#include <vector>
using namespace std;

void kadane(vector<int>&  array){
	int max = 0, sum = -1;
	int size = array.size();

	for(int i = 0; i < size; i++){
		max += array[i];
		if(max < 0) max = 0;
		if(max > sum) sum = max;
	}

	cout << "The maximum value this array: " << sum << endl;
}

int main(void){
	vector<int> array(5);
	array[0] = -2;
	array[1] = 5;
	array[2] = -1;
	array[3] = 2;
	array[4] = -3;

	kadane(array);

	return 0;
}
// is the algorithm with a complexit in O(n)
//maximum subarray problem
