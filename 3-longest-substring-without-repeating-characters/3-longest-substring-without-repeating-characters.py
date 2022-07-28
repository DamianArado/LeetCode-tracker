class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        i = maxLen = 0
        freq = {}
        for j in range (n):
            if s[j] in freq:
                freq[s[j]] += 1
            else:
                freq[s[j]] = 1
            windowSize = j - i + 1
            if len(freq) < windowSize:
                freq[s[i]] -= 1
                if freq[s[i]] == 0:
                    del freq[s[i]]
                i += 1
            else:
                maxLen = max(maxLen, windowSize)
        return maxLen