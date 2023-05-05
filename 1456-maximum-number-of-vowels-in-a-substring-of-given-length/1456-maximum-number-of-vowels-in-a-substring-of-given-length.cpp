class Solution {
private:
    static bool isVowel(const char &c) {
        return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int l = 0, ans = 0, vowels = 0;
        for(int r = 0; r < size(s); ++r) {
            if(isVowel(s[r])) ++vowels;
            int window = r - l + 1;
            if(window == k) 
                ans = max(ans, vowels);
            else if(window > k) {
                if(isVowel(s[l])) --vowels;
                ++l;
                ans = max(ans, vowels);
            }
        }
        return ans;
    }
};