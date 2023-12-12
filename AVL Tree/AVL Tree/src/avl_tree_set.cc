#include <algorithm>
#include <iostream>
#include <string>
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

  int Empty() { return (size_ == 0) ? 1 : 0; };

  int Size() { return size_; };

  int Insert(T x) {
    size_ += 1;
    return FindDepth(x);
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

  // 노드 x가 루트인 부분트리에서 최소 key를 갖는 노드의 key와 depth를 공백으로
  // 구분하여 리턴
  std::string Minimum(T x) {
    AVLTreeNode *node = FindNode(x);

    if (node == nullptr)
      return "Not found";

    while (node->get_left() != nullptr)
      node = node->get_left();

    return std::to_string(node->get_key()) + " " +
           std::to_string(FindDepth(node->get_key()));
  };

  // 노드 x가 루트인 부분트리에서 최대 key를갖는 노드의 key와 depth를 공백으로
  // 구분하여 리턴
  std::string Maximum(T x) {
    AVLTreeNode *node = FindNode(x);

    if (node == nullptr)
      return "Not found";

    while (node->get_right() != nullptr) {
      node = node->get_right();
    }

    std::string tmp = std::to_string(node->get_height()) + " " +
                      std::to_string(node->get_key());

    return tmp;
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
        : Node<T>(key), height_(0), left_(nullptr), right_(nullptr),
          parent_(nullptr) {}

    // 후위 순회 방식으로 노드 삭제
    ~AVLTreeNode() {
      delete left_;
      delete right_;
    }

    void set_height(int height) { height_ = height; }

    int get_height() { return height_; }

    void set_left(AVLTreeNode *left) { left_ = left; }

    AVLTreeNode *get_left() { return left_; }

    void set_right(AVLTreeNode *right) { right_ = right; }

    AVLTreeNode *get_right() { return right_; }

    void set_parent(AVLTreeNode *parent) { parent_ = parent; }

    AVLTreeNode *get_parent() { return parent_; }

  private:
    int height_;
    AVLTreeNode *left_;
    AVLTreeNode *right_;
    AVLTreeNode *parent_;
  };

  // 노드의 깊이를 구하는 함수
  int Height(AVLTreeNode *node) {
    if (node == nullptr)
      return -1;
    return node->height_;
  };

  // key가 x인 노드의 깊이를 반환하는 함수
  int FindDepth(T x) { return FindDepthUtil(root_, x); }
  int FindDepthUtil(AVLTreeNode *node, T x) {
    if (node == nullptr)
      return -1;

    int distance = -1;
    if ((node->get_key() == x) ||
        ((distance = FindDepthUtil(node->get_left(), x)) >= 0) ||
        ((distance = FindDepthUtil(node->get_right(), x)) >= 0))
      return distance + 1;

    return distance;
  }

  // 노드의 깊이를 업데이트하는 함수
  void UpdateHeight(AVLTreeNode *node) {
    if (node != nullptr)
      node->height_ = 1 + max(Height(node->left_), Height(node->right_));
  };

  // Right Roatation을 수행하는 함수
  void RightRotate(AVLTreeNode *node) {
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
  void LeftRotate(AVLTreeNode *node) {
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
  AVLTreeNode *FindNode(T x) {
    AVLTreeNode *node = root_;

    while (node != nullptr) {
      if (x == node->get_key()) {
        return node;
      } else if (x < node->get_key()) {
        node = node->get_left();
      } else {
        node = node->get_right();
      }
    }

    return nullptr;
  };

  AVLTreeNode *root_;
  int size_;
};
