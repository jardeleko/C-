#include <iostream>
#include <list>
#include <stdlib.h>
//TAD with a template
//politic FIFO (first in first out)
using namespace std;

template<class Q>

class Queue{

private:
	list<Q> queue;

public:
	void queue_insert(const Q& x){
		queue.push_back(x);
	}	

	bool queue_empty(){
		return queue.empty();
	}

	Q queue_remove(){
		if(!this->queue_empty()){
			Q x = queue.front();
			queue.pop_front();
			return x;
		}

		throw "empty queue";
	}

	Q first(){
		if(!this->queue_empty()){
			return queue.back();
		}
		throw "empty queue";
	}

	Q queue_begin(){
		if(!this->queue_empty()) return queue.front();
		throw "Bug\n";
	} 

	Q queue_end(){
		if(!this->queue_empty()) return queue.back();
		throw "Bug\n";
	}

	void print_(){
		list<int> :: iterator it;
		if(!this->queue_empty()){
			for (it = queue.begin(); it != queue.end(); ++it)	{
				cout << *it << " \t";
			}
			printf("\n");
		}
	}

};
	

int main (void){
	int op, key;
	Queue<int> f; 	

	while(scanf(" %d", &op) != EOF){
		switch(op){
			case 1:
				cout << "insert:\n";
				cin >> key;
				f.queue_insert(key);
				break;

			case 2:
				cout << "remove:\n";
				try{
					int aux = f.queue_remove();
					printf("%d\n", aux);
				}
				catch(const char *err){
					cerr << "Exception: " << err << endl;
				}
				break;
			case 3:
				f.print_();
				break;
			default:
				exit(1);
		}
	}
	return 0;
}