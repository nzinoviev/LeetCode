#include <vector>

#include <gtest/gtest.h>

///////////////////////////////////////////////////////////////////////////////
///   https://leetcode.com/problems/move-zeroes/description/
///
///   Given an integer array nums, move all 0's to the end of it while maintaining
///   the relative order of the non-zero elements.
///
///   Note that you must do this in-place without making a copy of the array.
///////////////////////////////////////////////////////////////////////////////

//       Nz
// 0 1 0 3 12
//         It
// 1 3 12 0 0

class Solution
{
public:
   void moveZeroes(std::vector<int>& Nums)
   {
      auto nz = Nums.begin();
      for (auto it = Nums.begin(); it != Nums.end(); ++it)
      {
         if (*it != 0)
         {
            std::swap(*it, *nz++);
         }
      }
   }

};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(MoveZeroes, Test_1) {
   Solution sulution;
   std::vector<int> v {0, 1, 0 , 3, 12};
   std::vector<int> expected {1, 3, 12, 0, 0};

   sulution.moveZeroes(v);

   EXPECT_EQ(v, expected);
}


TEST(MoveZeroes, Test_2) {
   Solution sulution;
   std::vector<int> v {0};
   std::vector<int> expected {0};

   sulution.moveZeroes(v);

   EXPECT_EQ(v, expected);
}


TEST(MoveZeroes, Test_3) {
   Solution sulution;
   std::vector<int> v;
   std::vector<int> expected;

   sulution.moveZeroes(v);

   EXPECT_EQ(v, expected);
}


TEST(MoveZeroes, Test_4) {
   Solution sulution;
   std::vector<int> v { 1, 2, 3};
   std::vector<int> expected { 1, 2, 3};

   sulution.moveZeroes(v);

   EXPECT_EQ(v, expected);
}


int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}