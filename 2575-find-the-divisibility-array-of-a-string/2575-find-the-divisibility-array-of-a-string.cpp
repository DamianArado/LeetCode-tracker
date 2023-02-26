class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = size(word);
        vector<int> ans(n);
        long long int prefix = 0;
        for(int i = 0; i < n; ++i) {
            int digit = word[i] - '0';
            prefix = (prefix * 10 + digit) % m;
            if(prefix == 0) ans[i] = 1;
        }
        return ans;
    }
};