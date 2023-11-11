#ifndef AVLTREE_AVLTREE_AVLTREE_H_
#define AVLTREE_AVLTREE_AVLTREE_H_

#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int data;
  int height;
  Node *parent;
  Node *left_child;
  Node *right_child;
  Node(int data, Node *parent)
      : data(data), height(0), parent(parent), left_child(NULL),
        right_child(NULL) {}
};

class AvlTree {
public:
  AvlTree();

  Node *Minimum(int data);

  Node *Maximum(int data);

  int Size();

  bool Empty();

  void Insert(int data);

  int Find(int data);

private:
  Node *root_;

  int Height(Node *node);

  void UpdateHeight(Node *node);

  void RightRotate(Node *node);

  void LeftRotate(Node *node);

  void Balance(Node *node);

  Node *FindNode(int data);
};

#endif