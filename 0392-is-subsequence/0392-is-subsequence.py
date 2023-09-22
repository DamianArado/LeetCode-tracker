class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        idx1, idx2, n1, n2 = 0, 0, len(s), len(t)
        while idx1 < n1 and idx2 < n2:
            if s[idx1] == t[idx2]:
                idx1, idx2 = idx1 + 1, idx2 + 1
            else:
                idx2 += 1
        return idx1 is n1