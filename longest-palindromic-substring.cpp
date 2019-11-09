#include <string>
#include <unordered_map>
class Solution
{
 public:
  std::string longestPalindrome(std::string s)
  {
    int i, j;
    std::unordered_map<char, int> char_pos_map;
    for (i = 0, j = 0; j < static_cast<int>(s.size()); j++)
    {
      auto it = char_pos_map.find(s[j]);
      if (it != char_pos_map.end())
      {
        std::string sub_str = s.substr() i = it->second + 1;
      }
      else
      {
      }
    }
  }

 private:
  bool IsPalindromic(const std::string &s, int bgn, int end) const;
};

bool Solution::IsPalindromic(const std::string &s, int bgn, int end) const
{
  while () }
