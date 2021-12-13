class Solution {
public:
    int characterReplacement(string s, int k) {
        /*
            maxf means the max frequency of the same character in the sliding window
            res is the length of the largest window we can find. The largest window we can find has 
            this property: res = maxf + k where maxf is the maximum character count within the window. 
            And here, we just find this length. 
        */
        
        int maxf = 0, i = 0, n = s.length();
        vector<int> count(26);
        
        for (int j = 0; j < n; ++j) {
            maxf = max(maxf, ++count[s[j] - 'A']);
            
            if (j - i + 1 > maxf + k)
                --count[s[i++] - 'A'];
        }
        
        return n - i;
    }
};