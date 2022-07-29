class Solution:
    def minWindow(self, s: str, t: str) -> str:
        n, minLen = len(s), 1e7
        i = start = windowSize = 0
        freq = {}
        for c in t:
            if c in freq:
                freq[c] += 1
            else:
                freq[c] = 1
        chars = len(freq)
        for j in range (n):
            if s[j] in freq:
                freq[s[j]] -= 1
                if freq[s[j]] == 0:
                    chars -= 1
            if chars == 0:
                while chars == 0:
                    if s[i] in freq:
                        freq[s[i]] += 1
                        if freq[s[i]] == 1:
                            chars += 1
                    windowSize = j - i + 1
                    if minLen > windowSize:
                        minLen = windowSize
                        start = i
                    i += 1
        if minLen == 1e7: return ""
        else: return s[start : start + minLen]