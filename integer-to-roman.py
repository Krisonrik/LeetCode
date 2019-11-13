class Solution:
    def intToRoman(self, num: int) -> str:
        thousand: str = ''
        five_hundred: str = ''
        one_hundred: str = ''
        fifty: str = ''
        ten: str = ''
        five: str = ''
        one: str = ''
        remainder = num % 1000
        for i in range(0, int(num / 1000)):
            thousand += 'M'
        if remainder >= 900:
            five_hundred = 'CM'
            remainder -= 900
        elif remainder >= 500:
            five_hundred = 'D'
            remainder -= 500
            for i in range(0, int(remainder / 100)):
                one_hundred += 'C'
        elif remainder >= 400:
            five_hundred = 'CD'
            remainder -= 400
        else:
            for i in range(0, int(remainder / 100)):
                one_hundred += 'C'

        remainder = remainder % 100

        if remainder >= 90:
            fifty = 'XC'
            remainder -= 90
        elif remainder >= 50:
            fifty = 'L'
            remainder -= 50
            for i in range(0, int(remainder / 10)):
                ten += 'X'
        elif remainder >= 40:
            fifty = 'XL'
            remainder -= 40
        else:
            for i in range(0, int(remainder / 10)):
                ten += 'X'

        remainder = remainder % 10

        if remainder == 9:
            five = 'IX'
            remainder -= 9
        elif remainder >= 5:
            five = 'V'
            remainder -= 5
            for i in range(0, remainder):
                one += 'I'
        elif remainder == 4:
            five = 'IV'
            remainder -= 4
        else:
            for i in range(0, remainder):
                one += 'I'

        return thousand + five_hundred + one_hundred + fifty + ten + five + one
