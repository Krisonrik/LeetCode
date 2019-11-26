class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        cur_val_idx = 0
        cur_val = nums[0]
        for i in range(len(nums)):
            if nums[i] != cur_val:
                nums[cur_val_idx + 1], nums[i] = nums[i], nums[cur_val_idx + 1]
                cur_val_idx += 1
                cur_val = nums[cur_val_idx]
        return cur_val_idx + 1
