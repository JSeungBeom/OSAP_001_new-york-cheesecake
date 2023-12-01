#include <algorithm>
#include <iostream>
#include <vector>

template <typename T> class Set {
public:
  virtual int Empty() = 0;
  virtual int Size() = 0;
  virtual int Insert(T x) = 0;
  virtual int Find(T x) = 0;
  virtual std::string Minimum(T x) = 0;
  virtual std::string Maximum(T x) = 0;
  virtual std::string Rank(T x) = 0;
  virtual int Erase(T x) = 0;
};

template <typename T> class Node {
public:
  void set_key(T key) { key_ = key; }
  T get_key() { return key_; }

protected:
  Node(T key) : key_(key) {}

private:
  T key_;
};

template <typename T> class AVLTreeSet : public Set<T> {
public:
  AVLTreeSet() : root_(nullptr), size_(0) {}

  int Empty(){
      // return (size_ == 0) ? 1 : 0;
  };
  int Size(){
      // return size_;
  };
  int Insert(T x){
      //
  };
  int Find(T x){
      // if (root_ == nullptr)
      //   return 0;

      // Node<T> *node = root_;
      // int depth = 0;

      // while (node != nullptr) {
      //   if (data == node->data) {
      //     return depth;
      //   } else if (data < node->data) {
      //     depth++;
      //     node = node->left_child;
      //   } else {
      //     depth++;
      //     node = node->right_child;
      //   }
      // }

      // return 0;
  };
  std::string Minimum(T x){
      // Node<T> *node = FindNode(data);

      // if (node == nullptr) {
      //   return nullptr;
      // }

      // while (node->left_child != nullptr) {
      //   node = node->left_child;
      // }

      // return node;
  };
  std::string Maximum(T x){
      // Node<T> *node = FindNode(data);

      // if (node == nullptr)
      //   return nullptr;

      // while (node->right_child != nullptr) {
      //   node = node->right_child;
      // }

      // return node;
  };
  std::string Rank(T x){
      //
  };
  int Erase(T x){
      //
  };

private:
  class AVLTreeNode : public Node<T> {
  public:
    AVLTreeNode(T key)
        : Node<T>(key), height_(0), left_(nullptr), right_(nullptr) {}

    void set_height(int height) { height_ = height; }
    int get_height() { return height_; }
    void set_left(AVLTreeNode *left) { left_ = left; }
    AVLTreeNode *get_left() { return left_; }
    void set_right(AVLTreeNode *right) { right_ = right; }
    AVLTreeNode *get_right() { return right_; }

  private:
    int height_;
    AVLTreeNode *left_;
    AVLTreeNode *right_;
  };

  // int Height(Node<T> *node){
  //     if (node == nullptr)
  //       return -1;
  //     return node->height;
  // };
  // void UpdateHeight(Node<T> *node){
  //     if (node != nullptr)
  //       node->height =
  //           1 + max(Height(node->left_child), Height(node->right_child));
  // };
  // void RightRotate(Node<T> *node){
  //     Node<T> *left_child = node->left_child;
  //     node->left_child = left_child->right_child;

  //     if (left_child->right_child != nullptr)
  //       left_child->right_child->parent = node;

  //     left_child->parent = node->parent;

  //     if (node->parent == nullptr)
  //       root_ = left_child;
  //     else if (node == node->parent->left_child)
  //       node->parent->left_child = left_child;
  //     else
  //       node->parent->right_child = left_child;

  //     left_child->right_child = node;
  //     node->parent = left_child;

  //     UpdateHeight(node);
  //     UpdateHeight(left_child);
  // };
  // void LeftRotate(Node<T> *node){
  //     Node<T> *right_child = node->right_child;
  //     node->right_child = right_child->left_child;

  //     if (right_child->left_child != nullptr)
  //       right_child->left_child->parent = node;

  //     right_child->parent = node->parent;

  //     if (node->parent == nullptr)
  //       root_ = right_child;
  //     else if (node == node->parent->left_child)
  //       node->parent->left_child = right_child;
  //     else
  //       node->parent->right_child = right_child;

  //     right_child->left_child = node;
  //     node->parent = right_child;

  //     UpdateHeight(node);
  //     UpdateHeight(right_child);
  // };

  // void Balance(Node<T> *node){};

  // // 특정 키 값을 갖는 노드를 찾는 함수
  // Node<T> *FindNode(T data){
  //     Node<T> *node = root_;

  //     while (node != nullptr) {
  //       if (data == node->data) {
  //         return node;
  //       } else if (data < node->data) {
  //         node = node->left_child;
  //       } else {
  //         node = node->right_child;
  //       }
  //     }

  //     return nullptr;
  // };

  AVLTreeNode *root_;
  int size_;
};
