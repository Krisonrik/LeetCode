class Solution:
    dic_o = {'(': ')', '[': ']',  '{': '}'}

    def isValid(self, s: str) -> bool:
        holder = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                holder.append(i)
            else:
                if len(holder) - 1 < 0:
                    return False
                if i != self.dic_o[holder[len(holder)-1]]:
                    return False
                holder.pop(len(holder) - 1)
        if len(holder) != 0:
            return False
        return True

    # def isValid(self, s: str) -> bool:
    #     if len(s) == 0:
    #         return True
    #     symbol_map = {}
    #     for i in range(len(s)):
    #         symbol_map.setdefault(s[i], []).append(i)

    #     for key in symbol_map:
    #         if key == ')' or key == ']' or key == '}':
    #             continue

    #         open_ls = symbol_map[key]
    #         close_ls = symbol_map[self.dic_o[key]]
    #         if len(open_ls) != len(open_ls):
    #             print("open count does not match close count")
    #             return False
    #         for i in range(len(open_ls)):
    #             if (close_ls[i] - open_ls[i]) % 2 != 1:

    #                 print(key + " " + str(close_ls[i])+":"+str(open_ls[i]))
    #                 return False

    #         return True

    # def isValid(self, s: str) -> bool:
    #     open_cumulated = 0
    #     sz = len(s)
    #     if sz % 2 != 0:
    #         return False
    #     pivot = 0
    #     opened = False
    #     open_pos = 0
    #     for i in range(sz):
    #         if s[i] == '(' or s[i] == '[' or s[i] == '{':
    #             if opened == False:
    #                 opened = True
    #                 open_pos = i
    #             if (i + 1 >= len(s)):
    #                 return False
    #             if self.dic_o[s[i]] == s[i + 1]:
    #                 pivot = i
    #                 for j in range(pivot - open_pos+1):
    #                     if (pivot + j + 1 >= len(s)):
    #                         return False
    #                     if self.dic_o[s[pivot - j]] != s[pivot + j + 1]:
    #                         return False
    #                 opened = False
    #     return opened == False
