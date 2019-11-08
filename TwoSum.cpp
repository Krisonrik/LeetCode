#include <algorithm>
#include <unordered_map>
#include <vector>

// class Solution {
// public:
//   std::vector<int> twoSum(std::vector<int> &nums, int target) {
//     std::unordered_map<int, int> holder;
//     std::vector<int> rslt;
//     for (auto i = 0; i < static_cast<int>(nums.size()); i++) {
//       int complement = target - nums[i];
//       auto it = holder.find(complement);
//       if (it != holder.end()) {
//         rslt.emplace_back(i);
//         rslt.emplace_back(it->second);
//         return rslt;
//       } else {
//         holder.emplace(nums[i], i);
//       }
//     }
//     return rslt;
//   }
// };

class Solution {
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::vector<int> sorted_vec = nums;
    std::sort(sorted_vec.begin(), sorted_vec.end());
    int bgn = 0;
    int end = nums.size() - 1;
    // int max_smaller_idx = 0;
    // FindNearestIndex(sorted_vec, bgn, end, target, max_smaller_idx);
    int idx_l, idx_r, val_l, val_r;
    // if (FindSumFromTwoEnd(sorted_vec, bgn, max_smaller_idx, target, idx_l,
    //                       idx_r)) {
    //   val_l = sorted_vec[idx_l];
    //   val_r = sorted_vec[idx_r];
    // } else {
    //   FindSumFromTwoEnd(sorted_vec, max_smaller_idx, end, target, idx_l,
    //   idx_r); val_l = sorted_vec[idx_l]; val_r = sorted_vec[idx_r];
    // }

    FindSumFromTwoEnd(sorted_vec, bgn, end, target, idx_l, idx_r);
    val_l = sorted_vec[idx_l];
    val_r = sorted_vec[idx_r];

    bool found_l = false;
    for (int i = 0; i < nums.size(); i++) {
      if (!found_l) {
        if (val_l == nums[i]) {
          idx_l = i;
          found_l = true;
        }
      }
      if (val_r == nums[i]) {
        idx_r = i;
      }
    }
    std::vector<int> components;
    components.push_back(idx_l);
    components.push_back(idx_r);
    return components;
  }

private:
  void FindNearestIndex(std::vector<int> &sorted_vec, int bgn, int end,
                        int target, int &idx);

  bool FindSumFromTwoEnd(std::vector<int> &sorted_vec, int bgn, int end,
                         int target, int &idx_l, int &idx_r);
};

void Solution::FindNearestIndex(std::vector<int> &sorted_vec, int bgn, int end,
                                int target, int &idx) {
  if (end - bgn > 1) {
    int mid = (end + bgn) / 2;
    if (sorted_vec[mid] < target) {
      FindNearestIndex(sorted_vec, mid, end, target, idx);
    } else if (sorted_vec[mid] > target) {
      FindNearestIndex(sorted_vec, bgn, mid, target, idx);
    } else {
      idx = mid;
    }
  } else {
    if (std::abs(sorted_vec[bgn] - target) <
        std::abs(sorted_vec[end] - target)) {
      idx = bgn;
    } else {
      idx = end;
    }
  }
}

bool Solution::FindSumFromTwoEnd(std::vector<int> &sorted_vec, int bgn, int end,
                                 int target, int &idx_l, int &idx_r) {
  bool found = false;
  idx_l = bgn;
  idx_r = end;
  while (!found) {
    if (idx_l >= idx_r) {
      return false;
    }
    if (sorted_vec[idx_l] + sorted_vec[idx_r] > target) {
      idx_r--;
    } else if (sorted_vec[idx_l] + sorted_vec[idx_r] < target) {
      idx_l++;
    } else {
      found = true;
    }
  }
  return true;
}
