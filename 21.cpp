#include <iostream>
#include <vector>

using namespace std;

int count_coins(vector<int>& coins, int value){
	int aux = 0;
	int size = coins.size();

	for (int i = size - 1; i >= 0; i--){
		int count = value/coins[i];
		value -= count * coins[i];
		aux += count;		
	}

	return aux;
}

int main(void){
	
	vector <int> coins;
	int sum = 26, value;

	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	coins.push_back(10);
	coins.push_back(20);

	cout << "Finally coins: " << count_coins(coins, sum) << endl;

	return 0;
}