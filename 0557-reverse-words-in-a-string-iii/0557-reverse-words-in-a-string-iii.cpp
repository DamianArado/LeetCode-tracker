class Solution {
private:
    void copyWordToString(string &ans, const string &word) {
        for (const char &ch : word)
            ans += ch;
        ans += " ";
    }
public:
    string reverseWords(string s) {
        string ans, word;
        for (const char &c : s) {
            if (c == ' ') {
                reverse(begin(word), end(word));
                copyWordToString(ans, word);
                word = "";
                continue;
            }
            word += c;
        }
        reverse(begin(word), end(word));
        copyWordToString(ans, word);
        ans.pop_back();
        return ans;
    }
};