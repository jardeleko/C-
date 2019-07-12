#include <iostream>

//LIFO STACK, agora com classe  
using namespace std;

class Stack{
private:
	int *size;
	int overflow;	
	int top;

public:
	Stack(){
		size = new int[100];
		overflow = 99;
		top = -1;
	}		
	
	~Stack(){ //esses destructors são tipo o free(var) no C 
		delete[] size;
	}

	int push(int key){
		if(top == overflow) return 0; //overflow
		size[++top] = key;
		return 1;
		
		//se colocasse isso no do while daria pra considerar o uso do overflow
		// no caso a ultima posição sem ser a size[n-1];
	}
	int pop(){
		int ret;
		if(top == -1) return -1; //underflow
		ret = size[top], top--;
		return ret;
	}

	void print_stack(){
		if(top != -1 && top != overflow){
			for(int i = top; i >= -1; --i) printf(" %d ->", size[i]);
		}
		cout << "empty" << endl;	
	}

};


int main (void){

	Stack s;
	int loop;

	while(scanf("%d", &loop) != EOF){
		int key, ret;
	
		switch(loop){
			case 1:
				cin >> key;
				s.push(key);
				break;
			case 2:
				ret = s.pop();
				cout << ret << endl;	
				break;
			case 3:
				s.print_stack();
				break;
			case 0:
				exit(1);
			default:
				exit(1);
						
		}
	}

	return 0;
}