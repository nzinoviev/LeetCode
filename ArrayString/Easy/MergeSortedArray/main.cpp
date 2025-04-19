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
   void
   merge(
      std::vector<int>&  nums1,
      int                m,
      std::vector<int>&  nums2,
      int                n)
   {
      int i = m - 1;
      int j = n - 1;
      int k = m + n - 1;

      while (j >= 0)
      {
         if (i >= 0 && nums1[i] > nums2[j])
         {
            nums1[k--] = nums1[i--];
         }
         else
         {
            nums1[k--] = nums2[j--];
         }
      }
   }
};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(MergeSortedArray, Test_1) {
   Solution solution;
   std::vector<int> v1 { 1, 2, 3, 0, 0, 0 };
   std::vector<int> v2 { 2, 5, 6 };
   std::vector<int> expected { 1, 2, 2, 3, 5, 6 };

   solution.merge(v1, 3, v2, 3);
   EXPECT_EQ(v1, expected);
}


TEST(MergeSortedArray, Test_2) {
   Solution solution;
   std::vector<int> v1 { 1 };
   std::vector<int> v2 { };
   std::vector<int> expected { 1 };

   solution.merge(v1, 1, v2, 0);
   EXPECT_EQ(v1, expected);
}


TEST(MergeSortedArray, TEST_3) {
   Solution solution;
   std::vector<int> v1 { 0 };
   std::vector<int> v2 { 1 };
   std::vector<int> expected { 1 };

   solution.merge(v1, 0, v2, 1);
   EXPECT_EQ(v1, expected);
}


int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}