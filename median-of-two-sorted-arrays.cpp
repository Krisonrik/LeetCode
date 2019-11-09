#include <algorithm>
#include <iostream>
#include <vector>
class Solution
{
 public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2)
  {
    // int sum = RecurseAdd(nums1, 0, static_cast<int>(nums1.size() - 1));
    // sum += RecurseAdd(nums2, 0, static_cast<int>(nums2.size() - 1));
    // double mean = sum / 2;
    // return mean;
    // nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    // std::sort(nums1.begin(), nums1.end());

    std::vector<int> merged_nums;
    int total_size = static_cast<int>(nums1.size() + nums2.size());
    if (nums1.empty())
    {
      merged_nums = nums1;
    }
    else if (nums2.empty())
    {
      merged_nums = nums2;
    }
    else
    {
      merged_nums.reserve(total_size);
      RecurseSortedMerge(
          nums1, nums2, 0, nums1.size() - 1, 0, nums2.size() - 1, merged_nums);
    }
    for (auto &e : merged_nums)
    {
      std::cout << e << std::endl;
    }
    if (total_size % 2 != 0)
    {
      return merged_nums[total_size / 2 + 1];
    }
    return (merged_nums[total_size / 2] + merged_nums[total_size / 2 + 1]) /
           2.0;
  }

 private:
  //   int RecurseAdd(std::vector<int> &nums, int bgn, int end);
  void RecurseSortedMerge(const std::vector<int> &vec_1,
                          const std::vector<int> &vec_2,
                          int bgn_1,
                          int end_1,
                          int bgn_2,
                          int end_2,
                          std::vector<int> &merged_vec);
};

// int Solution::RecurseAdd(std::vector<int> &nums, int bgn, int end)
// {
//   int sum = 0;
//   if (end - bgn > 1)
//   {
//     int mid = (bgn + end) / 2;
//     // std::cout << bgn << " " << mid << " " << end << std::endl;
//     sum += RecurseAdd(nums, bgn, mid);
//     sum += RecurseAdd(nums, mid + 1, end);
//   }
//   else if (end - bgn == 1)
//   {
//     sum = nums[bgn] + nums[end];
//   }
//   else if (end - bgn == 0)
//   {
//     sum = nums[bgn];
//   }
//   else
//   {
//     sum = 0;
//   }
//   return sum;
// }

void Solution::RecurseSortedMerge(const std::vector<int> &vec_1,
                                  const std::vector<int> &vec_2,
                                  int bgn_1,
                                  int end_1,
                                  int bgn_2,
                                  int end_2,
                                  std::vector<int> &merged_vec)
{
  std::vector<int> tmp_merged_vec;
  if (vec_1[end_1] < vec_2[bgn_2])
  {
    tmp_merged_vec.resize((end_1 - bgn_1 + end_2 - bgn_2) + 2);
    memcpy(tmp_merged_vec.data(), vec_1.data(), end_1 - bgn_1 + 1);
    memcpy(tmp_merged_vec.data() + end_1 - bgn_1 + 1,
           vec_2.data(),
           end_2 - bgn_2 + 1);
    merged_vec.insert(
        merged_vec.end(), tmp_merged_vec.begin(), tmp_merged_vec.end());
  }
  else
  {
    int mid_1 = (end_1 - bgn_1) / 2;
    int mid_2 = (end_2 - bgn_2) / 2;
    RecurseSortedMerge(vec_1, vec_2, bgn_1, mid_1, bgn_2, mid_2, merged_vec);
    RecurseSortedMerge(vec_1, vec_2, mid_1, end_1, mid_2, end_2, merged_vec);
  }
}
