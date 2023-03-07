class Solution {
public:
    char repeatedCharacter(string s) {
        int freq[26] = {};
        for(const char &c : s) {
            freq[c - 'a']++;
            if(freq[c - 'a'] >= 2)
                return c;
        }
        return 'a';
    }
};