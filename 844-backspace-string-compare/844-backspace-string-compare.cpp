class Solution {
public:
/* Follow up: O(1) Space
Can you do it in O(N) time and O(1) space?
I believe you have one difficulty here:
When we meet a char, we are not sure if it will be still there or be deleted.

However, we can do a back string compare (just like the title of problem).
If we do it backward, we meet a char and we can be sure this char won't be deleted.
If we meet a '#', it tell us we need to skip next lowercase char.

The idea is that, read next letter from end to start.
If we meet #, we increase the number we need to step back, until back = 0*/

    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1, j = T.length() - 1, back;
        while (true) {
            back = 0;
            while (i >= 0 && (back > 0 || S[i] == '#')) {
                back += S[i] == '#' ? 1 : -1;
                i--;
            }
            back = 0;
            while (j >= 0 && (back > 0 || T[j] == '#')) {
                back += T[j] == '#' ? 1 : -1;
                j--;
            }
            if (i >= 0 && j >= 0 && S[i] == T[j]) {
                i--;
                j--;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }
};
    
    /* 
    
    SC and TC -> O(s.length() + t.length())
    
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

*/