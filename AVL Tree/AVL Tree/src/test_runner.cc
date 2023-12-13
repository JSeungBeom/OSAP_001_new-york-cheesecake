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

#include "avl_tree_set.cc"
#include "gtest/gtest.h"
#include <string>

TEST(SetTest, TestConstructor) {
  AVLTreeSet<int> avl_tree_set;

  ASSERT_EQ(avl_tree_set.Size(), 0);
  ASSERT_EQ(avl_tree_set.Empty(), 1);
}

TEST(SetTest, TestDestructor) {
  Destructed = false;
  AVLTreeSet<int> *avl_tree_set = new AVLTreeSet<int>();

  delete avl_tree_set;

  ASSERT_TRUE(Destructed);
}

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

class MaximumFixture
    : public testing::TestWithParam<std::tuple<int, std::string>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    MaximumTests, MaximumFixture,
    testing::Values(std::make_tuple(5, "15 3"), std::make_tuple(7, "7 2"),
                    std::make_tuple(4, "4 1"), std::make_tuple(9, "9 3"),
                    std::make_tuple(3, "3 2"), std::make_tuple(12, "15 3"),
                    std::make_tuple(8, "15 3"), std::make_tuple(15, "15 3"),
                    std::make_tuple(1, "Not found")));

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

TEST_P(MaximumFixture, TestMaximum) {
  std::tuple<int, std::string> tuple = GetParam();

  int param = std::get<0>(tuple);
  std::string expected_value = std::get<1>(tuple);

  std::cout << "param = " << param << " expected value = " << expected_value
            << '\n';

  avl_tree_set_.Insert(5);
  avl_tree_set_.Insert(8);
  avl_tree_set_.Insert(12);
  avl_tree_set_.Insert(4);
  avl_tree_set_.Insert(3);
  avl_tree_set_.Insert(7);
  avl_tree_set_.Insert(15);
  avl_tree_set_.Insert(9);

  std::string key_depth = avl_tree_set_.Maximum(param);

  ASSERT_EQ(expected_value, key_depth);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
