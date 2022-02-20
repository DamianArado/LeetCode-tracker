class Solution {
public:
    string removeDuplicates(string s, int k) {
        auto j = 0;  // rightmost index of the resultant string
        vector<int> cnt(s.size(), 1);  // store counts to eep track as soon as it becomes k
        for(auto i = 0; i < s.size(); ++i, ++j) {
            s[j] = s[i];  // skip duplicates
            if(j > 0 && s[j] == s[j - 1]) cnt[j] = cnt[j - 1] + 1;  
            else cnt[j] = 1;  
            if(cnt[j] == k) j -= k;  // remove k duplicates
        }
        return s.substr(0, j);
    }
};