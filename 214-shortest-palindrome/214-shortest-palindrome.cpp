class Solution {
private:
    vector<int> KMP(string &text) {
        vector<int> kmp(size(text) + 1);
        int i = 0, j = -1;
        kmp[0] = -1;
        while(i < size(text)) {
            while(j != -1 and text[i] != text[j]) 
                j = kmp[j];
            ++i, ++j;
            kmp[i] = j;
        }
        return kmp;
    }
public:
    string shortestPalindrome(string s) {
        string rev = s;
        // Step 1: reverse the original string and add it to the end of it with # (acts as a delimiter)
        reverse(rev.begin(), rev.end());
        string text = s + "#" + rev;
        
        // Step 2: find the kmp array for the string (original + # + reversed)
        vector<int> kmp = KMP(text);
        
        // Step 3: find the number of characters that match 
        int n = text.length();
        int pos = kmp[n];
        
        // Step 4: remove the characters till pos in s and store it in ans
        string ans = s.substr(pos);
        
        // Step 5: reverse the current ans and append it to the start of string s
        reverse(ans.begin(), ans.end());
        return ans + s;
    }
};