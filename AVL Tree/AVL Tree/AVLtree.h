#define INHA_OSAP_001_new-york-cheesecake_AVLTree_Avltree_H_
#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* parent;
	node* left_child;
	node* right_child;
	node(int data, node* parent) :
		data(data),
		parent(parent),
		left_child(NULL),
		right_child(NULL) {}
};

class Avltree {
public:
	Avltree() {
		root = new node(1, NULL);
	}
private:
	node* root;
};
