#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int b[], int n){
	int v[n + 1][W + 1];

	for (int w = 0; w <= W; w++)	v[0][w] = 0;
	for (int i = 1; i <= n; i++) v[i][0] = 0;

	for (int i = 1; i <= n; i++){
		for (int w = 1; w <= W; w++){

			if(wt[i - 1] <= w){

				if((b[i - 1] + v[i - 1][w - wt[i - 1]]) > v[i - 1][w]) 	
					v[i][w] = b[i - 1] + v[i - 1][w - wt[i - 1]];
				else v[i][w] = v[i - 1][w];
			
			}
			else 
				v[i][w] = v[i - 1][w];
		}
	}
	return v[n][W];
	
}

int main(void){
	int W = 10;
	int n = 5;

	int b[] = {3, 5, 8, 4, 10};

	int wt[] = {2, 4, 5, 3, 9};

	int max_size = knapsack(W, wt, b, n);

	cout << "the maximum value: " << max_size << endl; 
	return 0;
}

//knapsack