class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i = 0, j = 0, n1 = size(word1), n2 = size(word2);
        while(i < n1 and j < n2) {
            ans += word1[i++];
            ans += word2[j++];
        }
        while(i < n1) ans += word1[i++];
        while(j < n2) ans += word2[j++];
        return ans;
    }
};