class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, n = s.size(), maxLen = 0;
        unordered_map<char, int> freq;
        for(int j = 0; j < n; ++j) {
            freq[s[j]]++;
            int windowSize = j - i + 1;
            if(freq.size() < windowSize) {
                freq[s[i]]--;
                if(freq[s[i]] == 0)
                    freq.erase(s[i]);
                i++;
            // then only we will be sure that all characters are unique in this window
            } else if(freq.size() == windowSize)
                maxLen = max(maxLen, windowSize);
        }
        return maxLen;
    }
};