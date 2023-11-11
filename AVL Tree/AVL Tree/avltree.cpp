#include "avltree.h"

using namespace std;

// 생성자
AvlTree::AvlTree() { root_ = NULL; }

// 노드의 높이 구하는 함수
int AvlTree::Height(Node *node) {
  if (node == NULL)
    return -1;
  return node->height;
}

// 노드의 높이를 업데이트하는 함수
void AvlTree::UpdateHeight(Node *node) {
  if (node != NULL)
    node->height = 1 + max(Height(node->left_child), Height(node->right_child));
}

// 노드를 중심으로, Right roation을 수행하는 함수
void AvlTree::RightRotate(Node *node) {
  Node *left_child = node->left_child;
  node->left_child = left_child->right_child;

  if (left_child->right_child != NULL)
    left_child->right_child->parent = node;

  left_child->parent = node->parent;

  if (node->parent == NULL)
    root_ = left_child;
  else if (node == node->parent->left_child)
    node->parent->left_child = left_child;
  else
    node->parent->right_child = left_child;

  left_child->right_child = node;
  node->parent = left_child;

  UpdateHeight(node);
  UpdateHeight(left_child);
}

// 노드를 중심으로, Left roation을 수행하는 함수
void AvlTree::LeftRotate(Node *node) {
  Node *right_child = node->right_child;
  node->right_child = right_child->left_child;

  if (right_child->left_child != NULL)
    right_child->left_child->parent = node;

  right_child->parent = node->parent;

  if (node->parent == NULL)
    root_ = right_child;
  else if (node == node->parent->left_child)
    node->parent->left_child = right_child;
  else
    node->parent->right_child = right_child;

  right_child->left_child = node;
  node->parent = right_child;

  UpdateHeight(node);
  UpdateHeight(right_child);
}