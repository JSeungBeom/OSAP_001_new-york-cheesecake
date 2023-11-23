#include <iostream>
#include <algorithm>
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

// template <typename T>
// class Set
// {
// public:
//   virtual Node<T> *Minimum(T data) = 0;

//   virtual Node<T> *Maximum(T data) = 0;

//   // 트리에 저장된 원소의 수를 반환
//   virtual int Size()
//   {
//     return size_;
//   }

//   // 트리가 비어있으면 1, 비어있지 않다면 0을 반환
//   virtual bool Empty()
//   {
//     return (size_ == 0);
//   }

//   virtual void Insert(T data) = 0;

// protected:
//   int size_;
// };

template <typename T>
class AvlTree
{
public:
  // 생성자
  AvlTree()
  {
    root_ = nullptr;
    size_ = 0;
  };

  // data 값을 갖는 노드가 root인 부분트리에서, 최소값 노드를 반환하는 함수
  Node<T> *Minimum(T data)
  {
    Node<T> *node = FindNode(data);

    if (node == nullptr)
    {
      return nullptr;
    }

    while (node->left_child != nullptr)
    {
      node = node->left_child;
    }

    return node;
  };

  // data 값을 갖는 노드가 root인 부분트리에서, 최댓값 노드를 반환하는 함수
  Node<T> *Maximum(T data)
  {
    Node<T> *node = FindNode(data);

    if (node == nullptr)
      return nullptr;

    while (node->right_child != nullptr)
    {
      node = node->right_child;
    }

    return node;
  };

  // 트리에 저장된 원소의 수를 반환
  int Size()
  {
    return size_;
  };

  // 트리가 비어있으면 1, 비어있지 않다면 0을 반환
  bool Empty()
  {
    return (size_ == 0);
  };

  void Insert(T data);

  // data 값을 갖는 노드의 depth를 반환하고,
  // 노드가 존재하지 않는다면 0을 반환하는 함수
  int Find(T data)
  {
    if (root_ == nullptr)
      return 0;

    Node<T> *node = root_;
    int depth = 0;

    while (node != nullptr)
    {
      if (data == node->data)
      {
        return depth;
      }
      else if (data < node->data)
      {
        depth++;
        node = node->left_child;
      }
      else
      {
        depth++;
        node = node->right_child;
      }
    }

    return 0;
  };

private:
  Node<T> *root_;
  int size_;

  // 노드의 높이 구하는 함수
  int Height(Node<T> *node)
  {
    if (node == nullptr)
      return -1;
    return node->height;
  };

  // 노드의 높이를 업데이트하는 함수
  void UpdateHeight(Node<T> *node)
  {
    if (node != nullptr)
      node->height = 1 + max(Height(node->left_child), Height(node->right_child));
  };

  // 노드를 중심으로, Right roation을 수행하는 함수
  void RightRotate(Node<T> *node)
  {
    Node<T> *left_child = node->left_child;
    node->left_child = left_child->right_child;

    if (left_child->right_child != nullptr)
      left_child->right_child->parent = node;

    left_child->parent = node->parent;

    if (node->parent == nullptr)
      root_ = left_child;
    else if (node == node->parent->left_child)
      node->parent->left_child = left_child;
    else
      node->parent->right_child = left_child;

    left_child->right_child = node;
    node->parent = left_child;

    UpdateHeight(node);
    UpdateHeight(left_child);
  };

  // 노드를 중심으로, Left roation을 수행하는 함수
  void LeftRotate(Node<T> *node)
  {
    Node<T> *right_child = node->right_child;
    node->right_child = right_child->left_child;

    if (right_child->left_child != nullptr)
      right_child->left_child->parent = node;

    right_child->parent = node->parent;

    if (node->parent == nullptr)
      root_ = right_child;
    else if (node == node->parent->left_child)
      node->parent->left_child = right_child;
    else
      node->parent->right_child = right_child;

    right_child->left_child = node;
    node->parent = right_child;

    UpdateHeight(node);
    UpdateHeight(right_child);
  };

  void Balance(Node<T> *node);

  // 특정 키 값을 갖는 노드를 찾는 함수
  Node<T> *FindNode(T data)
  {
    Node<T> *node = root_;

    while (node != nullptr)
    {
      if (data == node->data)
      {
        return node;
      }
      else if (data < node->data)
      {
        node = node->left_child;
      }
      else
      {
        node = node->right_child;
      }
    }

    return nullptr;
  };
};