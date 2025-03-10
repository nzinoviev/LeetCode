// https://leetcode.com/problems/roman-to-integer/description/

#include <map>
#include <string>

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

int main() {
   Solution solution;
   solution.romanToInt("MCMXCIV");
   return 0;
}