// https://leetcode.com/problems/longest-common-prefix/description/

#include <algorithm>
#include <string>
#include <vector>

#include <gtest/gtest.h>


///////////////////////////////////////////////////////////////////////////////
/// Solution.
///////////////////////////////////////////////////////////////////////////////

class Solution {
public:
   std::string longestCommonPrefix(std::vector<std::string>& strs) {
      if (std::find(std::begin(strs), std::end(strs), "") != std::end(strs)) {
         return "";
      }

      std::string prefix = "";
      std::size_t index = 0;
      bool exit = false;

      while (true) {
         std::map<char, int> map;
         for (std::size_t i = 0; i < strs.size(); ++i) {
            if (strs[i].find(prefix) != std::string::npos && index < strs[i].length()) {
               map[strs[i][index]]++;
            }
         }

         auto maxIt = std::max_element(
                        std::begin(map),
                        std::begin(map),
                        [](const auto& lhs, const auto& rhs) {
                           return lhs.second < rhs.second;
                        });
         if (maxIt == map.end()) {
            break;
         }

         for (std::size_t i = 0; i < strs.size(); ++i) {
            if (strs[i][index] != maxIt->first) {
               exit = true;
            }
         }
         if (exit) {
            break;
         }

         prefix += maxIt->first;
         ++index;
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