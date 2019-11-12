#include <iostream>
#include <string>

class Solution
{
 public:
  int myAtoi(std::string str)
  {
    int sz          = static_cast<int>(str.size());
    int digit_count = 0;
    int rslt        = 0;
    bool found_num  = false;
    bool negative   = false;

    for (int i = 0; i < sz; i++)
    {
      char &cur_char = str[i];
      if (cur_char == ' ')
      {
        if (found_num)
        {
          break;
        }
        else
        {
          continue;
        }
      }
      else
      {
        if (cur_char == '-')
        {
          if (found_num)
          {
            break;
          }
          negative  = true;
          found_num = true;
        }
        else if (cur_char == '+')
        {
          if (found_num)
          {
            break;
          }
          // negative  = true;
          found_num = true;
        }
        else if (cur_char >= 48 && cur_char <= 57)
        {
          int digit = cur_char - 48;
          if (negative)
          {
            if (rslt == 0)
            {
              rslt -= digit;
              if (rslt != 0)
              {
                digit_count++;
                // std::cout << "digit count: " << digit_count << " " <<
                // cur_char
                //           << std::endl;
              }
            }
            else
            {
              if (digit_count < 9)
              {
                rslt *= 10;
                rslt -= digit;
                digit_count++;
                // std::cout << "digit count: " << digit_count << " " <<
                // cur_char
                //           << std::endl;
              }
              else if (digit_count == 9)
              {
                if (rslt > std::numeric_limits<int>::min() / 10)
                {
                  rslt *= 10;
                  rslt -= digit;
                  digit_count++;
                  // std::cout << "digit count: " << digit_count << " "
                  //           << cur_char << std::endl;
                }
                else if (rslt == std::numeric_limits<int>::min() / 10)
                {
                  if (cur_char <= 56)
                  {
                    rslt *= 10;
                    rslt -= digit;
                    digit_count++;
                    // std::cout << "digit count: " << digit_count << " "
                    //           << cur_char << std::endl;
                  }
                  else
                  {
                    rslt = std::numeric_limits<int>::min();
                    break;
                  }
                }
                else
                {
                  rslt = std::numeric_limits<int>::min();
                  break;
                }
              }
              else
              {
                rslt = std::numeric_limits<int>::min();
                break;
              }
            }
          }
          else
          {
            if (rslt == 0)
            {
              rslt += digit;
              if (rslt != 0)
              {
                digit_count++;
                // std::cout << "digit count: " << digit_count << " " <<
                // cur_char
                //           << std::endl;
              }
            }
            else
            {
              if (digit_count < 9)
              {
                rslt *= 10;
                rslt += digit;
                digit_count++;
                // std::cout << "digit count: " << digit_count << " " <<
                // cur_char
                //           << std::endl;
              }
              else if (digit_count == 9)
              {
                // std::cout << "on digit 9: " << rslt << std::endl;
                // std::cout << std::numeric_limits<int>::max() / 10 <<
                // std::endl;

                if (rslt < std::numeric_limits<int>::max() / 10)
                {
                  rslt *= 10;
                  rslt += digit;
                  digit_count++;
                  // std::cout << "digit count: " << digit_count << " "
                  //           << cur_char << std::endl;
                }
                else if (rslt == std::numeric_limits<int>::max() / 10)
                {
                  if (cur_char <= 55)
                  {
                    rslt *= 10;
                    rslt += digit;
                    digit_count++;
                    // std::cout << "digit count: " << digit_count << " "
                    //           << cur_char << std::endl;
                  }
                  else
                  {
                    rslt = std::numeric_limits<int>::max();
                    break;
                  }
                }
                else
                {
                  rslt = std::numeric_limits<int>::max();
                  break;
                }
              }
              else
              {
                rslt = std::numeric_limits<int>::max();
                break;
              }
            }
          }
          found_num = true;
        }
        else
        {
          break;
        }
      }
    }
    return rslt;
  }
};