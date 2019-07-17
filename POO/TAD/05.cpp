#include <iostream>

using namespace std;

int graph[5][5] = {
	{0,0,1,0,0},
	{0,0,1,0,0},
	{1,1,0,1,1},
	{0,0,1,0,1},
	{0,0,1,1,0}
};

bool is_linked(int i, int j){
	if(graph[i][j]) return true;
	return false;
}

int main(void){

	cout << is_linked(0, 2) << endl; // se A e C == 1 return true
	return 0;
}
/* 

	*A      D* //		  A B C D E 
	  '    '		A 0 0 1 0 0
	    -C-			B 0 0 1 0 0
	   '   '		C 1 1 0 1 1 
	*B'     'E*   		D 0 0 1 0 1
*/		//		E 0 0 1 1 0		
