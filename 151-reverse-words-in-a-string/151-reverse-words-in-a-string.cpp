/*
    Reverse whole string then reverse word by word - O(1) in Space Complexity

    Reverse the whole string.
    Then we iterate characters in string s, fill found word into s then reverse it, word by word.
    Let l keep the starting index of the current word, r keep the next index for filling the current word.
    Reverse the current word, which is s[l..r-1]
    Set space character for character s[r] if r < s.size()
    Finally, resize the string s to remove redundant chars.
    
    Complexity

    Time: O(N), where N <= 10^4 is length of string s.
    Space: O(1)
*/

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0, i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != ' ')
                s[r++] = s[i++];

            if (l < r) { // if we can find a non-empty word then
                reverse(s.begin() + l, s.begin() + r); // reverse current word
                if (r == n) break;
                s[r++] = ' '; // set empty space
                l = r;
            }
            ++i; // now i == n or s[i] == ' ', so we skip that character!
        }
        if (r > 0 && s[r-1] == ' ') --r; // skip last empty character if have
        s.resize(r);
        return s;
    }
};