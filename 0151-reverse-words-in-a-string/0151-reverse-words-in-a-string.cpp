class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        // step 1: remove the leading and trailing white spaces
        int i = 0;
        for(i = 0; i < n; ++i)
            if(s[i] != ' ') 
                break;
        s = s.substr(i, n);
        
        n = s.length();
        for(i = n - 1; i >= 0; --i)
            if(s[i] != ' ')
                break;
        s = s.substr(0, i + 1);
        n = s.length();
        
        // step 2: reverse the complete string
        reverse(begin(s), end(s));
        
        cout <<s;
        
        // step 3: reverse the words inside the string
        string ans = "";
        string word = "";
        for(i = 0; i < n; ++i) {
            if(s[i] == ' ') {
                reverse(begin(word), end(word));
                ans = ans + (word == "" ? word + "" : word + " ");
                word = "";
                continue;
            }
            word += s[i];
        }
        reverse(begin(word), end(word));
        ans = ans + (word == "" ? word + "" : word + " ");
        n  = ans.length();
        ans = ans.substr(0, n - 1);
        return ans;
    }
};