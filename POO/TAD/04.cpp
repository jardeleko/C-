#include <iostream>

using namespace std;

class  node{
private:
	node *left, *right;
	int key;
public:
	node(int key){
		this->key = key;
		left = NULL;
		right = NULL;
	}	

	int get_key(){
		return this->key;
	}
	node* get_left(){
		return this->left;
	}
	node* get_right(){
		return this->right;
	}
	void set_left(node *leaf){
		this->left = leaf;
	}
	void set_right(node *leaf){
		this->left = leaf;
	}

};

class bstree{
private:
	node* root;

public:
	bstree(){
		root = NULL;
	}
	void insert_bstree(int key){
		if(root == NULL) root = new node(key);
		else bstree_insert_fixup(root, key);
	}

	void bstree_insert_fixup(node* xnode, int key){
		if(key < xnode->get_key()){
			if(xnode->get_left() == NULL){
				node* snode = new node(key);
				xnode->set_left(snode);
			}
			else bstree_insert_fixup(xnode->get_left(), key);

		}
		else if(key > xnode->get_key()){
			if(xnode->get_right() == NULL){
				node* snode = new node(key);
				xnode->set_right(snode);
			}
			else bstree_insert_fixup(xnode->get_right(), key);

		}
	}

	node* get_root(){
		return this->root;
	}

	void print_bstree(node* xnode){
		if(xnode != NULL){
			print_bstree(xnode->get_left());
			cout << xnode->get_key() << "\t";
			print_bstree(xnode->get_right());
		}
		
	}
};

int main(void){

	bstree tree;
	tree.insert_bstree(16);
	tree.insert_bstree(25);
	tree.insert_bstree(5);
	tree.insert_bstree(7);

	tree.print_bstree(tree.get_root());
	printf("\n");
	return 0;
}