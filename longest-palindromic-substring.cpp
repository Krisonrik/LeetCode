#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
 public:
  std::string longestPalindrome(std::string s)
  {
    if (s.empty())
    {
      return std::string();
    }
    std::pair<int, int> longest_polidrome;
    longest_polidrome.first  = 0;
    longest_polidrome.second = 1;
    for (auto i = 0; i < s.size(); i++)
    {
      int expand = 0;
      int sz     = 0;
      if (i + 1 < s.size())
      {
        if (s[i] == s[i + 1])
        {
          expand = TryExpand(s, i, i + 1);
          sz     = expand * 2 + 2;
          //   std::cout << "E: " << expand << std::endl;
          if (longest_polidrome.second < sz)
          {
            longest_polidrome.first  = i - expand;
            longest_polidrome.second = sz;
          }
        }
      }
      expand = TryExpand(s, i, i);
      sz     = expand * 2 + 1;
      //   std::cout << "E: " << expand << std::endl;
      if (longest_polidrome.second < sz)
      {
        longest_polidrome.first  = i - expand;
        longest_polidrome.second = sz;
      }
    }
    return s.substr(longest_polidrome.first, longest_polidrome.second);
  }

 private:
  int TryExpand(const std::string &s, int bgn, int end) const;
};

int Solution::TryExpand(const std::string &s, int bgn, int end) const
{
  //   std::cout << "BF "
  //             << "\"" << s.substr(bgn, end - bgn + 1) << "\"" << std::endl;

  int expand = 0;
  if (bgn > 0 && end < s.size() - 1)
  {
    bgn--;
    end++;
  }
  else
  {
    // std::cout << std::endl;
    return 0;
  }

  while (s[bgn] == s[end])
  {
    expand++;
    if (bgn > 0 && end < s.size() - 1)
    {
      bgn--;
      end++;
    }
    else
    {
      //   std::cout << "AF "
      //             << "\"" << s.substr(bgn, end - bgn + 1) << "\"" <<
      //             std::endl
      //             << std::endl;
      return expand;
    }
  }
  //   std::cout << "AF "
  //             << "\"" << s.substr(bgn, end - bgn + 1) << "\"" << std::endl
  //             << std::endl;
  return expand;
}

// class Solution
// {
//  public:
//   std::string longestPalindrome(std::string s)
//   {
//     int i, j;
//     std::unordered_map<char, int> char_pos_map;
//     std::pair<int, int> longest_polidrome;
//     for (i = 0, j = 0; j < static_cast<int>(s.size()); j++)
//     {
//       auto it = char_pos_map.find(s[j]);
//       if (it != char_pos_map.end())
//       {
//         i = it->second;
//         if (IsPalindromic(s, i, j))
//         {
//           int expandable_chars = TryExpand(s, i, j);
//           std::cout << s.substr(i, j) << " expandable-" << expandable_chars
//                     << std::endl;
//           if (longest_polidrome.second < j - i)
//           {
//             longest_polidrome.first  = i - expandable_chars;
//             longest_polidrome.second = j - i + 1 + expandable_chars * 2;
//           }
//         }
//       }
//       char_pos_map[s[j]] = j;
//     }
//     if (!s.empty() && longest_polidrome.second == 0)
//     {
//       return s.substr(0, 1);
//     }
//     return s.substr(longest_polidrome.first, longest_polidrome.second);
//   }

//  private:
//   bool IsPalindromic(const std::string &s, int bgn, int end) const;
//   std::pair<int, int> TryExpand(const std::string &s, int bgn, int end)
//   const;
// };

// bool Solution::IsPalindromic(const std::string &s, int bgn, int end) const
// {
//   // std::cout << "\"" << s.substr(bgn, end - bgn + 1) << "\"" <<
//   std::endl;

//   int word_sz = end - bgn + 1;
//   // std::cout << "sz: " << word_sz << std::endl;

//   int loop_cnt = word_sz / 2;

//   // std::cout << "loops: " << loop_cnt << std::endl;

//   int pos = 1;
//   for (int i = bgn + pos; i < loop_cnt + bgn; i++)
//   {
//     // std::cout << "lf: " << s[i] << " rt: " << s[end - pos] << std::endl;
//     if (s[i] != s[end - pos])
//     {
//       // std::cout << std::endl;
//       return false;
//     }
//     pos++;
//   }
//   // std::cout << "\"" << s.substr(bgn, end - bgn + 1) << "\""
//   //           << " is!" << std::endl;
//   // std::cout << std::endl;

//   return true;
// }
