class Solution:
    def search(self, nums: List[int], target: int) -> int:
        idx = -1
        pivot = 0
        rslt = []
        if len(nums) == 0:
            return idx

        self.FindPivot(nums, 0, len(nums)-1, rslt)
        if len(rslt) != 0:
            pivot = rslt[0]
            print(pivot)

        if nums[pivot] == target:
            return pivot

        rslt = []
        self.BinarySearch(nums, 0, pivot, target, rslt)
        if len(rslt) != 0:
            idx = rslt[0]
        self.BinarySearch(nums, pivot, len(nums)-1, target, rslt)
        if len(rslt) != 0:
            idx = rslt[0]

        return idx

    def BinarySearch(self, nums: List[int], bgn: int, end: int, target: int, rslt: List[int]):
        # print(str(bgn)+":"+str(end))
        if end - bgn <= 1:
            if nums[bgn] == target:
                rslt.append(bgn)
            elif nums[end] == target:
                rslt.append(end)
            return
        mid = int((bgn + end)/2)
        if target >= nums[bgn] and target <= nums[mid]:
            self.BinarySearch(nums, bgn, mid, target, rslt)
        else:
            # if target >= nums[mid+1] and target <= nums[end]:
            self.BinarySearch(nums, mid+1, end, target, rslt)

    def FindPivot(self, nums: List[int], bgn: int, end: int, rslt: List[int]):
        if end - bgn <= 1:
            if nums[bgn] > nums[end]:
                rslt.append(end)
            else:
                rslt.append(bgn)
            return
        mid = int((bgn + end)/2)
        if nums[bgn] > nums[mid]:
            self.FindPivot(nums, bgn, mid, rslt)
        else:
            self.FindPivot(nums, mid, end, rslt)
