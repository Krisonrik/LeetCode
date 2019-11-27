class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        needle_sz = len(needle)
        haystack_sz = len(haystack)
        starting_positions = []
        if needle_sz == 0:
            return 0
        if haystack_sz == 0:
            return - 1
        needle_char_pos = 0
        i = 0
        while i < haystack_sz:
            if haystack[i] == needle[0]:
                starting_positions.append(i)
            if haystack[i] == needle[needle_char_pos]:
                if needle_char_pos == 0:
                    starting_positions.pop(0)
                needle_char_pos += 1
                if needle_char_pos == needle_sz:
                    return i - needle_sz + 1
            else:
                needle_char_pos = 0
                if len(starting_positions) != 0:
                    i = starting_positions[0]
                    starting_positions.pop(0)
                    needle_char_pos += 1
            i += 1
        return -1
