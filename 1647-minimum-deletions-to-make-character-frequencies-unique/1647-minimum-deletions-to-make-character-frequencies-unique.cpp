class Solution {
public:
    // O(26log26) + O(n) = O(n) tc
    int minDeletions(string s) {
        vector<int> freq(26);
        for (const char &c : s)
            ++freq[c - 'a'];
        sort(begin(freq), end(freq));
        int deletions = 0;
        for (int i = 24; i >= 0; --i) {
            if (!freq[i])
                break;
            if (freq[i] >= freq[i + 1]) {
                int prevFreq = freq[i];
                freq[i] = max(0, freq[i + 1] - 1);
                deletions += (prevFreq - freq[i]);
            }
        }
        return deletions;
    }
};