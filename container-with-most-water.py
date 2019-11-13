class Solution:
    def maxArea(self, height: List[int]) -> int:
        sz = len(height)
        lf = 0
        rt = sz - 1
        max_vol = 0
        while lf < rt:
            max_vol = max(max_vol, min(height[lf], height[rt])*(rt-lf))
            if (height[lf] < height[rt]):
                lf += 1
            else:
                rt -= 1
        return max_vol
