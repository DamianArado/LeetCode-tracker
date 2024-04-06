class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int i = s.size();
        int balance = 0;
        for (int j = s.size() - 1; j >= 0; j--) {
            if (s[j] == ')') balance++;
            else if (s[j] == '(') {
                if (balance == 0) continue;
                balance--;
            }
            s[--i] = s[j];
        }
        int len = 0;
        balance = 0;
        for (; i < s.size(); i++) {
            if (s[i] == '(') balance++;
            else if (s[i] == ')') {
                if (balance == 0) continue;
                balance--;
            }
            s[len++] = s[i];
        }
        s.erase(len);
        return s;
    }
};