class Solution:
    def longestPrefix(self, s: str) -> str:
        i, j, n = 0, 1, len(s)
        lps = [0] * n
        while j < n:
            if s[i] == s[j]:
                lps[j] = i + 1
                i, j = i + 1, j + 1
            elif i == 0:
                lps[j] = 0
                j += 1
            else:
                i = lps[i - 1]
        prefixLen = lps[n - 1]
        return s[0 : prefixLen]