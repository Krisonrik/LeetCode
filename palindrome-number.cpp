#include <iostream>
#include <stdexcept>
#include <string>

class Solution
{
 public:
  bool isPalindrome(int x)
  {
    if (x < 0)
    {
      return false;
    }
    else if (x < 10)
    {
      return true;
    }
    else
    {
      std::string int_str;
      try
      {
        int_str = std::to_string(x);
      }
      catch (std::invalid_argument& e)
      {
        return false;
      }
      catch (std::out_of_range& e)
      {
        return false;
      }
      int sz         = int_str.size();
      int loop_count = sz / 2;
      if (sz % 2 == 0)
      {
        loop_count++;
      }
      //   std::cout << loop_count << std::endl;
      for (int i = 0; i < loop_count; i++)
      {
        if (int_str[i] != int_str[sz - 1 - i])
        {
          return false;
        }
      }
    }
    return true;
  }
};