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
        : Node<T>(key), height_(0), left_(nullptr), right_(nullptr), parent_(nullptr) {}

  private:
    int height_;
    AVLTreeNode *left_;
    AVLTreeNode *right_;
    AVLTreeNode* parent_;
  };

  // 노드의 깊이를 구하는 함수
  int Height(AVLTreeNode *node){
      if (node == nullptr)
        return -1;
      return node->height_;
  };

  // 노드의 깊이를 업데이트하는 함수
  void UpdateHeight(AVLTreeNode *node){
      if (node != nullptr)
        node->height_ =
            1 + max(Height(node->left_), Height(node->right_));
  };

  // Right Roatation을 수행하는 함수
  void RightRotate(AVLTreeNode *node){
      AVLTreeNode *left_child = node->left_;
      node->left_ = left_child->right_;

      if (left_child->right_child != nullptr)
        left_child->right_->parent_ = node;

      left_child->parent_ = node->parent_;

      if (node->parent_ == nullptr)
        root_ = left_child;
      else if (node == node->parent_->left_)
        node->parent_->left_ = left_child;
      else
        node->parent_->right_ = left_child;

      left_child->right_ = node;
      node->parent_ = left_child;

      UpdateHeight(node);
      UpdateHeight(left_child);
  };

  // Left Rotation을 실행하는 함수
  void LeftRotate(AVLTreeNode *node){
      AVLTreeNode *right_child = node->right_;
      node->right_ = right_child->left_;

      if (right_child->left_ != nullptr)
        right_child->left_->parent_ = node;

      right_child->parent_ = node->parent_;

      if (node->parent_ == nullptr)
        root_ = right_child;
      else if (node == node->parent_->left_)
        node->parent_->left_ = right_child;
      else
        node->parent_->right_ = right_child;

      right_child->left_ = node;
      node->parent_ = right_child;

      UpdateHeight(node);
      UpdateHeight(right_child);
  };

  void Balance(AVLTreeNode *node){};

  // 특정 키 값을 갖는 노드를 찾는 함수
  AVLTreeNode *FindNode(T x){
      AVLTreeNode *node = root_;

      while (node != nullptr) {
        if (x == node->key_) {
          return node;
        } else if (x < node->key_) {
          node = node->left_child;
        } else {
          node = node->right_child;
        }
      }

      return nullptr;
  };

  AVLTreeNode *root_;
  int size_;
};
