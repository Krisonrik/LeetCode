class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        if len(nums) == 0:
            return 0
        cur_val_idx = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[cur_val_idx], nums[i] = nums[i], nums[cur_val_idx]
                cur_val_idx += 1
        return cur_val_idx
