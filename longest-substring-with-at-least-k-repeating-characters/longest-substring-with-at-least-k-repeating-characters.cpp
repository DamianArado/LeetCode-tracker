class Solution {
public:
    int longestSubstring(string s, int k) {
        
        int n = static_cast<int>(s.length());
        unordered_map<char, int> count;
        
        for (char c : s) 
            ++count[c];
        
        int mid = 0;
        
        while (mid < n && count[s[mid]] >= k) 
            ++mid;
        
        if (mid == n) return n;
        
        int left = longestSubstring(s.substr(0, mid), k);
        
        while (mid < n && count[s[mid]] < k) 
            ++mid;
        
        int right = longestSubstring(s.substr(mid), k);
        
        return max(left, right);
    }
};