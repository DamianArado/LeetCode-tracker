class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> freqP(26), freqS(26);
        for(const char &ch : p) ++freqP[ch - 'a'];
        int i = 0, n = size(s);
        vector<int> ans;
        for(int j = 0; j < n; ++j) {
            int windowSize = j - i + 1;
            ++freqS[s[j] - 'a'];
            if(windowSize == size(p) and freqP == freqS) 
                ans.emplace_back(i);
            if(windowSize >= size(p)) {
                --freqS[s[i] - 'a'];
                ++i;
            }
        }
        return ans;
    }
};