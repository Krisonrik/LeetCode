class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        list_depth = 0
        i = len(nums) - 1
        least_val_pos = i
        while i >= 0:
            if i != len(nums) - 1:
                if nums[i] > nums[least_val_pos]:
                    nums[i], nums[least_val_pos] = nums[least_val_pos], nums[i]
                    return
                elif nums[i] < nums[least_val_pos]:
                    least_val_pos = i
            i -= 1
        nums.sort()
