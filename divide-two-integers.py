class Solution:
    # def divide(self, dividend: int, divisor: int) -> int:
    #     rslt = 0
    #     sign = 1
    #     if dividend < 0:
    #         if divisor > 0:
    #             sign = -1
    #     else:
    #         if divisor < 0:
    #             sign = -1

    #     abs_dividend = abs(dividend)
    #     abs_divisor = abs(divisor)

    #     while abs_dividend > 0:
    #         abs_dividend -= abs_divisor
    #         if abs_dividend >= 0:
    #             rslt += 1

    #     return rslt

    def divide(self, dividend: int, divisor: int) -> int:
        rslt = 0
        positive = True
        if dividend < 0:
            if divisor > 0:
                positive = False
        else:
            if divisor < 0:
                positive = False

        abs_dividend = abs(dividend)
        abs_divisor = abs(divisor)

        while abs_dividend > 0:
            abs_dividend -= abs_divisor
            if abs_dividend >= 0:
                rslt += 1

        return rslt
