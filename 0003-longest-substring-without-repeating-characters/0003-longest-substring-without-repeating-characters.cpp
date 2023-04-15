class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int i = 0, ans = 0;
        for(int j = 0; j < size(s); ++j) {
            ++mp[s[j]];
            while(mp[s[j]] > 1) {
                if(--mp[s[i]] == 0)
                    mp.erase(s[i]);
                ++i;
            }
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};