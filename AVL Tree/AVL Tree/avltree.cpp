#include "avltree.h"

using namespace std;

AvlTree::AvlTree() { root_ = NULL; }

int AvlTree::Height(Node *node) {
  if (node == NULL)
    return -1;
  return node->height;
}

void AvlTree::UpdateHeight(Node *node) {
  if (node != NULL)
    node->height = 1 + max(Height(node->left_child), Height(node->right_child));
}