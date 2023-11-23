#include "avltree.cpp"
#include <gtest/gtest.h>
#include <iostream>

// 기본 기능 테스트 - Empty 함수
TEST(BasicFunctions, Empty) {
  AvlTree<int> set;
  
  EXPECT_TRUE(set.Empty());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}