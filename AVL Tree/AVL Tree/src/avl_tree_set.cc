
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
    if (root_ == nullptr) {
      root_ = new AVLTreeNode(x);
      size_++;
      return root_->get_height();
    }

    AVLTreeNode *current = root_;
    AVLTreeNode *parent = nullptr;

    while (current != nullptr) {
      parent = current;

      if (x < current->get_key()) {
        current = current->get_left();
      } else if (x > current->get_key()) {
        current = current->get_right();
      } else {
        return current->get_height();
      }
    }

    AVLTreeNode *new_node = new AVLTreeNode(x);
    new_node->set_parent(parent);

    if (x < parent->get_key()) {
      parent->set_left(new_node);
    } else {
      parent->set_right(new_node);
    }

    size_++;
    UpdateHeight(new_node);
    Balance(new_node);

    return new_node->get_height();
  }

  int Find(T x) {
    if (root_ == nullptr)
      return 0;

    AVLTreeNode *node = root_;
    int depth = 0;

    while (node != nullptr) {
      if (x == node->get_key()) {
        return depth;
      } else if (x < node->get_key()) {
        depth++;
        node = node->get_left();
      } else {
        depth++;
        node = node->get_right();
      }
    }

    return 0;
  };
  std::string Minimum(T x) {
    AVLTreeNode *node = FindNode(x);

    if (node == nullptr)
      return "Not found";

    while (node->get_left() != nullptr) {
      node = node->get_left();
    }

    std::string tmp = std::to_string(Find(x)) + " " + std::to_string(node->get_key());

    return tmp;
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

    return std::to_string(Find(x)) + " " + std::to_string(node->get_key);
  };

  std::string Rank(T x){

  };
  int Erase(T x){

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
    return node->get_height();
  };

  // 노드의 깊이를 업데이트하는 함수
  void UpdateHeight(AVLTreeNode *node) {
    if (node != nullptr)
      node->set_height(
          1 + std::max(Height(node->get_left()), Height(node->get_right())));
  };

  // Right Roatation을 수행하는 함수
  void RightRotate(AVLTreeNode *node) {
    AVLTreeNode *left_child = node->get_left();
    node->set_left(left_child->get_right());

    if (left_child->get_right() != nullptr)
      left_child->get_right()->set_parent(node);

    left_child->set_parent(node->get_parent());

    if (node->get_parent() == nullptr)
      root_ = left_child;
    else if (node == node->get_parent()->get_left())
      node->get_parent()->set_left(left_child);
    else
      node->get_parent()->set_right(left_child);

    left_child->set_right(node);
    node->set_parent(left_child);

    UpdateHeight(node);
    UpdateHeight(left_child);
  };

  // Left Rotation을 실행하는 함수
  void LeftRotate(AVLTreeNode *node) {
    AVLTreeNode *right_child = node->get_right();
    node->set_right(right_child->get_left());

    if (right_child->get_left() != nullptr)
      right_child->get_left()->set_parent(node);

    right_child->set_parent(node->get_parent());

    if (node->get_parent() == nullptr)
      root_ = right_child;
    else if (node == node->get_parent()->get_left())
      node->get_parent()->set_left(right_child);
    else
      node->get_parent()->set_right(right_child);

    right_child->set_left(node);
    node->set_parent(right_child);

    UpdateHeight(node);
    UpdateHeight(right_child);
  };

  void Balance(AVLTreeNode *node) {
    UpdateHeight(node);

    int balance = BalanceFactor(node);
    if (balance > 1) {
      if (BalanceFactor(root->get_left()) >= 0) {
        RightRotate(node);
      } else {
        node->set_left(LeftRotate(node->get_left()));
        RightRotate(node);
      }
    } else if (balance < -1) {
      if (BalanceFactor(root->get->right()) <= 0) {
        LeftRotate(node);
      } else {
        node->set_right(RightRotate(node->get_right()));
        LeftRotate(node);
      }
    }
  };

  int BalanceFactor(AVLTreeNode* node){
    if(node == nullptr)
      return 0;

      return (node->left->get_height() - node->right->get_height());
  }

  

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