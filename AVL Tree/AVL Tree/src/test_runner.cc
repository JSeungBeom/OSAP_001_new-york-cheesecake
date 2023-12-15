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

class EraseTestFixture : public testing::Test {
public:
  EraseTestFixture();
  virtual ~EraseTestFixture();
  void SetUp() override;
  void TearDown() override;

protected:
  AVLTreeSet<int> avl_tree_set_;
};

EraseTestFixture::EraseTestFixture() {
  // std::cout << "EraseTestFixture: Constuctor called\n";
}

EraseTestFixture::~EraseTestFixture() {
  // std::cout << "EraseTestFixture: Destructor called\n";
}

void EraseTestFixture::SetUp() {
  // std::cout << "EraseTestFixture: SetUp called\n";
  avl_tree_set_.Insert(1);
  avl_tree_set_.Insert(5);
  avl_tree_set_.Insert(3);
  avl_tree_set_.Insert(10);
  avl_tree_set_.Insert(2);
}

void EraseTestFixture::TearDown() {
  // std::cout << "EraseTestFixture: TearDown called\n";
}

class FindTestFixture : public testing::TestWithParam<std::tuple<int, int>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    FindTests, FindTestFixture,
    testing::Values(std::make_tuple(5, 0), std::make_tuple(7, 2),
                    std::make_tuple(4, 1), std::make_tuple(9, 3),
                    std::make_tuple(3, 2), std::make_tuple(12, 2),
                    std::make_tuple(8, 1), std::make_tuple(15, 3),
                    std::make_tuple(1, 0)));

class MaximumTestFixture
    : public testing::TestWithParam<std::tuple<int, std::string>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    MaximumTests, MaximumTestFixture,
    testing::Values(std::make_tuple(5, "15 3"), std::make_tuple(7, "7 2"),
                    std::make_tuple(4, "4 1"), std::make_tuple(9, "9 3"),
                    std::make_tuple(3, "3 2"), std::make_tuple(12, "15 3"),
                    std::make_tuple(8, "15 3"), std::make_tuple(15, "15 3"),
                    std::make_tuple(1, "Not found")));

class MinimumTestFixture
    : public testing::TestWithParam<std::tuple<int, std::string>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    MinimumTests, MinimumTestFixture,
    testing::Values(std::make_tuple(5, "3 2"), std::make_tuple(7, "7 2"),
                    std::make_tuple(4, "3 2"), std::make_tuple(9, "9 3"),
                    std::make_tuple(3, "3 2"), std::make_tuple(12, "9 3"),
                    std::make_tuple(8, "7 2"), std::make_tuple(15, "15 3"),
                    std::make_tuple(1, "Not found")));

class RankTestFixture
    : public testing::TestWithParam<std::tuple<int, std::string>> {
public:
protected:
  AVLTreeSet<int> avl_tree_set_;
};

INSTANTIATE_TEST_CASE_P(
    RankTests, RankTestFixture,
    testing::Values(std::make_tuple(5, "0 3"), std::make_tuple(7, "2 4"),
                    std::make_tuple(4, "1 2"), std::make_tuple(9, "3 6"),
                    std::make_tuple(3, "2 1"), std::make_tuple(12, "2 7"),
                    std::make_tuple(8, "1 5"), std::make_tuple(15, "3 8"),
                    std::make_tuple(1, "0")));

// 생성자 테스트
TEST(ConstructorTest, TestConstructor) {
  AVLTreeSet<int> avl_tree_set;

  ASSERT_EQ(avl_tree_set.Size(), 0);
  ASSERT_EQ(avl_tree_set.Empty(), 1);
}

// 소멸자 테스트
TEST(DestructorTest, TestDestructor) {
  Destructed = false;
  AVLTreeSet<int> *avl_tree_set = new AVLTreeSet<int>();

  delete avl_tree_set;

  ASSERT_TRUE(Destructed);
}

// Insert 테스트, (Normal, LL, RR, LR, RL Case)
TEST(InsertTest, TestInsertNormalCase) {
  AVLTreeSet<int> avl_tree_set;

  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(5));
  EXPECT_EQ(1, avl_tree_set.Insert(1));
}

TEST(InsertTest, TestInsertLLCase) {
  AVLTreeSet<int> avl_tree_set;

  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(2));
  EXPECT_EQ(1, avl_tree_set.Insert(1));
}

TEST(InsertTest, TestInsertRRCase) {
  AVLTreeSet<int> avl_tree_set;

  EXPECT_EQ(0, avl_tree_set.Insert(1));
  EXPECT_EQ(1, avl_tree_set.Insert(2));
  EXPECT_EQ(1, avl_tree_set.Insert(3));
}

TEST(InsertTest, TestInsertLRCase) {
  AVLTreeSet<int> avl_tree_set;

  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(1));
  EXPECT_EQ(0, avl_tree_set.Insert(2));
}

TEST(InsertTest, TestInsertRLCase) {
  AVLTreeSet<int> avl_tree_set;

  EXPECT_EQ(0, avl_tree_set.Insert(3));
  EXPECT_EQ(1, avl_tree_set.Insert(5));
  EXPECT_EQ(0, avl_tree_set.Insert(4));
}

TEST(EmptyTest, TestEmpty) {
  AVLTreeSet<int> avl_tree_set;

  EXPECT_EQ(avl_tree_set.Empty(), 1);
  avl_tree_set.Insert(1);
  EXPECT_EQ(avl_tree_set.Empty(), 0);
  avl_tree_set.Insert(5);
  EXPECT_EQ(avl_tree_set.Empty(), 0);
}

TEST(SizeTest, TestSize) {
  AVLTreeSet<int> avl_tree_set;

  EXPECT_EQ(avl_tree_set.Size(), 0);
  avl_tree_set.Insert(1);
  EXPECT_EQ(avl_tree_set.Size(), 1);
  avl_tree_set.Insert(5);
  EXPECT_EQ(avl_tree_set.Size(), 2);
  avl_tree_set.Insert(3);
  EXPECT_EQ(avl_tree_set.Size(), 3);
  avl_tree_set.Erase(1);
  EXPECT_EQ(avl_tree_set.Size(), 2);
  avl_tree_set.Erase(5);
  EXPECT_EQ(avl_tree_set.Size(), 1);
  avl_tree_set.Erase(3);
  EXPECT_EQ(avl_tree_set.Size(), 0);
}

TEST_F(EraseTestFixture, TestErase) {
  EXPECT_EQ(0, avl_tree_set_.Erase(4));
  EXPECT_EQ(1, avl_tree_set_.Erase(1));
  EXPECT_EQ(1, avl_tree_set_.Erase(5));
  EXPECT_EQ(0, avl_tree_set_.Erase(3));
  EXPECT_EQ(0, avl_tree_set_.Erase(10));
  EXPECT_EQ(0, avl_tree_set_.Erase(2));
}

TEST_P(FindTestFixture, TestFind) {
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

TEST_P(MaximumTestFixture, TestMaximum) {
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

TEST_P(MinimumTestFixture, TestMinimum) {
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

TEST_P(RankTestFixture, TestRank) {
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
