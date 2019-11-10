#include <iostream>
#include <limits>
#include <string>

class Solution
{
 public:
  int reverse(int x)
  {
    std::string int_str = std::to_string(x);
    int mid             = int_str.size() / 2;
    int bgn             = 0;
    int end             = int_str.size() - 1;
    if (int_str[0] == '-')
    {
      bgn++;
      mid++;
    }
    for (bgn; bgn < mid; bgn++)
    {
      std::swap(int_str[bgn], int_str[end]);
      end--;
    }

    try
    {
      x = stoi(int_str);
    }
    catch (std::invalid_argument& e)
    {
      return 0;
    }
    catch (std::out_of_range& e)
    {
      return 0;
    }

    return x;
  }
};