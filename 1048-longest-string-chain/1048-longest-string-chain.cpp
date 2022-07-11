class Solution {
private:
    static bool comparator(string& a, string& b) {
        return (a.size() < b.size());
    }
    
    bool match(string &a, string &b) {
        // by default a > b and a.size - b.size = 1
        if(size(a) - size(b) != 1) return false;
        // if not then start matching 
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < size(a)) {
            if(a[ptr1] == b[ptr2] and ptr2 < size(b)) {
                // for cases like: a = "humay", b = "huma"
                ptr1++;
                ptr2++;
            } else ptr1++;
        }
        // if both reach the end, matching done
        if(ptr1 == size(a) and ptr2 == size(b)) return true;
        return false;
    }
public:
    int longestStrChain(vector<string>& words) {
        int n = size(words);
        // sort the array as we want to compare the size of adjacent ones
        sort(begin(words), end(words), comparator);
        int maxStrChain = 1;
        vector<int> dp(n, 1);
        for(int idx = 1; idx < n; ++idx) {
            for(int prev = 0; prev < idx; ++prev) {
                if(match(words[idx], words[prev]) and dp[idx] < dp[prev] + 1)
                    dp[idx] = 1 + dp[prev];
            }
            maxStrChain = max(maxStrChain, dp[idx]);
        }
        return maxStrChain;
    }
};