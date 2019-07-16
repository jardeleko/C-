//class deque FIFO
#include <iostream>
#include <deque>

using namespace std;

int main (void){

	deque<int> queue;
	deque<int> :: iterator it;

	cout << "before insert\n";
	if(queue.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";
	//insert in end
	queue.push_back(10);
	queue.push_back(6);
	queue.push_back(20);
	queue.push_front(30);

	cout << "after insert\n";
	if(queue.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";

	for(it = queue.begin(); it != queue.end(); it++){
		printf("%d\t", *it);
	}
	printf("\n");
	queue.clear();
	if(queue.empty()) cout << "is empty\n";
	else cout << "isnt empty\n";
	queue.push_front(10);
	queue.push_front(6);
	queue.push_back(20);
	queue.push_front(23);
	queue.push_front(34);
	queue.push_front(64);	

	//para chaamar o primeiro elemento queue.front() e o ultimo queue.back()
	//mesma coisa só que p/ inserir push_front() push_back()

	for(it = queue.begin(); it != queue.end(); it++){
		printf("%d\t", *it);
	}
	printf("\n");
	queue.erase(queue.begin() + 1);
	for(it = queue.begin(); it != queue.end(); it++){
		printf("%d\t", *it);
	}
	printf("\n");	

	it = queue.begin() + 1;
	queue.insert(it, 10);
	for(it = queue.begin(); it != queue.end(); it++){
		printf("%d\t", *it);
	}
	
	printf("\n");
	queue.pop_front();	
	queue.pop_back();
	queue.pop_front();	
	queue.pop_back();	

	for(it = queue.begin(); it != queue.end(); it++){
		printf("%d\t", *it);
	}

	printf("\n");
	return 0;
}