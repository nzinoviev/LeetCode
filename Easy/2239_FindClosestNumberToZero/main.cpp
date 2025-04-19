#include <vector>

#include <gtest/gtest.h>


///////////////////////////////////////////////////////////////////////////////
///   https://leetcode.com/problems/find-closest-number-to-zero/
///
///   Given an integer array nums of size n, return the number with the value closest to 0 in nums.
///   If there are multiple answers, return the number with the largest value.
///////////////////////////////////////////////////////////////////////////////

class Solution
{
public:
   int findClosestNumber(std::vector<int>& nums)
   {
      int closestToZero = nums.front();
      for (auto it = nums.begin(); it != nums.end(); ++it)
      {
         if (std::abs(closestToZero) >= std::abs(*it))
         {
            closestToZero = ((std::abs(*it) == std::abs(closestToZero)) && (*it != closestToZero)) ? std::abs(*it): *it;
         }
      }

      return closestToZero;
   }
};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(FindClosestNumber, Test_1) {
   Solution sulution;
   std::vector<int> v {-4, -2, 1, 4, 8};
   int expected = 1;
   int result = 0;

   result = sulution.findClosestNumber(v);

   EXPECT_EQ(result, expected);
}


TEST(FindClosestNumber, Test_2) {
   Solution sulution;
   std::vector<int> v {2, -1, 1};
   int expected = 1;
   int result = 0;

   result = sulution.findClosestNumber(v);

   EXPECT_EQ(result, expected);
}

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}