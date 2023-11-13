class Solution {
private:
    static bool isVowel(const char &c) {
        return c == 'A' or c == 'E' or c == 'I' or c == 'O' or c == 'U' or
            c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
    }
public:
    string sortVowels(string s) {
        unordered_map<char, int> vowelCount;
        for (const char &c : s)
            if (isVowel(c))
                ++vowelCount[c];
        string sortedVowel = "AEIOUaeiou";
        string ans;
        int j = 0;
        for (const char &c : s) {
            if (!isVowel(c))
                ans += c;
            else {
                while (vowelCount[sortedVowel[j]] == 0)
                    ++j;
                ans += sortedVowel[j];
                --vowelCount[sortedVowel[j]];
            }
        }
        return ans;
    }
};