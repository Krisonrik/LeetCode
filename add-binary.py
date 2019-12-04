class Solution:
    def addBinary(self, a: str, b: str) -> str:
        sz_a = len(a)
        sz_b = len(b)
        a = a[::-1]
        b = b[::-1]
        loop = min(sz_a, sz_b)
        diff = abs(sz_a - sz_b)
        rslt = ""
        carry = False
        j = 0
        for i in range(loop):
            if a[i] == b[i] == "1":
                if carry == True:
                    rslt += '1'
                else:
                    rslt += '0'
                carry = True
            elif a[i] != b[i]:
                if carry == True:
                    rslt += '0'
                    carry = True
                else:
                    rslt += '1'
                    carry = False
            else:
                if carry == True:
                    rslt += '1'
                    carry = False
                else:
                    rslt += '0'
                    carry = False
            j += 1
        if sz_a > sz_b:
            for i in range(diff):
                if a[j] == '1':
                    if carry == True:
                        rslt += '0'
                        carry = True
                    else:
                        rslt += '1'
                        carry = False
                else:
                    if carry == True:
                        rslt += '1'
                        carry = False
                    else:
                        rslt += '0'
                j += 1
        else:
            for i in range(diff):
                if b[j] == '1':
                    if carry == True:
                        rslt += '0'
                        carry = True
                    else:
                        rslt += '1'
                        carry = False
                else:
                    if carry == True:
                        rslt += '1'
                        carry = False
                    else:
                        rslt += '0'
                j += 1
        if carry == True:
            rslt += '1'
        rslt = rslt[::-1]
        if len(rslt) > 1:
            if rslt[0] == '0':
                rslt = rslt[1:]
        return rslt
