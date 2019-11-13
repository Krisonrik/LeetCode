class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        common_prefix: str = ''
        sz = len(strs)
        if sz < 2:
            if sz == 1:
                return strs[0]
            return ''

        cur_idx = 0
        ended = False
        while ended == False:
            for i in range(0, sz - 1):
                if cur_idx == len(strs[i]) or cur_idx == len(strs[i+1]):
                    ended = True
                    break
                if strs[i][cur_idx] != strs[i + 1][cur_idx]:
                    ended = True
                    break
            if ended == False:
                common_prefix += strs[i][cur_idx]
                cur_idx += 1

        return common_prefix
