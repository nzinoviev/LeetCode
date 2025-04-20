#include <vector>

#include <gtest/gtest.h>


///////////////////////////////////////////////////////////////////////////////
///   https://leetcode.com/problems/binary-search/
///
///   Given an array of integers nums which is sorted in ascending order, and an integer target,
///   write a function to search target in nums. If target exists, then return its index. Otherwise,
///   return -1.
///
///   You must write an algorithm with O(log n) runtime complexity.
///////////////////////////////////////////////////////////////////////////////

/// L
/// -1 0 3 5 9 12
/// R
class Solution
{
public:
   int search(std::vector<int>& nums, int target)
   {
      int index = -1;

      int left = 0;
      int right = nums.size() - 1;

      while (left <= right)
      {
         int mid = (left + right) / 2;

         if (target == nums[mid])
         {
            index = mid;
            break;
         }
         else if (nums[mid] > target)
         {
            right = mid - 1;
         }
         else
         {
            left = mid + 1;
         }

      }

      return index;
   }
};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(FindClosestNumber, Test_1) {
   std::vector<int> v { -1, 0, 3, 5 , 9, 12 };
   int result = -1;
   int expected = 4;
   Solution s;

   result = s.search(v, 9);

   EXPECT_EQ(result, expected);
}


TEST(FindClosestNumber, Test_2) {
   std::vector<int> v { -1, 0, 3, 5, 9, 12 };
   int result = -1;
   int expected = -1;
   Solution s;

   result = s.search(v, 2);

   EXPECT_EQ(result, expected);
}


int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}