class Solution:
    def KMP(self, text: str) -> list:
        i, j, kmp = 0, -1, [0] * (len(text) + 1)
        kmp[0] = -1
        while i < len(text):
            while j != -1 and text[i] != text[j]:
                j = kmp[j]
            i, j = i + 1, j + 1
            kmp[i] = j
        return kmp
        
    def shortestPalindrome(self, s: str) -> str:
        temp = s[::-1]
        text = s + "#" + temp
        kmp = self.KMP(text)
        pos = kmp[len(text)]
        ans = s[pos:]
        return ans[::-1] + s