#ifndef AVLTREE_AVLTREE_AVLTREE_H_
#define AVLTREE_AVLTREE_AVLTREE_H_

#include <iostream>
#include <vector>

template <typename T>
struct Node
{
  T data;
  int height;
  Node *parent;
  Node *left_child;
  Node *right_child;
  Node(T data, Node *parent)
      : data(data), height(0), parent(parent), left_child(nullptr),
        right_child(nullptr) {}
};

template <typename T>
class AvlTree
{
public:
  AvlTree();

  Node<T> *Minimum(T data);

  Node<T> *Maximum(T data);

  int Size();

  bool Empty();

  void Insert(T data);

  int Find(T data);

private:
  Node<T> *root_;
  int size_;

  int Height(Node<T> *node);

  void UpdateHeight(Node<T> *node);

  void RightRotate(Node<T> *node);

  void LeftRotate(Node<T> *node);

  void Balance(Node<T> *node);

  Node<T> *FindNode(T data);
};

#endif