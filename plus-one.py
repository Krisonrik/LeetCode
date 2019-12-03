class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        sz = len(digits)
        if sz == 0:
            return [1]
        digits[sz-1] += 1
        for i in reversed(range(sz)):
            if digits[i] >= 10:
                digits[i] %= 10
                if i - 1 >= 0:
                    digits[i - 1] += 1
                else:
                    digits.insert(0, 1)
        return digits
