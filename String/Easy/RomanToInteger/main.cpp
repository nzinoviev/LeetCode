// https://leetcode.com/problems/roman-to-integer/description/

#include <map>
#include <string>

///////////////////////////////////////////////////////////////////////////////
/// Solution.
///////////////////////////////////////////////////////////////////////////////


class Solution {
public:
   int romanToInt(std::string Str) {
      int result = 0;

      for (std::size_t i = 0; i < Str.size(); ++i) {
         if ('I' == Str[i]) {
            if ('V' == Str[i + 1]) {
               result += 4;
               i += 1;
            }
            else if ('X' == Str[i + 1]) {
               result += 9;
               i += 1;
            }
            else {
               result += 1;
            }
         }
         else if ('V' == Str[i]) {
            result += 5;
         }
         else if ('X' == Str[i]) {
            if ('L' == Str[i + 1]) {
               result += 40;
               i += 1;
            }
            else if ('C' == Str[i + 1]) {
               result += 90;
               i += 1;
            }
            else {
               result += 10;
            }
         }
         else if ('L' == Str[i]) {
            result += 50;
         }
         else if ('C' == Str[i]) {
            if ('D' == Str[i + 1]) {
               result += 400;
               i += 1;
            }
            else if ('M' == Str[i + 1]) {
               result += 900;
               i += 1;
            }
            else {
               result += 100;
            }
         }
         else if ('D' == Str[i]) {
            result += 500;
         }
         else if ('M' == Str[i]) {
            result += 1000;
         }
      }

      return result;
   }

private:
   // std::map<char, int> romanNumerals = {
   //    { 'I', 1 }, { 'V', 5 },
   //    { 'X', 10 }, { 'L', 50 },
   //    { 'C', 100 }, { 'D', 500 },
   //    { 'M', 1000 }
   // };
};


///////////////////////////////////////////////////////////////////////////////
/// Unit tests.
///////////////////////////////////////////////////////////////////////////////

int main() {
   Solution solution;
   solution.romanToInt("MCMXCIV");
   return 0;
}