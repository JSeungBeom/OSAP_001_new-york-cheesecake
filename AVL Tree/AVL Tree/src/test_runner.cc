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

// 생성자 테스트
TEST(SetTest, TestConstructor) {
  AVLTreeSet<int> avl_tree_set;

  ASSERT_EQ(avl_tree_set.Size(), 0);
  ASSERT_EQ(avl_tree_set.Empty(), 1);
}

// 소멸자 테스트
TEST(SetTest, TestDestructor) {
  Destructed = false;
  AVLTreeSet<int> *avl_tree_set = new AVLTreeSet<int>();

  delete avl_tree_set;

  ASSERT_TRUE(Destructed);
}

// Insert 테스트, (Normal, LL, RR, LR, RL Case)
TEST(InsertTest, TestNormalCase){
  AVLTreeSet<int> avl_tree_set;
  
  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(5));
  EXPECT_EQ(1, avl_tree_set.Insert(1));
}

TEST(InsertTest, TestLLCase){
  AVLTreeSet<int> avl_tree_set;
  
  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(2));
  EXPECT_EQ(1, avl_tree_set.Insert(1));
}

TEST(InsertTest, TestRRCase){
  AVLTreeSet<int> avl_tree_set;
  
  EXPECT_EQ(0, avl_tree_set.Insert(1));
  EXPECT_EQ(1, avl_tree_set.Insert(2));
  EXPECT_EQ(1, avl_tree_set.Insert(3));
}

TEST(InsertTest, TestLRCaseInsert){
  AVLTreeSet<int> avl_tree_set;
  
  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(1));
  EXPECT_EQ(0, avl_tree_set.Insert(2));
}

TEST(InsertTest, TestRLCaseInsert){
  AVLTreeSet<int> avl_tree_set;
  
  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(5));
  EXPECT_EQ(0, avl_tree_set.Insert(4));
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

class FindFixture
    : public testing::TestWithParam<std::tuple<int, int>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    FindTests, FindFixture,
    testing::Values(std::make_tuple(5, 0), std::make_tuple(7, 2),
                    std::make_tuple(4, 1), std::make_tuple(9, 3),
                    std::make_tuple(3, 2), std::make_tuple(12, 2),
                    std::make_tuple(8, 1), std::make_tuple(15, 3),
                    std::make_tuple(1, 0)));

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

class MinimumFixture
    : public testing::TestWithParam<std::tuple<int, std::string>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    MinimumTests, MinimumFixture,
    testing::Values(std::make_tuple(5, "3 2"), std::make_tuple(7, "7 2"),
                    std::make_tuple(4, "3 2"), std::make_tuple(9, "9 3"),
                    std::make_tuple(3, "3 2"), std::make_tuple(12, "9 3"),
                    std::make_tuple(8, "7 2"), std::make_tuple(15, "15 3"),
                    std::make_tuple(1, "Not found")));                    
                    

class RankFixture
    : public testing::TestWithParam<std::tuple<int, std::string>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    RankTests, RankFixture,
    testing::Values(std::make_tuple(5, "0 3"), std::make_tuple(7, "2 4"),
                    std::make_tuple(4, "1 2"), std::make_tuple(9, "3 6"),
                    std::make_tuple(3, "2 1"), std::make_tuple(12, "2 7"),
                    std::make_tuple(8, "1 5"), std::make_tuple(15, "3 8"),
                    std::make_tuple(1, "0")));
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
  avl_tree_set_.Insert(3);
  EXPECT_EQ(avl_tree_set_.Size(), 3);
  avl_tree_set_.Erase(1);
  EXPECT_EQ(avl_tree_set_.Size(), 2);
  avl_tree_set_.Erase(5);
  EXPECT_EQ(avl_tree_set_.Size(), 1);
  avl_tree_set_.Erase(3);
  EXPECT_EQ(avl_tree_set_.Size(), 0);
}

TEST_F(SetTestFixture, TestErase) {
  EXPECT_EQ(0, avl_tree_set_.Erase(4));
  EXPECT_EQ(1, avl_tree_set_.Erase(1));
  EXPECT_EQ(1, avl_tree_set_.Erase(5));
  EXPECT_EQ(0, avl_tree_set_.Erase(3));
  EXPECT_EQ(0, avl_tree_set_.Erase(10));
  EXPECT_EQ(0, avl_tree_set_.Erase(2));
}

TEST_P(FindFixture, TestFind) {
  std::tuple<int, int> tuple = GetParam();

  int param = std::get<0>(tuple);
  int expected_value = std::get<1>(tuple);

  // std::cout << "param = " << param << " expected value = " << expected_value
  //           << '\n';

  avl_tree_set_.Insert(5);
  avl_tree_set_.Insert(8);
  avl_tree_set_.Insert(12);
  avl_tree_set_.Insert(4);
  avl_tree_set_.Insert(3);
  avl_tree_set_.Insert(7);
  avl_tree_set_.Insert(15);
  avl_tree_set_.Insert(9);

  int depth = avl_tree_set_.Find(param);

  ASSERT_EQ(expected_value, depth);
}

TEST_P(MaximumFixture, TestMaximum) {
  std::tuple<int, std::string> tuple = GetParam();

  int param = std::get<0>(tuple);
  std::string expected_value = std::get<1>(tuple);

  // std::cout << "param = " << param << " expected value = " << expected_value
  //           << '\n';

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

TEST_P(MinimumFixture, TestMinimum) {
  std::tuple<int, std::string> tuple = GetParam();

  int param = std::get<0>(tuple);
  std::string expected_value = std::get<1>(tuple);

  // std::cout << "param = " << param << " expected value = " << expected_value
  //           << '\n';

  avl_tree_set_.Insert(5);
  avl_tree_set_.Insert(8);
  avl_tree_set_.Insert(12);
  avl_tree_set_.Insert(4);
  avl_tree_set_.Insert(3);
  avl_tree_set_.Insert(7);
  avl_tree_set_.Insert(15);
  avl_tree_set_.Insert(9);

  std::string key_depth = avl_tree_set_.Minimum(param);

  ASSERT_EQ(expected_value, key_depth);
}

TEST_P(RankFixture, TestRank) {
  std::tuple<int, std::string> tuple = GetParam();

  int param = std::get<0>(tuple);
  std::string expected_value = std::get<1>(tuple);

  // std::cout << "param = " << param << " expected value = " << expected_value
  //           << '\n';

  avl_tree_set_.Insert(5);
  avl_tree_set_.Insert(8);
  avl_tree_set_.Insert(12);
  avl_tree_set_.Insert(4);
  avl_tree_set_.Insert(3);
  avl_tree_set_.Insert(7);
  avl_tree_set_.Insert(15);
  avl_tree_set_.Insert(9);

  std::string key_depth = avl_tree_set_.Rank(param);

  ASSERT_EQ(expected_value, key_depth);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
