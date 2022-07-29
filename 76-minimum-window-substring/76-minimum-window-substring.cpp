class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), i = 0, minLen = INT_MAX, start = 0;
        unordered_map<char, int> freq;
        for(char &c : t) freq[c]++;
        int chars = freq.size();
        for(int j = 0; j < n; ++j) {
            if(freq.find(s[j]) != freq.end()) {
                freq[s[j]]--;
                if(freq[s[j]] == 0) chars--;
            }
            if(chars == 0) {
                while(chars == 0) {
                    int windowSize = j - i + 1;
                    if(freq.find(s[i]) != freq.end()) {
                        freq[s[i]]++;
                        if(freq[s[i]] == 1) chars++;
                        if(windowSize < minLen) {
                            minLen = windowSize;
                            start = i;
                        }
                    }
                    i++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};