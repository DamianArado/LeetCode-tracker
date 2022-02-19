class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        for(int i = 0; i < s.length(); ++i) {
            if(!st1.empty() && s[i] == '#') st1.pop();
            if(s[i] != '#') st1.push(s[i]);
        }
        string x1 = "";
        while(!st1.empty()) {
            x1 += st1.top();
            st1.pop();
        }
        stack<char> st2;
        for(int i = 0; i < t.length(); ++i) {
            if(!st2.empty() && t[i] == '#') st2.pop();
            if(t[i] != '#') st2.push(t[i]);
        }
        string x2 = "";
        while(!st2.empty()) {
            x2 += st2.top();
            st2.pop();
        }
        return !x1.compare(x2);
    }
};