// https://leetcode.com/problems/roman-to-integer/description/

#include <map>
#include <string>

#include <gtest/gtest.h>

///////////////////////////////////////////////////////////////////////////////
/// Solution.
///////////////////////////////////////////////////////////////////////////////


class Solution {
public:
   int romanToInt(const std::string& Str) {
      int result = 0;

      for (int i = Str.size() - 1; i >= 0; --i) {
         auto current = Str[i];
         if ((i == 0)) {
            result += romanNumerals[current];
         }
         else {
            auto previous = Str[i - 1];
            if (romanNumerals[current] > romanNumerals[previous]) {
               result += romanNumerals[current] - romanNumerals[previous];
               --i;
            }
            else {
               result += romanNumerals[current];
            }
         }
      }

      return result;
   }

private:
   std::map<char, int> romanNumerals = {
      { 'I', 1 }, { 'V', 5 },
      { 'X', 10 }, { 'L', 50 },
      { 'C', 100 }, { 'D', 500 },
      { 'M', 1000 }
   };
};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

TEST(RomanToInt, SingleNumber_I) {
   Solution sulution;
   int      result = 0;
   int      expected = 1;

   result = sulution.romanToInt("I");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, SingleNumber_V) {
   Solution sulution;
   int      result = 0;
   int      expected = 5;

   result = sulution.romanToInt("V");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, SingleNumber_X) {
   Solution sulution;
   int      result = 0;
   int      expected = 10;

   result = sulution.romanToInt("X");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, SingleNumber_L) {
   Solution sulution;
   int      result = 0;
   int      expected = 50;

   result = sulution.romanToInt("L");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, SingleNumber_C) {
   Solution sulution;
   int      result = 0;
   int      expected = 100;

   result = sulution.romanToInt("C");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, SingleNumber_D) {
   Solution sulution;
   int      result = 0;
   int      expected = 500;

   result = sulution.romanToInt("D");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, SingleNumber_M) {
   Solution sulution;
   int      result = 0;
   int      expected = 1000;

   result = sulution.romanToInt("M");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_II) {
   Solution sulution;
   int      result = 0;
   int      expected = 2;

   result = sulution.romanToInt("II");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_IV) {
   Solution sulution;
   int      result = 0;
   int      expected = 4;

   result = sulution.romanToInt("IV");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_IX) {
   Solution sulution;
   int      result = 0;
   int      expected = 9;

   result = sulution.romanToInt("IX");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_XL) {
   Solution sulution;
   int      result = 0;
   int      expected = 40;

   result = sulution.romanToInt("XL");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_XC) {
   Solution sulution;
   int      result = 0;
   int      expected = 90;

   result = sulution.romanToInt("XC");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_CD) {
   Solution sulution;
   int      result = 0;
   int      expected = 400;

   result = sulution.romanToInt("CD");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_CM) {
   Solution sulution;
   int      result = 0;
   int      expected = 900;

   result = sulution.romanToInt("CM");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, DifficultRomanNumber_LVIII) {
   Solution sulution;
   int      result = 0;
   int      expected = 58;

   result = sulution.romanToInt("LVIII");

   EXPECT_EQ(result, expected);
}


TEST(RomanToInt, TwoRomanNumber_MCMXCIV) {
   Solution sulution;
   int      result = 0;
   int      expected = 1994;

   result = sulution.romanToInt("MCMXCIV");

   EXPECT_EQ(result, expected);
}


int main(int argc, char** argv) {
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}