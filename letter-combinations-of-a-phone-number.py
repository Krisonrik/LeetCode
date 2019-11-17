class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        letter_char = {2: ['a', 'b', 'c'], 3: ['d', 'e', 'f'], 4: ['g', 'h', 'i'], 5: ['j', 'k', 'l'], 6: [
            'm', 'n', 'o'], 7: ['p', 'q', 'r'], 8: ['t', 'u', 'v'], 9: ['w', 'x', 'y', 'z']}
        loops = 1
        for i in digits:
            loops *= len(letter_char[int(i)])
        print(loops)
        combinations = []
        for i in digits:
            combinations.append

        return []

    def Increment(num: int) -> List[str]:
        print(letter_char)
