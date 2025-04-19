// https://leetcode.com/problems/longest-common-prefix/description/

#include <algorithm>
#include <string>
#include <vector>

#include <gtest/gtest.h>


///////////////////////////////////////////////////////////////////////////////
/// Solution.
///////////////////////////////////////////////////////////////////////////////

class Solution
{
public:
   int removeDuplicates(std::vector<int>& nums)
   {
      std::size_t i = 1;
      for (std::size_t j = 1; j < nums.size(); ++j)
      {
         if (nums[j] != nums[i - 1])
         {
            nums[i] = nums[j];
            ++i;
         }
      }

      return i;
   }
};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(RemoveDuplicatesFromSortedArray, Test_1)
{
   std::vector<int> v { 1, 1, 1, 2, 3 };
   std::vector<int> expected { 1, 2 };

   Solution solution;
   solution.removeDuplicates(v);

   EXPECT_EQ(v, expected);
}


int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}