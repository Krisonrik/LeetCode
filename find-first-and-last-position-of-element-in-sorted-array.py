class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:

    def FindBegin(self, nums: List[int], target: int, bgn: int, end: int, bgn_idx: List[int])
        if end-bgn <= 1:
                if nums[bgn] == target:
                    bgn_idx.append(bgn)
                elif nums[end] == target:
                    bgn_idx.append(end)
                else:
            mid = int((end+bgn)/2)
            FindBegin(nums,target,bgn,mid,bgn_idx)
            FindBegin(nums,target,mid,end,bgn_idx)

