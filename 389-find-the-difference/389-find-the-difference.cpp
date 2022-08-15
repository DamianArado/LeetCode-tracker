class Solution {
public:
    char findTheDifference(string s, string t) {
        int freq[26] = {0};
        for(char &c : t) freq[c - 'a']++;
        for(char &c : s) freq[c - 'a']--;
        for(int i = 0; i < 26; ++i)
            if(freq[i]) return (char)('a' + i);
        return 'a';
    }
};