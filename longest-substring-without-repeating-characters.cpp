#include <algorithm>
#include <string>
#include <unordered_set>

class Solution
{
 public:
  int lengthOfLongestSubstring(std::string s)
  {
    int cur_cumulated = 0;
    int longest       = 0;
    std::string str_holder;
    for (auto &e : s)
    {
      if (str_holder.find(e) == std::string::npos)
      {
        str_holder.push_back(e);
        cur_cumulated++;
      }
      else
      {
        longest             = std::max(cur_cumulated, longest);
        int first_occur_pos = str_holder.find(e);
        // std::cout << "first occ "<< first_occur_pos << std::endl;
        cur_cumulated = static_cast<int>(str_holder.size() - first_occur_pos);
        str_holder    = str_holder.substr(first_occur_pos + 1, cur_cumulated);
        str_holder.push_back(e);
      }
    }
    // std::cout << str_holder << std::endl;
    longest = std::max(cur_cumulated, longest);

    return longest;
  }
};