#include "avl_tree_set.cc"
#include <string>
#include "gtest/gtest.h"

class SetEmptyTestFixture : public testing::Test {
public:
  SetEmptyTestFixture();
  virtual ~SetEmptyTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  AVLTreeSet<int> avl_tree_set_;
};

SetEmptyTestFixture::SetEmptyTestFixture() {
  // std::cout << "SetEmptyTestFixture: Constuctor called\n";
}

SetEmptyTestFixture::~SetEmptyTestFixture() {
  // std::cout << "SetEmptyTestFixture: Destructor called\n";
}

void SetEmptyTestFixture::SetUp() {
  // std::cout << "SetEmptyTestFixture: SetUp called\n";
}

void SetEmptyTestFixture::TearDown() {
  // std::cout << "SetEmptyTestFixture: TearDown called\n";
}

class SetTestFixture : public testing::Test {
  public:
    SetTestFixture();
    virtual ~SetTestFixture();
    void SetUp() override;
    void TearDown() override;

    protected:
      AVLTreeSet<int> avl_tree_set_;
};

SetTestFixture::SetTestFixture() {
  // std::cout << "SetTestFixture: Constuctor called\n";
}

SetTestFixture::~SetTestFixture() {
  // std::cout << "SetTestFixture: Destructor called\n";
}

void SetTestFixture::SetUp() {
  // std::cout << "SetTestFixture: SetUp called\n";
  avl_tree_set_.Insert(1);
  avl_tree_set_.Insert(5);
  avl_tree_set_.Insert(3);
  avl_tree_set_.Insert(10);
  avl_tree_set_.Insert(2);
}

void SetTestFixture::TearDown() {
  // std::cout << "SetTestFixture: TearDown called\n";
}

TEST_F(SetEmptyTestFixture, TestEmpty) {
  EXPECT_EQ(avl_tree_set_.Empty(), 1);
  avl_tree_set_.Insert(1);
  EXPECT_EQ(avl_tree_set_.Empty(), 0);
  avl_tree_set_.Insert(5);
  EXPECT_EQ(avl_tree_set_.Empty(), 0);
}

TEST_F(SetEmptyTestFixture, TestSize) {
  EXPECT_EQ(avl_tree_set_.Size(), 0);
  avl_tree_set_.Insert(1);
  EXPECT_EQ(avl_tree_set_.Size(), 1);
  avl_tree_set_.Insert(5);
  EXPECT_EQ(avl_tree_set_.Size(), 2);
}

TEST_F(SetTestFixture, TestMinimum) {
  EXPECT_EQ("Not found", avl_tree_set_.Minimum(4));
  EXPECT_EQ("1 1", avl_tree_set_.Minimum(1));
  EXPECT_EQ("5 1", avl_tree_set_.Minimum(5));
  EXPECT_EQ("1 1", avl_tree_set_.Minimum(3));
  EXPECT_EQ("10 2", avl_tree_set_.Minimum(10));
  EXPECT_EQ("2 2", avl_tree_set_.Minimum(2));
}

TEST_F(SetTestFixture, TestMaximum) {
    EXPECT_EQ("Not found", avl_tree_set_.Maximum(4));
    EXPECT_EQ("2 10", avl_tree_set_.Maximum(3));
    EXPECT_EQ("2 10", avl_tree_set_.Maximum(5));
    EXPECT_EQ("2 2", avl_tree_set_.Maximum(2));
    EXPECT_EQ("1 1", avl_tree_set_.Maximum(1));
    EXPECT_EQ("2 10", avl_tree_set_.Maximum(10));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
