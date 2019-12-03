class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        gl_max_len = 0
        loc_max_len = 0
        for i in s:
            if i != ' ':
                loc_max_len += 1
            else:
                if loc_max_len != 0:
                    gl_max_len = loc_max_len
                loc_max_len = 0
        if loc_max_len != 0:
            gl_max_len = loc_max_len
        return gl_max_len
