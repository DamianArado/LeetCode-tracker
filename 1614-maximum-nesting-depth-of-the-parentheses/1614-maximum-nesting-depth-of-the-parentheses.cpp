class Solution {
public:
    int maxDepth(string s) {
        int depth = 0, maxDepth = 0;
        stack<char> stk;
        for (const char &c : s) {
            if (c == '(') {
                ++depth;
                maxDepth = max(maxDepth, depth);
                stk.emplace(c);
            } else if (c == ')' and !stk.empty() and stk.top() == '(') {
                --depth;
                stk.pop();
            }
        }
        return maxDepth;
    }
};