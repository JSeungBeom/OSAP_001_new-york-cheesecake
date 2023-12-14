/*
Copyright (C)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>

2023 by Seungbeom Jang <wkdtmf357@gmail.com>

*/

// A macro to disallow copy constructor and operator=
// This should be used in the private: declarations for a class.
#define DISALLOW_COPY_AND_ASSIGN(TypeName)                                     \
  TypeName(const TypeName &);                                                  \
  void operator=(const TypeName &)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool Destructed = false;

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
  AVLTreeSet() : root_(nullptr) {}

  ~AVLTreeSet() {
    Destructed = true;
    delete root_;
  }

  int Empty() { return !Size(); };

  int Size() { return (root_ == nullptr) ? 0 : root_->get_size(); };

  int Insert(T x) {
    // root_ = InsertUtil(root_, x);
    // return Find(x);
    return -2;
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
           std::to_string(Find(node->get_key()));
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

    std::string tmp = std::to_string(node->get_key()) + " " +
                      std::to_string(Find(node->get_key()));

    return tmp;
  };

  // key가 x인 노드의 rank를 반환하는 함수(노드가 없다면 "0" 반환)
  // rank는 Set에서 x보다 작은 수 + 1
  std::string Rank(T x) {
    int rank = RankUtil(x, root_);
    if (rank == 0)
      return "0";
    else
      return std::to_string(Find(x)) + " " + std::to_string(rank);
  };

  int Erase(T x) {
    //
    return -2;
  };

private:
  class AVLTreeNode : public Node<T> {
  public:
    AVLTreeNode(T key)
        : Node<T>(key), size_(1), height_(0), left_(nullptr), right_(nullptr),
          parent_(nullptr) {}

    // 후위 순회 방식으로 노드 삭제
    ~AVLTreeNode() {
      delete left_;
      delete right_;
    }

    void set_size(int size) { size_ = size; }
    int get_size() { return size_; }

    void set_height(int height) { height_ = height; }
    int get_height() { return height_; }

    void set_left(AVLTreeNode *left) { left_ = left; }
    AVLTreeNode *get_left() { return left_; }

    void set_right(AVLTreeNode *right) { right_ = right; }
    AVLTreeNode *get_right() { return right_; }

    void set_parent(AVLTreeNode *parent) { parent_ = parent; }
    AVLTreeNode *get_parent() { return parent_; }

  private:
    int size_;
    int height_;
    AVLTreeNode *left_;
    AVLTreeNode *right_;
    AVLTreeNode *parent_;
    DISALLOW_COPY_AND_ASSIGN(AVLTreeNode);
  };

  // 노드의 깊이를 구하는 함수
  int Height(AVLTreeNode *node) {
    if (node == nullptr)
      return -1;
    return node->height_;
  };

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

  // 재귀적으로 rank를 계산하는 함수
  int RankUtil(T x, AVLTreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    if (x < node->get_key())
      return RankUtil(x, node->get_left());

    int rank = 1;

    if (x > node->get_key()) {
      int child_rank = RankUtil(x, node->get_right());
      if (child_rank == 0)
        return 0;
      rank += child_rank;
    }

    AVLTreeNode *left = node->get_left();
    if (left != nullptr)
      rank += left->get_size();

    return rank;
  }

  AVLTreeNode *root_;
  DISALLOW_COPY_AND_ASSIGN(AVLTreeSet);
};
