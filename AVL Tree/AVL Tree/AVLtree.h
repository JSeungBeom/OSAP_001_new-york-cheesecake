#ifndef AVLTREE_AVLTREE_AVLTREE_H_
#define AVLTREE_AVLTREE_AVLTREE_H_

#include <iostream>
#include <vector>

using namespace std;

struct Node
{
	int data;
	Node *parent;
	Node *left_child;
	Node *right_child;
	Node(int data, Node *parent) : data(data),
								   parent(parent),
								   left_child(NULL),
								   right_child(NULL) {}
};

class AvlTree
{
public:
	AvlTree()
	{
		root_ = new Node(1, NULL);
	}

	int Minimum();

	int Maximum();

	int Size();

	bool Empty();

	void Insert(int data);

	int Find(int data);

private:
	Node *root_;

	void RightRotate(Node *node);

	void LeftRotate(Node *node);

	void Balance(Node *node);
};

#endif