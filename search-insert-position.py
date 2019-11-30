class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return 0
        rslt = []
        self.SearchPosition(nums, 0, len(nums)-1, target, rslt)
        return rslt[0]

    def SearchPosition(self, nums: List[int], bgn: int, end: int, target: int, rslt: List[int]):
        # print(str(bgn) + ":"+str(end))
        if bgn < end:
            mid = int((end+bgn)/2)
            # print("mid:" + str(mid)+":"+str(nums[mid]))
            if target > nums[mid]:
                self.SearchPosition(nums, mid+1, end, target, rslt)
            elif target >= nums[bgn]:
                self.SearchPosition(nums, bgn, mid, target, rslt)
            else:
                if bgn-1 >= 0:
                    rslt.append(bgn)
                else:
                    rslt.append(0)
        else:
            if nums[bgn] == target:
                # print("equal:"+str(bgn))
                rslt.append(bgn)
            else:
                if nums[bgn] > target:
                    if bgn-1 >= 0:
                        rslt.append(bgn)
                    else:
                        rslt.append(0)
                else:
                    rslt.append(bgn+1)
