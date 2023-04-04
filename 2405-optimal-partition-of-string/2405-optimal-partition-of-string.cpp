class Solution {
public:
    int partitionString(string s) {
        int partition = 1;
        vector<int> freq(26);
        for(const char &c : s) {
            if(freq[c - 'a'] == 1) {
                ++partition;
                fill(begin(freq), end(freq), 0);
            }
            freq[c - 'a']++;
        }
        return partition;
    }
};