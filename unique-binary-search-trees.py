class Solution:
    def numTrees(self, n: int) -> int:
        sum = 0
        for i in range(1, n+1):
            sum += FindBST(i, n)

        return sum


def FindBST(root: int, n: int) -> int:
    if root > 1 and root < n:
        bst_count = 0
        bst_count += FindBST(root - 1, n) * FindBST(n - root, n)
        return bst_count
    else:
        return 1
