#include <algorithm>
#include <iostream>
#include <map>
#include <string>

class Solution
{
 public:
  std::string convert(std::string s, int numRows)
  {
    if (numRows < 2)
    {
      return s;
    }
    int sz         = static_cast<int>(s.size());
    int offset     = numRows * 2 - 2;
    int loop_count = sz / offset + 1;
    int row_w      = loop_count * (numRows - 1);
    std::map<int, char> str_pos_holder;

    for (int i = 0; i < sz; i++)
    {
      int cycle_idx    = i / offset;
      int in_cycle_pos = i % offset;

      if (in_cycle_pos < numRows)
      {
        int gap_offset = cycle_idx * (numRows - 1);
        str_pos_holder[in_cycle_pos * row_w + gap_offset] = s[i];
      }
      else
      {
        int row = numRows - (in_cycle_pos + 1) % numRows - 1;
        int gap_offset =
            cycle_idx * (numRows - 1) + (in_cycle_pos + 1) - numRows;
        str_pos_holder[row * row_w + gap_offset] = s[i];
      }
    }
    int idx = 0;
    for (auto it = str_pos_holder.begin(); it != str_pos_holder.end(); it++)
    {
      s[idx] = it->second;
      idx++;
    }

    return s;
  }
};

// class Solution
// {
//  public:
//   std::string convert(std::string s, int numRows)
//   {
//     if (numRows < 2)
//     {
//       return s;
//     }
//     int sz         = static_cast<int>(s.size());
//     int offset     = numRows * 2 - 2;
//     int loop_count = sz / offset + 1;
//     int row_w      = loop_count * (numRows - 1);
//     std::string padded_holder(row_w * numRows, ' ');
//     for (int i = 0; i < sz; i++)
//     {
//       int cycle_idx    = i / offset;
//       int in_cycle_pos = i % offset;

//       if (in_cycle_pos < numRows)
//       {
//         int gap_offset = cycle_idx * (numRows - 1);
//         padded_holder[in_cycle_pos * row_w + gap_offset] = s[i];
//       }
//       else
//       {
//         int row = numRows - (in_cycle_pos + 1) % numRows - 1;
//         int gap_offset =
//             cycle_idx * (numRows - 1) + (in_cycle_pos + 1) - numRows;
//         padded_holder[row * row_w + gap_offset] = s[i];
//       }
//     }
//     std::string out;
//     for (auto &e : padded_holder)
//     {
//       if (e != ' ')
//       {
//         out.push_back(e);
//       }
//     }
//     return out;
//   }
// };