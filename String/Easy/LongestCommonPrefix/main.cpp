// https://leetcode.com/problems/longest-common-prefix/description/

#include <algorithm>
#include <string>
#include <vector>

#include <gtest/gtest.h>


///////////////////////////////////////////////////////////////////////////////
/// Solution (Horizontal scanning).
///////////////////////////////////////////////////////////////////////////////

//
// LCP (S1, ..., Sn) = LCP(LCP(LCP(S1, S2), S3), ..., Sn)
//

class Solution {
   public:
      std::string
      longestCommonPrefix(
         std::vector<std::string>& Strs) {
            if (Strs.size() == 0) {
               return "";
            }

            std::string prefix = Strs[0];
            for (std::size_t i = 1; i < Strs.size(); ++i) {
               while (Strs[i].find(prefix) != 0) {
                  prefix = prefix.substr(0, prefix.length() - 1);
                  if (prefix.empty()) {
                     return "";
                  }
               }
            }

         return prefix;
      }
   };


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(LongestCommonPrefix, Prefix_fl) {
   Solution sulution;
   std::vector<std::string> strs = { "flower", "flow", "flight" };
   std::string expected = "fl";
   std::string result = "";

   result = sulution.longestCommonPrefix(strs);

   EXPECT_EQ(result, expected);
}


TEST(LongestCommonPrefix, Prefix_empty) {
   Solution sulution;
   std::vector<std::string> strs = { "flower", "apple" };
   std::string expected = "";
   std::string result = "";

   result = sulution.longestCommonPrefix(strs);

   EXPECT_EQ(result, expected);
}


TEST(LongestCommonPrefix, Prefix_apple) {
   Solution sulution;
   std::vector<std::string> strs = { "apple", "apple" };
   std::string expected = "apple";
   std::string result = "";

   result = sulution.longestCommonPrefix(strs);

   EXPECT_EQ(result, expected);
}


TEST(LongestCommonPrefix, Two_empty_strings) {
   Solution sulution;
   std::vector<std::string> strs = { "", "" };
   std::string expected = "";
   std::string result = "";

   result = sulution.longestCommonPrefix(strs);

   EXPECT_EQ(result, expected);
}


TEST(LongestCommonPrefix, OneString) {
   Solution sulution;
   std::vector<std::string> strs = { "apple" };
   std::string expected = "apple";
   std::string result = "";

   result = sulution.longestCommonPrefix(strs);

   EXPECT_EQ(result, expected);
}


TEST(LongestCommonPrefix, Prefix_a) {
   Solution sulution;
   std::vector<std::string> strs = {
      "ab",
      "ab",
      "ab",
      "a"
   };
   std::string expected = "a";
   std::string result = "";

   result = sulution.longestCommonPrefix(strs);

   EXPECT_EQ(result, expected);
}


int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}