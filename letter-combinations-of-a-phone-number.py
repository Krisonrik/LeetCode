class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letter_char = {0: [], 1: [], 2: ['a', 'b', 'c'], 3: ['d', 'e', 'f'], 4: ['g', 'h', 'i'], 5: ['j', 'k', 'l'], 6: [
            'm', 'n', 'o'], 7: ['p', 'q', 'r', 's'], 8: ['t', 'u', 'v'], 9: ['w', 'x', 'y', 'z']}
        if len(digits) == 0:
            return []
        loops = 1
        char_counter = []
        char_pos_chart = []
        combinations = []
        for i in digits:
            digit_val = int(i)
            loops *= len(letter_char[digit_val])
            char_counter.append(letter_char[digit_val])
            char_pos_chart.append(1)

        # print(loops)
        for i in range(loops):
            cur_combo = ''
            for j in range(len(char_pos_chart)):
                if(char_pos_chart[j]-1 == len(char_counter[j])):
                    char_pos_chart[j] = 1
                    if j < len(char_counter)-1:
                        char_pos_chart[j+1] += 1
                cur_combo += char_counter[j][char_pos_chart[j]-1]
            combinations.append(cur_combo)
            # print(char_pos_chart)
            char_pos_chart[0] += 1

        return combinations
