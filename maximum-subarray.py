class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return -2147483648
        loc_sum: int = nums[0]
        glob_sum: int = nums[0]
        for i in range(len(nums)):
            if i != 0:
                cur_val = nums[i]
                loc_sum = max(loc_sum + cur_val, cur_val)
                glob_sum = max(loc_sum, glob_sum)
        return glob_sum
