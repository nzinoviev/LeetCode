// https://leetcode.com/problems/longest-common-prefix/description/

#include <algorithm>
#include <string>
#include <vector>

#include <gtest/gtest.h>


///////////////////////////////////////////////////////////////////////////////
/// Solution.
/// https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
///////////////////////////////////////////////////////////////////////////////

// 2 2 1 1 1 2 2
class Solution
{
public:
   int majorityElement(std::vector<int>& nums)
   {
      int m = nums[0];
      int c = 1;

      for (std::size_t i = 1; i < nums.size(); ++i)
      {
         if (0 == c)
         {
            m = nums[i];
            ++c;
         }
         else if (nums[i] == m)
         {
            ++c;
         }
         else
         {
            --c;
         }

      }

      return m;
   }
};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(MajorityElement, Test_1) {
   Solution solution;
   std::vector<int> v { 3, 2, 3 };
   int expected = 3;

   int result = solution.majorityElement(v);
   EXPECT_EQ(result, expected);
}


TEST(MajorityElement, Test_2) {
   Solution solution;
   std::vector<int> v { 2, 2, 1, 1, 1, 2, 2 };
   int expected = 2;

   int result = solution.majorityElement(v);
   EXPECT_EQ(result, expected);
}


int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}