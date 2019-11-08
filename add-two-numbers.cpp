#include <iostream>
#include <list>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL)
  {
  }
};

class Solution
{
 public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    ListNode *root       = new ListNode(0);
    ListNode *cur_nd_1   = l1;
    ListNode *cur_nd_2   = l2;
    int cur_val          = 0;
    ListNode *cur_digit  = new ListNode(0);
    root->next           = cur_digit;
    ListNode *before_end = nullptr;

    while (cur_nd_1 != nullptr || cur_nd_2 != nullptr)
    {
      if (cur_nd_1 == nullptr)
      {
        cur_val = cur_nd_2->val;
      }
      else if (cur_nd_2 == nullptr)
      {
        cur_val = cur_nd_1->val;
      }
      else
      {
        cur_val = cur_nd_1->val + cur_nd_2->val;
      }
      int &tmp_val = cur_digit->val;
      tmp_val += cur_val;
      int carry = tmp_val / 10;

      if (tmp_val >= 10)
      {
        tmp_val = tmp_val % 10;
      }
      cur_digit->next = new ListNode(carry);

      if (cur_nd_1 != nullptr)
      {
        cur_nd_1 = cur_nd_1->next;
      }
      if (cur_nd_2 != nullptr)
      {
        cur_nd_2 = cur_nd_2->next;
      }
      before_end = cur_digit;
      cur_digit  = cur_digit->next;
    }

    if (cur_digit->val == 0)
    {
      before_end->next = nullptr;
      delete cur_digit;
    }

    ListNode *rslt = root->next;
    delete root;
    return rslt;
  }
};
