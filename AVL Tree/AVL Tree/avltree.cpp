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

// 특정 키 값을 갖는 노드를 찾는 함수
Node *AvlTree::FindNode(int data) {
  Node *node = root_;

  while (node != NULL) {
    if (data == node->data) {
      return node;
    } else if (data < node->data) {
      node = node->left_child;
    } else {
      node = node->right_child;
    }
  }

  return NULL;
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

// data 값을 갖는 노드가 root인 부분트리에서, 최댓값 노드를 반환하는 함수
Node *AvlTree::Maximum(int data) {
  Node *node = FindNode(data);

  if (node == NULL)
    return NULL;

  while (node->right_child != NULL) {
    node = node->right_child;
  }

  return node;
}

// 트리에 저장된 원소의 수를 반환
int AvlTree::Size() {
  return size_;
}

// 트리가 비어있으면 1, 비어있지 않다면 0을 반환
bool AvlTree::Empty() {
  if (size_ > 0) {
    return 0;
  } else {
    return 1;
  }
};

//data 값을 갖는 노드의 depth를 반환하고,
//노드가 존재하지 않는다면 0을 반환하는 함수
int AvlTree::Find(int data) {
  if (root == NULL) return 0;

  Node *node = root_;
  int depth = 0;

  while (node!=NULL) {
    if (data == node->data) {
      return depth;
    }
    else if (data < node->data) {
      depth++;
      node = node->left_child;
    }
    else {
      depth++;
      node = node->right_child;
    }
  }

  return 0;

}