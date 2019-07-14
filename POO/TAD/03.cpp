#include <iostream>

using namespace std;

class Node{

private:	
	int key;
	Node* next;

public:
	Node(int key){ 
		this->key = key;
		this->next = NULL;
	}

	int get_key(){
		return this->key;
	}

	Node* get_next(){
		return this->next;
	}

	void set_next(Node* snode){
		this->next = snode;
	}
	
};

class Sllist{

private:
	Node* head;
	Node* shut; 
public:
	Sllist(){
		head = NULL;
		shut = NULL;
	}

	Sllist(int key){
		head = new Node(key);
		shut = head;

	}

	virtual ~Sllist(){
		delete[] head;
		head = NULL;
	}

	bool void_sllist(){
		return (head == NULL);
	}
	
	void _print_sllist(){
		Node* c = this->head;
		if(!void_sllist()){
			while(c != NULL){
				cout << c->get_key() << "\t";
				c = c->get_next();
			}	
		cout << endl;
		}
		return;
	}
	
	int insert_begin(int key){
		Node* new_node = new Node(key);
		new_node->set_next(head);
		head = new_node;
		return 1;
	}

	int insert_end(int key){
		Node* new_node = new Node(key);
		if(void_sllist()){
			head = new_node;
			shut = new_node; 
		}else {
			shut->set_next(new_node);
			shut = new_node;
		}
		return 1;
	}

	int sizeof_sllist(){
		if(void_sllist()) return 0;
		Node *c = head;
		int size = 0;
		while(c) size++, c=c->get_next();
		return size; 
	}

	int search_sllist(int key){
		Node* c = head;
		while(c != NULL){
			if(c->get_key() == key) return key;
			c = c->get_next();
		}
		return -1;
	}

	void remove_sllist(){ //Função só deleta do final e é pessima pois tem complexidade de O(n)
		Node* root = head;
		Node* prev = head->get_next();
		Node* tmp = head->get_next()->get_next();
		if(!void_sllist()){//podendo muito bem ser implementada com O(1), se ouvesse um ponteiro p/ o indice anterior
			if(head->get_next() == NULL) head = NULL; 
			else if (head->get_next()->get_next() == NULL) head->set_next(NULL);
			else 
				//conceito comentado acima será implementado futuramente
				while(tmp != NULL){
					Node* aux = prev;
					prev = tmp;
					root = aux;
					tmp = tmp->get_next(); 
				}
				delete root->get_next();
				root->set_next(NULL);
				shut = root;
		}
	}
};

int main (void){
	int op;
	Sllist l;
	if(l.void_sllist());
		cout << "Vazia" << endl;
	while(scanf("%d", &op) != EOF){
		int key;
		switch(op){

			case 1:
				cout << "insert value at the begin:\n"; 
				cin >> key;
				l.insert_begin(key);
				break;

			case 2:
				cout << "insert value at the end:\n"; 
				cin >> key;
				l.insert_end(key);
				break;
			
			case 3:
				int key, a;
				cout << "Enter with a key search:\n"; 
				cin >> key;
				a = l.search_sllist(key);
				if(a != -1) printf("%d\n", a);
				else printf("Not exists in list\n");
				break;

			case 4:
				cout << "Remove element at the end list\n";
				l.remove_sllist();
				break;
			
			case 5:
				l._print_sllist();
				break;
			default:					
				exit(1);	
		}
	}
	return 0;
}