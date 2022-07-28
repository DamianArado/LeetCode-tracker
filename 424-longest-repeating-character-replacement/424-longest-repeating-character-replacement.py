class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        n, i, maxFreq, windowSize = len(s), 0, 0, 0
        freq = collections.Counter()
        for j in range (n):
            freq[s[j]] += 1
            maxFreq = max(maxFreq, freq[s[j]])
            windowSize = j - i + 1
            if windowSize > maxFreq + k:
                freq[s[i]] -= 1
                i += 1
        return n - i