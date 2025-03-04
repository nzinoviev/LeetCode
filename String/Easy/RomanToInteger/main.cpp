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

      char prev = Str.back();
      for (auto it = Str.rbegin(); it != Str.rend(); ++it) {
         if ('I' == *it) {
            if (prev == 'V' || prev == 'X') {
               result -= 1;
            }
            else {
               result += 1;
            }
         }
         else if ('V' == *it) {
            result += 5;
         }
         else if ('X' == *it) {
            if (prev == 'L' || prev == 'C') {
               result -= 10;
            } else {
               result += 10;
            }
         }
         else if ('L' == *it) {
            result += 50;
         }
         else if ('C' == *it) {
            if (prev == 'D' || prev == 'M') {
               result -= 100;
            } else {
               result += 100;
            }
         }
         else if ('D' == *it) {
            result += 500;
         }
         else if ('M' == *it) {
            result += 1000;
         }

         prev = *it;
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