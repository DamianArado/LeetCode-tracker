class Solution:
    def removeStars(self, s: str) -> str:
        st = []
        for c in s:
            if c is not '*': st.append(c)
            else: st.pop()
        ans = ""
        for c in st:
            ans += c
        return ans