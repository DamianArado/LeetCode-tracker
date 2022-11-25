class Solution {
private:
    bool isPalindrome(string &s) {
        int i = 0, j = size(s) - 1;
        while(i < j)
            if(s[i++] != s[j--]) 
                return false;
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string &word : words)
            if(isPalindrome(word)) 
                return word;
        return "";
    }
};