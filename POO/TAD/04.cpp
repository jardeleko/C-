#include <iostream>

using namespace std;

class  Node{
private:
	Node *left, *right;
	int key;

public:
	Node(int key){
		this->key = key;
		left = NULL;
		right = NULL;
	}

	int get_key(){
		return this->key;
	}
	Node* get_left(){
		return this->left;
	}
	Node* get_right(){
		return this->right;
	}	
	void set_left(Node* node){
		this->left = node;
	}
	void set_right(Node* node){
		this->right = node;
	}	
};

class bstree {

private:
	Node* root;
public:
	bstree(){
		this->root = NULL;
	}

	void insert_bstree(int key){
		 if(root == NULL) root = new Node(key);
		 else insert_fixup(root, key);
	}
	
	void insert_fixup(Node *node, int key){ // exemplo chave unica
		if(key < node->get_key()){
			if(node->get_left() == NULL){
				Node* snode = new Node(key);
				node->set_left(snode);
			}
			else insert_fixup(node->get_left(), key);
		}
		else if(key > node->get_key()){
			if(node->get_right() == NULL){
				Node* snode = new Node(key);
				node->set_right(snode);
			}
			else insert_fixup(node->get_right(), key);
		}

	}
	Node *get_root(){
		return this->root;
	}

	void print_bstree(Node* node){
		if(node != NULL){
			print_bstree(node->get_left());
			cout << node->get_key() << "\t";
			print_bstree(node->get_right());
		}
	}
};

int main (void){

bstree tree;
	
	tree.insert_bstree(8);
	tree.insert_bstree(10);
	tree.insert_bstree(14);
	tree.insert_bstree(13);
	tree.insert_bstree(3);
	tree.insert_bstree(1);
	tree.insert_bstree(6);
	tree.insert_bstree(4);
	tree.insert_bstree(7);

	tree.print_bstree(tree.get_root());
	printf("\n");
	return 0;
}