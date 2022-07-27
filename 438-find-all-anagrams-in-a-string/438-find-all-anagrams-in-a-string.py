class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        n, k, i, j = len(s), len(p), 0, 0
        ans, mp = [], {}
        for c in p:
            if c in mp:
                mp[c] += 1
            else:
                mp[c] = 1
        chars = len(mp)
        
        while j < n:
            if s[j] in mp:
                mp[s[j]] -= 1
                if mp[s[j]] == 0: 
                    chars -= 1
            if j - i + 1 < k:
                j += 1
            elif j - i + 1 == k:
                if chars == 0:
                    ans.append(i)
                if s[i] in mp:
                    mp[s[i]] += 1
                    if mp[s[i]] == 1:
                        chars += 1
                i, j = i + 1, j + 1
                
        return ans