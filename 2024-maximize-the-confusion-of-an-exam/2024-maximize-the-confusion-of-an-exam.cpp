class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size(), i = 0, maxFreq = 0, windowSize = 0;
        vector<int> freq(26);
        for(int j = 0; j < n; ++j) {
            windowSize = j - i + 1;
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            // we need to reduce the window size since at max longest repeating characters 
            // will be present inside the window size of maxFreq (element having max freq in the window) + k
            if(windowSize > maxFreq + k) {
                freq[s[i] - 'A']--;
                i++;
            }
        }
        return n - i;
    }
};