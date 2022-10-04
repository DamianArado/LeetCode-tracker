class Solution {
public:
    // maximize the size of window
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j;
        for(j = 0; j < size(s); ++j) 
            if((maxCost -= abs(s[j] - t[j])) < 0)
                maxCost += abs(s[i] - t[i++]);
        return j - i;
    }
};