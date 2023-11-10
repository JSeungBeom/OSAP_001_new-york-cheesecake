#pragma once
#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct node {
	int data;
	node* parent;
	node* left_child;
	node* right_child;
	node(int data, node* parent) {
		this->data = data;
		this->parent = parent;
		this->left_child = NULL;
		this->right_child = NULL;
	}
};

class Avltree {
public:
	Avltree() {
		root = new node(1, NULL);
	}
private:
	node* root;
};
