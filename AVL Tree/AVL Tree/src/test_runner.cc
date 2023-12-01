#include "avl_tree_set.cc"
#include <string>
#include "gtest/gtest.h"

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
  std::cout << "Constuctor called\n";
}

SetTestFixture::~SetTestFixture() {
  std::cout << "Destructor called\n";
}

void SetTestFixture::SetUp() {
  std::cout << "SetUp called\n";
  avl_tree_set_.Insert(1);
  avl_tree_set_.Insert(5);
  avl_tree_set_.Insert(3);
  avl_tree_set_.Insert(10);
  avl_tree_set_.Insert(2);
}

void SetTestFixture::TearDown() {
  std::cout << "TearDown called\n";
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

