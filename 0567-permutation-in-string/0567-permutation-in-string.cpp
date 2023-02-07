class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqS1(26), freqS2(26);
        for(const char &ch : s1) ++freqS1[ch - 'a'];
        int n = size(s2), i = 0;
        for(int j = 0; j < n; ++j) {
            int windowSize = j - i + 1;
            ++freqS2[s2[j] - 'a'];
            if(windowSize == size(s1) and freqS1 == freqS2)
                return true;
            if(windowSize >= size(s1)) {
                --freqS2[s2[i] - 'a'];
                ++i;
            }
        }
        return false;
    }
};