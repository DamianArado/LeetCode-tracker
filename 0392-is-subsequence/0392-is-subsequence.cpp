class Solution {
public:
    bool isSubsequence(string s, string t) {
        int idx1 = 0, idx2 = 0, n1 = size(s), n2 = size(t);
        while (idx1 < n1 and idx2 < n2) {
            if (s[idx1] == t[idx2])
                ++idx1, ++idx2;
            else 
                ++idx2;
        }
        return idx1 == n1;
    }
};